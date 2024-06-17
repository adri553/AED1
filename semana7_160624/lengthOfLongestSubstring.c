#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lengthOfLongest = 0;
    int currentLength;
    
    for(int i=0; i<strlen(s); i++){ 
 currentLength = findLengthOfSubstring(i, s);
 lengthOfLongest = (currentLength > lengthOfLongest) ? currentLength : lengthOfLongest;
    }
return lengthOfLongest;
}

int findLengthOfSubstring(int current, char* s){
     char theLongest[5000] = {};
    while(strchr(theLongest, s[current])==NULL ){
            theLongest[strlen(theLongest)] = s[current];
        current++;
 }
 return strlen(theLongest);
}
