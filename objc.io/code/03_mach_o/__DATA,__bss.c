#include <stdio.h>
// a is stored in __DATA,__bss section
static int a;

int main(int argc, char *argv[])
{
    a = 1;
    printf("a = %d\n", a);
}