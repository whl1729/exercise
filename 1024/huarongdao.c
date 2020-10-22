#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 20
#define LINE_SIZE 10000

typedef struct map {
    int board[BOARD_SIZE][BOARD_SIZE];
    int fixed;
    int size;
    int stage;
} Map;

int read_map(Map *map);
void play_huarongdao(Map *map);
int read_element(char *line, const char *name, FILE *fp);
int read_number(char *line, char **endptr);

int main() {
    Map map;
    int result;

    while ((result = read_map(&map)) == 0) {
        play_huarongdao(&map);
    }

    return 0;
}

void play_huarongdao(Map *map) {
    int i, j;
    printf("map: fixed = %d, size = %d, stage = %d\n", map->fixed, map->size, map->stage);
    for (i = 0; i < map->size; i++) {
        for (j = 0; j < map->size; j++) {
            printf("%d ", map->board[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int read_map(Map *map) {
    int *board;
    int reached = 0;
    char *line;
    char *tmp;
    static FILE *fp = NULL;
    char path[] = "/home/along/src/exercise/1024/levels.json";
    int pos = 0;
    int i, j, elem;

    if ((board = malloc(sizeof(int) * BOARD_SIZE * BOARD_SIZE)) == NULL) {
        printf("malloc error!\n");
        return -1;
    }

    if ((line = malloc(LINE_SIZE)) == NULL) {
        printf("malloc error!\n");
        return -1;
    }

    if (fp == NULL) {
        if ((fp = fopen(path, "r")) == NULL) {
            printf("fopen %s error!\n", path);
            free(board);
            free(line);
            return -1;
        }
    }

    // read board
    while (fgets(line, LINE_SIZE-2, fp) != NULL) {
        if (strstr(line, "fixed") != NULL) {
            break;
        }

        if (!reached && (strstr(line, "board") == NULL)) {
            continue;
        }

        reached = 1;
        tmp = line;
        while ((elem = read_number(tmp, &tmp)) >= 0) {
            board[pos++] = elem;
        }
    }

    if (strstr(line, "fixed") == NULL) {
        free(board);
        free(line);
        return -1;
    }

    // read fixed
    if ((map->fixed = read_element(line, "fixed", NULL)) < 0) {
        printf("read fixed failed!\n");
        free(board);
        free(line);
        return -1;
    }

    printf("fixed: %d\n", map->fixed);

    // read size
    if ((map->size = read_element(line, "size", fp)) < 0) {
        printf("read size failed!\n");
        free(board);
        free(line);
        return -1;
    }

    printf("size: %d\n", map->size);

    // read stage
    if ((map->stage = read_element(line, "stage", fp)) < 0) {
        printf("read stage failed!\n");
        free(board);
        free(line);
        return -1;
    }

    printf("stage: %d\n", map->stage);

    // set map.board
    pos = 0;
    for (i = 0; i < map->size; i++) {
        for (j = 0; j < map->size; j++) {
            map->board[i][j] = board[pos];
            pos++;
        }
    }

    free(board);
    free(line);

    return 0;
}

int read_element(char *line, const char *name, FILE *fp) {
    int elem;

    if (fp != NULL) {
        if (fgets(line, LINE_SIZE-2, fp) == NULL) {
            printf("unexpected end of file when read %s!\n", name);
            return -1;
        }
    }

    if (strstr(line, name) == NULL) {
        printf("not found %s!\n", name);
        return -1;
    }

    if ((elem = read_number(line, NULL)) < 0) {
        printf("read_number error!\n");
        return -1;
    }

    return elem;
}

int read_number(char *line, char **endptr) {
    int num;

    for (; line && *line && (!isdigit(*line)); line++);

    num = (int)strtol(line, endptr, 10);

    if (endptr && *endptr == line) {
        return -1;
    }

    return num;
}
