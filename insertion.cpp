#include <bits/stdc++.h>
#include <omp.h>

using namespace std;


void preencher_vetores(int vetor1[], int tam){
	for (int i = 0; i < tam; ++i)
		vetor1[i] = rand()% +(tam*2);
}

void insertion_sort(int vetor[], int n) {
   for (int i = 1; i < n; i++) {
		int escolhido = vetor[i];
		int j = i - 1;	
		while ((j >= 0) && (vetor[j] > escolhido)) {
			vetor[j + 1] = vetor[j];
			j--;
		}		
		vetor[j + 1] = escolhido;
	}
	//for (int i = 0; i < n; ++i)
	//	cout<<vetor[i]<<" ";
}


void ordVetoresSP(int qtdv, int tam){
	double geral = 0.0;
	int vetor[tam];
	for (int i = 0; i < qtdv; ++i){
		preencher_vetores(vetor,tam);
		clock_t inicio = clock();
		insertion_sort(vetor,tam);
		clock_t fim = clock();

		geral+=(double) (fim-inicio)/CLOCKS_PER_SEC;
	}
	cout<<"ordenacao de vetores SP: "<<geral<<" segundos"<<endl;
}

void ordVetoresCP(int qtdv, int tam){
	double geral = 0.0;
	int vetor[tam], i;

	#pragma omp parallel for private(i) shared(geral,qtdv)
	for (i = 0; i < qtdv; ++i){
		preencher_vetores(vetor,tam);
		
		double inicio = omp_get_wtime();
		insertion_sort(vetor,tam);
		double fim = omp_get_wtime();
		geral+= (double) (fim-inicio);
	}
	cout<<"ordenacao de vetores CP: "<<geral<<" segundos"<<endl;
}

int main(){

	int n, tam;	cout<<"vetores e tamanho: "<<endl;
	cin>>n>>tam;
	ordVetoresSP(n,tam);
	ordVetoresCP(n,tam);
	

}