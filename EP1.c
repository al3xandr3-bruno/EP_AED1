#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO 10000
char *strsep(char **stringp, const char *delim) {
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}

int main(int argc, char ** argv){

	FILE * in;
	char * linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
	int contador_linha;

	if(argc == 2) {

		in = fopen(argv[1], "r");

		printf(">>>>> Carregando arquivo...\n");

		contador_linha = 0;
 		linha = (char *) malloc((TAMANHO + 1) * sizeof(char));

		while(in && fgets(linha, TAMANHO, in)){
			
			if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;

			printf("linha %03d: '%s'\n", contador_linha + 1, linha);

			// fazemos uma copia do endereço que corresponde ao array de chars 
			// usado para armazenar cada linha lida do arquivo pois a função 'strsep' 
			// modifica o endereço do ponteiro a cada chamada feita a esta função (e 
			// não queremos que 'linha' deixe de apontar para o inicio do array).

			copia_ponteiro_linha = linha;

			while( (palavra = strsep(&copia_ponteiro_linha, " ")) ){

				// antes de guardar a palavra em algum tipo de estrutura usada
				// para implementar o índice, será necessário fazer uma copia
				// da mesma, uma vez que o ponteiro 'palavra' aponta para uma 
				// substring dentro da string 'linha', e a cada nova linha lida
				// o conteúdo da linha anterior é sobreescrito.

				printf("\t\t'%s'\n", palavra);
			}

			contador_linha++;
		}

		printf(">>>>> Arquivo carregado!\n");

		return 0;
	}

	return 1;
}

int tist (){
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
        if(c == ' ' || c == '-' || c == ',' || 
            c == '.'|| c == ';' || 
            c == ':' || c == ':') continue;
        
        printf("%c", c);
    }while (c != EOF);


    printf("\n______________________________\n");

    printf("Olá Mundo!\n");
    int a = 0;
    printf("Agora foi\n %d", a);
    return 0;    
}

int teste(){
    
    char ch [20] = "b";
    char ch1 [20]  = "B";

    for (int i = 0; i < 20; i++)
    {
        ch[i] = toupper(ch[i]);
    }

    for (int i = 0; i < 20; i++)
    {
        ch1[i] = tolower(ch1[i]);
    }

    if (strcmp(ch, ch1)>0) printf("ch é maior que ch1");
    else if (strcmp(ch, ch1)<0)printf("ch1 é maior que ch");
    else printf("Foi porra nenhuma nessa joça kkkkk");

    printf("\n");
}