int resultado = 0, resultado2 = 0, x=3, y=5;

__asm__(
    "movl %1, %%eax;"
    "movl %2, %%ebx;"
    "addl %%ebx, %%eax;"
    : "=r" (resultado)
    : "a" (x), "b" (y));