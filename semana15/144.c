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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {


    int* returnedArray = malloc (sizeof(int) * 100);
    //returnedArray[0] = 47;
    int tamanho=0;
 //    if (root == NULL) {
       // return returnedArray;
   // }
   // printf("%d", root->val);
  preorder(root, &returnedArray, &tamanho);
printf("\nA%dA\n", returnedArray[0]);
printf("\nA%dA\n", returnedArray[1]);
printf("\nA%dA\n", returnedArray[2]);
*returnSize = tamanho;
  return returnedArray;  

}

void preorder (struct TreeNode* nodo, int** array, int* tamanho){

//raiz antes
if(nodo!=  NULL){
    //*tamanho +=1;
printf("%d", nodo->val);
(*array)[(*tamanho)++] = nodo->val;
preorder(nodo->left, array, tamanho);
preorder(nodo->right, array, tamanho);
printf("B%dB", *tamanho);
//printf("\nA%dA\n", (*array)[0]);
}
return;
}