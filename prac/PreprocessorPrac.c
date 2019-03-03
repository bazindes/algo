#include <stdio.h>

#define ABC "Elon"

#define CHOOSE(x, y) ("Thx, "#x" and "#y)

#define GENERIC_MAX(type) \
type type##_max(type x, type y) \
{ \
    return x > y ? x: y; \
};

GENERIC_MAX(int)
GENERIC_MAX(double)

void getMax(){
    printf("%d is greater\n" , int_max(3, 6));
    printf("%f is greater\n" , double_max(3.6, 3.61));
}

int main(){
    printf("%s\n" , ABC);
    printf("%s\n" , CHOOSE("asdf" , 4));
    getMax();
    return 0;
}

