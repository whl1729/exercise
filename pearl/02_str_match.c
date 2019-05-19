#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STR_LEN 10000
#define PATTERN_LEN  5
#define TEST_TIME 1000
#define BC_LEN  256

void set_str(char *str, int len);
void set_next(char *pattern, int len, int *next);
void set_bc(char *pattern, int len, int *bc);
int str_match_brute(char *str, char *pattern);
int str_match_kmp(char *str, char *pattern);
int str_match_bm(char *str, char *pattern);

int main()
{
    char str[STR_LEN + 1] = {0};
    char pattern[PATTERN_LEN + 1] = {0};
    int pos_brute, pos_kmp, pos_bm;
    int test;

    srand((unsigned)time(0));

    for (test = 0; test < TEST_TIME; test++)
    {
        set_str(str, STR_LEN);
        set_str(pattern, PATTERN_LEN);

        printf("%s\n", str);
        printf("%s\n", pattern);

        pos_brute = str_match_brute(str, pattern);
        pos_kmp = str_match_kmp(str, pattern);
        pos_bm = str_match_bm(str, pattern);

        printf("pos_brute=%d, pos_kmp=%d, pos_bm=%d\n", pos_brute, pos_kmp, pos_bm);

        if (pos_brute != pos_kmp || pos_kmp != pos_bm)
            printf("error!!\n");
    }

    return 0;
}

int str_match_brute(char *str, char *pattern)
{
    int pos;
    int idx;

    for (pos = 0; pos < STR_LEN - PATTERN_LEN; pos++)
    {
        for (idx = 0; (idx < PATTERN_LEN) && (str[pos + idx] == pattern[idx]); idx++);

        if (idx == PATTERN_LEN)
            return pos;
    }

    return -1;
}

int str_match_kmp(char *str, char *pattern)
{
    int pos = -1;
    int idx = -1;
    int next[PATTERN_LEN+1] = {0};

    set_next(pattern, PATTERN_LEN, next);

    while (pos < STR_LEN - PATTERN_LEN)
    {
        if (idx < 0 || str[pos] == pattern[idx])
        {
            pos++;
            idx++;

            if (idx == PATTERN_LEN)
                return (pos - PATTERN_LEN);
        }
        else
        {
            idx = next[idx];
        }
    }

    return -1;
}

void set_next(char *pattern, int len, int *next)
{
    int pos = 0;
    int idx = -1;

    next[0] = -1;

    while (pos < len)
    {
        if (idx < 0 || pattern[pos] == pattern[idx])
        {
            pos++;
            idx++;
            next[pos] = idx;
        }
        else
        {
            idx = next[idx];
        }
    }
}

int str_match_bm(char *str, char *pattern)
{
    int pos = 0;
    int idx = PATTERN_LEN - 1;
    int bc[BC_LEN];

    set_bc(pattern, BC_LEN, bc);

    while (pos < STR_LEN - PATTERN_LEN)
    {
        idx = PATTERN_LEN - 1;

        for (; idx >= 0 && str[pos + idx] == pattern[idx]; idx--);

        if (idx < 0)
            return pos;
        else
        {
            if (idx > bc[str[pos + idx]])
                pos += (idx - bc[str[pos + idx]]);
            else
                pos++;
        }
    }

    return -1;
}

void set_bc(char *pattern, int len, int *bc)
{
    int pos;
    for (pos = 0; pos < len; pos++)
        bc[pos] = -1;

    for (pos = 0; pos < PATTERN_LEN; pos++)
    {
        bc[pattern[pos]] = pos;
    }
}

void set_str(char *str, int len)
{
    int pos;

    for (pos = 0; pos < len; pos++)
        str[pos] = 'a' + (rand() % 5);
}
