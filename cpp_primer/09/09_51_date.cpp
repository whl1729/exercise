#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Date
{
public:
    Date() = default;
    Date(const string &date);
    void print_date() const;

private:
    int year;
    int month;
    int day;
};

const string months[24] =
{
    "January", "Jan",
    "February", "Feb",
    "March", "Mar",
    "April", "Apr",
    "May", "May",
    "June", "June",
    "July", "July",
    "August", "Aug",
    "September", "Sept",
    "October", "Oct",
    "November", "Nov",
    "December", "Dec",
};


/**
 * The format of date should be one of the following:
 * January 1, 1900
 * 1/1/1900
 * Jan 1, 1900
 */
Date::Date(const string &date)
{
    const string digit{"0123456789"};
    string::size_type dpos, spos;

    dpos = date.find_first_of(digit);
    spos = date.find_first_not_of(digit);

    if (dpos)
    {
        for (int pos = 0; pos < 12; ++pos)
        {
            if (date.find(months[2*pos]) != string::npos ||
                date.find(months[2*pos+1]) != string::npos)
            {
                month = pos + 1;
                break;
            }
        }

        spos = date.find_first_not_of(digit, dpos);
        day = stoi(date.substr(dpos, spos - dpos));

        dpos = date.find_first_of(digit, spos);
        year = stoi(date.substr(dpos));
    }
    else
    {
        day = stoi(date.substr(dpos, spos - dpos));

        dpos = date.find_first_of(digit, spos);
        spos = date.find_first_not_of(digit, dpos);
        month = stoi(date.substr(dpos, spos - dpos));

        dpos = date.find_first_of(digit, spos);
        year = stoi(date.substr(dpos));
    }
}

void Date::print_date() const
{
    cout << year << '/' << month << '/' << day << endl;
}

int main()
{
    string date;

    cout << "Enter date: " << endl;

    while (getline(cin, date))
    {
        Date someday(date);
        someday.print_date();
    }

    cout << endl;
}
