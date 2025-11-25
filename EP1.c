#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int teste (){
    FILE *texto;
    char c;

    texto = fopen("texto.txt", "r");

    if(texto == NULL) {
        printf("ERRO!Não foi possível abrir o arquivo.\n");
        exit(1);
    }
    printf("Lendo e exibindo conteúdo do arquivo!\nAguarde...\n");

    do{
        /*
        Acho que vou precisar chegar char a char pra tirar as 
        pontuações que eu não quero, mas acho que é isso,
        basta organizar as palavra em alguma estrutura.

        Preciso também descobrir como comparar strings
        (ou cadeias de chars), será que o C faz isso 
        como faz com números? funciona!
        */
        c = fgetc(texto);
        if(c == ' ' || c == '\n' || c == '-' || c == ',' || 
            c == '.'|| c == ';' || 
            c == ':' || c == ':') printf("\n");
        
        else printf("%c", c);
    }while (c != EOF);

    printf("______________________________\n");

    printf("Olá Mundo!\n");
    int a = 0;
    printf("Agora foi\n %d", a);
    return 0;    
}

int main(){
    
    char ch [20] = "babb";
    char ch1 [20]  = "bab";

    if (strcmp(ch, ch1)>0) printf("ch é maior que ch1");
    else if (strcmp(ch, ch1)<0)printf("ch1 é maior que ch");
    else printf("Foi porra nenhuma nessa joça kkkkk");

    printf("\n");
}