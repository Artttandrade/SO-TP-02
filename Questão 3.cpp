#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

using namespace std;


// Inicializa a Matriz tuda com 0;
void init_Matriz(int Matriz[][20]){
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            Matriz[i][j] = 0;
        }        
    }

}

void Controle(int Matriz[][20]){

    #pragma omp parallel
    


}

void SemControle(int Matriz[][20]){

}

// Mostrar estado atual da Matriz
void ShowMatriz(int Matriz[][20]){
    int i, j;
    for (i = 0; i < 20; i++){
        for (j = 0; j < 20; j++){
            printf("%d ", Matriz[i][j]);
        }
        printf("\n");
    }    
    

}

int main(){
    int Matriz[20][20];

    init_Matriz(Matriz);

    Controle(Matriz);
    SemControle(Matriz);
    ShowMatriz(Matriz);
}