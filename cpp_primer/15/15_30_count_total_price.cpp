#include "Quote.h"
#include "Bulk_quote.h"
#include "Basket.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main()
{
    Quote q1("Old man and sea", 50);
    Bulk_quote bq1("Harry Potter", 100, 5, 0.1);
    Bulk_quote bq2("Walden", 100, 5, 0.2);
    Bulk_quote bq3("Bible", 100, 5, 0.3);

    Basket bk;

    for (int pos = 0; pos < 10; pos++)
        bk.add_item(q1);
    for (int pos = 0; pos < 20; pos++)
        bk.add_item(bq1);
    for (int pos = 0; pos < 30; pos++)
        bk.add_item(bq2);
    for (int pos = 0; pos < 40; pos++)
        bk.add_item(bq3);

    bk.total_receipt(cout);

    return 0;
}
