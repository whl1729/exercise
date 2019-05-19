#include "MyQueryCommand.h"

using std::stringstream;

bool QueryCommand::get_cmd(istringstream &iss, char &op, string &word)
{
    iss >> op >> word;
    return iss ? true : false;
}
