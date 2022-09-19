#include <cstdio>
#include <cstring>

typedef struct {
    unsigned int bv; // 0 = partição vazia
    char processo[5];
} particao; particao RAM[10];

int main() {
    int i;
    for (i=0;i<10;i++) {
        RAM[i].bv=0;
    }

    for (i=0;i<10;i++) {
        if(RAM[i].bv == 0) {
            printf("Digite um processo: ");
            RAM[i].bv = 1;
            scanf("%s",&RAM[i].processo);
        }
    }

    strcpy(RAM[2].processo,"");RAM[2].bv=0; printf("\n3o processo finalizado\n");
    strcpy(RAM[8].processo," ");RAM[8].bv=0; printf("9o processo finalizado\n");

    printf("\nStatus da RAM\n");
    for(i=0;i<10;i++) {
        printf("%da Particao da RAM: [%d|%s]\n",i+1,RAM[i].bv,RAM[i].processo);
    }

    for (i=0;i<10;i++) {
        if (RAM[i].bv == 0) {
            printf("\n");
            printf("Digite um processo: ");
            RAM[i].bv=1;
            scanf("%s",&RAM[i].processo);
        }
    }

    printf("\nStatus da RAM\n");
    for(i=0;i<10;i++) {
        printf("%da Particao da RAM: [%d|%s]\n",i+1,RAM[i].bv,RAM[i].processo);
    }
    return(0);
}
