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

typedef struct point {
    int x;
    int y;
} Point;

int read_map(Map *map);
void play_huarongdao(Map *map);
int read_element(char *line, const char *name, FILE *fp);
int read_number(char *line, char **endptr);
void get_position(Map *map, int val, Point *p);

void play_one_turn(Map *map, int turn, Point fixed);
void play_before_fixed(Map *map, int turn, Point fixed);
void play_in_fixed(Map *map, int turn, Point fixed);
void play_after_fixed(Map *map, int turn, Point fixed);

void move_one_slide_in_row(Map *map, Point target);
void move_one_slide_in_col(Map *map, Point target);
void move_two_slides_in_row(Map *map, Point target);
void move_two_slides_in_col(Map *map, Point target);
void move_one_step_in_row(Map *map, Point target, Point *cur);
void move_empty_slide(Map *map, Point target);
void move_target_from_down(Map *map, Point target, Point cur);
void move_target_from_left(Map *map, Point target, Point cur);
void move_target_from_right(Map *map, Point target, Point cur);

void move_left(Map *map, Point empty);
void move_right(Map *map, Point empty);
void move_up(Map *map, Point empty);
void move_down(Map *map, Point empty);

void right_rotate(Map *map, Point empty);

int equals(Point a, Point b);
int min(int x, int y);

int main() {
    Map map;
    int result;

    while ((result = read_map(&map)) == 0) {
        if (map.stage == 6) {
            play_huarongdao(&map);
        }
    }

    return 0;
}

void play_huarongdao(Map *map) {
    int turn;
    Point fixed;

    get_position(map, map->fixed, &fixed);

    printf("solution:\n");

    for (turn = 0; turn < map->size; turn++) {
        play_one_turn(map, turn, fixed);
    }

    printf("\n");
}

void play_one_turn(Map *map, int turn, Point fixed) {
    if ((turn < fixed.x -1) && (turn < fixed.y -1)) {
        play_before_fixed(map, turn, fixed);
        return;
    }

    if ((turn > fixed.x) && (turn > fixed.y)) {
        play_after_fixed(map, turn, fixed);
        return;
    }

    play_in_fixed(map, turn, fixed);
}

void play_before_fixed(Map *map, int turn, Point fixed) {
    int i;
    Point target;

    target.x = turn;

    for (i = turn; i < map->size - 2; i++) {
        target.y = i;
        move_one_slide_in_row(map, target);
    }

    target.y = map->size - 2;
    move_two_slides_in_row(map, target);

    target.y = turn;

    for (i = turn+1; i < map->size - 2; i++) {
        target.x = i;
        printf("move (%d, %d)\n", target.x, target.y);
        move_one_slide_in_col(map, target);
    }

    target.x = map->size - 2;
    move_two_slides_in_col(map, target);
}

void move_one_slide_in_col(Map *map, Point target) {

}

void move_one_slide_in_row(Map *map, Point target) {
    Point cur;
    int elem;

    elem = target.x * map->size + target.y + 1;
    get_position(map, elem, &cur);

    if (equals(cur, target)) {
        return;
    }

    move_empty_slide(map, target);
    get_position(map, elem, &cur);

    if (cur.y == target.y) {
        move_target_from_down(map, target, cur);
    } else if (cur.y < target.y) {
        move_target_from_left(map, target, cur);
    } else {
        move_target_from_right(map, target, cur);
    }
}

void move_target_from_down(Map *map, Point target, Point cur) {
    Point empty;

    move_empty_slide(map, cur);

    empty.x = cur.x;
    empty.y = cur.y;
    cur.x--;

    while (!equals(cur, target)) {
        right_rotate(map, empty);
        cur.x--;
        empty.x--;
    }
}


void right_rotate(Map *map, Point empty) {
    map->board[empty.x][empty.y] = map->board[empty.x][empty.y+1];
    map->board[empty.x][empty.y+1] = map->board[empty.x-1][empty.y+1];
    map->board[empty.x-1][empty.y+1] = map->board[empty.x-2][empty.y+1];
    map->board[empty.x-2][empty.y+1] = map->board[empty.x-2][empty.y];
    map->board[empty.x-2][empty.y] = map->board[empty.x-1][empty.y];
    map->board[empty.x-1][empty.y] = 0;
}

void move_target_from_left(Map *map, Point target, Point cur) {

}

void move_target_from_right(Map *map, Point target, Point cur) {

}

void move_one_step_in_row(Map *map, Point target, Point *cur) {
    int elem;


    elem = target.x * map->size + target.y + 1;
    get_position(map, elem, cur);
}

void move_empty_slide(Map *map, Point target) {
    Point empty;

    get_position(map, 0, &empty);

    while (empty.x < target.x) {
        move_down(map, empty);
        empty.x++;
    }

    while (empty.x > target.x) {
        move_up(map, empty);
        empty.x--;
    }

    while (empty.y < target.y) {
        move_right(map, empty);
        empty.y++;
    }

    while (empty.y > target.y) {
        move_left(map, empty);
        empty.y--;
    }
}

void move_left(Map *map, Point empty) {
    map->board[empty.x][empty.y] = map->board[empty.x][empty.y - 1];
    map->board[empty.x][empty.y - 1] = 0;
    printf("L");
}

void move_right(Map *map, Point empty) {
    map->board[empty.x][empty.y] = map->board[empty.x][empty.y + 1];
    map->board[empty.x][empty.y + 1] = 0;
    printf("R");
}

void move_up(Map *map, Point empty) {
    map->board[empty.x][empty.y] = map->board[empty.x - 1][empty.y];
    map->board[empty.x - 1][empty.y] = 0;
    printf("U");
}

void move_down(Map *map, Point empty) {
    map->board[empty.x][empty.y] = map->board[empty.x + 1][empty.y];
    map->board[empty.x + 1][empty.y] = 0;
    printf("D");
}

void move_two_slides_in_row(Map *map, Point target) {

}

void move_two_slides_in_col(Map *map, Point target) {

}

void play_in_fixed(Map *map, int turn, Point fixed) {

}

void play_after_fixed(Map *map, int turn, Point fixed) {

}

void get_position(Map *map, int val, Point *p) {
    int i, j;
    for (int i = 0; i < map->size; i++) {
        for (int j = 0; j < map->size; j++) {
            if (map->board[i][j] == val) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
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

    // read size
    if ((map->size = read_element(line, "size", fp)) < 0) {
        printf("read size failed!\n");
        free(board);
        free(line);
        return -1;
    }

    // read stage
    if ((map->stage = read_element(line, "stage", fp)) < 0) {
        printf("read stage failed!\n");
        free(board);
        free(line);
        return -1;
    }

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

int min(int x, int y) {
    return (x < y ? x : y);
}

int equals(Point a, Point b) {
    if (a.x == b.x && a.y == b.y) {
        return 1;
    }

    return 0;
}
