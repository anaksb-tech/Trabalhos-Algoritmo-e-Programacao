#include <stdio.h>

const int N = 5;

int main() {
    
int m[N][N], s[N];
int k, encontrou;
char resposta;
int totalValores=0;

 printf("Insira os valores inteiros da matriz M:\n");
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &m[i][j]);
        totalValores++; 
    }
  }
  
 do {
   printf("Informe o valor de K: ");
    scanf("%d", &k);
    
     
      while (!(k >= 2 && k <= N)) {
          
        printf("Valor de K inválido. Informe o valor de K novamente: ");
        scanf("%d", &k);
}

        printf("Informe a sequência S: ");
         for (int i = 0; i < k; i++) {
          scanf("%d", &s[i]);
}

    encontrou = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
                
         if (j <= N - k) {
           int SequenciaEncontrada = 1;
    for (int t = 0; t < k; t++) {
         if (m[i][j + t] != s[t]) {
         SequenciaEncontrada = 0;
            break;
}
}
         if (SequenciaEncontrada) {
           printf("(%d, %d) sentido: esquerda para direita\n", i, j);
           encontrou = 1;
}
}
         if (j >= k - 1) {
           int SequenciaEncontrada = 1;
    for (int t = 0; t < k; t++) {
         if (m[i][j - t] != s[t]) {
          SequenciaEncontrada = 0;
             break;
 }
}
         if (SequenciaEncontrada) {
           printf("(%d, %d) sentido: direita para esquerda\n", i, j);
            encontrou = 1;
 }
}
         if (i <= N - k) {
            int SequenciaEncontrada = 1;
    for (int t = 0; t < k; t++) {
         if (m[i + t][j] != s[t]) {
           SequenciaEncontrada = 0;
              break;
 }
}
         if (SequenciaEncontrada) {
           printf("(%d, %d) sentido: cima para baixo\n", i, j);
             encontrou = 1;
 }
}
         if (i >= k - 1) {
          int SequenciaEncontrada = 1;
        for (int t = 0; t < k; t++) {
         if (m[i - t][j] != s[t]) {
           SequenciaEncontrada = 0;
             break;
 }
}
          if (SequenciaEncontrada) {
           printf("(%d, %d) sentido: baixo para cima\n", i, j);
             encontrou = 1;
   }
  }
 }
}

     if (!encontrou) {
       printf("Sequência não encontrada.\n");
}

       printf("Deseja procurar uma nova sequência? (s/n): \n");
        scanf(" %c", &resposta);
      } while (resposta == 's' || resposta == 'S');

return 0;
}