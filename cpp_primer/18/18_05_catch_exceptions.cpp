#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {
        int num;
        cout << "Enter a number among 0 to 11: " << endl;
        cin >> num;

        switch(num)
        {
            case 0:
                throw exception();
                break;
            case 1:
                throw bad_cast();
                break;
            case 2:
                throw bad_alloc();
                break;
            case 3:
                throw runtime_error("3: runtime_error occurs");
                break;
            case 4:
                throw logic_error("4: logic_error occurs");
                break;
            case 5:
                throw overflow_error("5: overflow_error occurs");
                break;
            case 6:
                throw underflow_error("6: underflow_error occurs");
                break;
            case 7:
                throw range_error("7: range_error occurs");
                break;
            case 8:
                throw domain_error("8: domain_error occurs");
                break;
            case 9:
                throw invalid_argument("9: invalid_argument occurs");
                break;
            case 10:
                throw out_of_range("10: out_of_range occurs");
                break;
            case 11:
                throw length_error("11: length_error occurs");
                break;
            default:
                break;
        }
    }
    catch (overflow_error expt)
    {
        cout << expt.what();
    }
    catch (underflow_error expt)
    {
        cout << expt.what();
    }
    catch (range_error expt)
    {
        cout << expt.what();
    }
    catch (runtime_error expt)
    {
        cout << expt.what();
    }
    catch (domain_error expt)
    {
        cout << expt.what();
    }
    catch (invalid_argument expt)
    {
        cout << expt.what();
    }
    catch (out_of_range expt)
    {
        cout << expt.what();
    }
    catch (length_error expt)
    {
        cout << expt.what();
    }
    catch (logic_error expt)
    {
        cout << expt.what();
    }
    catch (bad_cast expt)
    {
        cout << expt.what();
    }
    catch (bad_alloc expt)
    {
        cout << expt.what();
    }
    catch (exception expt)
    {
        cout << expt.what();
    }

    cout << endl;

    return 0;
}
