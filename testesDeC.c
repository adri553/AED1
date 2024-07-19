#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//void adicionaNodo(void** nodo){
//    return 0;
//}

void** criaNodo() {  //*
    void** nodo = (void**)malloc(sizeof(void*) * 5);
       //void* nodo = (void*)malloc(sizeof(void*) * 5);
// int 
    nodo[0] = (char*)malloc(sizeof(char) * 300); // nome
    nodo[1] = (int*)malloc(sizeof(int));         // idade
    nodo[2] = (char*)malloc(sizeof(char) * 300); // email

    printf("Diga o nome da pessoa:\n");
    scanf("%s", (char*)nodo[0]);
      printf("Diga a idade da pessoa:\n");
    scanf("%d", (int*)nodo[1]);
    //printf("%s", ((char*)nodo[0]));
   nodo[3] = NULL; // Prev ponteiro pro nó anterior
   nodo[4] = NULL; // Next    //nodo[0]= (char*) realloc(nodo[0], sizeof(char)* strlen(*nodo[0]));

/*    printf("Diga a idade da pessoa:\n");
    scanf("%d", (int*)nodo[1]);
    printf("Diga o email da pessoa:\n"); 
    scanf("%s", (char*)nodo[2]);
    nodo[2]= (char*) realloc(nodo[2], sizeof(char)*strlen(*nodo[2]));
*/
    return nodo;
}


void* pBuffer;   //ATENÇÃO REALLOC
int main(){
printf("Agenda pBuffer\n");
    
pBuffer = (void*) malloc(sizeof(int*)*3 + sizeof(void**)*2);
if (pBuffer == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int* menu = (int*) pBuffer; //É o primeiro item do pBuffer
    *menu = 0; // *((int*) pBuffer) = 0

    int* i = (int*) pBuffer + 1;
    *i = 0;  // Segundo item /pro for 

    int* contador = (int*)pBuffer+2; // Contador de nodos  Terceiro item
    *contador = 0;
    /* Para recuperar o que está no pBuffer:
    int* recupera = (int*) pBuffer+2;
    printf("\ncon:%d\n", *recupera); 
    */

void** nodo = criaNodo();
//nodo é um endereço que aponta pra vários outros
//void** novoNodo = (void**) pBuffer+ 3; //+ contador;

//*novoNodo = nodo;
void** novoNodo = (pBuffer + sizeof(int*)*3);
*novoNodo = nodo;
printf("%p\n", novoNodo);
printf("%p\n", nodo);
printf("%p\n", *novoNodo);
printf("%p\n", (pBuffer + sizeof(int*)*3));

printf("\n\n%d", *((int*)nodo[1])); //printa o nodo

void** recup =(pBuffer + sizeof(int*)*3);
printf("\n\n%d", *((int*)recup[1])); 
//(pBuffer + sizeof(int*)*3) = nodo;

//printf("%d", *((int*)nodo[1])); //printa o nodo
//void** recup = (pBuffer + sizeof(int*)*3);

//printf("%d", *((int*)nodo[1]));

//printf("%d", *((int*)recup[1]));



// printf("%d", *((*int) (recup[1])) );
//printf("%d", *( (int*) recup[1] ) );


//printf("%d", *nodo[1]);
//  int* recupera = (int**) pBuffer+3;
 //   printf("\ncon:%d\n", *recupera); 

// void** recupera = (void**) pBuffer+3;
//transforma o pBuffer+3 em um ponteiro pra ponteiro
//armazena nesse endereço transformado o nodo
 //printf("%d", *((int*)nodo[1]));

//void* novoNodo = (void*) pBuffer+ 3;
//novoNodo = nodo;
//void* enderecoNodo = *novoNodo;

//printf("%d", *((int*)enderecoNodo[1]));

//dentro do endereço novoNodo tem p

//printf("%d", *((int*)((recupera)[1]))); 
 // printf("%d", *((int*)((*recupera)[1]))); 
// printf("\nd:%s\n", *((char*) recupera[1])); 

// void** acesso = (void**) (pBuffer+3);
// printf("%s", ((char*) acesso[0]));
  //  void* newItem = (void*) pBuffer + 2;
   // *newItem = nodo;  // Valor do novo item
//    printf("Nome: %s\n", nodo[0]);;    
    //pBuffer+2
    //criaNodo();
    return 0;
}
