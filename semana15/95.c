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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* returnedArray = (int*) malloc(sizeof(int)*100);
    int tamanho = 0;
    inorder(root, &returnedArray, &tamanho);
    *returnSize = tamanho;
    return returnedArray;
}

void inorder(struct TreeNode* node, int** vetorResultante, int* tamanho){
if(node != NULL){
    inorder(node->left, vetorResultante, tamanho);
    (*vetorResultante)[(*tamanho)++] = node->val;
    inorder(node->right, vetorResultante, tamanho);
}
return;
}


//printa o a direita
//chama a recursão
//printa o a esquerda

//recursao: 
//se não tem nada retorna true
//