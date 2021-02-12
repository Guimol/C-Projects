#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_ARQ 6

int comparacoes_chaves = 0;
int movimentacoes = 0;

typedef struct{
	char entrada[12];
}Dados;

int LerArquivo();
void InsercaoDireta();
void InsercaoBinaria();
void Selecao();
void BubbleSort();
void heapify();
void HeapSort();
void merge();
void mpass();
void MergeSort();
void Qsort();
void QuickSort();

int main(){
	FILE* arq[NUM_ARQ];
	int i, j, opcao = 0, opcao2, ler = -1;
	int tam[NUM_ARQ];
	Dados *dados;
	
	arq[1] = fopen("mes_1.txt", "r");
	arq[2] = fopen("mes_2.txt", "r");
	arq[3] = fopen("mes_3.txt", "r");
	arq[4] = fopen("mes_4.txt", "r");
	arq[5] = fopen("mes_5.txt", "r");
	
	for( i = 1; i < NUM_ARQ; i++ ){
		fseek(arq[i], 0L, SEEK_END);
		tam[i] = ftell(arq[i]);
		fseek(arq[i], 0L, SEEK_SET);
		fclose(arq[i]);
	}
	
	do{
		printf("\n\nMetodos de Ordenacao:\n");
		printf("1- Insercao Direta;\n2- Insercao Binaria;\n3- Selecao;\n4- BubbleSort;\n5- HeapSort;\n6- Fusao;\n7- QuickSort.\n");
		printf("\nEscolha um dos metodos: ");
		scanf("%d%*c", &opcao);
	}
	while( opcao < 1 || opcao > 7 );
		
	switch(opcao){
		
		case 1:	do{
					printf("Que arquivo deseja ordenar(1 ate 5) ? ");
					scanf("%d", &ler);
				}while(ler < 0 || ler > 5);
				dados = (Dados*)malloc( tam[ler] * (sizeof(Dados)));
				tam[ler] = LerArquivo( dados, ler );
				InsercaoDireta( dados, tam[ler] );
				printf("Deseja ver uma parte do vetor ordenado( vinte primeiros elementos )?\n1-Sim\n2-Nao\n");
				scanf("%d", &opcao2);
				if( opcao2 == 1 ){
					for(j = 1; j <= 20; j++ ){
						printf("\nteste %d: %s", j, dados[j].entrada);
					}
				}
				printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes_chaves, movimentacoes);
				free(dados);
				break;
				
		case 2: do{
					printf("Que arquivo deseja ordenar(1 ate 5) ? ");
					scanf("%d", &ler);
				}while(ler < 0 || ler > 5);
				dados = (Dados*)malloc( tam[ler] * (sizeof(Dados)));
				tam[ler] = LerArquivo( dados, ler );
				InsercaoBinaria( dados, tam[ler] );
				printf("Deseja ver uma parte do vetor ordenado( vinte primeiros elementos )?\n1-Sim\n2-Nao\n");
				scanf("%d", &opcao2);
				if( opcao2 == 1 ){
					for(j = 1; j <= 20; j++ ){
						printf("\nteste %d: %s", j, dados[j].entrada);
					}
				}
				printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes_chaves, movimentacoes);
				free(dados);
				break;
				
		case 3: do{
					printf("Que arquivo deseja ordenar(1 ate 5) ? ");
					scanf("%d", &ler);
				}while(ler < 0 || ler > 5);
				dados = (Dados*)malloc( tam[ler] * (sizeof(Dados)));
				tam[ler] = LerArquivo( dados, ler );
				Selecao( dados, tam[ler] );
				printf("Deseja ver uma parte do vetor ordenado( vinte primeiros elementos )?\n1-Sim\n2-Nao\n");
				scanf("%d", &opcao2);
				if( opcao2 == 1 ){
					for(j = 1; j <= 20; j++ ){
						printf("\nteste %d: %s", j, dados[j].entrada);
					}
				}
				printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes_chaves, movimentacoes);
				free(dados);
				break;
				
		case 4: do{
					printf("Que arquivo deseja ordenar(1 ate 5) ? ");
					scanf("%d", &ler);
				}while(ler < 0 || ler > 5);
				dados = (Dados*)malloc( tam[ler] * (sizeof(Dados)));
				tam[ler] = LerArquivo( dados, ler );
				BubbleSort( dados, tam[ler] );
				printf("Deseja ver uma parte do vetor ordenado( vinte primeiros elementos )?\n1-Sim\n2-Nao\n");
				scanf("%d", &opcao2);
				if( opcao2 == 1 ){
					for(j = 1; j <= 20; j++ ){
						printf("\nteste %d: %s", j, dados[j].entrada);
					}
				}
				printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes_chaves, movimentacoes);
				free(dados);
				break;
				
		case 5:	do{
					printf("Que arquivo deseja ordenar(1 ate 5) ? ");
					scanf("%d", &ler);
				}while(ler < 0 || ler > 5);
				dados = (Dados*)malloc( tam[ler] * (sizeof(Dados)));
				tam[ler] = LerArquivo( dados, ler );
				HeapSort( dados, tam[ler] );
				printf("Deseja ver uma parte do vetor ordenado( vinte primeiros elementos )?\n1-Sim\n2-Nao\n");
				scanf("%d", &opcao2);
				if( opcao2 == 1 ){
					for(j = 1; j <= 20; j++ ){
						printf("\nteste %d: %s", j, dados[j].entrada);
					}
				}
				printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes_chaves, movimentacoes);
				free(dados);
				break;
				
		case 6: do{
					printf("Que arquivo deseja ordenar(1 ate 5) ? ");
					scanf("%d", &ler);
				}while(ler < 0 || ler > 5);
				dados = (Dados*)malloc( tam[ler] * (sizeof(Dados)));
				tam[ler] = LerArquivo( dados, ler );
				MergeSort( dados, tam[ler] );
				printf("Deseja ver uma parte do vetor ordenado( vinte primeiros elementos )?\n1-Sim\n2-Nao\n");
				scanf("%d", &opcao2);
				if( opcao2 == 1 ){
					for(j = 1; j <= 20; j++ ){
						printf("\nteste %d: %s", j, dados[j].entrada);
					}
				}
				printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes_chaves, movimentacoes);
				free(dados);
				break;
				
		case 7: do{
					printf("Que arquivo deseja ordenar(1 ate 5) ? ");
					scanf("%d", &ler);
				}while(ler < 0 || ler > 5);
				dados = (Dados*)malloc( tam[ler] * (sizeof(Dados)));
				tam[ler] = LerArquivo( dados, ler );
				QuickSort( dados, tam[ler] );
				printf("Deseja ver uma parte do vetor ordenado( vinte primeiros elementos )?\n1-Sim\n2-Nao\n");
				scanf("%d", &opcao2);
				if( opcao2 == 1 ){
					for(j = 1; j <= 20; j++ ){
						printf("\nteste %d: %s", j, dados[j].entrada);
					}
				}
				printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes_chaves, movimentacoes);
				free(dados);
				break;
				
		default: printf("\nERRO!\n");
				 exit(0);
	}
	printf("\nObrigado :D\nFeito por: Guilherme Martiniano de Oliveira, 11215765\n           Mateus Miquelino da Silva, 11208412");
}

int LerArquivo( Dados *dados, int mes ){
	int i = 1, linhas = 0;
	char aux[12];
	FILE* arq[NUM_ARQ];
	
	arq[1] = fopen("mes_1.txt", "r");
	arq[2] = fopen("mes_2.txt", "r");
	arq[3] = fopen("mes_3.txt", "r");
	arq[4] = fopen("mes_4.txt", "r");
	arq[5] = fopen("mes_5.txt", "r");
	
	
	while( !feof(arq[mes]) ){
		fgets(aux, sizeof(aux), arq[mes]);
		strcpy(dados[i].entrada, aux);
		i++;
		linhas++;
	}
	
	for( i = 1; i < NUM_ARQ; i++ ){
		fclose(arq[i]);
	}
	
	return linhas;
}

void InsercaoDireta(Dados *dados, int tam){
	int i = 0, j = 0;
	Dados *a;
	Dados x;
	
	a = (Dados*)malloc( tam * (sizeof(Dados)));

	for ( i = 1; i <= tam; i++) {
		a[i] = dados[i];
		movimentacoes++;
	}
	

	for ( i = 2; i <= tam; i++) {

		x = a[i];
		a[0] = x;
		j = i;
		
		movimentacoes+=2;

		while( strcmp(x.entrada, a[j - 1].entrada) < 0 ) {
			comparacoes_chaves++;
			
			a[j] = a[j - 1];
			j = j - 1;
			
			movimentacoes++;
		}
		comparacoes_chaves++;
		
		a[j] = x;
		
		movimentacoes++;
	}

	for ( i = 1; i <= tam; i++) {
		dados[i] = a[i];
		movimentacoes++;
	}
}

void InsercaoBinaria(Dados *dados, int tam) {

	Dados x;
	int L, R, m,j;
	int i;
	
	for ( i = 1; i < tam; i++ ) {

		x = dados[i];
		
		movimentacoes++;
		
		L = 1;
		R = i;

		while (L < R) {

			m = (L + R) / 2;
			
			comparacoes_chaves++;

			if (strcmp(dados[m].entrada, x.entrada) < 0) {

				L = m + 1;
			}
			else {
				R = m;
			}
		}
		j = i;

		while (j > R) {

			dados[j] = dados[j - 1];
			
			movimentacoes++;
			
			j = j - 1;
		}
		dados[R] = x;
		
		movimentacoes++;
	}
}

void Selecao(Dados *dados, int tam) {

	int indice_menor;
	Dados aux;
	int i, j;

	for ( i = 0; i < tam; i++ ) {

		indice_menor = i;

		for ( j = i + 1; j < tam; j++ ) {
			
			comparacoes_chaves++;

			if (strcmp(dados[j].entrada , dados[indice_menor].entrada) < 0) {

				indice_menor = j;
			}
		}

		aux = dados[i];
		dados[i] = dados[indice_menor];
		dados[indice_menor] = aux;
		
		movimentacoes+=2;
		
	}
}

void BubbleSort(Dados *dados, int tam) {
	Dados aux;
	int i, j;

	for ( i = 1; i < tam; i++ ) {
		for ( j = tam - 1; j > i; j = j - 1) {
			
			comparacoes_chaves++;
			
			if ( strcmp(dados[j - 1].entrada, dados[j].entrada) > 0 ) {

				aux = dados[j - 1];
				dados[j - 1] = dados[j];
				dados[j] = aux;
				
				movimentacoes+=2;
			}
		}
	}
}

void heapify(Dados *a, int L, int R) {
	
	int i = L;
	int j = 2 * L;
	Dados x = a[L];
	
	movimentacoes++;
	
	comparacoes_chaves++;
	
	if ((j < R) && strcmp(a[j].entrada, a[j + 1].entrada) < 0) {

		j++;
	}

	while ((j <= R) && strcmp(x.entrada, a[j].entrada) < 0) {
		comparacoes_chaves++;
		
		a[i] = a[j];
		
		movimentacoes++;
		
		i = j;
		j = j * 2;

		comparacoes_chaves++;
		
		if ((j < R) && strcmp(a[j].entrada, a[j + 1].entrada) < 0) {

			j++;
		}
	}
	if( j <= R ){
		comparacoes_chaves++;
	}	
	a[i] = x;
	
	movimentacoes++;

}

void HeapSort(Dados *dados, int tam) {
	Dados *a, aux;
	int L, R, i;
	
	a = (Dados*)malloc( (tam + 1) * (sizeof(Dados)));

	for ( i = 0; i < tam; i++ ) {
		a[i + 1] = dados[i];
		movimentacoes++;
	}

	for (L = tam / 2; L >= 1; L = L - 1) {
		heapify(a, L, tam);
	}

	for (R = tam; R >= 2; R = R - 1) {
		aux = a[1];
		a[1] = a[R];
		a[R] = aux;
		movimentacoes+=2;
		heapify(a, 1, R - 1);
	}

	for ( i = 0; i < tam; i++ ) {
		dados[i] = a[i + 1];
		movimentacoes++;
	}
}

void merge(Dados *a, int L, int h, int R,Dados *c) {
	int i = L;
	int j = h + 1;
	int k = L - 1;

	while (i <= h && j <= R) {
		k++;
		
		comparacoes_chaves++;
		
		if (strcmp(a[i].entrada, a[j].entrada) < 0) {
			c[k] = a[i];
			movimentacoes++;
			i++;
		}
		else {
			c[k] = a[j];
			movimentacoes++;
			j++;
		}
	}
	while (i <= h) {
		k++;
		c[k] = a[i];
		movimentacoes++;
		i++;
	}
	while (j <= R) {
		k++;
		c[k] = a[j];
		movimentacoes++;
		j = j + 1;
	}
}

void mpass( Dados *a, int N, int p, Dados *c ) {
	
	int  i, j;
	i = 1;

	while (i <= N - 2 * p + 1) {

		merge(a, i, i + p - 1, i + 2 * p - 1, c);

		i = i + 2 * p;
	}

	if (i + p - 1 < N) {

		merge(a, i, i + p - 1, N, c);

	}else {
		for (j = i; j <= N; j++){
			c[j] = a[j];
			movimentacoes++;
		}
	}
}

void MergeSort(Dados *dados, int tam) {
	Dados *a, *c;
	int i, p = 1;
	
	a = (Dados*)malloc( (tam + 1) * (sizeof(Dados)));
	c = (Dados*)malloc( (tam + 1) * (sizeof(Dados)));

	for( i = 0; i < tam; i++ ) {
		a[i + 1] = dados[i];
		movimentacoes++;
	}

	while (p < tam) {

		mpass(a, tam, p, c);

		p = 2 * p;

		mpass(c, tam, p, a);

		p = 2 * p;
	}

	for ( i = 0; i < tam; i++ ) {
		dados[i] = a[i + 1];
		movimentacoes++;
	}
}

void Qsort(Dados *a, int L, int R) {
	int i = L;
	int j = R;
	Dados x, aux;
	
	x =  a[(L + R) / 2];
	movimentacoes++;

	do {
		while (strcmp(a[i].entrada, x.entrada) < 0) {
			comparacoes_chaves++;
			i++;
		}
		comparacoes_chaves++;

		while (strcmp(x.entrada, a[j].entrada) < 0) {
			comparacoes_chaves++;
			j--;
		}
		comparacoes_chaves++;

		if (i <= j) {
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			
			movimentacoes+=2;

			i++;
			j--;
		}
	} while (i <= j);
	
	if (L < j) {
		Qsort(a, L, j);
	}
	if (i < R) {
		Qsort(a, i, R);
	}
}

void QuickSort( Dados *dados, int tam ){
	Qsort( dados, 1, tam );
	
}