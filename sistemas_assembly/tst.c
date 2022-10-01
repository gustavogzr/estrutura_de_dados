#include <stdio.h>

int sum(int x, int y);

int main() {
    printf("%d\n", sum(3,7));
    return 0;
}

__asm__(
    "sum:\n"
    "   movl %edi, %eax\n"
    "   addl %esi, %eax\n"
    "   ret"
);