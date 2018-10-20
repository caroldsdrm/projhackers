#include "fila_privado.h"
#include <stdlib.h>
#include<stdio.h>
//coloque aqui a implementacao das operacoes do TDA fila generico
/*
 * Cria uma fila e a inicializa como fila vazia. 
 * "imp" eh um ponteiro para uma funcao de impressao dos dados armazenados dentro da fila. Deve ser usado em "fila_imprime". 
 * o argumento "libera" prove uma maneira de liberar dinamicamente os dados dentro da celula quando "fila_destroi" eh chamada. 
 * Para uma fila onde os dados nao devem ser liberados, libera deve ser NULL 
 * "comparar" eh um ponteiro para funcao de comparacao entre dois dados armazenados na fila. 
 * Deve retornar -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo   
 * Pre: nenhuma
 * Pos: Retorna um ponteiro para uma fila vazia se houver memaria disponivel
 */
fila_t *fila_cria(void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *)){
	fila_t *fila = (fila_t *)malloc(sizeof(fila_t));
	if(fila == NULL){
		//printf("nao alocou, bobalhona");
		return NULL;
	}
	//lembrar que fila segue o mesmo princípio de lista e tda(porque eh um tda)
	
	fila->cabeca = NULL;
	fila->cauda = NULL;
	fila->tamanho =0;
	fila->destruir = libera;
	fila->imprime = imp;
	fila->compara = comparar;

return fila;
}

/*
 * Destroi a fila especificada em "f". Nenhuma operacao eh permitida apos a funcao, a nao ser que fila cria seja chamada novamente. 
 * Destroi todos os elementos armazenados na fila, se o ponteiro "destruir" for valido
 * Pre: "f" deve ser uma fila valida criada previamente atraves da funcao fila cria
 * Pos: os recursos da fila foram liberados com sucesso e a fila "f" torna-se nula
 */
void fila_destroi(fila_t **f){
	if(f == NULL || (*f) == NULL){
		return;
	} //ainda segue o mesmo princípio de lista porque É semelhante a UMA LISTA?
	celula_t *abobrinha; 
	
	for(int i =0; i< (*f)->tamanho; i++){
		abobrinha = (*f)->cabeca;
		(*f)->cabeca = (*f)->cabeca->prox;
		if((*f)->destruir != NULL)
			(*f)->destruir(abobrinha->dado);
		free(abobrinha);
	}

	free(*f);
	(*f) = NULL;
	
return;
}

/*
 * Retorna 1 se a fila estiver vazia, 0 caso contrario
 * Pre: a fila deve existir
 * Pos: retorna 1 caso a fila estiver vazia, 0 se nao estiver. Retorna -1 caso a fila nao existir
 */
int fila_vazia(fila_t *f){
		if(f == NULL){
		return -1;
	}
	if(f->tamanho == 0){
		return 1;
	}
	if(f->tamanho !=0){
		return 0;
	}
}

/*
 * Retorna o tamanho da fila
 * Pre: a fila deve existir
 * Pos: retorna o tamanho da fila. Retorna -1 caso a fila nao existir
 */
int fila_tamanho(fila_t *f){
    if(f == NULL){
		return -1;
	}
return f->tamanho;	
}

/*
 * Enfileira um novo elemento na fila. O ponteiro "elem" eh inserido em uma celula da fila. 
 * Eh responsabilidade de quem chama o gerenciamento da memoria de "elem", onde ela devera permanecer valida enquanto estiver dentro da fila.
 * Retorna 1 caso conseguir enfileirar, 0 caso contrario
 * Pre: a fila deve existir e "elem" deve ser valido
 * Pos: o elemento recebido pela operacao eh a nova cauda da fila
 */
int fila_enfileira(fila_t *f, void *elem){
		if(f == NULL || elem == NULL){
		//printf("entrou aqui4");
		return 0;
	}
    //os desenhos pra onde cada ponteiro aponta tão no teu caderno
	celula_t *minnie = (celula_t *)malloc(sizeof(celula_t));
	if(minnie == NULL){
		//printf("entrou aqui3");
		return 0;
	}
	minnie->dado = elem;
	minnie->prox = NULL;
	if(fila_vazia(f) == 1){
		f->cabeca = minnie;
	}
	else{
		f->cauda->prox = minnie;
	}
	
	f->cauda = minnie;
	f->tamanho++;
	return 1;
}

/*
 * Enfileira um novo elemento na fila de forma ordenada (crescente). Caso o ponteiro "elem" tenha um valor igual a um elemento que estiver na fila, a insercao de "elem" deve ser feita logo apos.
 * Eh responsabilidade de quem chama o gerenciamento da memoria de "elem", onde ela devera permanecer valida enquanto estiver dentro da fila.
 * Caso o ponteiro de funcao "compara" for NULL, a insercao de "elem" deve ser feita na cauda da fila.
 * Retorna 1 caso conseguir enfileirar, 0 caso contrario
 * Pre: a fila deve existir e "elem" deve ser valido
 * Pos: o elemento recebido pela operacao eh inserido de forma ordenada (crescente)
 */
int fila_enfileira_ordenado(fila_t *f, void *elem){
		//respira e faz isso bem calma, como tinha que ter sido na prova
	if(f == NULL || elem == NULL){
		return 0;
	}
	//lista vazia ==1, lista nao vazia == 0, lista nula == -1
	if(fila_vazia(f) == 1 || f->compara == NULL){
		return fila_enfileira(f, elem);
	}
	//ponteiro de funcao para comparar dois dados armazenados na fila. 
	//Retorna -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo  
	celula_t *temporario  =  f->cabeca;
    celula_t *aux = (celula_t*)malloc(sizeof(celula_t));
    celula_t *aux2 = (celula_t*)malloc(sizeof(celula_t));
    
    fila_enfileira(f, elem); 
    while (temporario!= NULL ){
        if (f->compara(elem, temporario->dado) == -1){
            aux->dado = temporario->dado;
            temporario->dado = elem;
            while(temporario !=NULL){
            	//printf("entrou aqui, anjo");
                temporario = temporario->prox;
                if (temporario !=NULL){	 	  	 	     		     	   	 	  	  	 	
                    aux2->dado = temporario->dado;
                    temporario->dado = aux->dado;
                    aux->dado = aux2->dado;
                    //printf("css - superafim, playing on the background");
                }
                
            }
            
        }else{
        temporario = temporario->prox;
        //printf("d is for dangerous");
        }
        }
	free(aux);
	free(aux2);
	free(temporario);
return 1;
}

/*
 * Desenfileira o elemento que estiver na cabeca da fila e retorna o seu valor em "elem". Eh responsabilidade de quem chama gerenciar a memoria de "elem".
 * Retorna 1 caso conseguir desenfileirar, 0 caso contrario
 * Pre: a fila deve existir e nao deve estar vazia. "elem" deve ser valido
 * Pos: a fila tera um elemento a menos e o valor da antiga cabeca eh retornado
 */
int fila_desenfileira(fila_t *f, void **elem){
	if(f == NULL){
		//printf("o humbug nao eh o melhor album do arctic monkeys");	
		return 0;
	}
	if(fila_vazia(f) == 1){
		//printf("favorite worst nightmare é o melhor album do am...... o whatever pode ser tbm, sabe");	
		return 0;
	}
	if(elem == NULL){
		//printf("nao conseguimos escolher o melhor cd do muse");	
		return 0;
	}
	if(*elem == NULL){
		//printf("superafim - css playing on the background");
		return 0;
	}
	celula_t *muse = f->cabeca->prox;
	//printf("MEH\n");
	(*elem) = f->cabeca->dado;
	free(f->cabeca);
	f->cabeca = muse;
	f->tamanho--;
	//printf("42");
	
return 1;
}

/*
 * Retorna o valor do elemento na cabeca da fila em "elem". Retorna 1 caso a fila ter um valor na sua cabeca, 0 caso contrario
 * Pre: a fila deve existir e nao deve estar vazia. "elem" deve ser valido
 * Pos: o valor do elemento da cabeca eh retornado em uma variavel
 */
int fila_cabeca(fila_t *f, void **elem){
	if(f == NULL || !elem || fila_vazia(f) == 1){
		return 0;
	}
	*elem = f->cabeca->dado;
	return 1;
}


/*
 * Retorna o valor do elemento na cauda da fila em "elem". Retorna 1 caso a fila ter um valor na sua cauda, 0 caso contrario
 * Pre: a fila deve existir e nao deve estar vazia. "elem" deve ser valido
 * Pos: o valor do elemento da cauda eh retornado em uma variavel
 */
int fila_cauda(fila_t *f, void **elem){
	if(f == NULL || !elem || fila_vazia(f) == 1){
		return 0;
	}
	*elem = f->cauda->dado;
	return 1;	
}


/*
 * Imprime os elementos da fila atraves do ponteiro de funcao "imprime", comecando pela cabeca da fila
 * Pre: a fila deve existir e o ponteiro "imprime" deve ser valido
 * Pos: Os elementos sao impressos usando o ponteiro "imprime"
 */
void fila_imprime(fila_t *f){
    if(f == NULL){
		return;
	}
	if(f->imprime == NULL){
		return;
	}
	celula_t * aux = f->cabeca;
	while(aux != NULL){
		f->imprime(aux->dado);
		aux = aux->prox;
	}
free(aux);	
return;
}
