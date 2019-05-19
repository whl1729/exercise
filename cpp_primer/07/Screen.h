#ifndef __SCREEN_H__
#define __SCREEN_H__

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd),
                            contents(ht * wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), 
                                    contents(ht * wd, c) { }
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    Screen &set(char c);
    Screen &set(pos r, pos col, char ch);
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
    void do_display(std::ostream &os) const { os << contents[cursor]; }
};

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    pos idx = r * width + col;
    contents[idx] = ch;
    return *this;
}

inline Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

#endif
