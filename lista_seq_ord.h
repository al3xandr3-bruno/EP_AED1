#define FALSE 0
#define TRUE 1

typedef int Boolean;
typedef int Elemento;
//typedef char * palavra;

typedef struct {

	Elemento * a;
	int livre;
	int capacidade;

} ListaSequencialInt;

typedef struct {
	char *a;
	int n_ocorrencias;
	ListaSequencialInt *linhas;
	
} PalavraTexto;

typedef struct {

	PalavraTexto *palavras;
	int livre;
	int capacidade;

} ListaSequencialStr;

ListaSequencialStr * cria_lista(int n);
void destroi_lista(ListaSequencialStr * lista);
int tamanho(ListaSequencialStr * lista);
void imprime(ListaSequencialStr * lista);
int busca(ListaSequencialStr * lista, char * e);
Boolean insere(ListaSequencialStr * lista, char * e, int linha);
Boolean remove_elemento(ListaSequencialStr * lista, char * e); //creio que não vou usar isso, provavelmente vou tirar

ListaSequencialInt * cria_listaInt(int n);
void destroi_listaInt(ListaSequencialInt * lista);
int tamanhoInt(ListaSequencialInt * lista);
void imprimeInt(ListaSequencialInt * lista);
int buscaInt(ListaSequencialInt * lista, Elemento e);
Boolean insereInt(ListaSequencialInt * lista, Elemento e);
Boolean remove_elementoInt(ListaSequencialInt * lista, Elemento e);