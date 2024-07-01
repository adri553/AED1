bool isValid(char* s) {

char stackOfCharacters[10000];
int top=0;

for(int i=0; i<strlen(s); i++){
if(s[i]== '(' || s[i]=='[' || s[i]== '{'){
      stackOfCharacters[++top] = s[i];
} else {
switch (s[i]) {
   case ')':
        if(stackOfCharacters[top]== '('){
         top--;
        } else{
            return false;
        }
        break;
    case ']':
        if(stackOfCharacters[top]== '['){
         top--;
        }else{
            return false;
        }
        break;
    case '}':
        if(stackOfCharacters[top]== '{'){
         top--;
        }else{
            return false;
        }
        break;
}
}
    }

if(top==0){
return true;
}

return false;
}
