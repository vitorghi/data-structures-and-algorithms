#include <stdio.h>
#include "binaria.h"

int main() {
    p_no no1    = inserir(NULL, 1);
    p_no anterior = no1;

    for (int i = 2; i < 1000000; i++){
        p_no novo_no    = inserir(anterior, i);
        anterior = novo_no;
    }


//    printf("pre-order\n");
//    imprime_pre_ordem(anterior);
//    printf("\n");

    return 0;
}