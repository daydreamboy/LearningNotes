#include <stdio.h>
// a,b,c is stored in __DATA,__common section
int a;
char b;
char c;

int main(int argc, char *argv[])
{
    a = 1;
    printf("a = %d\n", a);
}