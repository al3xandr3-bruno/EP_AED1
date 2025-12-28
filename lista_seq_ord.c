#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_seq_ord.h"

ListaSequencial * cria_lista(int capacidade){

	ListaSequencial * lista =  (ListaSequencial *) malloc (sizeof(ListaSequencial));
	//lista->a = (char **) malloc (capacidade * sizeof(char *));
	lista->palavras = (PalavraTexto *) malloc(capacidade * sizeof(PalavraTexto*));
	lista->capacidade = capacidade;
	lista->livre = 0;

	return lista;
}

void destroi_lista(ListaSequencial * lista){

	free(lista->palavras);
	free(lista);
}

int tamanho(ListaSequencial * lista){

	return lista->livre;
}

void imprime(ListaSequencial * lista){

	int i;

	printf("Lista:");

	for(i = 0; i < lista->livre; i++){

		printf("[%d]: %s ", i, lista->palavras[i].a);
		//printf("[%d]: %s\n", i, lista->palavras[i].linhas_ocoreencias);
		printf("%d ocorrencias\n", lista->palavras[i].n_ocorrencias);
	}

	printf("\n");
}

int busca(ListaSequencial * lista, char *e){

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

Boolean insere(ListaSequencial * lista, char * e, int linha){

	int i;

	int indice_encontrado = busca(lista, e);

	Boolean ja_inserido = indice_encontrado > 0;

	if (ja_inserido) {
		lista->palavras[indice_encontrado].n_ocorrencias++;
		return TRUE;
	}
	

	else if(lista->livre < lista->capacidade) {

		for(i = lista->livre; i > 0 && strcmp(lista->palavras[i - 1].a, e)>0 ; i--){
			lista->palavras[i] = lista->palavras[i - 1];
		}

		lista->palavras[i].a = e;
		lista->palavras[i].n_ocorrencias = 1;
		lista->livre++;

		return TRUE;
	}

	return FALSE;
}

Boolean remove_elemento(ListaSequencial * lista, char * e){

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