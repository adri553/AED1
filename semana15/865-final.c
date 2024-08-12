/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    int tamanhoDoMaior = 0;
    int tamanhoPercorre = 0;
    int tamanhoDoCaminhoDireita = 0;
    int tamanhoDoCaminhoEsquerda = 0;
    struct TreeNode* subtree = NULL;
   
   percorre(root, &tamanhoDoMaior,  tamanhoPercorre, tamanhoDoCaminhoDireita, tamanhoDoCaminhoEsquerda, &subtree);

    return subtree;
}

int percorre(struct TreeNode* nodo, int* tamanhoMaior, int tamanhoPercorre, int tamanhoDoCaminhoDireita, int tamanhoDoCaminhoEsquerda, struct TreeNode** sub){ //2
  
if(nodo!=NULL){
    tamanhoDoCaminhoEsquerda= percorre(nodo->left, tamanhoMaior, (tamanhoPercorre+1), tamanhoDoCaminhoDireita, tamanhoDoCaminhoEsquerda, sub);
    tamanhoDoCaminhoDireita=  percorre(nodo->right, tamanhoMaior, (tamanhoPercorre+1),tamanhoDoCaminhoDireita, tamanhoDoCaminhoEsquerda, sub);
    tamanhoPercorre = tamanhoDoCaminhoEsquerda > tamanhoDoCaminhoDireita ? tamanhoDoCaminhoEsquerda : tamanhoDoCaminhoDireita;

    if(tamanhoPercorre>=(*tamanhoMaior)){
        
        (*tamanhoMaior) = tamanhoPercorre; 
        
        if (tamanhoDoCaminhoEsquerda == tamanhoDoCaminhoDireita){
            (*sub) = nodo;
        } 

    }
        }
      return tamanhoPercorre;
}
   