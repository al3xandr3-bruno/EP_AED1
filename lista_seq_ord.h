#define FALSE 0
#define TRUE 1

typedef int Boolean;
//typedef char * palavra;

typedef struct {
	char *a;
	int *n_ocorrencias;
	int *linhas_ocoreencias;
} PalavraTexto;

typedef struct {

	//char **a;
	PalavraTexto *palavras;
	int livre;
	int capacidade;

} ListaSequencial;

ListaSequencial * cria_lista(int n);
void destroi_lista(ListaSequencial * lista);
int tamanho(ListaSequencial * lista);
void imprime(ListaSequencial * lista);
int busca(ListaSequencial * lista, char * e);
Boolean insere(ListaSequencial * lista, char * e);
Boolean remove_elemento(ListaSequencial * lista, char * e);