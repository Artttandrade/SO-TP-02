#include <bits/stdc++.h>
#include <omp.h>

using namespace std;



void multMatrizesSP(int dimensao){
	int somador = 0, 
	m1[dimensao][dimensao],
	m2[dimensao][dimensao],
	m3[dimensao][dimensao];

	//preencher vetor
	for (int i = 0; i < dimensao; ++i){
		for (int j = 0; j < dimensao; ++j){
			m1[i][j] = rand()%+dimensao;
			m2[i][j] = rand()%+dimensao;
			m3[i][j] = 0;		
		}
	}
	clock_t inicio = clock();
	for (int i = 0; i < dimensao; ++i){
		for (int j = 0; j < dimensao; ++j){
			for (int z = 0; z < dimensao; ++z)
				somador+= m1[i][z]*m2[z][j];
			m3[i][j] = somador;
			somador=0;
		}
	}
	clock_t fim = clock();
	cout<<"Tempo da mult sem paralelismo: "<<(((double)(fim-inicio))/ CLOCKS_PER_SEC)<<" segundos"<<endl;

	/*for (int i = 0; i < dimensao; ++i){
		for (int j = 0; j < dimensao; ++j)
				cout<<m3[i][j]<<" ";
	}*/
}

void multMatrizesCP(int dimensao){
	int m1[dimensao][dimensao],
	m2[dimensao][dimensao],
	m3[dimensao][dimensao], somatorio = 0;

	int ii,ji,ki;

	ii=ji=ki=dimensao;
	
	//preencher vetor
	for (int i = 0; i < dimensao; ++i){
		for (int j = 0; j < dimensao; ++j){
			m1[i][j] = rand()%+dimensao;
			m2[i][j] = rand()%+dimensao;
			m3[i][j] = 0;			
		}
	}

	int j,k,i;
	double inicio = omp_get_wtime();
	#pragma omp parallel for private(j,k,i) shared(ii,ji,ki)
	for (int i = 0; i < ii; i++)	{
		for (j = 0; j < ji; ++j){
			for (k = 0; k < ki; ++k)
				m3[i][j] += m1[i][k]*m2[k][j];
		}
	}
	double fim = omp_get_wtime();
	cout<<"Tempo da mult com paralelismo: "<<(double)(fim-inicio)<<" segundos"<<endl;
	
	/*for (int i = 0; i < dimensao; ++i){
		for (int j = 0; j <= dimensao; ++j){
			if (j == dimensao)
				cout<<endl;
			else
				cout<<m3[i][j]<<" ";
		}
	}*/
}

int main(int argc, char const *argv[]){
	int dimensao;
	char val = 's';
	while(val == 's'){
		cout<<"Dimensao matriz: ";
		cin>>dimensao;
		multMatrizesSP(dimensao);
		multMatrizesCP(dimensao);
		cout<<"S para continuar: ";
		cin>>val;
	}
	return 0;
}