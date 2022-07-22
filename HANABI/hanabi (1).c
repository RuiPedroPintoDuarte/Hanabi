#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include <locale.h> //include do set locale
#include <Windows.h > //maximizar janela

	//cores das cartas: 15-branco | 6-amarelo | 4-vermelho | 3-azul | 2-verde
	char cores[50][10]={"branco","amarelo","vermelho","azul","verde","branco","amarelo","vermelho","azul","verde",
	"branco","amarelo","vermelho","azul","verde","branco","amarelo","vermelho","azul","verde",
	"branco","amarelo","vermelho","azul","verde","branco","amarelo","vermelho","azul","verde",
	"branco","amarelo","vermelho","azul","verde","branco","amarelo","vermelho","azul","verde",
	"branco","amarelo","vermelho","azul","verde","branco","amarelo","vermelho","azul","verde"}; 
	char *tabela[6][6]={"1","2","3","4","5"},*tabela2[6][6]={"Branco","0","0","0","0","0"},*tabela3[6][6]={"Amarelo","0","0","0","0","0"};
	char *tabela4[6][6]={"Vermelho","0","0","0","0","0"},*tabela5[6][6]={"Azul","0","0","0","0","0"},*tabela6[6][6]={"Verde","0","0","0","0","0"};
	//numero das cartas
	int num[10]={1,1,1,2,2,3,3,4,4,5}; 
	char jog1[17]="jogador", bot[]="bot"; //numero de jogadores e seu nome	
int main() 
	{	//interface(){print handbot e handjog, print table, discard vidas e pistas;}     !!!    estruturas
	system("MODE con cols=160 lines=60");
	system("title Hanabi v1.3");
	//maximizar janela
	HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE); 
	
		//definir logo no inicio para permitir suportar é á í ó ã õ ç 
	setlocale(LC_ALL, ""); 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	menu(jog1);
		int arrCor[] = {0, 1, 2, 3, 4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,
		36,37,38,39,40,41,42,43,44,45,46,47,48,49}; //corresponde as cores para baralhar
		int arrNum[] = {0, 1, 2, 3, 4,5,6,7,8,9}; //corresponde aos numeros para baralhar
		int pistas=7, vidas=3, total=50; // definir o numero de pistas,penalizacoes e total de cartas
		char corjog1[5][10],numjog1[5][10],corbot[5][10],numbot[5][10];
		int acao,compNome=0,compCor=0,compNum=0,informacao,descartar,jogar, i, j, primeiro,flag=0;
	//cartas bot
		//baralhar as cartas bot com a funcao random
			random (arrCor, 50);
			random (arrNum, 10);
		
			//cartas do bot
			//numero de cartas(5) para o bot
			for(j=0;j<5;j++) 
			{
				int aCj = arrCor[j];
				int aNj = arrNum[j];
				snprintf(corbot[j], sizeof corbot[j], "%s", cores[aCj]); //dividir os nomes das cores
				snprintf(numbot[j], sizeof numbot[j], "%d", num[aNj]); //dividir os numeros
				total--;
			}
		cartasBot(corbot,numbot);
			//baralhar as cartas jog1 com a funcao random
			random (arrCor, 50);
			random (arrNum, 10);
			
			//cartas do jog1
			//numero de cartas(5) para o jog1
			for(i=0;i<5;i++) 
			{
				int aCi = arrCor[i];
				int aNi = arrNum[i];
				snprintf(corjog1[i], sizeof corjog1[i], "%s", cores[aCi]); //dividir os nomes das cores
				snprintf(numjog1[i], sizeof numjog1[i], "%d", num[aNi]); //dividir os numeros
				total--;
			}
		//estrutura das cartas do jogador, mesa, compra, descarte, vidas e pistas
		cartasJog(corjog1,numjog1,jog1);
		mesa();
		compra(total);
		descarte(tabela,tabela2,tabela3,tabela4,tabela5,tabela6);
		drawVida(vidas);
		drawPista(pistas);
		
		primeiro=first(primeiro);
		
		if (primeiro==2)
		{int f=0;
			gotoxy(1,44);
			printf("\nPrimeiro a jogar: %s.\n",bot);
			if(pistas>0)
			{
			int b=0;
			for(b=0;b<5;b++)
			{
			int g=b+1;
				if(strcmp(numjog1[b],"1")==0)
				{
					printf("Dar pista: A carta na posição %d é um 1.\n",g);
					g++;
					f=1;
				}	
			}
			if(f==1)
			{
				pistas--;
				drawPista(pistas);
			}	
			}
					//se falso: perde uma vida( se for a ultima, o jogo termina c/ pontuacao 0)/ descarta-se a carta
			int a=0;
			if(f==0)
			{
				printf("Jogar carta:");
				for(a=0;a<5;a++)
				{
					if(flag==1 && strcmp(numbot[a],"1")==0)
					{
						setColor(2+(18*a),31,color(corbot[a]),color(corbot[a]));
						gotoxy(8+(18*a),36);
						SetConsoleTextAttribute(hConsole, 15);
						printf("%s",numbot[a]);
						flag++;
					}
					else if(flag==2 && strcmp(numbot[a],"2")==0)
					{
						setColor(2+(18*a),31,color(corbot[a]),color(corbot[a]));
						gotoxy(8+(18*a),36);
						SetConsoleTextAttribute(hConsole, 15);
						printf("%s",numbot[a]);
						flag++;
					}
					else if(flag==3 && strcmp(numbot[a],"3")==0)
					{
						setColor(2+(18*a),31,color(corbot[a]),color(corbot[a]));
						gotoxy(8+(18*a),36);
						SetConsoleTextAttribute(hConsole, 15);
						printf("%s",numbot[a]);
						flag++;
					}
					else if(flag==4 && strcmp(numbot[a],"4")==0)
					{
						setColor(2+(18*a),31,color(corbot[a]),color(corbot[a]));
						gotoxy(8+(18*a),36);
						SetConsoleTextAttribute(hConsole, 15);
						printf("%s",numbot[a]);
						flag++;
					}
					else if(flag==5 && strcmp(numbot[a],"5")==0)
					{
						setColor(2+(18*a),31,color(corbot[a]),color(corbot[a]));
						gotoxy(8+(18*a),36);
						SetConsoleTextAttribute(hConsole, 15);
						printf("%s",numbot[a]);
						flag++;
					}
				}
			}
			gotoxy(1,48);
			
	//		printf("\r                                              ");
		}
		if (primeiro==1)
		{
			gotoxy(1,44);
			printf("\nPrimeiro a jogar: %s.\n",jog1);
		//JOG1
			
			//acoes jog1: 1 => dar informacao/ 2 => descartar carta (SO POSSIVEL SE PISTAS <=7) / 3 => jogar carta
			//acao para cada valor das acoes do jog1
		acao=acaojog(acao,jog1,pistas,total);
			
			switch(acao) 
			{
				case 1: //DAR INFORMACAO - SO POSSIVEL SE PISTAS >=1 e nr de pistas -1
				{
				if(pistas>0)
				{				
				do
				{	
					printf("Insira o número da informação que pretende dar, %s:\n",jog1);
					printf("1-cor; 2-número ");
					scanf("%d",&informacao);
					if(informacao>2)
					printf("Inseriu um valor errado.\n\n");
				}	while(informacao!=1 && informacao!=2);	
				
				//acao para cada valor das informacoes do jog1
				if(informacao==1)
				{
					int cor,ver=0;
					do
					{
						printf("Que cor quer confirmar?\n");
						printf("1-Branco; 2-Amarelo; 3-Vermelho; 4-Azul; 5-Verde ");
						scanf("%d",&cor);
						
						if(cor>5)
						printf("Inseriu um valor errado.\n\n");
					}	while(ver!=0 && cor!=1 && cor!=2 && cor!=3 && cor!=4 && cor!=5);	
						
					switch(cor)
					{
						case 1:
							{
								int ci,ver=0;
								for(ci=0;ci<5;ci++)
									{
										if(strcmp(corbot[ci],"branco")==0)
										{
											ver++;
											printf("O outro jogador tem carta branca na posição: %d.\n",ci+1); //verificar quantidade de cartas brancas
										}
									}
						if(ver==0)
						printf("\nO outro jogador não tem a cor branca.\n");
						pistas--;
						drawPista(pistas);
						
						break;
							}
						
						case 2:
							{
								int ci,ver=0;
								for(ci=0;ci<5;ci++)
								{
									if(strcmp(corbot[ci],"amarelo")==0)
										{
											ver++;
											printf("O outro jogador tem carta amarela na posição: %d.\n",ci+1); //verificar quantidade de cartas brancas
										}
									}
						if(ver==0)
						printf("\nO outro jogador não tem a cor amarela.\n");
								pistas--;
								drawPista(pistas);
							}
							break;
						case 3:
							{
								int ci,ver=0;
								for(ci=0;ci<5;ci++)
								{
									if(strcmp(corbot[ci],"vermelho")==0)
										{
											ver++;
											printf("O outro jogador tem carta vermelha na posição: %d.\n",ci+1); //verificar quantidade de cartas brancas
										}
									}
						if(ver==0)
						printf("\nO outro jogador não tem a cor vermelha.\n");
								pistas--;
								drawPista(pistas);
							}
							break;
						case 4:
							{
								int ci,ver=0;
								for(ci=0;ci<5;ci++)
								{
									if(strcmp(corbot[ci],"azul")==0)
										{
											ver++;
											printf("O outro jogador tem carta azul na posição: %d.\n",ci+1); //verificar quantidade de cartas brancas
										}
									}
						if(ver==0)
						printf("\nO outro jogador não tem a cor azul.\n");
								pistas--;
								drawPista(pistas);
							}
							break;
						case 5:
							{
								int ci,ver=0;
								for(ci=0;ci<5;ci++)
								{
									if(strcmp(corbot[ci],"verde")==0)
										{
											ver++;
											printf("O outro jogador tem carta verde na posição: %d.\n",ci+1); //verificar quantidade de cartas brancas
										}
									}
						if(ver==0)
						printf("\nO outro jogador não tem a cor verde.\n");
								pistas--;
								drawPista(pistas);
							}
							break;
					}
				}
				if(informacao==2) 
				{
					int num;
					do
					{
						printf("Que número quer confirmar?\n");
						scanf("%d",&num);
						if(num>5)
						printf("Inseriu um valor errado.\n\n");
					}while(num!=1 && num!=2 && num!=3 && num!=4 && num!=5);	
						
					switch(num)
					{
						case 1:
							{
								int ni,ver=0;
								for(ni=0;ni<5;ni++)
								{
									if(strcmp(numbot[ni],"1")==0)
											{
												ver++;
												printf("O outro jogador tem uma carta 1 na posicao: %d. \n",ni+1);
											}
								}
								if(ver==0) 
							    printf("\nO outro jogador não tem o número 1.\n");
								pistas--;
								drawPista(pistas);
							}
							break;
						case 2:
							{
								int ni,ver=0;
								for(ni=0;ni<5;ni++)
								{
									if(strcmp(numbot[ni],"2")==0)
											{
												ver++;
												printf("O outro jogador tem uma carta 2 na posicao: %d. \n",ni+1);
											}
								}
								if(ver==0) 
							    printf("\nO outro jogador não tem o número 2.\n");
								pistas--;
								drawPista(pistas);
							}
							break;
						case 3:
							{
								int ni,ver=0;
								for(ni=0;ni<5;ni++)
								{
									if(strcmp(numbot[ni],"3")==0)
											{
												ver++;
												printf("O outro jogador tem uma carta 3 na posicao: %d. \n",ni+1);
											}
								}
								if(ver==0) 
							    printf("\nO outro jogador não tem o número 3.\n");
								pistas--;
								drawPista(pistas);
							}
							break;
						case 4:
							{
								int ni,ver=0;
								for(ni=0;ni<5;ni++)
								{
									if(strcmp(numbot[ni],"4")==0)
											{
												ver++;
												printf("O outro jogador tem uma carta 4 na posicao: %d. \n",ni+1);
											}
								}
								if(ver==0) 
							    printf("\nO outro jogador não tem o número 4.\n");
								pistas--;
								drawPista(pistas);
							}
							break;
						case 5:
							{
								int ni,ver=0;
								for(ni=0;ni<5;ni++)
								{
									if(strcmp(numbot[ni],"5")==0)
											{
												ver++;
												printf("O outro jogador tem uma carta 5 na posicao: %d. \n",ni+1);
											}
								}
								if(ver==0) 
							    printf("\nO outro jogador não tem o número 5.\n");
								pistas--;
								drawPista(pistas);
							}
							break;
					}
				}
				}
				else
				printf("Não tem pistas para dar informações.\n");
				gotoxy(0,56);
			}
				break;
				case 2: 
				//DESCARTAR CARTA (pistas <8)
				
					//buscar nova carta para substituir a descartada ( se é a ultima carta disponivel no descarte, é fim do jogo (ultima ronda))
					{
						int num;
						do
						{
							printf("Qual carta quer descartar? (de 1 a 5) ");
							scanf("%d",&num);
							if(num>5)
							printf("Inseriu um valor errado.\n\n");
						}while(num!=1 && num!=2 && num!=3 && num!=4 && num!=5);	
						
						int ni=num-1;
						int nr=1;
						printf("A carta é um %s %s.\n",numjog1[ni],corjog1[ni]);
						pistas++;
						drawPista(pistas);
						total--;
						compra(total);
						random (arrCor, 50);
						random (arrNum, 10);
						int aCt = arrCor[ni];
						int aNt = arrNum[ni];
						snprintf(corjog1[ni], sizeof corjog1[ni], "%s", cores[aCt]); //dividir os nomes das cores
						snprintf(numjog1[ni], sizeof numjog1[ni], "%d", num); //dividir os numeros
						if(strcmp(numjog1[ni],"1")==0)
						{
							if(strcmp(corjog1[ni],"branco")==0)
							{
							gotoxy(126,35);
							printf("%d",nr);
							nr++;
							}
							else if(strcmp(corjog1[ni],"amarelo")==0)
							{
							gotoxy(126,36);
							SetConsoleTextAttribute(hConsole, 6);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"vermelho")==0)
							{
							gotoxy(126,37);
							SetConsoleTextAttribute(hConsole, 4);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"azul")==0)
							{
							gotoxy(126,38);
							SetConsoleTextAttribute(hConsole, 3);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"verde")==0)
							{
							gotoxy(126,39);
							SetConsoleTextAttribute(hConsole, 2);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else
								printf("Valor errado.\n");
						}
						else if(strcmp(numjog1[ni],"2")==0)
						{
							if(strcmp(corjog1[ni],"branco")==0)
							{
							gotoxy(129,35);
							printf("%d",nr);
							nr++;
							}
							else if(strcmp(corjog1[ni],"amarelo")==0)
							{
							gotoxy(129,36);
							SetConsoleTextAttribute(hConsole, 6);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"vermelho")==0)
							{
							gotoxy(129,37);
							SetConsoleTextAttribute(hConsole, 4);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"azul")==0)
							{
							gotoxy(129,38);
							SetConsoleTextAttribute(hConsole, 3);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"verde")==0)
							{
							gotoxy(129,39);
							SetConsoleTextAttribute(hConsole, 2);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else
								printf("Valor errado.\n");
						}
						else if(strcmp(numjog1[ni],"3")==0)
						{
							if(strcmp(corjog1[ni],"branco")==0)
							{
							gotoxy(132,35);
							printf("%d",nr);
							nr++;
							}
							else if(strcmp(corjog1[ni],"amarelo")==0)
							{
							gotoxy(132,36);
							SetConsoleTextAttribute(hConsole, 6);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"vermelho")==0)
							{
							gotoxy(132,37);
							SetConsoleTextAttribute(hConsole, 4);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"azul")==0)
							{
							gotoxy(132,38);
							SetConsoleTextAttribute(hConsole, 3);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"verde")==0)
							{
							gotoxy(132,39);
							SetConsoleTextAttribute(hConsole, 2);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else
								printf("Valor errado.\n");
						}
						else if(strcmp(numjog1[ni],"4")==0)
						{
							if(strcmp(corjog1[ni],"branco")==0)
							{
							gotoxy(135,35);
							printf("%d",nr);
							nr++;
							}
							else if(strcmp(corjog1[ni],"amarelo")==0)
							{
							gotoxy(135,36);
							SetConsoleTextAttribute(hConsole, 6);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"vermelho")==0)
							{
							gotoxy(135,37);
							SetConsoleTextAttribute(hConsole, 4);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"azul")==0)
							{
							gotoxy(135,38);
							SetConsoleTextAttribute(hConsole, 3);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"verde")==0)
							{
							gotoxy(135,39);
							SetConsoleTextAttribute(hConsole, 2);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else
								printf("Valor errado.\n");
						}
						else if(strcmp(numjog1[ni],"5")==0)
						{
							if(strcmp(corjog1[ni],"branco")==0)
							{
							gotoxy(138,35);
							printf("%d",nr);
							nr++;
							}
							else if(strcmp(corjog1[ni],"amarelo")==0)
							{
							gotoxy(138,36);
							SetConsoleTextAttribute(hConsole, 6);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"vermelho")==0)
							{
							gotoxy(138,37);
							SetConsoleTextAttribute(hConsole, 4);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"azul")==0)
							{
							gotoxy(138,38);
							SetConsoleTextAttribute(hConsole, 3);
							printf("%d",nr);
							resetColor();
							nr++;
							}
							else if(strcmp(corjog1[ni],"verde")==0)
							{
							gotoxy(138,39);
							SetConsoleTextAttribute(hConsole, 2);
							printf("%d",nr);
							resetColor();
							
							nr++;
							}
							else
								printf("Valor errado.\n");
						}
					}
				gotoxy(0,50);
				break;
				case 3: //JOGAR PARA A MESA
				{
					
					//se falso: perde uma vida( se for a ultima, o jogo termina c/ pontuacao 0)/ descarta-se a carta
					int num;
						do
						{
							printf("Qual carta quer jogar? (de 1 a 5) ");
							scanf("%d",&num);
							if(num>5)
							printf("Inseriu um valor errado.\n\n");
						}while(num!=1 && num!=2 && num!=3 && num!=4 && num!=5);
						flag++;
						int ni=num-1;
						printf("A carta é um %s %s.\n",numjog1[ni],corjog1[ni]);
						if(flag==1 && strcmp(numjog1[ni],"1")==0)
						{
							setColor(2+(18*ni),31,color(corjog1[ni]),color(corjog1[ni]));
							gotoxy(8+(18*ni),36);
							SetConsoleTextAttribute(hConsole, 15);
							printf("%s",numjog1[ni]);
						}
						else if(flag==1 && strcmp(numjog1[ni],"1")!=0)
						{
						gotoxy(0,49);
						printf("\nA carta não é um 1: -1 vida.\n");
						vidas--;
						drawVida(vidas);
						}
						else if(flag==2 && strcmp(numjog1[ni],"2")==0)
						{
							setColor(2+(18*ni),31,color(corjog1[ni]),color(corjog1[ni]));
							gotoxy(8+(18*ni),36);
							SetConsoleTextAttribute(hConsole, 15);
							printf("%s",numjog1[ni]);
						}
						else if(flag==2 && strcmp(numjog1[ni],"2")!=0)
						{
						gotoxy(0,49);
						printf("\nA carta não é um 2: -1 vida.\n");
						vidas--;
						drawVida(vidas);
						}
						else if(flag==3 && strcmp(numjog1[ni],"3")==0)
						{
							setColor(2+(18*ni),31,color(corjog1[ni]),color(corjog1[ni]));
							gotoxy(8+(18*ni),36);
							SetConsoleTextAttribute(hConsole, 15);
							printf("%s",numjog1[ni]);
						}
						else if(flag==3 && strcmp(numjog1[ni],"3")!=0)
						{
						gotoxy(0,49);
						printf("\nA carta não é um 3: -1 vida.\n");
						vidas--;
						drawVida(vidas);
						}
						else if(flag==4 && strcmp(numjog1[ni],"4")==0)
						{
							setColor(2+(18*ni),31,color(corjog1[ni]),color(corjog1[ni]));
							gotoxy(8+(18*ni),36);
							SetConsoleTextAttribute(hConsole, 15);
							printf("%s",numjog1[ni]);
						}
						else if(flag==4 && strcmp(numjog1[ni],"4")!=0)
						{
						gotoxy(0,49);
						printf("\nA carta não é um 4: -1 vida.\n");
						vidas--;
						drawVida(vidas);
						}
						else if(flag==5 && strcmp(numjog1[ni],"5")==0)
						{
							setColor(2+(18*ni),31,color(corjog1[ni]),color(corjog1[ni]));
							gotoxy(8+(18*ni),36);
							SetConsoleTextAttribute(hConsole, 15);
							printf("%s",numjog1[ni]);
						}
						else if(flag==5 && strcmp(numjog1[ni],"5")!=0)
						{
						gotoxy(0,49);
						printf("\nA carta não é um 5: -1 vida.\n");
						vidas--;
						drawVida(vidas);
						}
				gotoxy(0,53);
				break;
			}
			
		}
	}
	guardar(jog1,vidas,pistas,total,corbot,numbot,corjog1,numjog1);
	return 0;	
	}
