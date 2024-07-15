int maximumGain(char* s, int x, int y) {
 char* prioridade = "ab";
 char pilha[100001];
 int topo = 0;
 long total = 0;
 int valorP = x;
 int valorS = y;
 if( x < y ) {
    prioridade = "ba";
    valorP = y;
    valorS=x;
}
 int tam= strlen(s);
 for(int i=0; i<tam;i++) {
    if( pilha[topo] == prioridade[0] && s[i] == prioridade[1] ){
        topo--;
        total += valorP;
    } else {
        pilha[++topo] = s[i];
   }
}

char novaPilha[topo+2];
int topo2 = 0;

 for( int i = 0; i < topo+1;i++ ){
    if( novaPilha[topo2] == prioridade[1] && pilha[i]==prioridade[0] ){
        topo2--;
        total += valorS;
    } else {
        novaPilha[++topo2] = pilha[i];
}
   }
   return total;
}  