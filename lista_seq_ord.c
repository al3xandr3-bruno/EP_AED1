#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_seq_ord.h"

ListaSequencial * cria_lista(int capacidade){

	ListaSequencial * lista =  (ListaSequencial *) malloc (sizeof(ListaSequencial));
	lista->a = (char **) malloc (capacidade * sizeof(char *));
	lista->capacidade = capacidade;
	lista->livre = 0;

	return lista;
}

void destroi_lista(ListaSequencial * lista){

	free(lista->a);
	free(lista);
}

int tamanho(ListaSequencial * lista){

	return lista->livre;
}

void imprime(ListaSequencial * lista){

	int i;

	printf("Lista:");

	for(i = 0; i < lista->livre; i++){

		printf("[%d]: %s\n", i, lista->a[i]);
	}

	printf("\n");
}

int busca(ListaSequencial * lista, palavra e){

	// busca binária! ;)

	int ini = 0;
	int fim = lista->livre - 1;
	int meio;

	while(ini <= fim){

		meio = (ini + fim) / 2;

		if(strcmp(e, lista->a[meio])==0) return meio;
		if(strcmp(e, lista->a[meio])<0) fim = meio - 1;
		if(strcmp(e, lista->a[meio])>0) ini = meio + 1;
	}
		
	return -1;
}

Boolean insere(ListaSequencial * lista, char * e){

	int i;

	if(lista->livre < lista->capacidade) {

		for(i = lista->livre; i > 0 && strcmp(lista->a[i - 1], e)>0 ; i--){
			lista->a[i] = lista->a[i - 1];
		}

		lista->a[i] = e;
		lista->livre++;

		return TRUE;
	}

	return FALSE;
}

Boolean remove_elemento(ListaSequencial * lista, palavra e){

	int i;
	int indice = busca(lista, e);

	if(indice >= 0) {

		lista->livre--;

		for(i = indice; i < lista->livre; i++){

			lista->a[i] = lista->a[i + 1];
		}

		return TRUE;
	}

	return FALSE;
}

