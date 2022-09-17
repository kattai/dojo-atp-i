#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    char color_u[255];
    char color_l[255];
    int code;
}ITEM;

ITEM tabela[12] = {
    {"Preto", "preto", 0},
    {"Marrom", "marrom", 1},
    {"Vermelho", "vermelho", 2},
    {"Laranja", "laranja", 3},
    {"Amarelo", "amarelo", 4},
    {"Verde", "verde", 5},
    {"Azul", "azul", 6},
    {"Violeta", "violeta", 7},
    {"Cinza", "cinza", 8},
    {"Branco", "branco", 9},
    {"Dourado", "dourado", -1},
};

int converte_tabela(char *cor){
    int i;
    bool find = false;

    for(i = 0; i <= 13; i++){
        if(strcmp(cor, tabela[i].color_u) == 0 || strcmp(cor, tabela[i].color_l) == 0){
            return tabela[i].code;
        }
    }
    return -2;
}

int main(){
    float res;
    bool find = false;
    char fica, cor1[100], cor2[100], cor3[100];
    int n1, n2, n3, i;
    int combos[13][2] = {
        {1, 0},
        {1, 2},
        {1, 5},
        {1, 8},
        {2, 2},
        {2, 7},
        {3, 3},
        {3, 9},
        {4, 7},
        {5, 6},
        {6, 8},
        {8, 2},
        {9, 1},
    };

    do{
        printf("Digite uma cor: ");
        scanf("%s", &cor1[0]);
        n1 = converte_tabela(cor1);

        printf("Digite a segunda cor: ");
        scanf("%s", &cor2[0]);
        n2 = converte_tabela(cor2);

        for(i = 0; i < 13; i++){
            if(n1 == combos[i][0] && n2 == combos[i][1]){
                find = true;
            }
        }

        if(!find){
            printf("Essa combinação não existe!\n");
            continue;
        }

        res = n1*10 + n2;
        printf("A soma das cores é %f\n", res);

        printf("Digite a terceira cor: ");
        scanf("%s", &cor3[0]);
        n3 = converte_tabela(cor3);

        if(n3 == -1){
            res = res/10;
        }else{
            for(i=0; i<n3; i++){
                res = res*10;
            }
        }

        if(res >= 1000000.0){
            printf("Resultado: %.1f%c\n", res / 1000000.0, 'M');
        }else if(res >= 1000.0){
            printf("Resultado: %.1f%c\n", res / 1000.0, 'K');
        }else{
            printf("%.1f\n", res);
        }

        printf("Quer continuar? (S/N)\n");
        scanf(" %c", &fica);
    }while(fica == 'S' || fica == 's');

    return 0;
}