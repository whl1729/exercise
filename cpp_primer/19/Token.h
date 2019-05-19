#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include "Sales_data.h"

using std::string;

class Token
{
public:
    Token() : tok(INT), ival(0) {}
    Token(const Token &t): tok(t.tok) { copyUnion(t); }
    Token(Token &&t);
    Token &operator=(const Token &t);
    Token &operator=(Token &&t);
    ~Token(); 

    Token &operator=(const std::string &s);
    Token &operator=(const Sales_data &b);
    Token &operator=(char c);
    Token &operator=(int i);
    Token &operator=(double d);

    void print();
private:
    enum {INT, CHAR, DBL, STR, BOOK} tok;
    union
    {
        char cval;
        int ival;
        double dval;
        std::string sval;
        Sales_data bval;
    };
    void copyUnion(const Token &t);
};

#endif
