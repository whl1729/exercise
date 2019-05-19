#include <iostream>
#include <string>
#include <stack>

using namespace std;

char prio[256] = {0};
const string digit{"0123456789"};
const string sign{"(+-*/^)"};

void set_prio()
{
    prio['('] = 0;
    prio[')'] = 1;
    prio['+'] = prio['-'] = 2;
    prio['*'] = prio['/'] = 3;
    prio['^'] = 4;
}

bool get_token(const string &expr, int &token, int &flag)
{
    static string::size_type pos = 0;

    if (pos > expr.size())
    {
        pos = 0;
        return false;
    }

    // skip blanks
    for (; pos < expr.size() && expr[pos] == ' '; ++pos);

    // add a ')' as a sentinel in order to simplify handling.
    if (pos == expr.size())
    {
        token = ')';
        flag = 0;
        ++pos;
        return true;
    }

    string::size_type dpos = expr.find_first_of(digit, pos);
    string::size_type spos = expr.find_first_of(sign, pos);

    if (dpos == pos)
    {
        spos = (spos == string::npos) ? expr.size() : spos;
        token = stoi(expr.substr(dpos, spos - dpos));
        pos = spos;
        flag = 1;
        return true;
    }
    else if (spos == pos)
    {
        token = expr[pos];
        pos = spos + 1;
        flag = 0;
        return true;
    }
    else
        return false;
}

int do_calc(int first, int second, int oper)
{
    int result;

    switch(oper)
    {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            result = first / second;
            break;
        default:
            result = 0;
            break;
    }

    return result;
}

bool calc_expr(const string &expr, int &result)
{
    int token = 0;
    int flag = 0;  // 0 = operator, 1 = operand.
    stack<int> oper;
    stack<int> oprd;
    int top, first, second;

    oper.push('(');

    while (get_token(expr, token, flag))
    {
        if (flag)  // the token is an operand
        {
            oprd.push(token);
        }
        else if (token == '(')
        {
            oper.push(token);
        }
        else  // the token is an operator
        {
            top = oper.top();

            while (prio[top] >= prio[token])
            {
                oper.pop();

                if (oprd.empty())
                    return false;
                second = oprd.top();
                oprd.pop();
                
                if (oprd.empty())
                    return false;
                first = oprd.top();
                oprd.pop();

                oprd.push(do_calc(first, second, top));

                top = oper.top();
            }

            if (token == ')')
            {
                if (top != '(')
                    return false;
                oper.pop();
            }
            else
                oper.push(token);
        }
    }

    if (oprd.empty())
        return false;

    result = oprd.top();
    oprd.pop();

    return (oprd.empty()? true : false);
}

int main()
{
    string expr;
    int result;

    set_prio();

    cout << "Enter expressions: " << endl;

    while (getline(cin, expr))
    {
        if (calc_expr(expr, result))
            cout << expr << " = " << result << endl;
        else
            cout << "Error: Invalid expression!" << endl;
    }

    return 0;
}
