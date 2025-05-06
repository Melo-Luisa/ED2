#include "abbLista.h"


Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {
   if(a == NULL){
    a = (Arvore*)malloc(sizeof(Arvore));
    a->info = v;
    a->esq = NULL;
    a->dir = NULL;
   }else if(v < a->info){ // caso v seja MENOR que a
    a->esq = inserir(a->esq,v);
   }else{ // caso seja maior
    a->dir = inserir(a->dir,v); //recursivamento procura um espaço para o v
   }
   return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
   if(a==NULL){return NULL;}
   else{
    if(a->info > v){ //caso a seja maior que v
        a->esq = remover(a->esq, v);
    }else if(a->info < v){
        a->dir = remover(a->dir, v);
    }else{
        if((a->esq == NULL) && (a->dir == NULL)){
            free(a);
            a = NULL;
        }else if(a->dir == NULL){
            Arvore *tmp = a;
            a = a->esq;
            free(tmp);
        }else if(a->esq == NULL){
            Arvore *tmp = a;
            a = a->dir;
            free(tmp);
        }else{
            Arvore *tmp = a->esq;
            while(tmp->dir != NULL){
                tmp = tmp->dir;
            }
            a->info = tmp->info;
            tmp->info = v;
            a->esq = remover(a->esq,v);
        }
    }
  }
   
   return a;
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
    if(a == NULL){return 0;}
    else if(a->info > v){return buscar(a->dir,v);} // se a é maior
    else if(a->info < v){return buscar(a->esq,v);} // se a é menor
    else{return 1;} // caso tenho achado
  
  return 1; 
    
}

//========= Q2 - min =====
int minimo (Arvore *a){
    if(a == NULL){return -1;}
    while(a->esq != NULL){
        a = a->esq;
    }
    return(a->info);
}


//========= Q2 - max =====
int maximo (Arvore *a){
    if(a == NULL){return -1;}
    while(a->dir != NULL){
        a = a->dir;
    }
    return(a->info);
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente (Arvore *a){
    if(a!= NULL){
        imprime_decrescente(a->dir);
        printf("%d ", a->info);
        imprime_decrescente(a->esq);
        
    }
}


//========= Q4 - maior ramo =====
int maior_ramo(Arvore *a){
    if(a != NULL){
        int esq = a->info + maior_ramo(a->esq);
        int dir = a->info + maior_ramo(a->dir);
        if(esq > dir){
            return esq;
        }else{
            return dir;
        }
        
    }else{
        return 0;
    }
}


void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}



int main () {

   //int i;

   Arvore *a = cria_arvore_vazia ();

   a = inserir (a, 20);
   a = inserir (a, 8);
   a = inserir (a, 22);
   a = inserir (a, 4);
   a = inserir (a, 12);
   //a = inserir (a, 95);
   a = inserir (a, 10);
   a = inserir (a, 14);
   //a = inserir (a, 45);

   printf("\n");
   pre_order (a);	
   printf("\n");

    int min = minimo(a);
    int max = maximo(a);
    int maior = maior_ramo(a);
    imprime_decrescente(a);
    printf("\nMinimo: %d\n", min);
    printf("Maximo: %d\n", max);
    printf("Maior: %d\n", maior);

   // ====== Q5 ====
   /*a) No primeiro caso teremos O(n) no pior caso pois teremos que percorrer a arvore inteira e seus niveis são maiores
   b) No segundo caso teremos algo mais rapido com custo medio de log n
   
   */

   return 0;
}

