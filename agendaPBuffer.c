#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *criaNodo();
char *pegaNomeDoNodoAnterior(void *nodo);
void limpaNodos(int *i, int *qtdPessoas);
char *pegaNomeDoProximoNodo(void *nodo);
void buscarNodo(int *i, int *qtdPessoas);
void **pegaEndDoNodoAnterior(void **endDeNodo);
void **pegaEndDoProximoNodo(void **endDeNodo);
void atualizaNodoAnterior(void *nodo, void *anterior);
void atualizaProximoNodo(void *nodo, void *proximo);
void atualizaPrimeiroNodo(void *nodo, int *qtdPessoas);
void atualizaUltimoNodo(void *nodo, int *qtdPessoas);
void atualizaNodoNoMeio(void *nodo, int *i, int *qtdPessoas);
void adicionaNodo(void *nodo, int *i, int *qtdPessoas);
void removePrimeiroNodo(int *qtdPessoas);
void removeUltimoNodo(int *qtdPessoas);
void removerNodo(int *i, int *qtdPessoas);
void listarAgenda(int *i, int *qtdPessoas);

void *pBuffer; // ATENÇÃO REALLOC

int main() {
  printf("Agenda pBuffer\n");

  pBuffer = (void *)malloc(sizeof(int) * 3 + sizeof(void *) * 2);

  if (pBuffer == NULL) {
    printf("Erro ao alocar memória.\n");
    return 1;
  }

  int *menu = (int *)pBuffer;
  *menu = 0;

  int *i = (int *)(pBuffer + sizeof(int));
  *i = 0;

  int *qtdPessoas = (int *)(pBuffer + (sizeof(int) * 2));
  *qtdPessoas = 0;

  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
  *primeiroNodo = NULL;
  void **ultimoNodo = pBuffer + (sizeof(int) * 3 + sizeof(void *));
  *ultimoNodo = NULL;
  void *pessoa;
  //  void *busca = malloc;
  do {
    printf("\nEscolha uma opção para agenda:\n1- Adicionar Pessoa (Nome, "
           "Idade,email) \n2- Remover Pessoa\n3- Buscar Pessoa\n4- Listar "
           "todos\n5- Sair\n\nOpção: ");
    scanf("%d", menu);
    switch (*menu) {
    case 1:
      pessoa = criaNodo();
      adicionaNodo(pessoa, i, qtdPessoas);
      break;
    case 2:
      removerNodo(i, qtdPessoas);
      break;
    case 3:
      buscarNodo(i, qtdPessoas);
      break;
    case 4:
      listarAgenda(i, qtdPessoas);
      break;
    case 5:
      limpaNodos(i, qtdPessoas);
      free(pBuffer);
      exit(0);
      break;
    }

  } while (*menu != 5);
  
  return 0;
}

void *criaNodo() {

  void *nodo =
      (void *)malloc(sizeof(char) * 300 + sizeof(int) + sizeof(char) * 300 +
                     sizeof(void *) + sizeof(void *));
  // nome, idade, email, ponteiro pro anterior, ponteiro pro prox
  printf("\nDiga o nome da pessoa:");
  scanf("%s", (char *)nodo);
  printf("\nDiga a idade da pessoa:");
  scanf("%d", (int *)nodo + (sizeof(char) * 300));
  printf("\nDiga o email da pessoa:");
  scanf("%s", (char *)nodo + (sizeof(char) * 300 + sizeof(int)));

  return nodo;
}

void limpaNodos(int *i, int *qtdPessoas) {
  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
  void **endNodoPercorreFila = primeiroNodo;
  void *nodo;
  (*i) = 0;

  while ((*i) < (*qtdPessoas) - 1) {
    endNodoPercorreFila = pegaEndDoProximoNodo(endNodoPercorreFila);
    nodo = *endNodoPercorreFila;
    free(nodo);
    (*i)++;
  }
  free(*primeiroNodo);
}
char *pegaNomeDoNodoAnterior(void *nodo) {
  void **endDoAnterior =
      nodo + (sizeof(char) * 300 + sizeof(int) + sizeof(char) * 300);
  printf("Func Nome do anterior (1) vindo do 2 %s ", (char *)(*endDoAnterior));
  return ((char *)(*endDoAnterior));
}
char *pegaNomeDoProximoNodo(void *nodo) {
  void **endDoProximo = nodo + (sizeof(char) * 300 + sizeof(int) +
                                sizeof(char) * 300 + sizeof(void *));
 
  return ((char *)(*endDoProximo));
}

void buscarNodo(int *i, int *qtdPessoas) {
  char *nome = malloc(sizeof(char) * 300);
  printf("\nDigite o nome:\n");
  scanf("%s", (char *)nome);

  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
  void **endNodoPercorreFila = primeiroNodo;
 
  (*i) = 0;
  
  if (*qtdPessoas == 0) {
    printf("Não há ninguém na lista.");
  } else {

    while (*i < *qtdPessoas &&
           strcmp(nome, (char *)(*endNodoPercorreFila)) != 0) {
      
      endNodoPercorreFila = pegaEndDoProximoNodo(endNodoPercorreFila);
      (*i)++;
    }
    

    if (*i == (*qtdPessoas)) {
      printf("Essa pessoa não está na lista\n");
    } else {
      printf("\nNome do nodo buscado: %s\n", (char *)(*endNodoPercorreFila));

      printf("\nIdade do nodo buscado: %d\n",
             *((int *)*endNodoPercorreFila + (sizeof(char) * 300)));

      printf(
          "\nEmail do nodo buscado: %s\n",
          (char *)(*endNodoPercorreFila + (sizeof(char) * 300 + sizeof(int))));
    }
  }
  free(nome);
  return;
}

void atualizaNodoAnterior(void *nodo, void *anterior) {
  void **posAntPNodo =
      nodo + (sizeof(char) * 300 + sizeof(int) + sizeof(char) * 300);
  *(void **)posAntPNodo = anterior;
  return;
}
void atualizaProximoNodo(void *nodo, void *proximo) {
  void **posProxPNodo = nodo + (sizeof(char) * 300 + sizeof(int) +
                                sizeof(char) * 300 + sizeof(void *));
  *(void **)posProxPNodo = proximo;
  return;
}
void **pegaEndDoNodoAnterior(void **endDeNodo) {
  void **endDoAnterior =
      *endDeNodo + (sizeof(char) * 300 + sizeof(int) + sizeof(char) * 300);
  return (endDoAnterior);
}
void **pegaEndDoProximoNodo(void **endDeNodo) {
  void **endDoProximo = *endDeNodo + (sizeof(char) * 300 + sizeof(int) +
                                      sizeof(char) * 300 + sizeof(void *));
  return (endDoProximo);
}

void atualizaPrimeiroNodo(void *nodo, int *qtdPessoas) {
  void **primeiroNodo = pBuffer + (sizeof(int) * 3);

  if ((*qtdPessoas) > 0) {
    atualizaNodoAnterior(*primeiroNodo, nodo);
    atualizaProximoNodo(nodo, *primeiroNodo);
    *(void **)primeiroNodo = nodo;

  } else {

    printf("primiero");
    *(void **)primeiroNodo = nodo;
  }

  return;
}

void atualizaUltimoNodo(void *nodo, int *qtdPessoas) {
  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
  void **ultimoNodo = pBuffer + (sizeof(int) * 3 + sizeof(void *));

  if ((*qtdPessoas) >= 2) {
    printf("seg");
    void **tmp = pegaEndDoNodoAnterior(*ultimoNodo);
    atualizaNodoAnterior(nodo, *ultimoNodo);
    atualizaProximoNodo(*ultimoNodo, nodo);
    *(void **)ultimoNodo = nodo;
  } else {
    printf("primiero");
    *(void **)ultimoNodo = nodo;
    atualizaProximoNodo(*primeiroNodo, *ultimoNodo);
    atualizaNodoAnterior(*ultimoNodo, *primeiroNodo);
  }

  ///  atualizaProximoNodo(nodo, NULL);

  //  atualizaNodoAnterior(nodo3, *endNodoPercorreFila);

  //    atualizaProximoNodo(*endNodoPercorreFila, nodo3);

  /*
  pegaEndDoProximoNodo(endNodoPercorreFila));
    atualizaProximoNodo(nodo3, NULL);

    atualizaNodoAnterior(nodo3, *endNodoPercorreFila);

    atualizaProximoNodo(*endNodoPercorreFila, nodo3);
   */
  /*void **segundoNodo = pBuffer + (sizeof(int) * 3) + sizeof(void *);
  *(void **)segundoNodo = nodo;

  void **posAntDoUltimoNodo =
      segundoNodo + (sizeof(char) * 300 + sizeof(int) + sizeof(char) * 300);
  *posAntDoUltimoNodo = anterior;
  */

  return;
}

void atualizaNodoNoMeio(void *nodo, int *i, int *qtdPessoas) {

  void **ultimoNodo = pBuffer + (sizeof(int) * 3 + sizeof(void *));
  *i = 0;
  void **endNodoPercorreFila = ultimoNodo;
  while ((*i) < (*qtdPessoas) &&
         strcmp(((char *)nodo), (char *)(*endNodoPercorreFila)) < 0) {
    
    endNodoPercorreFila = pegaEndDoNodoAnterior(endNodoPercorreFila);
    (*i)++;
  }
 

  void **anteriorAoQueQueroAdd = *endNodoPercorreFila;

  void **vemDepoisDoQueQueroAdd = *pegaEndDoProximoNodo(endNodoPercorreFila);

  atualizaProximoNodo(anteriorAoQueQueroAdd, nodo);
  atualizaNodoAnterior(nodo, anteriorAoQueQueroAdd);
  atualizaNodoAnterior(vemDepoisDoQueQueroAdd, nodo);
  atualizaProximoNodo(nodo, vemDepoisDoQueQueroAdd);

  /*atualizaNodoAnterior(*pegaEndDoProximoNodo(endNodoPercorreFila), nodo);

  atualizaProximoNodo(nodo, *pegaEndDoProximoNodo(endNodoPercorreFila));

  atualizaNodoAnterior(nodo, *endNodoPercorreFila);

  atualizaProximoNodo(*endNodoPercorreFila, nodo);
// */
  //   printf("\n\nEntão: do meio o %s\n", (char *)nodo);
  //   printf("Depois dele tem o %s\n",
  //          (char *)*pegaEndDoProximoNodo(endNodoPercorreFila));
  //   printf("Antes dele tem o %s\n", (char *)*endNodoPercorreFila);

  return;
}

void listarAgenda(int *i, int *qtdPessoas) {
  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
  // printf("\nPrimeiro %s\n", (char *)(*primeiroNodo));

  void **endNodoPercorreFila = primeiroNodo;
  printf("\nItem: %s\n", (char *)*endNodoPercorreFila);

  void **endProx = pegaEndDoProximoNodo(endNodoPercorreFila);

  for (*i = 0; *i < (*qtdPessoas - 1); (*i)++) {
    printf("\nItem: %s\n", (char *)*endProx);
    endProx = pegaEndDoProximoNodo(endProx);
  }
  return;
}

void adicionaNodo(void *nodo, int *i, int *qtdPessoas) {
  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
  void **ultimoNodo = pBuffer + (sizeof(int) * 3 + sizeof(void *));
  if (*qtdPessoas == 0 ||
      strcmp(((char *)nodo), (char *)(*primeiroNodo)) <= 0) {
    atualizaPrimeiroNodo(nodo, qtdPessoas);
  } else if (*ultimoNodo == NULL ||
             strcmp(((char *)nodo), (char *)(*ultimoNodo)) >= 0) {
    atualizaUltimoNodo(nodo, qtdPessoas);
    // printf("okks");
  } else {
    // printf("\nno meio\n");
    atualizaNodoNoMeio(nodo, i, qtdPessoas);
    // listarAgenda(i, qtdPessoas);
  }

  (*qtdPessoas)++;
}

/*
void removePrimeiroNodo(int *qtdPessoas) {
  void **primeiroNodo = pBuffer + (sizeof(int) * 3);

  if (*qtdPessoas > 1) {
    
    // falta?
    void **proximo = pegaEndDoProximoNodo(primeiroNodo);
    atualizaNodoAnterior(*proximo, NULL);
    *primeiroNodo = *pegaEndDoProximoNodo(primeiroNodo);
    //    pegaEndDoProximoNodo(primeiroNodo);
  } else {
    printf("ultimo");
    atualizaProximoNodo(*primeiroNodo, NULL);
    atualizaNodoAnterior(*primeiroNodo, NULL);
    *primeiroNodo = NULL;
  }
}
void removeUltimoNodo(int *qtdPessoas) {
  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
  void **ultimoNodo = pBuffer + (sizeof(int) * 3 + sizeof(void *));
  if (*qtdPessoas > 1) {
    printf("AAA");
    void **anterior = pegaEndDoNodoAnterior(ultimoNodo);
    atualizaProximoNodo(*anterior, NULL);
    atualizaProximoNodo(*ultimoNodo, NULL);
    atualizaNodoAnterior(*ultimoNodo, NULL);
    *ultimoNodo = *anterior;
    //  void** proximo = pegaEndDoProximoNodo(primeiroNodo);
    // atualizaNodoAnterior(*proximo, NULL);
    // *primeiroNodo = *pegaEndDoProximoNodo(primeiroNodo);
    //    pegaEndDoProximoNodo(primeiroNodo);
  } else {
    void **primeiroNodo = ultimoNodo;
    printf("ultimo");
    atualizaProximoNodo(*primeiroNodo, NULL);
    atualizaNodoAnterior(*primeiroNodo, NULL);
    atualizaProximoNodo(*ultimoNodo, NULL);
    atualizaNodoAnterior(*ultimoNodo, NULL);
    *primeiroNodo = NULL;
    *ultimoNodo = NULL;
  }
}*/
void removerNodo(int *i, int *qtdPessoas) {
  char *nome = malloc(sizeof(char) * 300);
  printf("\nDigite o nome:\n");
  scanf("%s", (char *)nome);
  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
  void **ultimoNodo = pBuffer + (sizeof(int) * 3 + sizeof(void *));
  void **endNodoPercorreFila = primeiroNodo;

  if (*qtdPessoas == 0) {
    printf("Não há ninguém na lista.");
  } /* else if (strcmp(nome, (char *)(*primeiroNodo)) == 0) {
     if (*qtdPessoas == 1) {
       atualizaProximoNodo(*primeiroNodo, NULL);
       *primeiroNodo = NULL;

     } else {
       void **proximo = pegaEndDoProximoNodo(*primeiroNodo);
       atualizaNodoAnterior(*proximo, NULL);
       *primeiroNodo = *proximo;
     }
     (*qtdPessoas)--;

   } else if (strcmp(nome, (char *)(*ultimoNodo)) == 0) {
     if (*qtdPessoas == 1) {
       atualizaNodoAnterior(*ultimoNodo, NULL);
       // atualizaProximoNodo(*primeiroNodo, NULL);
       *ultimoNodo = NULL;
     } else {
       void **anterior = pegaEndDoNodoAnterior(*ultimoNodo);
       atualizaProximoNodo(*anterior, NULL);
       // atualizaNodoAnterior(*proximo, NULL);
       *ultimoNodo = *anterior;
     }
     (*qtdPessoas)--;
 */
  else if (*qtdPessoas == 1) {
    printf("Só tem uma pessoa na lista");
    //    *primeiroNodo = NULL;
    //   *ultimoNodo = NULL;
  } else {
    while (*i < *qtdPessoas &&
           strcmp(nome, (char *)(*endNodoPercorreFila)) != 0) {

      endNodoPercorreFila = pegaEndDoProximoNodo(endNodoPercorreFila);
      (*i)++;
    }

    if (*i == (*qtdPessoas) + 1) {
      printf("Essa pessoa não está na lista\n");
    } else {
      void **proximo = pegaEndDoProximoNodo(*endNodoPercorreFila);
      void **anterior = pegaEndDoNodoAnterior(*endNodoPercorreFila);
      atualizaProximoNodo(*anterior, *proximo);
      atualizaNodoAnterior(*proximo, *anterior);

      (*qtdPessoas)--;
    }
  }

  free(nome);
  return;
}
/*
  void **proximo = pegaEndDoProximoNodo(primeiroNodo);
  atualizaNodoAnterior(*proximo, NULL);
  *primeiroNodo = *proximo;
  atualizaProximoNodo(*primeiroNodo, NULL);
  printf("OARR");
*/

//  void **endNodoPercorreFila = primeiroNodo;
// (*i) = 0;
/*
  if (*qtdPessoas == 0) {
    printf("Não há ninguém na lista.");
  } else if (strcmp(nome, (char *)(*primeiroNodo)) == 0) {
    / *primeiroNodo = NULL;
    printf("\nDigitee\n");
    removePrimeiroNodo(qtdPessoas);
    (*qtdPessoas)--;
  } else if (strcmp(nome, (char *)(*ultimoNodo)) == 0) {
    removeUltimoNodo(qtdPessoas);
    (*qtdPessoas)--;
    //  printf("\nDigitee2\n");
    // atualizaUltimoNodo(NULL, qtdPessoas);
    //  *ultimoNodo = NULL;
  } else {
  }
  */
// printf("\nDigitee3\n");
/*
    while (*i < *qtdPessoas &&
           strcmp(nome, (char *)(*endNodoPercorreFila)) != 0) {
      // printf("\nAnterior da fila no while: %s\n", (char
      // *)*endNodoPercorreFila);
      endNodoPercorreFila = pegaEndDoProximoNodo(endNodoPercorreFila, );
      (*i)++;
    }
    //}
    // printf("LPEaa\n");
    //  printf("\nPalavra encontrada: %s\n",  (char
   *)(*endNodoPercorreFila));

    if (*i == (*qtdPessoas)) {
      printf("Essa pessoa não está na lista");
    } else {

    }
  */

/*
void adicionaNodo(void *nodo, int *i, int *qtdPessoas) {

  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
void **ultimoNodo = pBuffer + (sizeof(int) * 3 + sizeof(void *));
  //printf("Ultimo %s\n", (char *)(*ultimoNodo));
  while (*ultimoNodo != *primeiroNodo &&
         strcmp(((char *)nodo), ((char *)(*ultimoNodo))) < 0) {
    printf("\ntem 1");
    endAntDoUltimoNodo =
        ultimoNodoP + (sizeof(char) * 300 + sizeof(int) + sizeof(char) * 300);
    ultimoNodoP = endAntDoUltimoNodo;
  }

  printf("\nUltimo nodo pós whileP: %p", *ultimoNodoP);

  if (*ultimoNodoP == *primeiroNodoP) {
    printf("\nEE");
    void **endProxDoPrimeiroNodo =
        *primeiroNodoP + (sizeof(char) * 300 + sizeof(int) +sizeof(char) * 300 +
sizeof(void *)); printf("\nProximo do primeiro nodo P antes: %p\n",
*endProxDoPrimeiroNodo);

    void **endAnteriorDoNodoAtual =
        nodo3 + (sizeof(char) * 300 + sizeof(int) + sizeof(char) * 300);

    void **endProxDoNodoAtual = nodo3 + (sizeof(char) * 300 + sizeof(int)
+sizeof(char) * 300 + sizeof(void *));

   // printf("\n aaprox do nodo atual : %p\n", *endProxDoPrimeiroNodo);
    *endProxDoNodoAtual = *endProxDoPrimeiroNodo;
    endAnteriorDoNodoAtual = primeiroNodoP;
    *endProxDoPrimeiroNodo = nodo3;
    // printf("\n prox do nodo atual : %p\n", *endProxDoNodoAtual);
    // printf("\n anterior do nodo atual : %p\n", *endAnteriorDoNodoAtual);
    // printf("\nNovo Proximo do primeiro nodo P: %p\n",
*endProxDoPrimeiroNodo);
    // atualizaPrimeiroNodo(nodo3, NULL, primeiroNodoP);
  }
}*/
/*
void adicionaNodo(void *nodo, int *i, int *qtdPessoas)
  printf("chega");
  void **primeiroNodo = pBuffer + (sizeof(int) * 3);
  void **ultimoNodo = pBuffer + (sizeof(int) * 3 + sizeof(void *));
  void **posAntDoUltimoNodo =
      ultimoNodo + (sizeof(char) * 300 + sizeof(int) + sizeof(char) * 300);
  printf("\n%s\n", (char *)nodo);
  printf("\n%s\n", (char *)(*ultimoNodo));
  if ((char *)(*ultimoNodo)) {
    //  printf("%d", strcmp(((char *)nodo), (char *)(*ultimoNodo)));
    while ((*i) >= 0 && strcmp(((char *)nodo), (char *)(*ultimoNodo)) < 0) {
      ultimoNodo = posAntDoUltimoNodo;
      posAntDoUltimoNodo =
          ultimoNodo + (sizeof(char) * 300 + sizeof(int) + sizeof(char) * 300);
      printf("Func Nome do anterior %s ", (char *)(*ultimoNodo));
      (*i)--;
      //   printf("%")
    }
  }

  (*qtdPessoas)++;
  return;
}*/
