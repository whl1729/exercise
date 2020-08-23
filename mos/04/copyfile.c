#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define OUTPUT_MODE 0700
#define TRUE 1

int main(int argc, char *argv[])
{
    int in_fd, out_fd, rd_count, wt_count;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        printf("Usage: copyfile src dest\n");
        exit(1);
    }

    in_fd = open(argv[1], O_RDONLY);
    if (in_fd < 0) {
        printf("open error! in_fd=%d\n", in_fd);
        exit(2);
    }

    printf("in_fd=%d\n", in_fd);

    out_fd = creat(argv[2], OUTPUT_MODE);
    if (out_fd < 0) {
        printf("creat error! out_fd=%d\n", out_fd);
        exit(3);
    }

    printf("out_fd=%d\n", out_fd);

    while (TRUE) {
        rd_count = read(in_fd, buffer, BUF_SIZE);
        if (rd_count <= 0) {
            printf("read end. rd_count=%d\n", rd_count);
            break;
        }

        wt_count = write(out_fd, buffer, rd_count);
        if (wt_count <= 0) {
            printf("write error! wt_count=%d\n", wt_count);
            exit(4);
        }
    }

    close(in_fd);
    close(out_fd);
    if (rd_count == 0) {
        exit(0);
    } else {
        exit(5);
    }
}
