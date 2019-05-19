#ifndef __QUERYCOMMAND_H__
#define __QUERYCOMMAND_H__

#include <string>
#include <sstream>

using std::string;
using std::istringstream;

class QueryCommand
{
public:
    QueryCommand(string s): cmd(s) { }
    bool get_cmd(istringstream &iss, char &op, string &word);
private:
    string cmd;
};

#endif
