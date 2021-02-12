#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	char *title; //o tı́tulo do vı́deo;
	char *rating; //a faixa etária sugerida;
	char *ratingLevel; // descrição sobre a restrição da faixa etária;
	char *ratingDescription; //faixa etária numa escala numérica;
	char *releaseYear; //ano de lançamento do vı́deo;
	char *userRatingScore;// nota dos usuários; 
	char *userRatingSize;// tamanho da amostra das notas
} dados;
typedef struct {
	int PG13;
	int TV14;
	int TVPG;
	int TVMA;
	int R;
	int TVY;
	int TVY7;
	int G;
	int NR;
	int PG;
	int TVY7FV;
	int TVG;
	int UR;
} rtg;

typedef struct {
	int rtg_score;
	char* title;
} the_best;

char* tokensep = ";";

void ex1 (dados* filme)
{
	int i = 0, vdd = 0;
	FILE* arq;
	char string[91000];
	arq = fopen("netflix_all.csv", "r");
	fread ( &string, sizeof(char), 91000, arq);
	fclose(arq);
	
	filme[0].title = strtok(string, tokensep);
	filme[0].rating = strtok(NULL, tokensep);
	filme[0].ratingLevel = strtok(NULL, tokensep);
	filme[0].ratingDescription = strtok(NULL, tokensep);
	filme[0].releaseYear = strtok(NULL, tokensep);
	filme[0].userRatingScore = strtok(NULL, tokensep);
	filme[0].userRatingSize = strtok(NULL, tokensep);

	for (i = 1; i < 1001; i++ )
	{
		filme[i].title = strtok(NULL, tokensep);
		filme[i].rating = strtok(NULL, tokensep);
		filme[i].ratingLevel = strtok(NULL, tokensep);
		filme[i].ratingDescription = strtok(NULL, tokensep);
		filme[i].releaseYear = strtok(NULL, tokensep);
		filme[i].userRatingScore = strtok(NULL, tokensep);
		filme[i].userRatingSize = strtok(NULL, tokensep);
	}
	printf ("Você deseja ver todas as variaveis do struct (ex1)... Dgite 0 para não e 1 para sim\n");
	scanf ("%d", &vdd);
	if (vdd == 1)
	{
		for ( i = 1; i < 1001; i++ )
		{
			printf ("%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n", filme[i].title, filme[i].rating, filme[i].ratingLevel, filme[i].ratingDescription, filme[i].releaseYear, filme[i].userRatingScore, filme[i].userRatingSize); 
		}
	}
}	


void ex2ex3 (rtg* year, dados* filme)
{
	int i = 0;
	int atual = 0;
	int total[78];
	int vdd = 0;//variavel TOTAL para resolver o EX3.
	
	for ( i = 0; i < 78; i++ )
	{
		year[i].PG13 = 0;
		year[i].TV14 = 0;
		year[i].TVPG = 0;
		year[i].TVMA = 0;
		year[i].R = 0;
		year[i].TVY = 0;
		year[i].NR = 0;
		year[i].G = 0;
		year[i].TVY7 = 0;
		year[i].PG = 0;
		year[i].TVY7FV = 0;
		year[i].TVG = 0;
		year[i].UR = 0;
		total[i] = 0;
	}
	for (i = 0; i < 1001; i++)
	{
		atual = atoi(filme[i].releaseYear);//com a fucao atoi conseguimos tranformar uma string em um int ... com isso podemos pegar o ano de cada filme e chamar o lanc que corresponde a esse ano. por ex: o lanc que corresponde aos filmes de 2016 = lanc[2016 - 1976] ... 
		if(!(strcmp(filme[i].rating, "PG-13"))) //a funcao strcmp devolve 0 se as duas strings comparadas por ela forem iguias ...
		{	
			year[(atual - 1940)].PG13++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "TV-14")))
		{	
			year[(atual - 1940)].TV14++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "TV-PG")))
		{	
			year[(atual - 1940)].TVPG++;
			total[atual - 1940]++;
		}
		else if(!(strcmp(filme[i].rating, "TV-MA")))
		{
			year[(atual - 1940)].TVMA++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "R")))
		{
			year[(atual - 1940)].R++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "TV-Y")))
		{
			year[(atual - 1940)].TVY++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "NR")))
		{	
			year[(atual - 1940)].NR++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "TV-Y7")))
		{	
			year[(atual - 1940)].TVY7++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "G")))
		{
			year[(atual - 1940)].G++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "TV-Y7-FV")))
		{	
			year[(atual - 1940)].TVY7FV++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "PG")))
		{
			year[(atual - 1940)].PG++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "TV-G")))
		{	
			year[(atual - 1940)].TVG++;
			total[(atual - 1940)]++;
		}
		else if(!(strcmp(filme[i].rating, "UR")))
		{	
			year[(atual - 1940)].UR++;
			total[(atual - 1940)]++;
		}
	}
	
	printf ("Você deseja reseber a printagem dos ratings( ex2 ) ... Digite 0 para não e 1 para sim :\n");
	scanf ("%d", &vdd);
	if ( vdd == 1)
	{
		printf(" Ano ; PG-13 ; TV-14 ; TV-PG ; TV-MA ;  R  ; TV-Y ; NR ; TV-Y7 ;  G  ; PG ; TV-Y7-FV ; TV-G ; UR \n"); 
		for (i = 0; i < 78; i++)
		{
			if (!(total[i] == 0))
			{
				printf("%5d;%7d;%7d;%7d;%7d;%5d;%6d;%4d;%7d;%5d;%4d;%10d;%6d;%4d\n", (1940 + i), year[i].PG13, year[i].TV14, year[i].TVPG, year[i].TVMA, year[i].R, year[i].TVY, year[i].NR, year[i].G, year[i].TVY7, year[i].PG , year[i].TVY7FV, year[i].TVG, year[i].UR);
			}
		}
	}
	printf ("Você deseja reseber a printagem dos totais de filmes postados em cada ano ( ex3 ) ... Digite 0 para não e 1 para sim :\n");
	scanf ("%d", &vdd);
	if ( vdd == 1)
	{
		for (i = 0; i < 78; i++)
		{
			if (!(total[i] == 0))
			{
				printf ("No ano de %d, foram lançados %d filmes\n", (1940 + i), total[i]);
			}
		}
	}
}

void ex4 ( dados* filme )
{
	the_best do_ano[10][78]; // uma coluna para cada ano, cada linha guarda um dos melhores naquele ano.
	the_best aux;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int pontos = 0;
	int atual = 0;
	int vdd = 0;
	
	for ( j = 0; j < 78; j++ )
	{
		for ( i = 0; i < 10; i++ )
		{
			do_ano[i][j].rtg_score = 0;
			do_ano[i][j].title = "vazio";
		}
	}
	for ( k = 0; k < 1001; k++ )
	{
		pontos = atoi (filme[k].userRatingScore);
		atual = atoi (filme[k].releaseYear);
		if (pontos > do_ano[9][(atual - 1940)].rtg_score)
		{
			do_ano[9][(atual - 1940)].rtg_score = atoi (filme[k].userRatingScore);
			do_ano[9][(atual - 1940)].title = filme[k].title;
			for (i = 0; i < 10; i++)
			{
				for (j = (i + 1); j < 10; j++)
				{
					if (do_ano[i][(atual - 1940)].rtg_score < do_ano[j][(atual - 1940)].rtg_score)
					{
						aux.rtg_score = do_ano[i][(atual - 1940)].rtg_score;
						aux.title = do_ano[i][(atual - 1940)].title;
						do_ano[i][(atual - 1940)].rtg_score = do_ano[j][(atual - 1940)].rtg_score;
						do_ano[i][(atual - 1940)].title = do_ano[j][(atual - 1940)].title;
						do_ano[j][(atual - 1940)].rtg_score = aux.rtg_score;
						do_ano[j][(atual - 1940)].title = aux.title;
					}
				}
			}		
		}
	}
	
	
	printf ("Você deseja receber a printagem dos 10 melhores filmes(ex4) ... digite 0 para naõ e 1 para sim:\n");
	scanf ("%d", &vdd);
	
	if (vdd == 1)
	{
		for ( j = 0; j < 78; j++ )
		{
			printf ("Ano %d:\n", (1940 + j));
			for ( i = 0; i < 10; i++ )
			{
				if (! (do_ano[i][j].rtg_score == 0))
				{
					printf ("%d colocado: %s, rating score: %d\n", (i + 1), do_ano[i][j].title, do_ano[i][j].rtg_score);
				}
			}
			printf ("\n");
		}
	}
}

void ex5 (dados* filme)
{
	int i = 0;
	int vdd = 0;
	int violent = 0;
	int sexual_content = 0;
	int violence = 0;
	int soma = 0;
	char *result;
	char *strtest1 = "violent";
	char *strtest2 = "sexual content";
	char *strtest3 = "violence";
	
	for ( i = 0; i < 1001; i++ )
	{
		result = strstr(filme[i].ratingLevel , strtest1);// essa funcao strstr pode achar uma string dentro de outra string.
		if (!(result == NULL))
		{
			violent++;
		}
		result = strstr(filme[i].ratingLevel , strtest2);
		if (!(result == NULL))
		{
			sexual_content++;
		}

		result = strstr(filme[i].ratingLevel , strtest3);
		if (!(result == NULL))
		{
			violence++;
		}
	}
	soma = violent + violence;
	printf("Voce eseja ver os a quantidade de filmes clasificados como violent ou sexual contente (ex5) ... digite 0 para nao e 1 para sim: \n");
	scanf ("%d", &vdd);
	if ( vdd = 1 )
	{
		printf("Filmes com 'violent' ou 'violence' no ratingDscripition: %d \n ", soma);
		printf("Filmes com 'sexual content' no ratingDescripition: %d \n", sexual_content);	
	}
}	
int main()
{
	setlocale (LC_ALL, "Portuguese");
	dados filme[1001]; 
	rtg year[78];//para cada ano , teremos uma variavel do tipo rtg ... year[0] = 1940 (ano mais antigo que existe um fime) ... year[77] = 2017(ano mais novo que existe um filme).

	ex1 (&filme[0]);
	
	ex2ex3 (&year[0], &filme[0]);

	ex4 (&filme[0]);
	
	ex5 (&filme[0]);

	return 0;
} 
