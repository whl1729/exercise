#ifndef __QUERY_BASE_H__
#define __QUERY_BASE_H__

#include <string>
#include "QueryResult.h"
#include "TextQuery.h"

using std::string;

class Query_base
{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

#endif
