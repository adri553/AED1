/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int* returnedArray;
    *returnSize= numsSize;
    int top=0;
    int c;
    returnedArray = (int*) malloc(sizeof(int) * numsSize);
    for(int i=0; i<numsSize; i++){
    c=i;
   while(c <numsSize && nums[c]<=nums[i]){
    c++;
   }
 if(c<numsSize){
    returnedArray[top++]= nums[c];
   } else{
    c=0;
    while(c< i && nums[c]<=nums[i]){
    c++;
    }
      returnedArray[top++] = (c<i) ? nums[c] : -1;
   }
    }
return returnedArray;
}