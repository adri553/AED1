/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int percorre(struct TreeNode* nodo, int tamanho){

if(nodo!= NULL){
    int left =percorre(nodo->left, tamanho+1);
    int right= percorre(nodo->right, tamanho+1);
  if(left>=right){
    tamanho= left;
  } else{
    tamanho= right;
  }
   printf("%dt:\n", (tamanho));
    
}
return tamanho;
}
int maxDepth(struct TreeNode* root) {

    int result = percorre(root, 0);

    return result;
}