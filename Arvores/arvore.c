#include "arvore.h"
//teste de commit 

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem - R E D ====

void pre_order(Arvore *a){
    if (!verifica_arv_vazia(a)) {
        printf("%c", a->info);
        pre_order(a->esq);
        pre_order(a->dir);
    }
}



//========= Exercício 2 - in-ordem - E R D ====

void in_order(Arvore *a){
    if(!verifica_arv_vazia(a)){
        in_order(a->esq);
        printf("%c", a->info);
        in_order(a->dir);
    }
}

//========= Exercício 2 - pós-ordem  E D R====
void pos_order(Arvore *a){
    if(!verifica_arv_vazia(a)){
        pos_order(a->esq);
        pos_order(a->dir);
        printf("%c", a->info);
    }
    else{
        return 0;
    }
}

//========= Exercício 3 - pertence ====
int pertence(Arvore *a, char c){
    if(!verifica_arv_vazia(a)){
        if(a->info == c){
            return 1;
        }
    }else{
        return 0;
    }
    return pertence(a->dir,c) || pertence(a->esq, c);
}


//========= Exercício 4 - conta nós ====
int conta_nos(Arvore *a){
    int conta = 0;
    if(verifica_arv_vazia(a)){
        return 0;
    }
    conta += conta_nos(a->dir);
    conta += conta_nos(a->esq);
    return conta + 1; //considerando o primeiro nó 

}

//========= Exercício 5 - calcula altura ====
int altura(Arvore *a){
    int conta_esq = 0;
    int conta_dir = 0;
    if(!verifica_arv_vazia(a)){
       conta_dir = altura(a->dir);
       conta_esq = altura(a->esq);
       return 1 + (conta_esq > conta_dir ? conta_esq : conta_dir);
        
    }else{
        return 0;
    }
}


//========= Exercício 6 - conta folhas ====
int conta_folhas(Arvore *a){
    if(verifica_arv_vazia(a)){
        return 0;
    }
    if(a->esq == NULL && a->dir == NULL){
        return 1; //chega no final e retorna um pq tem filhos
    }
    return conta_folhas(a->dir) + conta_folhas(a->esq); //junta todo mundo 
}


int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

   arv_libera (a);
    printf("Percorrendo em pre-ordem: ");
    pre_order(a);
    printf("\n");

   return 0;
}
