#include <iostream>
#include "Message.h"
#include "Folder.h"

using std::cout;
using std::endl;

Folder::Folder(const Folder& f): name(f.name), msgs(f.msgs)
{
    add_to_message(f);
}

Folder::~Folder()
{
    remove_from_message();
}

Folder& Folder::operator=(const Folder& f)
{
    remove_from_message();
    name = f.name;
    msgs = f.msgs;
    add_to_message(f);
}

void Folder::addMsg(Message* m)
{
    msgs.insert(m);
}

void Folder::remMsg(Message* m)
{
    msgs.erase(m);
}

void Folder::add_to_message(const Folder &f)
{
    for (auto &m : f.msgs)
        m->save(*this);
}

void Folder::remove_from_message()
{
    for (auto &m : msgs)
        m->remove(*this);
}

void Folder::print()
{
    cout << "Folder \"" << name << "\" contains these messages: " << endl;
    for (auto m : msgs)
        cout << m->contents << endl;
}
