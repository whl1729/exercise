#include <iostream>
#include "Token.h"

using std::cout;
using std::endl;
 
Token::Token(Token &&t): tok(t.tok)
{
    cout << "Token(Token &&t)" << endl;

    if (tok == STR)
        sval = std::move(t.sval);
    else if (tok == BOOK)
        bval = std::move(t.bval);
    else
        copyUnion(t);
}

Token::~Token() 
{ 
    if (tok == STR) 
        sval.~string(); 
    else if (tok == BOOK)
        bval.~Sales_data();
}

Token &Token::operator=(int i)
{
    if (tok == STR)
        sval.~string();
    else if (tok == BOOK)
        bval.~Sales_data();

    ival = i;
    tok = INT;
    return *this;
}

Token &Token::operator=(char c)
{
    if (tok == STR)
        sval.~string();
    else if (tok == BOOK)
        bval.~Sales_data();

    cval = c;
    tok = CHAR;
    return *this;
}

Token &Token::operator=(double d)
{
    if (tok == STR)
        sval.~string();
    else if (tok == BOOK)
        bval.~Sales_data();

    dval = d;
    tok = DBL;
    return *this;
}

Token &Token::operator=(const std::string &s)
{
    if (tok == BOOK)
        bval.~Sales_data();

    if (tok == STR)
        sval = s;
    else
    {
        new (&sval) string(s);
        tok = STR;
    }

    return *this;
}

Token &Token::operator=(const Sales_data &b)
{
    if (tok == STR)
        sval.~string();

    if (tok == BOOK)
        bval = b;
    else
    {
        new (&bval) Sales_data(b);
        tok = BOOK;
    }

    return *this;
}

void Token::copyUnion(const Token &t)
{
    switch(t.tok)
    {
        case INT:
            ival = t.ival;
            break;
        case CHAR:
            cval = t.cval;
            break;
        case DBL:
            dval = t.dval;
            break;
        case STR:
            new (&sval) string(t.sval);
            break;
        case BOOK:
            new (&bval) Sales_data(t.bval);
            break;
    }
}

Token &Token::operator=(const Token &t)
{
    if (tok == STR && t.tok != STR)
        sval.~string();

    if (tok == BOOK && t.tok != BOOK)
        bval.~Sales_data();

    if (tok == STR && t.tok == STR)
        sval = t.sval;
    else if (tok == BOOK && t.tok == BOOK)
        bval = t.bval;
    else
        copyUnion(t);
    
    tok = t.tok;
    return *this;
}

Token &Token::operator=(Token &&t)
{
    cout << "operator=(Token &&t)" << endl;

    if (tok == STR && t.tok != STR)
        sval.~string();

    if (tok == BOOK && t.tok != BOOK)
        bval.~Sales_data();

    if (tok == STR && t.tok == STR)
        sval = std::move(t.sval);
    else if (tok == BOOK && t.tok == BOOK)
        bval = std::move(t.bval);
    else
        copyUnion(t);
    
    tok = t.tok;
    return *this;
}

void Token::print()
{
    cout << "tok: " << tok << ", val: ";

    switch(tok)
    {
        case INT:
            cout << ival << endl;
            break;
        case CHAR:
            cout << cval << endl;
            break;
        case DBL:
            cout << dval << endl;
            break;
        case STR:
            cout << sval << endl;
            break;
        case BOOK:
            cout << bval;
            break;
    }
}
