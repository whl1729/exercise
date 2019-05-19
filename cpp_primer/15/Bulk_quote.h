#ifndef __BULK_QUOTE_H__
#define __BULK_QUOTE_H__

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double disc):
        Quote(book, p), min_qty(qty), discount(disc) { }
    double net_price(size_t n) const override;
    void debug() const override;
    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif
