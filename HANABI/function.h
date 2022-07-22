#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h> //include do set locale
#include <string.h>

//auxiliar para funcao random (apontador)
swap(int *a, int *b) 
	{
	    int aux = *a;
	    *a = *b;
	    *b = aux;
	}
//funcao baralhar as cores e numeros dos arrays
void random(int arr[], int n) 
	{
	    srand(time(NULL));
	    int i;
	    for(i = n-1; i > 0; i--) 
		{
	        int j = rand() % (i+1);
	        swap(&arr[i], &arr[j]);
    	}
	}
//funcao escolher primeiro a jogar	
int first(int primeiro) 
	{
	    srand(time(NULL));
	    primeiro = rand() %2 +1;
	    
    	return primeiro;
	}
//coloca o Cursor na posicao X,Y
void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//cor das cartas
void setColor(int x, int y, int foreGround, int backGround) 
	{
		int i,j;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backGround*16 + foreGround);
		gotoxy(x, y);
		for (i = y; i < 11 + y; i++)
		{
			for (j = x; j < 15 + x; j++)
			{
				gotoxy(j, i);
				printf("%c", 186);
			}
		} 
	}
//reset cor
void resetColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 15);
}
//acao do jogador
int acaojog(int acao,char jog1[17],int pistas,int total)
{
int flag=-1;	
	do
		{int check=1;
			printf("Insira o n�mero da a��o que pretende fazer, %s:\n",jog1);
			printf("1-dar informa��o; 2-descartar carta; 3-jogar carta: ");
			check=scanf("%d",&acao);
			if(acao>3 || check==0)
			{
			printf("Inseriu um valor errado.\n\n");
			flag=0;	
			}
			else if(acao==1 && pistas <1)
			{
				printf("N�o pode dar informa��o, pois j� n�o tem pistas.\n\n");
				flag=0;
			}
			else if(acao==2 && pistas==8)
			{
				printf("N�o pode descartar uma carta, pois tem todas as pistas.\n\n");
				flag=0;
			}
			else if(acao==2 && total==0)
			{
				printf("N�o pode descartar uma carta, pois n�o pode buscar mais � compra.\n\n");
				flag=0;
			}
			
		}while(flag==0);
	return acao;
}
//desenha um retangulo com linhas duplas na posicao X,Y com as dimensoes Width e Height 
void drawRect(int x, int y, int width, int height)
{
	setlocale(LC_ALL, "C");
	int i;
	gotoxy(x, y);
	printf("%c", 201);
	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}

	printf("%c", 187);
	gotoxy(x, height + y);
	printf("%c", 200);

	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}

	printf("%c", 188);

	for (i = y + 1; i < height + y; i++)
	{
		gotoxy(x, i);
		printf("%c", 186);

		gotoxy(x + width, i);
		printf("%c", 186);
	} 
	setlocale(LC_ALL, "");
}
//colorir as cartas
int color(char cor[])
{
	if(strcmp(cor,"branco")==0)
	return 15;
	else if(strcmp(cor,"amarelo")==0)
	return 6;
	else if(strcmp(cor,"vermelho")==0)
	return 4;
	else if(strcmp(cor,"azul")==0)
	return 3;
	else if(strcmp(cor,"verde")==0)
	return 2;
	else
	return 28;	 
}
//menu inicial
void menu(char jog1[17])
{
	system("MODE con cols=156 lines=100");
	system("title Hanabi v1.3");
	setlocale(LC_ALL, ""); 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	drawRect(78,3,9,2); 
	gotoxy(80,4);
	SetConsoleTextAttribute(hConsole, 4);  	printf("H");	SetConsoleTextAttribute(hConsole, 6);	printf("a");	SetConsoleTextAttribute(hConsole, 3);	printf("n");
	SetConsoleTextAttribute(hConsole, 2);	printf("a");	SetConsoleTextAttribute(hConsole, 7);	printf("b");	SetConsoleTextAttribute(hConsole, 4);	printf("i\n\n\n");
	SetConsoleTextAttribute(hConsole, 15);
	
	printf("Criado por: Rui Duarte\n\n");
	printf("Clique em alguma tecla para continuar...\n\n");  
	_getch();	
	
	char escolha,ver;
	printf("Selecione uma das op��es: \n\n");
	do
	{
		printf("A. Jogar uma Partida de Hanabi\n"); 
		printf("B. Carregar uma partida a partir de ficheiro\n"); 
		printf("C. Apresentar uma descri��o do jogo na consola\n"); 
		printf("D. Sair da aplica��o.\n");  
		scanf("%s",&escolha);
		ver=toupper(escolha);
		if((ver!='A') && (ver!='B') && (ver!='C') && (ver!='D'))
			{printf("Inseriu um valor errado.\n\n");}
		if(ver=='C')
		{
			printf("�Componentes:\n- 50 Cartas Hanabi\n- 8 Cartas de Dica\n- 3 Cartas de Penalidade\n\n");
			printf("�Objetivo do jogo:\nHanabi � um jogo cooperativo, isso significa que os jogadores n�o competem uns contra os outros, mas sim trabalham em conjunto em busca de um objetivo.\nNeste jogo, os jogadores s�o fabricantes de fogos de artif�cio que, acidentalmente, misturaram suas p�lvoras, corantes e foguetes.\nO festival vai come�ar e o p�nico toma conta de todos. Eles tem que trabalhar juntos para impedir que o show seja um desastre!\nOs pirot�cnicos devem juntar as 5 cores de fogos de artif�cio diferentes (branco, vermelho, azul, amarelo e verde),\ncolocando-os em s�rie (1, 2, 3, 4 e 5) dentro de suas cores.\n\n");
			printf("�Prepara��o:\nSepare as 5 cartas multicolores, elas ser�o usadas somente para a expans�o.\nColoque as 8 cartas de dica ao lado da pilha de compras e as 3 cartas de penalidade em baixo da caixa do jogo.\nEmbaralhe as 50 cartas Hanabi e coloque-as viradas para baixo, formando uma pilha de compras. Distribua as 5 cartas para cada jogador.\n\n");
			printf("�Importante:\nOs jogadores n�o devem olhar as cartas que recebem!\nCada um pega suas pr�prias cartas de uma maneira que os outros jogadores conseguem ver a carta, mas ele pr�prio n�o consegue!\nOs jogadores n�o podem olhar suas pr�prias cartas durante todo o jogo. Isso significaria uma desonra.\n\n");
			printf("�O Jogo:\nO jogador com as roupas mais coloridas deve come�ar o jogo. Os jogadores ent�o fazem sua jogada e o jogo sempre segue no sentido hor�rio.\nEm seu turno, um jogador deve realizar uma, e somente uma das tr�s a��es abaixo (voc� n�o pode pular sua vez):\n-Dar uma informa��o.\n-Descartar uma carta.\n-Jogar uma carta.\n\nNota : Quando � a vez de um jogador, seus colegas n�o podem comentar nada ou tentar influenci�-lo.\n\n");
			printf("�Dar uma informa��o:\nPara realizar esta a��o, o jogador deve retornar uma carta de dica para dentro da caixa do jogo.\nAgora ele pode passar uma informa��o a um dos colegas, sobre as cartas que est�o na m�o daquele colega.\nImportante:\nO jogador deve apontar claramente para a carta sobre a qual est� dando informa��o.\nDois tipos de informa��es podem ser passados:\n-Informa��es sobre uma cor (somente uma).\n-Informa��es sobre um n�mero (somente um).\nImportante:\nO jogador deve dar uma informa��o completa: Se o seu colega possui duas cartas verdes, o jogador n�o pode apontar somente uma delas!\nNota:\nEsta a��o s� pode ser realizada se existirem cartas de dica dispon�veis ao lado da pilha de compras.\nSe todas as cartas de dica estiverem dentro da caixa do jogo, o jogador deve escolher outra a��o.\n\n");
			printf("�Descartar uma carta:\nPara realizar essa a��o, o jogador deve tirar uma carta de dica de dentro da caixa do jogo e coloc�-la ao lado da pilha de compras.\nEnt�o, o jogador descarta uma carta de sua m�o e a coloca na pilha de descartes (ao lado da pilha de compras, com a face virada para cima).\nDepois o jogador compra uma nova carta da pilha de compras e a coloca em sua m�o, sem ver seu conte�do!\nNota:\nEsta a��o s� pode ser realizada se existirem cartas de dica dentro da caixa do jogo.\nSe todas as cartas de dica estiverem ao lado da pilha de compras, o jogador deve escolher outra a��o.\n\n");
			printf("�Jogar uma carta:\nO jogador pega uma carta de sua m�o e a coloca em sua frente.\nDuas op��es s�o poss�veis:\nA carta inicia ou continua uma sequ�ncia de fogos, e ent�o � adicionada aos fogos.\nA carta revelada n�o se encaixa em nenhuma sequ�ncia de fogos:\nEla � descartada e uma carta de penalidade (com o foguete) � retirada debaixo da caixa do jogo.\n\n\n");
		
		}
		
	}while(ver!='A' && ver!='B' && (ver=='C' || ver!='C') && ver!='D');
	if(ver=='A')
	{
		//Inserir o nome do jogador
		printf("\nInsira o nome do jogador: ");
		scanf("%s",jog1);
		printf("\nA iniciar...\n");
		sleep(1);
		system("cls");
	}
	if(ver=='B')
			printf("\nA retomar...\n");
			sleep(1);
			system("cls");
	if(ver=='D')
	{
		printf("A sair...");
		sleep(1);
		exit(0);
	}
}
//estrutura cartas bot
void cartasBot(char corbot[5][10],char numbot[5][10])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//cartas bot;
		setColor(2,1,color(corbot[0]),color(corbot[0]));
		gotoxy(8,6);
		SetConsoleTextAttribute(hConsole, 15);
		printf("%s",numbot[0]);
		setColor(20,1,color(corbot[1]),color(corbot[1]));
		gotoxy(26,6);
		SetConsoleTextAttribute(hConsole, 15);
		printf("%s",numbot[1]);
		setColor(38,1,color(corbot[2]),color(corbot[2]));
		gotoxy(44,6);
		SetConsoleTextAttribute(hConsole, 15);
		printf("%s",numbot[2]);
		setColor(56,1,color(corbot[3]),color(corbot[3]));
		gotoxy(62,6);
		SetConsoleTextAttribute(hConsole, 15);
		printf("%s",numbot[3]);
		setColor(74,1,color(corbot[4]),color(corbot[4]));
		gotoxy(80,6);
		SetConsoleTextAttribute(hConsole, 15);
		printf("%s",numbot[4]);
		resetColor();
		drawRect(41,12,8,2); //caixa para nome do bot
		gotoxy(44,13); //nome dentro da caixa
		printf("Bot");	
}
//estrutura cartas jogador
void cartasJog(char corjog1[5][10],char numjog1[5][10], char jog1[17])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//cartas jog
		setColor(2,16,8,8);
		gotoxy(6,21);
		SetConsoleTextAttribute(hConsole, 4);  	printf("H");	SetConsoleTextAttribute(hConsole, 6);	printf("a");	SetConsoleTextAttribute(hConsole, 3);	printf("n");
		SetConsoleTextAttribute(hConsole, 2);	printf("a");	SetConsoleTextAttribute(hConsole, 7);	printf("b");	SetConsoleTextAttribute(hConsole, 4);	printf("i\n\n\n");
		SetConsoleTextAttribute(hConsole, 143);
		drawRect(4,20,9,2); 
		setColor(20,16,8,8);
		gotoxy(24,21);
		SetConsoleTextAttribute(hConsole, 4);  	printf("H");	SetConsoleTextAttribute(hConsole, 6);	printf("a");	SetConsoleTextAttribute(hConsole, 3);	printf("n");
		SetConsoleTextAttribute(hConsole, 2);	printf("a");	SetConsoleTextAttribute(hConsole, 7);	printf("b");	SetConsoleTextAttribute(hConsole, 4);	printf("i\n\n\n");
		SetConsoleTextAttribute(hConsole, 143);
		drawRect(22,20,9,2); 
		setColor(38,16,8,8);
		gotoxy(42,21);
		SetConsoleTextAttribute(hConsole, 4);  	printf("H");	SetConsoleTextAttribute(hConsole, 6);	printf("a");	SetConsoleTextAttribute(hConsole, 3);	printf("n");
		SetConsoleTextAttribute(hConsole, 2);	printf("a");	SetConsoleTextAttribute(hConsole, 7);	printf("b");	SetConsoleTextAttribute(hConsole, 4);	printf("i\n\n\n");
		SetConsoleTextAttribute(hConsole, 143);
		drawRect(40,20,9,2); 
		setColor(56,16,8,8);
		gotoxy(60,21);
		SetConsoleTextAttribute(hConsole, 4);  	printf("H");	SetConsoleTextAttribute(hConsole, 6);	printf("a");	SetConsoleTextAttribute(hConsole, 3);	printf("n");
		SetConsoleTextAttribute(hConsole, 2);	printf("a");	SetConsoleTextAttribute(hConsole, 7);	printf("b");	SetConsoleTextAttribute(hConsole, 4);	printf("i\n\n\n");
		SetConsoleTextAttribute(hConsole, 143);
		drawRect(58,20,9,2); 
		setColor(74,16,8,8);
		gotoxy(78,21);
		SetConsoleTextAttribute(hConsole, 4);  	printf("H");	SetConsoleTextAttribute(hConsole, 6);	printf("a");	SetConsoleTextAttribute(hConsole, 3);	printf("n");
		SetConsoleTextAttribute(hConsole, 2);	printf("a");	SetConsoleTextAttribute(hConsole, 7);	printf("b");	SetConsoleTextAttribute(hConsole, 4);	printf("i\n\n\n");
		SetConsoleTextAttribute(hConsole, 143);
		drawRect(76,20,9,2); 
		resetColor();
		if(strlen(jog1)>=6)
		{
			drawRect(40,27,strlen(jog1)+3,2); //caixa para nome do jogador
			gotoxy(42,28); //nome dentro da caixa
		}
		else
		{
			drawRect(41,27,strlen(jog1)+5,2); //caixa para nome do jogador
			gotoxy(44,28); //nome dentro da caixa
		}
		printf("%s",jog1);	
}
//estrutura cartas mesa
void mesa()
{
//mesa
		drawRect(2,31,14,10); 
		drawRect(20,31,14,10);
		drawRect(38,31,14,10);
		drawRect(56,31,14,10);
		drawRect(74,31,14,10);
		resetColor();
		drawRect(41,42,7,2); //caixa para nome da mesa
		gotoxy(43,43); //nome dentro da caixa
		printf("Mesa");	
}
//estrutura cartas compra
void compra(int total)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//baralho compra
		setColor(122,16,8,8);
		gotoxy(126,21);
		SetConsoleTextAttribute(hConsole, 4);  	printf("H");	SetConsoleTextAttribute(hConsole, 6);	printf("a");	SetConsoleTextAttribute(hConsole, 3);	printf("n");
		SetConsoleTextAttribute(hConsole, 2);	printf("a");	SetConsoleTextAttribute(hConsole, 7);	printf("b");	SetConsoleTextAttribute(hConsole, 4);	printf("i\n\n\n");
		SetConsoleTextAttribute(hConsole, 143);
		gotoxy(128,18);
		printf("%d",total);
		drawRect(124,20,9,2); 
		resetColor();
		drawRect(124,27,9,2);
		gotoxy(126,28);
		printf("Compra");
}
//estrutura descarte
void descarte(char *tabela[6][6],char *tabela2[6][6],char *tabela3[6][6],char *tabela4[6][6],char *tabela5[6][6],char *tabela6[6][6])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//descarte
		int a,b=1;

		drawRect(116,33,25,7); 
		drawRect(123,41,11,2);
		gotoxy(125,42);
		printf("Descarte");
		 
		for(a=0;a<5;a++)
		{	
		gotoxy(126+3*a,34);
		SetConsoleTextAttribute(hConsole, 14);
		printf("%s",tabela[0][a]);
		gotoxy(117,35);
		SetConsoleTextAttribute(hConsole, 15);
		printf("%s",tabela2[0][0]);
		gotoxy(126+3*a,35);
		printf("%s",tabela2[0][b]);
		gotoxy(117,36);
		SetConsoleTextAttribute(hConsole, 6);
		printf("%s",tabela3[0][0]);
		gotoxy(126+3*a,36);
		printf("%s",tabela2[0][b]);
		gotoxy(117,37);
		SetConsoleTextAttribute(hConsole, 4);
		printf("%s",tabela4[0][0]);
		gotoxy(126+3*a,37);
		printf("%s",tabela2[0][b]);
		gotoxy(117,38);
		SetConsoleTextAttribute(hConsole, 3);
		printf("%s",tabela5[0][0]);
		gotoxy(126+3*a,38);
		printf("%s",tabela2[0][b]);
		gotoxy(117,39);
		SetConsoleTextAttribute(hConsole, 2);
		printf("%s  ",tabela6[0][0]);
		gotoxy(126+3*a,39);
		printf("%s",tabela2[0][b]);
		b=b+1;
		}
		resetColor();	
}
//estrutura vidas
void drawVida(int vidas)
{
	gotoxy(112,2);
	printf("    ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("o  o\n"); 
    resetColor();
    gotoxy(112,3);
    printf(" ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("o        o\n"); 
    gotoxy(112,4);
    printf("o   vida:  o\n"); 
    gotoxy(112,5);
    printf("o     %d    o\n",vidas); 
    resetColor();
    gotoxy(112,6);
    printf(" ");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("o        o\n"); 
    resetColor();
    gotoxy(112,7);
    printf("    ");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
 	printf("o  o\n\n"); 
 	resetColor();
}
//estrutura pistas
void drawPista(int pistas)
{
	gotoxy(132,2);
	printf("    ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    printf("?  ?\n"); 
    resetColor();
    gotoxy(132,3);
    printf(" ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    printf("?        ?\n"); 
    gotoxy(132,4);
    printf("?  pista:  ?\n"); 
    gotoxy(132,5);
    printf("?    %d     ?\n",pistas); 
    resetColor();
    gotoxy(132,6);
    printf(" ");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    printf("?        ?\n"); 
    resetColor();
    gotoxy(132,7);
    printf("    ");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
 	printf("?  ?\n\n"); 
 	resetColor();
}
//guardar dados
void guardar(char jog1[17], int vidas, int pistas,int total,char corbot[5][10],char numbot[5][10],char corjog1[5][10],char numjog1[5][10])
{
	FILE* filept=NULL;
		char name[]="backup.txt";
		int i,j;
		
		filept=fopen(name,"w");
		if(filept==NULL) //ficheiro nao existe ou nao consegue abrir
		exit(0);
		
		fprintf(filept,"Nome:\n%s\n",jog1);
		fprintf(filept,"Vidas:\n%d\nPistas:\n%d\nTotal:\n%d\n",vidas,pistas,total);
		fprintf(filept,"Bot:\n");
		for(i=0;i<5;i++)
		{
		fprintf(filept,"%s %s\n",numbot[i],corbot[i]);
		}
		fprintf(filept,"Jogador:\n");
		for(j=0;j<5;j++)
		{
		fprintf(filept,"%s %s\n",numjog1[j],corjog1[j]);
		}
		fclose(filept);
}
//ler dados jog
void lerjog(char jog1[17])
{
		FILE *fileler=NULL;
		char name[]="backup.txt", lerv[120];
		int count = 0;
		fileler=fopen(name,"r");
		
		if(fileler==NULL) //ficheiro nao existe ou nao consegue abrir
		printf("Erro de abertura");
	while (fgets(lerv,sizeof lerv,fileler) != NULL)
      {			
			if (count==1)
	        strcpy(jog1,lerv);
	        else
	        count++;
		}
		fclose(fileler);
}
//ler dados vidas
int lervida(int vidas)
{
	FILE *fileler=NULL;
		char name[]="backup.txt", lerv[120];
		fileler=fopen(name,"r");
		int count=0;
		if(fileler==NULL) //ficheiro nao existe ou nao consegue abrir
		printf("Erro de abertura");
	while (fgets(lerv,sizeof lerv,fileler) != NULL)
      {			
			if (count==3)
	        {
	        	sscanf(lerv, "%d", &vidas);
	        	return vidas;
	   		 }
	         count++;
		}
		fclose(fileler);
}
//ler dados pistas
int lerpista(int pistas)
{
	FILE *fileler=NULL;
		char name[]="backup.txt", lerv[120];
		fileler=fopen(name,"r");
		int count=0;
		if(fileler==NULL) //ficheiro nao existe ou nao consegue abrir
		printf("Erro de abertura");
	while (fgets(lerv,sizeof lerv,fileler) != NULL)
      {			
			if (count==5)
	        {
	        	sscanf(lerv, "%d", &pistas);
	        	return pistas;
	   		 }
	         count++;
		}
		fclose(fileler);
}
//ler dados total
int lertotal(int total)
{
	FILE *fileler=NULL;
		char name[]="backup.txt", lerv[120];
		fileler=fopen(name,"r");
		int count=0;
		if(fileler==NULL) //ficheiro nao existe ou nao consegue abrir
		printf("Erro de abertura");
	while (fgets(lerv,sizeof lerv,fileler) != NULL)
      {			
			if (count==5)
	        {
	        	sscanf(lerv, "%d", &total);
	        	return total;
	   		 }
	         count++;
		}
		fclose(fileler);
}

