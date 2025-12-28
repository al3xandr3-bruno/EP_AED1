#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_seq_ord.h"

/*----------------------------LISTA DE STRINGS---------------------------------*/
ListaSequencialStr * cria_lista(int capacidade){

	ListaSequencialStr * lista =  (ListaSequencialStr *) malloc (sizeof(ListaSequencialStr));
	lista->palavras = (PalavraTexto *) malloc(capacidade * sizeof(PalavraTexto*));
	lista->capacidade = capacidade;
	lista->livre = 0;

	return lista;
}

void destroi_lista(ListaSequencialStr * lista){

	free(lista->palavras);
	free(lista);
}

int tamanho(ListaSequencialStr * lista){

	return lista->livre;
}

void imprime(ListaSequencialStr * lista){

	int i;

	printf("Lista:");

	for(i = 0; i < lista->livre; i++){

		printf("[%d]: %s\n", i, lista->palavras[i].a);
		printf("%d ocorrencias, nas linhas:\n", lista->palavras[i].n_ocorrencias);
		imprimeInt(lista->palavras[i].linhas);

	}

	printf("\n");
}

int busca(ListaSequencialStr * lista, char *e){

	// busca binária! ;)

	int ini = 0;
	int fim = lista->livre - 1;
	int meio;

	while(ini <= fim){

		meio = (ini + fim) / 2;

		if(strcmp(e, lista->palavras[meio].a)==0) return meio;
		if(strcmp(e, lista->palavras[meio].a)<0) fim = meio - 1;
		if(strcmp(e, lista->palavras[meio].a)>0) ini = meio + 1;
	}
		
	return -1;
}

Boolean insere(ListaSequencialStr * lista, char * e, int linha){

	int i;

	int indice_encontrado = busca(lista, e);

	Boolean ja_inserido = indice_encontrado >= 0;

	if (ja_inserido) {
		lista->palavras[indice_encontrado].n_ocorrencias++;
		insereInt(lista->palavras[indice_encontrado].linhas, linha);
		return TRUE;
	}
	

	else if(lista->livre < lista->capacidade) {

		for(i = lista->livre; i > 0 && strcmp(lista->palavras[i - 1].a, e)>0 ; i--){
			lista->palavras[i] = lista->palavras[i - 1];
		}

		lista->palavras[i].a = e;
		lista->palavras[i].n_ocorrencias = 1;
		lista->palavras[i].linhas = cria_listaInt(lista->capacidade);
		insereInt(lista->palavras[i].linhas, linha);
		lista->livre++;

		return TRUE;
	}

	return FALSE;
}

Boolean remove_elemento(ListaSequencialStr * lista, char * e){

	int i;
	int indice = busca(lista, e);

	if(indice >= 0) {

		lista->livre--;

		for(i = indice; i < lista->livre; i++){

			lista->palavras[i].a = lista->palavras[i + 1].a;
		}

		return TRUE;
	}

	return FALSE;
}


/*-----------------------------LISTA DE INTEIROS------------------------------*/
ListaSequencialInt * cria_listaInt(int capacidade){

	ListaSequencialInt * lista =  (ListaSequencialInt *) malloc (sizeof(ListaSequencialInt));
	lista->a = (Elemento *) malloc (capacidade * sizeof(Elemento));
	lista->capacidade = capacidade;
	lista->livre = 0;

	return lista;
}

void destroi_listaInt(ListaSequencialInt * lista){

	free(lista->a);
	free(lista);
}

int tamanhoInt(ListaSequencialInt * lista){

	return lista->livre;
}

void imprimeInt(ListaSequencialInt * lista){

	int i;

	for(i = 0; i < lista->livre; i++){

		printf(" %d", lista->a[i]);
	}

	printf("\n");
}

int buscaInt(ListaSequencialInt * lista, Elemento e){

	// busca binária! ;)

	int ini = 0;
	int fim = lista->livre - 1;
	int meio;

	while(ini <= fim){

		meio = (ini + fim) / 2;

		if(e == lista->a[meio] ) return meio;
		if(e < lista->a[meio]) fim = meio - 1;
		if(e > lista->a[meio]) ini = meio + 1;
	}
		
	return -1;
}

Boolean insereInt(ListaSequencialInt * lista, Elemento e){

	int i;

	int indice_encontrado = buscaInt(lista, e);

	Boolean ja_inserido = indice_encontrado >= 0; 

	if(!ja_inserido && lista->livre < lista->capacidade) {

		for(i = lista->livre; i > 0 && lista->a[i - 1] > e ; i--){

			lista->a[i] = lista->a[i - 1];
		}

		lista->a[i] = e;
		lista->livre++;

		return TRUE;
	}

	return FALSE;
}

Boolean remove_elementoInt(ListaSequencialInt * lista, Elemento e){

	int i;
	int indice = buscaInt(lista, e);

	if(indice >= 0) {

		lista->livre--;

		for(i = indice; i < lista->livre; i++){

			lista->a[i] = lista->a[i + 1];
		}

		return TRUE;
	}

	return FALSE;
}
