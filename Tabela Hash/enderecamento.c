#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EMPTY -99999

/* */
typedef struct _hash {
   int key;
   char *data;
} Hash;

/* Transforma uma chave em um índice no intervalo 0..M-1. */
int funcao_hash (int key, int M) {
   return (key % M);
}

int linear_probing (int key, int iter, int M) {
   /*Completar!*/
   int j = (funcao_hash(key, M) + iter) % M;
   return j;
}

int quadratic_probing (int key, int iter, int M) {
   /*Completar!*/
   int j = (funcao_hash(key, M) + iter + pow(iter,2)) % M;
   return j;
}

int double_hash (int key, int iter, int M) {
   /*Completar!*/
   int h1 = funcao_hash(key, M);
   int h2 = 1 + (key % (M - 1)); // Evita divisão por zero
   int j = (h1 + iter * h2) % M;
}

/* */
Hash* create_hash (int M) 
{ 
   int h;
   Hash *H = (Hash *)malloc(M * sizeof(Hash));
   for (h = 0; h < M; h++) {
      H[h].key = EMPTY;
      H[h].data = (char *)malloc(256 * sizeof(char));
      sprintf(H[h].data, "");
   }
   return H;
}

/* */
void free_hash (Hash *H, int M) {
   int h;
   for (h = 0; h < M; h++) {
      free(H[h].data);
   }
   free(H);
}

/* */
int hash_search (Hash *H, int M, int key) {
   int j, i = 0;
   do {
      /*j = Completar*/
      printf("Testando chave: %d\n", j);
      char skey[256];
      sprintf(skey, "%d", key);
      if (H[j].key == key) {
         return j;
      }
      i++;
   } while ((i != M) || strcmp(H[j].data,"") == 0);
   printf("key not found!\n");
}

/* */
int hash_insert (Hash *H, int M, int key) {
   int j, i = 0;
   printf("Inserindo chave: %d\n", key);
   do {
      /*j = Completar*/
      printf("Testando chave: %d\n", j);
      if (strcmp(H[j].data,"") == 0) {
         H[j].key = key;
         sprintf(H[j].data, "%d", key);
         return j;
      }
      i++;
   } while (i != M);
   printf("hash table overflow!\n");
}

/* */
void hash_print (Hash *H, int M) {
   int i;
   for (i = 0; i < M; i++) {
      if (strcmp(H[i].data,"") != 0) {
         printf("%2d - %s\n", i, H[i].data);
      } 
   }
}

int main () {
   int M = 11;
   Hash *H = create_hash (M);
   hash_insert (H, M, 10);
   /*Completar com as demais chaves do exercício 2!*/
   hash_print (H, M);
   free_hash (H, M);
   return 0;
}