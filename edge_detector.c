#include <math.h>   /*Biblioteca com a funcao de raiz quadrada*/
#include <stdio.h>  /*Biblioteca para input e output*/

#define WIDTH 128
#define HEIGHT 96

int main() {
  int original[HEIGHT][WIDTH]; /*Declara matriz "original" de inteiros*/
  int copia[98][130]; /*Declara matriz "copia" de inteiros e duas linha e duas colunas maior que a original*/
  int saida[HEIGHT][WIDTH]; /*Declara matriz saida de inteiros*/
  int i, j;

  for (i=0;i<96;i++){
    for (j=0;j<128;j++){
      scanf("%d", &original[i][j]); /*recebe inteiros e os aloca na matriz "original"*/
    }
  }
  /*Coloca 0 nas bordas da matriz "copia" e coloca os elementos da matriz "original" na matriz copia, dentro das bordas*/
  for (j=0;j<130;j++){
    copia[0][j]=0;
    copia[97][j]=0;
  }
  for (i=1;i<98;i++){
    copia[i][0]=0;
    copia[i][129]=0;
  }
  for (i=1;i<97;i++){
    for (j=1;j<129;j++){
      copia[i][j]=original[i-1][j-1];
    }
  }
  int pixelh, pixelv, pixel;
  /*Faz convolução de matrizes - aplica os filtros em cada pixel e aloca os pixeis resultantes em uma matriz "saida" e imprime-os*/
  for (i=1;i<97;i++){
    for (j=1;j<129;j++){
      pixelh = 1*copia[i-1][j-1] + 0*copia[i-1][j] + (-1)*copia[i-1][j+1];
      pixelh = pixelh + 2*copia[i][j-1] + 0*copia[i][j] + (-2)*copia[i][j+1];
      pixelh = pixelh + 1*copia[i+1][j-1] + 0*copia[i+1][j] + (-1)*copia[i+1][j+1];

      pixelv = 1*copia[i-1][j-1] + 2*copia[i-1][j] + 1*copia[i-1][j+1];
      pixelv = pixelv + 0*copia[i][j-1] + 0*copia[i][j] + 0*copia[i][j+1];
      pixelv = pixelv + (-1)*copia[i+1][j-1] + (-2)*copia[i+1][j] + (-1)*copia[i+1][j+1];

      pixel = sqrt(pixelh*pixelh + pixelv*pixelv);
      saida[i-1][j-1] = pixel;
      printf("%d ", saida[i-1][j-1]);

    }
    printf("\n");
  }

  return 0;
}
