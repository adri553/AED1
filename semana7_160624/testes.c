 
 #include <string.h>
#include <stdio.h>
int main(){
  char arr[5] = { 'a', 'b', 'c', 'd', 'e' }; 
  
    printf("Before: "); 
  
    for (int i = 0; i<5; i++){ 
        printf("%c ", arr[i]); 
    }
    printf("\n"); 
  
    // Clearing the array 
    arr[0] = '\0'; 
  
    printf("After:\n "); 
  
    for (int i = 0; arr[i] != NULL; i++) 
        printf("%c ", arr[i]); 

    arr[1] = 'a';

    arr[2] = 'b';

    arr[0] = '\0'; 
    
     printf("After: "); 
  
    for (int i = 0; i<5; i++) 
        printf("%d e %c ", i, arr[i]); 

}