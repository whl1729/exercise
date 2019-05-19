#ifndef __FOLDER_H__
#define __FOLDER_H__

#include <string>
#include <set>

class Folder
{
friend class Message;
friend void swap(Message &lhs, Message &rhs);

public:
    Folder(const std::string &str = ""): name(str) { }
    Folder(const Folder& f);
    ~Folder();
    Folder& operator=(const Folder& f);
    void print();
private:
    std::string name;
    std::set<Message*> msgs;
    void addMsg(Message* msg);
    void remMsg(Message* msg);
    void add_to_message(const Folder &f);
    void remove_from_message();
};

#endif
