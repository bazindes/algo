/*
    StructUnionEnum.c
    Created by: baz
    Date: 2019-03-03 14:34
*/

struct{
    int number;
    char name[100];
    int on_hand;
} part1, part2;

struct Part
{
    int number;
    char name[100];
    int on_hand;
};

typedef struct 
{
    int number;
    char name[100];
    int on_hand;
} Part_;

union 
{
    int i;
    float f;
} u1, u2;

union Num 
{
    int i;
    float f;
};

typedef union 
{
    int i;
    float f;
} Num_;

enum {
    A, B, C, D
};

enum En{
    AE, BE, CE, DE
};

typedef enum{
    AD, BD, CD, DD
} En_;

