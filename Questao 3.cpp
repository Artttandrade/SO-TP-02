#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <ctime>
#include <iostream>

using namespace std;


// Mostrar estado atual da Matriz
void ShowMatriz(int Matriz[][4]){
    int i, j, soma=0;
    int tam = 4;
    for (i = 0; i < tam; i++){
        for (j = 0; j < tam; j++){
            printf("%d ", Matriz[i][j]);
            soma = soma + Matriz[i][j];
        }
        printf("\n");
    }    
    cout << "Soma da Matriz: " << soma << "\n";
}


// Inicializa a Matriz tuda com 0;
void init_Matriz(int Matriz[][4]){
    int i, j;
    int tam = 4;
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            Matriz[i][j] = 0;
        }        
    }

}

void Controle(int Matriz[][4]){
    int i=0, j=0, valor;
    int min, max, num;
    srand((unsigned)time(0)); //para gerar números aleatórios reais.
    max = 3;
    min = 0;
    cout << "Com Controle de Concorrencia\n";
    #pragma omp parallel num_threads(10000) shared(Matriz)
    {
        i = rand()%(max-min+1) + min;;
        j = rand()%(max-min+1) + min;;
        //valor = rand()%(max-min+1) + min;
        
        #pragma omp atomic
        Matriz[i][j]++;
        //ShowMatriz(Matriz);
    }
    


}

void SemControle(int Matriz[][4]){
    int i, j, valor;
    int min, max, num;
    srand((unsigned)time(0)); //para gerar números aleatórios reais.
    max = 3;
    min = 0;
    cout << "Sem controle de Concorrencia\n";
    
    #pragma omp parallel num_threads(10000) shared(Matriz)
    {
         
        i = rand()%(max-min+1) + min;;
        j = rand()%(max-min+1) + min;;
        //valor = rand()%(max-min+1) + min;
        
        Matriz[j][i]++;
        //ShowMatriz(Matriz);
    }

}



int main(){
    int Matriz[4][4];
    int min, max, num, escolha;
    
    srand((unsigned)time(0)); //para gerar números aleatórios reais.
    max = 10;
    min = 1;
    num = rand()%(max-min+1) + min;
    cout << "1 para: Com Controle de Concorrencia\n2 para: Sem Controle de Concorrecia\nEscolha: ";
    cin >> escolha;
    if (escolha == 1){
        for (int i = 0; i < 5; i++)
        {
            init_Matriz(Matriz);
            printf("Iteração: %d\n", i);
            Controle(Matriz);
            ShowMatriz(Matriz);
            cout << "\n";
        }
    }

    else {
        for (int i = 0; i < 5; i++)
        {
            init_Matriz(Matriz);
            printf("Iteração: %d\n", i);
            SemControle(Matriz);
            ShowMatriz(Matriz);
            cout << "\n";
        }
    }
}