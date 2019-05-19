#include "Quote.h"
#include "Bulk_quote.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Quote> items;
    Bulk_quote bq1("Harry Potter", 100, 5, 0.1);
    Bulk_quote bq2("Walden", 100, 5, 0.2);
    Bulk_quote bq3("Bible", 100, 5, 0.3);

    items.push_back(bq1);
    items.push_back(bq2);
    items.push_back(bq3);

    double total_price = 0.0;

    for (auto &i : items)
        total_price += i.net_price(10);

    cout << total_price << endl;

    return 0;
}
