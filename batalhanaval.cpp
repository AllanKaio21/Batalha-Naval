#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define n 10

int i, i2, j, a;
char TJ[n][n];
char TP[n][n];

int Gabarito()
{
	printf("\n\nGABARITO\n\n  ");
	for(i=1;i<=n;i++)
	{
		printf("  %d",i);
	}
	
	
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("\n%d",i);
		if(i<10)
		{
			printf(" ");
		}
		for(j=1;j<=n;j++)
		{
			printf("  %c",TP[i][j]);
		}
	}
}
int Resultado(int acerto, int erro)
{
	if(acerto==17)
	{
		printf("\n\nVoce Ganhou!\n");
		i2=25;	
	}
	if(erro==25)
	{
		printf("\n\nVoce Perdeu!\n");
	}
}

int MostrarJogo()
{
	printf("\n  -----===Batalha Naval===-----\n\n");
	printf("  ");
	for(i=1;i<=n;i++)
	{
		printf("  %d",i);
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("\n%d",i);
		if(i<10)
		{
			printf(" ");
		}
		for(j=1;j<=n;j++)
		{
			printf("  %c",TJ[i][j]);
		}
	}
}

int Tiro()
{
	int linha, coluna, CR;
	int ac=0, err=0, nr=17;
	for(i2=1; i2<=25; i2++)
	{
		printf("\n\nLinha: ");
		scanf("%d",&linha);
		printf("\nColuna: ");
		scanf("%d",&coluna);
		printf("\n\n");
		system("clear");
		if(TJ[linha][coluna]=='~')
		{
			if(TP[linha][coluna]=='w')
			{
				printf("\nAcertou!\n");
				TJ[linha][coluna]='X';
				printf("Posicao(%d, %d)\n",linha,coluna);
				ac++;
				nr-=1;
			}
			else
			{
				printf("\nTiro na agua!\n");
				TJ[linha][coluna]='O';
			}
		}
		else
		{
			printf("\nDigite valor valido!\n");
			i2--;
		}
		err=i2;
		CR=25-i2;
		printf("Navios Restantes: %d\n",nr);
		printf("Chances Restantes: %d\n\n",CR);
		MostrarJogo();	
		Resultado(ac, err);

	}
}

int Posicionar()
{
	srand(time(NULL));
	
	//Navio de tamanho 4/
	j=(rand()%n)+1;
	i=(rand()%n)+1;
	if(j>=10)
	{
		j=j-4;
	}
	if(j>6)
	{
		j=j-3;
	}
	TP[i][j]='w';
	TP[i][j+1]='w';
	TP[i][j+2]='w';
	TP[i][j+3]='w';
	
	//Navio de tamanho 3/
	for(a=1;a<=2;a++)
	{
		j=(rand()%n)+1;
		i=(rand()%n)+1;
		if(j>=10)
			j=j-3;
			
		if(j>=8)
			j=j-2;
			
		if((TP[i][j]!='w')&&(TP[i][j+1]!='w')&&(TP[i][j+2]!='w')&&(TP[i][j-1]!='w'))
		{
			TP[i][j]='w';
			TP[i][j+1]='w';
			TP[i][j+2]='w';
		}
		else
			a=a-1;
	}
	
	//Navio de tamanho 2/
	for(a=1; a<2; a++)
	{
		j=(rand()%n)+1;
		i=(rand()%n)+1;
		if(j>=10)
			j=j-2;
		if(j==9)
			j=j-1;
		if((TP[i][j]!='w')&&(TP[i][j+1]!='w')&&(TP[i][j-1]!='w'))
		{
			TP[i][j]='w';
			TP[i][j+1]='w';
		}
		else
		{
			a=a-1;
		}
	}

	//Navio de tamanho 1/
	for(a=1;a<=5;a++)
	{
		j=(rand()%n)+1;
		i=(rand()%n)+1;
		if((TP[i][j]!='w')&&(TP[i][j-1]!='w')&&(TP[i][j+1]!='w'))
		{
			TP[i][j]='w';		
		}
		else
		{
			a=a-1;
		}
	}
}

int main()
{
	int play=0;
	do{
		printf("\n  -----===Batalha Naval===-----\n\n");
		printf("  ");
		for(i=1;i<=n;i++)
		{
			printf("  %d",i);
		}
		printf("\n");
		for(i=1;i<=n;i++)
		{
			printf("\n%d",i);
			if(i<10)
			{
				printf(" ");
			}
			for(j=1;j<=n;j++)
			{
				TJ[i][j]='~';
				TP[i][j]='~';
				printf("  %c",TJ[i][j]);
			}
		}
  		Posicionar();
        //Gabarito();
  		Tiro();
  		printf("\n\nDigite 1 para jogar novamente ou 0 para sair: ");
		scanf("%d",&play);
		system("clear");
	}while(play==1);
	return(0);
}
