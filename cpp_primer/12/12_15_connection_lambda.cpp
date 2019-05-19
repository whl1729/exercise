#include <iostream>
#include <memory>

using namespace std;
using uint = unsigned int;

typedef struct dest
{
    uint ip;
    uint port;
} destination;

typedef struct connect
{
    uint *pid;
    uint ip;
    uint port;
} connection;

connection connect(shared_ptr<destination> dest)
{
    cout << "Connect to peer with ip("
         << ((dest->ip & 0xff000000) >> 24) << "."
         << ((dest->ip & 0x00ff0000) >> 16) << "."
         << ((dest->ip & 0x0000ff00) >> 8) << "."
         << (dest->ip & 0x000000ff)
         << ") and port(" << dest->port << ")" << endl;

    connection conn = {0, dest->ip, dest->port};
    conn.pid = new uint(10086);

    return conn;
}

void disconnect(connection conn)
{
    cout << "Disconnect to peer with pid(" << conn.pid << "), ip("
         << ((conn.ip & 0xff000000) >> 24) << "."
         << ((conn.ip & 0x00ff0000) >> 16) << "."
         << ((conn.ip & 0x0000ff00) >> 8) << "."
         << (conn.ip & 0x000000ff) << ") and port("
         << conn.port << ")" << endl;

    free(conn.pid);
}

void do_connect(destination &d)
{
    connection c = connect(make_shared<destination>(d));
    shared_ptr<connection> p(&c, [](connection *c) { disconnect(*c); });
}

int main()
{
    destination dest = {0xC0A80001, 8080};
    do_connect(dest);

    return 0;
}
