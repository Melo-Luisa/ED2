#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
    G->Mat[v] = (int *)calloc(tamanho, sizeof(int)); // zera os elementos da linha
    }
   return G;
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
        
      if (G->Mat[v] != NULL) {
         free(G->Mat[v]);
      }
   }
   free(G->Mat);
   free(G);
}

/*Função para imprimir a matriz de adjacências de um grafo*/
void imprimirMatrizAdjacencia(GrafoM *G) {
    printf("Matriz de Adjacencia:\n");
    printf("    ");
    for(int j = 0; j < G->V; j++) { // Imprime os índices das colunas
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < G->V; i++) {// Imprime o índice do vértice
        printf(" %d  ", i); 
        for (int j = 0; j < G->V; j++) {
            printf("%d ", G->Mat[i][j]);
        }
        
        printf("\n");
    }
}
void adicionar_aresta_mat(GrafoM *G, int origem, int destino) {
    if (G->Mat[origem][destino] == 0) {
        G->Mat[origem][destino] = 1; // ou o peso da aresta, se quiser
        G->E++;
    }
}

void imprimirListaAdjacente(GrafoM *G){
    printf("Lista de Adjacências:\n");
    for (int i = 0; i < G->V; i++) {
        printf("%d-> ", i);
        for (int j = 0; j < G->V; j++) {
            if (G->Mat[i][j] != 0) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void adicionar_aresta_adj(GrafoA *G, int origem, int destino) {
    NoA *novo_no = (NoA *)malloc(sizeof(NoA));
    novo_no->id = destino;
    novo_no->next = G->Adj[origem];
    G->Adj[origem] = novo_no;
    G->E++;
}

/* */
int main () {

   int Va = 6; /*Número de vértices*/

   GrafoA* Ga = criar_grafo_adj (Va);
    
   int Vm = 6; /*Número de vértices*/

   GrafoM* Gm = criar_grafo_mat (Vm);

    adicionar_aresta_mat(Gm, 0, 1);
    adicionar_aresta_mat(Gm, 0, 2);
    adicionar_aresta_mat(Gm, 0, 5);

    adicionar_aresta_mat(Gm, 1, 0);
    adicionar_aresta_mat(Gm, 1, 2);
    adicionar_aresta_mat(Gm, 1, 3);

    adicionar_aresta_mat(Gm, 2, 0);
    adicionar_aresta_mat(Gm, 2, 1);
    adicionar_aresta_mat(Gm, 2, 3);
    adicionar_aresta_mat(Gm, 2, 4);

    adicionar_aresta_mat(Gm, 3, 1);
    adicionar_aresta_mat(Gm, 3, 2);
    adicionar_aresta_mat(Gm, 3, 4);

    adicionar_aresta_mat(Gm, 4, 2);
    adicionar_aresta_mat(Gm, 4, 3);
    adicionar_aresta_mat(Gm, 4, 5);

    adicionar_aresta_mat(Gm, 5, 0);
    adicionar_aresta_mat(Gm, 5, 4);

    adicionar_aresta_adj(Ga, 0, 1);
    adicionar_aresta_adj(Ga, 0, 2);
    adicionar_aresta_adj(Ga, 0, 5);
    adicionar_aresta_adj(Ga, 1, 0);
    adicionar_aresta_adj(Ga, 1, 2);
    adicionar_aresta_adj(Ga, 1, 3);
    adicionar_aresta_adj(Ga, 2, 0);


    
   //imprimirMatrizAdjacencia(Gm); // Imprime a matriz de adjacências
   imprimirListaAdjacente(Ga); // Imprime a lista de adjacências

   liberar_grafo_adj (Ga);
   liberar_grafo_mat (Gm);

   return 0;
}
