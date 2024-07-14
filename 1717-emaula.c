int maximumGain(char* s, int x, int y) {
 char* prioridade;
 char* secundario;
char pilha[100001];
char novaPilha[100001];

pilha[0] = s[0];
 //char topo = 0;
// char base = 0;
 int topo=0;
 long total =0;
 int valorP;
  int valorS;
//e se tiverem o mesmo valor?
 //está invertido, quando for ler de trás pra frente
if(x>=y){
    prioridade = "ab";
    secundario = "ba";
    valorP = x;
      valorS = y;
} else{
    prioridade = "ba";
    secundario = "ab";
    valorP = y;
    valorS=x;
}


    for(int i=0; i<strlen(s);i++){

if(topo && pilha[topo] == prioridade[0] && s[i]==prioridade[1]){
   // printf("\nif\n");
topo--;
total+=valorP;
} else{
//printf("else\n");
if(s[i]=='a' || s[i]=='b' || 
(s[i]!='a' && s[i]!='b' && (pilha[topo]=='a' || pilha[topo]=='b'))){
    //se não é a e não é b e o topo
    pilha[++topo] = s[i];
}
    //topo++;
}
//pilha = realloc(pilha, (2 + (sizeof(char) * (topo)))); 
   }
printf("%s", pilha);

novaPilha[0] = pilha[0];
int tamanho = topo;
printf("%d", topo);
topo=0;
    for(int i=1; i<tamanho+1;i++){

if(topo && novaPilha[topo] == secundario[0] && pilha[i]==secundario[1]){
   // printf("\nif\n");
topo--;
total+=valorS;
} else{
//printf("else\n");
    novaPilha[++topo] = pilha[i];
    //topo++;
}
   }

   printf("\n%s", novaPilha);

   
   return total;
}  

   //if(int i=0; i<strlen(s);i++){
 //vê se o maior é ab ou ba
    //se o maior for ab, tira todos os ab
    //enquanto tiver ab vai tirando da nova string formada
    //depois tira ba um por um, para cada um que surgir passa a função que tira ab

    //outra opção: ler a string como pilha e a cada ba ou ab limpar as 2 últimas