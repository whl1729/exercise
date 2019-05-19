#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <cstring>
#include <iostream>

using std::istream;
using std::ostream;
using std::endl;
using std::string;
using std::size_t;

inline void print(ostream &os, char ch, int num);
template <unsigned H, unsigned W> class Screen;
template <unsigned H, unsigned W>
    istream& operator>>(istream &is, Screen<H,W> &sc);
template <unsigned H, unsigned W>
    ostream& operator<<(ostream &os, const Screen<H,W> &sc);

template <unsigned H, unsigned W>
class Screen
{
    friend istream& operator>> <>(istream &os, Screen<H,W> &sc); 
    friend ostream& operator<< <>(ostream &os, const Screen<H,W> &sc); 
public:
    Screen(): contents(string(H * W, ' ')) { }
    Screen(const char &ch): contents(string(H * W, ch)) { }
    Screen(const string &msg);
    Screen& move(size_t pos) 
    { 
        if (pos < H * W) 
            cursor = pos; 
        return *this;
    }
    static const size_t Screen<H,W>::*pcursor() { return &Screen<H,W>::cursor; }
    char get() { return contents[cursor]; }

private:
    string contents;
    size_t cursor = 0;
    size_t height = H;
    size_t width = W;
};


template <unsigned H, unsigned W>
Screen<H,W>::Screen(const string &msg)
{
    if (msg.size() >= H*W)
        contents = string(msg.substr(0, H*W));
    else
        contents = msg + string(H*W - msg.size(), ' ');
}

template <unsigned H, unsigned W>
istream& operator>>(istream &is, Screen<H,W> &sc)
{
    string msg;
    getline(is, msg);
    if (msg.size() >= H*W)
        sc.contents = string(msg.substr(0, H*W));
    else
        sc.contents = msg + string(H*W - msg.size(), ' ');
}

template <unsigned H, unsigned W>
ostream& operator<<(ostream &os, const Screen<H,W> &sc)
{
    print(os, '-', W+2);
    for (unsigned i = 0; i < H; ++i)
    {
        os << "|";
        for (unsigned j = 0; j < W; ++j)
        {
            os << sc.contents[i * W + j];
        }
        os << "|" << endl;
    }
    print(os, '-', W+2);
    return os;
}

inline void print(ostream &os, char ch, int num)
{
    while (num--)
        os << ch;
    os << endl;
}

#endif
