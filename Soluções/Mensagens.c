#include <stdio.h>
#include <stdlib.h>
#define TAM 20000
#define MAX 1000001

//Merge function
void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//MergeSort
void mergeSort(int *arr, int l, int r)
{
    if (l < r) {
        
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main(){
    //Declarations
    char inputLetra;
    int inputNumero, count = 0;

    int *hash = calloc(MAX,sizeof(int));
    int res[TAM];

    //Body
    printf("Informe o numero e o caracter de cada pacote:\n");

    while(scanf("%d %c", &inputNumero, &inputLetra) == 2){ //Scan inputs
        if(hash[inputNumero] == 0){ //Check if it's repeated
            hash[inputNumero] = inputLetra;
            res[count] = inputNumero;
            count++;
        }
    }

    //Mergesort to order message
    mergeSort(res, 0, count-1);

    //Print message in order
    printf("\n------------\nA Mensagem recebida foi: ");

    for(int i = 0; i < count; i++){
        printf("%c", (char)hash[res[i]]);
    }
    printf("\n");
}
