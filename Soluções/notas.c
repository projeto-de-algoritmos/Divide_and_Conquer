#include <stdio.h>


typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }


int buscaBinaria(int v[], int n, int posicaoInicial, int posicaoFinal);
int separa(int *v, int l, int r);
void quicksort(int *v, int l, int r);

int main() {
  int quantidade, numeros[128000];
  int m = 0;
  int c = 0;
  int x = 1;
  //quantidade total
  scanf("%d", &quantidade);
  
  for(int i = 0; i < quantidade; i++){
    scanf("%d", &numeros[i]);
    }
  //ordenação com quicksort
    quicksort(numeros, 0, quantidade-1);

    for(int j = 1; j < quantidade; j++) {
			
      if(numeros[j-1] == numeros[j])
        ++x;

      if(numeros[j-1] != numeros[j])
      {
       if(x >= c)
       {
		     c = x;
		     m = numeros[j-1];
			 }
       if(j == quantidade - 1 && c == 1)
          m = numeros[j];
       x = 1; 
      }
    }
//Resultado a ser imprimido.
    printf("%d\n", m);

}

int buscaBinaria(int v[], int n, int posicaoInicial, int posicaoFinal){
    int i = 0;
    int metade = (posicaoFinal + posicaoInicial)/2;

    if(n == v[metade] || n == v[posicaoInicial] || n == v[posicaoFinal])
        return i = 1;
    
    else 
    {
        if(posicaoFinal > posicaoInicial+1)
        {
         
            if(n < v[metade])  i = buscaBinaria(v, n, posicaoInicial+1, metade-1);
            else i = buscaBinaria(v, n, metade+1, posicaoFinal-1);
        }
    }
        return i;  
 }

int separa(Item *V,int l,int r)
{
  int i=l-1, j=r; Item v=V[r];
  for(;;)
  {
    while(less(V[++i],v));
    while(less(v,V[--j])) if(j==l) break;
    if(i>=j) break;
    exch(V[i],V[j]);
  }
  exch(V[i],V[r]);
  return i;
}

void quicksort(Item *V,int l, int r)
{
  if (r<=l) return;

  cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
      cmpexch(V[r],V[(l+r)/2]);

  int j=separa(V,l,r);
  quicksort(V,l,j-1);
  quicksort(V,j+1,r);
}
