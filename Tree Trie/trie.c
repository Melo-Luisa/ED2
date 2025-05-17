#include "trie.h"

/* */
Trie *create_node (char data) {
  Trie *node = (Trie *)malloc(sizeof(Trie));
  node->data = data;
  node->end = FALSE;
  node->nchild = 0;
  int i;
  //size is the alphabet size 
  for (i = 0; i < size; i++) {
    node->keys[i] = NULL;	   
  }
  return node;   
}

/* */
void free_node (Trie *node) {
  int i;
  for (i = 0; i < size; i++) {
    if (node->keys[i] != NULL) {
      free_node (node->keys[i]);	    
    }
  }	  
  free (node);
}



/* */
int search_auxiliary (Trie *root, char *word) {
  Trie *t = root;
  for(int i = 0; word[i] != '\0'; i++){
    int index = word[i] - 'a';
    if(t->keys[index] == NULL){
      return FALSE;
    }else{
      t = t->keys[index];
    }
  }
  if(t->end){
    return TRUE;
  }else{
    return FALSE;
  }
}

void search (Trie *root, char *word) {
  if (search_auxiliary (root, word))
    printf("Word %s found!\n", word);
  else  
    printf("Error: word %s not found!\n", word);
}

/* */
Trie *insert (Trie *root, char *word) {
  int index, i;
  if(search_auxiliary(root, word)){
    printf("Error: already inserted");
    return root;
  }
  Trie *t = root;
  for(i = 0; word[i] != '\0'; i++){
    index = word[i] - 'a';
    if(t->keys[index] == NULL){
      t->keys[index] = create_node(word[i]);
    }
    t->nchild += 1;
    t = t ->keys[index];
  }
  t->end = TRUE;

  return root;  	
}

/* */
void print (Trie *root, int level) {
  if (root != NULL) {
    int i;
    if (root->data == '\0')
      printf ("(null)");	    
    for (i = 0; i < level; i++) {
      printf ("| ");
    }	    
    printf ("%c (%d - %d)\n", root->data, root->end, root->nchild);
    for (i = 0; i < size; i++) {
      print (root->keys[i], level+1);      
    }
  }	  
}

int empty(Trie* root) {
    for (int i = 0; i < size; i++) {
        if (root->keys[i] != NULL) {
            return 0; // false
        }
    }
    return 1; // true
}

// void delete (Trie *root, char *word) {
  
//   int deep;
//   Trie *t = root;
//   if(t == NULL){
//     return NULL;
//   }

//   if(word[deep] == '\0'){
//     if(t->end){
//       t->end = FALSE;
//     }
//     if(empty(t)){
//       free(t);
//       return NULL;
//     }

//     int indice = word[deep] - 'a';
//     t->keys[indice] = delete(t->nchild, word);

//     if(empty(t) && t->end == FALSE){
//       free(t);
//       return NULL;
//     }
//   }

// }  

Trie* delete(Trie* root, char* word, int depth) {
    if (root == NULL) {
        return NULL;
    }

    if (word[depth] == '\0') {
        if (root->end) {
            root->end = 0; // Marca como não final de palavra
        }

        if (empty(root)) {
            free(root);
            return NULL;
        }

        return root;
    }

    int index = word[depth] - 'a';
    root->keys[index] = delete(root->keys[index], word, depth + 1);

    if (empty(root) && root->end == 0) {
        free(root);
        return NULL;
    }

    return root;
}

 
