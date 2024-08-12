/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //contar o caminho maximo que vimos ate agora e ir substituindo:
 //se o caminho atual for maior que o máximo, troca
  /* //Função que criaria o nodo
struct TreeNode* criaNodo(int val){
       struct TreeNode nodo;
       nodo.val = val;
      // struct TreeNode* ref = &nodo;
       return &nodo;
}
*/

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    int tamanhoDoMaior = 0;
    int tamanhoCaminhoAtual = 0;
   // struct TreeNode* subtree = criaNodo(54);
/*
    struct TreeNode leftdaconsubtree;
    struct TreeNode* subtreeleft;
    subtreeleft = &leftdaconsubtree;

    struct TreeNode rightdaconsubtree;
    struct TreeNode* subtreeright;
    subtreeright = &rightdaconsubtree;

    struct TreeNode* subtree;
    struct TreeNode consubtree;
    subtree = &consubtree;
    subtree->left = subtreeleft;
    subtree->right = subtreeright;

*/
   if(root->left == NULL && root->right == NULL){ //PARA O CASO COM árvore =[1];
    return root;
   }
   
    struct TreeNode* subtree = NULL;
   struct TreeNode* teste;
   percorre(root, &tamanhoDoMaior, &tamanhoCaminhoAtual, &subtree);

 //  printf("\rRoot %d",  (subtree)->val);
  // printf("\nLeft %d",  ((subtree)->left)->val);
  // printf("\nRight %d",  ((subtree)->right)->val);

    return subtree;
}

void percorre(struct TreeNode* nodo, int* tamanhoMaior, int* tamanhoPercorre, struct TreeNode** sub){ //2
   if(nodo!=NULL){
   
    if(nodo->left == NULL && nodo->right == NULL){
        if((*tamanhoPercorre)>(*tamanhoMaior))
        {
   (*tamanhoMaior) = (*tamanhoPercorre); //tg = 3
        }
 //printf("\n nodo folha: %d\n", nodo->val);
   return;

    } else{
   
//printf("\n nodo não folha: %d", nodo->val); 
        (*tamanhoPercorre)++; //3
        percorre(nodo->left, tamanhoMaior, tamanhoPercorre, sub);
        percorre(nodo->right, tamanhoMaior, tamanhoPercorre, sub);
    
    }

    if((*tamanhoMaior) == (*tamanhoPercorre)){
        //atribui árvore
//printf("nodo da menor que contem a arvore %d", nodo->val);
     
        //se um deles é null, a subarvore vira o outro

if(nodo->left != NULL && nodo->right != NULL){
*sub = nodo;
   /* (*sub)->val = nodo->val;
    (*sub)->left = nodo->left;
    (*sub)->right = nodo-> right;
*/
} else{

        if(nodo->left == NULL){
         (*sub) = nodo->right;
          //   (*sub)->val = nodo->right->val; 
          // printf("\nUm ramo é nulo então vai ser %d", nodo->right->val);
        } 
        else if(nodo->right== NULL){
          (*sub) = nodo-> left;
          //  (*sub)->val = nodo->left->val; 
             //printf("\nUm ramo é nulo então vai ser %d", nodo->left->val);
        }
} 
        
    }

     // printf("\ntamanho: %d", (*tamanhoPercorre)); 
      //printf("\ntamanho maior: %d", (*tamanhoMaior)); 
      (*tamanhoPercorre)--;

   } 
      return;
}
