#include "Quote.h"
#include "Disc_quote.h"
#include "15_27_Bulk_quote.h"

int main()
{
    Quote qa;
    Quote qb("Bible", 100);
    Quote qc(qb);
    Quote qd(std::move(qa));
    Quote qe = qd;
    Quote qf = std::move(qe);

    Bulk_quote ba;
    Bulk_quote bb("Bible", 100, 5, 0.2);
    Bulk_quote bc(bb);
    Bulk_quote bd(std::move(ba));
    Bulk_quote be = bd;
    Bulk_quote bf = std::move(be);

    return 0;
}
