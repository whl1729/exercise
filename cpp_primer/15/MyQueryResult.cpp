#include "MyQueryResult.h"

void print(ostream &output, const QueryResult &qr)
{
    cout << qr.sought << " occurs " << qr.lines.size()
         << (qr.lines.size() > 1 ? " times" : " time") << endl;

    for (auto &l: qr.lines)
        cout << "    (lines " << l+1 << ") " << (*qr.file)[l] << endl;
}
