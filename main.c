#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float funcao(float x, float y){
	return (2 * y - 2) / x;
}

float euler(float x0, float y0, float h, int n){
      float x = x0;
      float y = y0;
      float passo = h;
      int iteracao = n;

      FILE *arq = fopen("logIteracoes.txt", "w");

      for(int i = 0; i < iteracao; i++){

            y = (y + (passo * (funcao(x, y))));

            if (arq){
            	fprintf(arq, "\nIteracao %d: x = %.1f, y = %.2f", i, x, y);
            }

            x = x + passo;
      }

      printf("\nValor aproximado de y quando x = %.1f é: %.2f", x, y) ;

      fclose(arq);
      return 0;
}

int main(){

    float h, x0, y0;
    int n;
    printf("Considerando a função 2y - 2 / x\n");
    printf("Insira o passo (h): ");
    fflush(stdout);
    scanf("%f", &h);

    printf("Insira a condição inicial (y(x0) = y0): ");
    fflush(stdout);
    scanf("%f", &y0);

    printf("Insira o valor de x0: ");
    fflush(stdout);
    scanf("%f", &x0);

    printf("Número de aproximação para y(n): ");
    fflush(stdout);
    scanf("%d", &n);

    euler(x0, y0, h, n);

    printf("\nTotal de iterações: %d", n);

}
