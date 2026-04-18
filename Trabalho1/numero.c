#include <stdio.h>

int Rotacao_direita(long long *k, int n) {
    
    long long int num = *k;
    int digitos = 0;

    while (num > 0) {
        num /= 10;
        digitos++;
}

    if (n <= 0 || n >= digitos) {
        return 0; 
}

    long long int particao = 1;
    for (int i = 0; i < n; i++) {
        particao *= 10;
}

    long long int ultimos = *k % particao;
    *k /= particao;
    for (int i = 0; i < digitos - n; i++) {
        
        ultimos *= 10;
    }
    *k += ultimos; 

    return 1; 
}
  int Rotacao_esquerda(long long *k, int n) {
    
    long long int num = *k;
    int digitos = 0;

    while (num > 0) {
        num /= 10;
        digitos++;
    }

    if (n <= 0 || n >= digitos) {
        return 0; 
    }
  
    n = n % digitos; 

    long long int particao = 1;
    for (int i = 0; i < n; i++) {
        particao *= 10;
    }
    
    long long int multiplicador = 1;
    for (int i = 0; i < digitos - n; i++) {
        multiplicador *= 10;
    }
    
    long long int primeiros = *k / multiplicador;
    long long int resto = *k % multiplicador;
    
    *k = resto * particao + primeiros;

    return 1;

}
  int Inicio_num(long long *k, int n) {
      
    if (n < 0 || n > 9) {
        
        return 0; 
    }

    long long int num = *k;
    int digitos = 0;

    while (num > 0) {
        num /= 10;
        digitos++;
    }

    long long int resto = *k / 10;

   
    long long int multiplicador = 1;
    for (int i = 0; i < digitos - 1; i++) {
        multiplicador *= 10;
    }

    *k = n * multiplicador + resto;

    return 1;
}
   int Fim_num(long long *k, int n) {
       
    if (n < 0 || n > 9) {
        
        return 0; 
    }

    long long int num = *k;
    int digitos = 0;


    while (num > 0) {
        num /= 10;
        digitos++;
    }
    
     long long int divisor = 1;
    for (int i = 0; i < digitos - 1; i++) {
    divisor *= 10;
}
     long long int resto = *k % divisor;

   
      *k = resto * 10 + n;

    return 1;
}

int main() {
    long long int k;
    int n;
    char operacao[10];

    do {
        printf("Valor de K: ");
        scanf("%lld", &k);

        if (k >= 100 && k <= 9999999999) {
             
            break;
        } else {
            printf("O número deve ter de 3 a 10 dígitos. Digite um número correto.\n");
        }
    } while (1);

    while (1) {
        printf("\nOperação: ");
        scanf("%s", operacao);

       
        if (operacao[0] == 'D' || operacao[0] == 'd') {
        scanf("%d", &n);
        if (!Rotacao_direita(&k, n)) {

        continue;
    }
    printf("%lld", k);

        } else if (operacao[0] == 'E' || operacao[0] == 'e') {
           scanf("%d", &n);
         if (!Rotacao_esquerda(&k, n)) {
          continue;
    }
    
            printf("%lld", k);
            
        } else if (operacao[0] == 'I' || operacao[0] == 'i') {
           scanf("%d", &n);
         if (!Inicio_num (&k, n)) {
          continue;
    }
    
            printf("%lld", k);
            
        } else if (operacao[0] == 'F' || operacao[0] == 'f') {
           scanf("%d", &n);
         if (!Fim_num (&k, n)) {
          continue;
    }
    
            printf("%lld", k);
    
        } else if (operacao[0] == 'T' || operacao[0] == 't') {
            break;
    }
    
  }
  
    return 0;
}