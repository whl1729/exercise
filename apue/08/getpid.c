#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid, ppid;
    uid_t uid, euid;
    gid_t gid, egid;

    pid = getpid();
    ppid = getppid();
    uid = getuid();
    euid = geteuid();
    gid = getgid();
    egid = getegid();

    printf("pid = %d, ppid = %d, uid = %d, euid = %d, gid = %d, egid = %d\n",
            pid, ppid, uid, euid, gid, egid);

    return 0;
}
