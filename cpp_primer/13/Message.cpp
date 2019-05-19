#include <iostream>
#include "Message.h"
#include "Folder.h"

using std::cout;
using std::endl;

Message::Message(Message &&m): contents(std::move(m.contents))
{
    move_Folders(&m);
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message& Message::operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

void Message::print()
{
    cout << "message \"" << contents << "\" appears in these directories:" << endl;
    for (auto f : folders)
        cout << f->name << " ";
    cout << endl;
}

void Message::addFldr(Folder *f)  
{ 
    folders.insert(f); 
}

void Message::remFldr(Folder *f)  
{ 
    folders.erase(f); 
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;  // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) respective Folders
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);

    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    
    // add pointers to each Message to their (new) respective Folders
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}
