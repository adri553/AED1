/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* returnedArray = (int*) malloc(sizeof(int) * 100);
    int tamanho = 0;
    postorder(root, &returnedArray, &tamanho);
    *returnSize = tamanho;
    return returnedArray;
}

void postorder(struct TreeNode* nodo, int** returnedArray, int* tamanho){
if(nodo!=NULL){
    postorder(nodo->left, returnedArray, tamanho);
    postorder(nodo->right, returnedArray, tamanho);
    (*returnedArray)[(*tamanho)++] = nodo->val;
}
return;
}