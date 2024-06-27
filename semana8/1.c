int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

int* returnedArray;
returnedArray = (int*) malloc(sizeof(int)*2);
*returnSize=2;
 
for(int i=0; i<numsSize;i++){
 for(int j=i+1; j<numsSize;j++){
    if(nums[j]+nums[i]== target){
        returnedArray[0] = i;
        returnedArray[1] = j;
        return returnedArray;
    }
 }   
}
return returnedArray;
}