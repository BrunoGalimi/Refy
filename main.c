#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
#define LDATAUSER 20
#define SONGDATA 25
/*
cose da fare, utilizzare le cartelle, all'interno per ogni utente ci sono i file delle canzoni, playlist e tutto
implementare playlist
*/

void menuStart();
void inApplication();
void refyLogo();
bool controlLogin(bool k);
void codi(char str[]);
void addProfile();
void settings(char userVisual[]);
void library();
void myFavoriteSong(char ui[]);
void mySong(char ui[]);
void playSong(int base, char ui[]);
void search(char user[]);
void addSong(char u[]);

void SetColor(short Color);

struct s_dataUser{
	char username[LDATAUSER];
	char password[LDATAUSER];
}dataUser;

struct s_dataFile{
	char nomeCanzone[SONGDATA];
	char nomeAutore[SONGDATA];
	char durataCanzoneString[4];
	float durataCanzoneFloat;
	char likeDislike[2];
}dataFile;

void main()
{
	FILE *file;
file = fopen("registro.txt", "a");
fclose(file);
file = fopen("registro.txt", "r");
fseek(file, 0, SEEK_END);
long size = ftell(file);
fclose(file);
	if(size == 0)//se il file è vuoto scrivi admin admin
	{
		file = fopen("registro.txt", "w");
			fprintf(file, "%s %s", "admin", "admin");
		fclose(file);
	}

	menuStart();
system("cls");
	inApplication();
}


void inApplication()
{
char userGrafica[strlen(dataUser.username)];
bool k=false;
strcpy(userGrafica, dataUser.username);
userGrafica[0] = toupper(userGrafica[0]);
FILE *file;
char userIndividualizza[100] = "User-";
strcat(userIndividualizza, dataUser.username);
strcat(userIndividualizza, ".txt");
//printf("%s", userIndividualizza);
//system("PAUSE");
int base = 0;
int script = 0;
int i = 0, j = 0;
char ctrl[100];
//variabili base canzonerebase struttura
//

time_t now = time(NULL);
		struct tm *cur_time = localtime(&now);
	int tm_hour = cur_time->tm_hour;

	while(k == false)
	{
i = 0;
j = 0;
system("cls");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////parte grafica
//tm_hour = 11;
	refyLogo();
		if(base == 0)
		{
			//se è giorno scrive buongiorno sennò scrive buonasera
			if(tm_hour > 18 || tm_hour < 3)
				printf("\t\tBuonasera %s\t\t\t\t\t\t\t\t>\t%cInformazioni", userGrafica, 250);
			else
				printf("\t\tBuongiorno %s\t\t\t\t\t\t\t\t>\t%cInformazioni", userGrafica, 250);
		}
		else
		{
			if(tm_hour > 18 || tm_hour < 3)
				printf("\t\tBuonasera %s\t\t\t\t\t\t\t\t\t%cInformazioni", userGrafica, 250);
			else
				printf("\t\tBuongiorno %s\t\t\t\t\t\t\t\t\t%cInformazioni", userGrafica, 250);
		}
			
		
file = fopen(userIndividualizza, "r");
dataFile.durataCanzoneFloat = 0;
		while(fgets(ctrl, sizeof(ctrl), file))//conta quate cose ci sono scritte nel file(brani aggiunti), qunati mi piace e il numero complessivo di tempo delle canzoni
		{
			fscanf(file, "%s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike);
				if(strcmp("v", dataFile.likeDislike) == 0)
					j++;
			dataFile.durataCanzoneFloat += atof(dataFile.durataCanzoneString);//converto il valore del tempo della canzone in intero e li sommo
			i++;
		}
fclose(file);
dataFile.durataCanzoneFloat/=60;
		printf("\n\n\n\n\n\t\t\t\t\t|Canzoni Aggiunte:\t\t%d\n\t\t\t\t\t|Canzoni che ti Piacciono:\t%d\n\t\t\t\t\t|Durarata Ascolto totale:\t%.0f minuti e %.0f secondi\n\n\n\n\n\n", i, j, dataFile.durataCanzoneFloat, (float)(dataFile.durataCanzoneFloat - (int)dataFile.durataCanzoneFloat) * 100);

		
		
		
//printf("\n\n\n\n\n\t\t\t\t\t|Canzoni Aggiunte:\t\t@\n\t\t\t\t\t|Canzoni che ti Piacciono:\t@\n\t\t\t\t\t|Durarata Ascolto totale:\t@\n\n\n\n\n\n\n");			
		if(base == 1)
			printf("\t>\t%cHome%c", 250, 250);
		else
			printf("\t\t%cHome%c", 250, 250);
		if(base == 2)
			printf("\t\t\t>\t%cRicerca", 250);
		else
			printf("\t\t\t\t%cRicerca", 250);
		if(base == 3)
			printf("\t\t>\t%cLa tua libreria", 250);
		else
			printf("\t\t\t%cLa tua libreria", 250);
		
		printf("\n\n\n\n");
		//barra canzone
		//printf("\t\t\t\t|NomeCanzone\t___\t\t\t||\t|\n\t\t\t\t|NomeAutore\t\t\t\t\t|\n");//%c-->16
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////fine parte grafica
			script = getch();
//77: destra  75: sinistra  72: su  80: giù			
			if(script == 72 || script == 80 || script == 77 || script == 75)
			{
				if(base == 0 && script == 72)
					base = 3;
				else if(base == 0 && script == 80)
					base++;
				else if(base != 0 && script == 72)
					base = 0;
				else if(base != 0 && script == 80)
					base = 0;
				
				if(base != 0 && script == 77)
					if(base != 3)
						base++;
					else
						base = 1;
				else if(base != 0 && script == 75)
					if(base != 1)
						base--;
					else
						base = 3;
				
			}
		
	if(script == 13){
		switch(base)
		{
			case 0:
				settings(userIndividualizza);
			break;
			case 2:
				search(userIndividualizza);
			break;
			case 3:
				library(i, j, userIndividualizza);
		}
		
	}
		
			
	}
}

void search(char user[])
{
	FILE *file;
	bool k = false;
	bool x = false;
	char identificativo[100];
	char song[20];
	int i = 0;
	int j = 0;
	int base = 0;
	int limitBase = 0;
	char script = 0;
	char temp = 0;
	bool inWrite = false;//variabile che diventa true quando sto scrivendo
	bool cerca = false;//quando sono sopra a "cerca"
	char ctrl[100];
	
	for(i = 0; i < 20; i++)
		song[i] = 0;
i = 0;		
	while(k == false)
	{
		system("cls");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		refyLogo();
		limitBase = 0;
		file = fopen(user, "r");
		//Cerco delle canzoni che hanno al loro interno quello che ce scritto
		
		if(base == 0 && cerca == false)
		{
			if(song[0] == 0)
			{
				printf("\t\t\t\t\t|\n\t\t\t\t>\t|");
				printf(" Cosa vuoi ascoltare?");
				//printf("\n\t\t\t\t\t|");
			}else
			{
				
				printf("\t\t\t\t\t|\n\t\t\t\t>\t|");
				printf(" %s", song);
				//printf("\n\t\t\t\t\t|");
			}	
		}else
		{
			if(song[0] == 0)
			{
				printf("\t\t\t\t\t|\n\t\t\t\t\t|");
				printf(" Cosa vuoi ascoltare?");
				//printf("\n\t\t\t\t\t|");
			}else
			{
				printf("\t\t\t\t\t|\n\t\t\t\t\t|");
				printf(" %s", song);
				//printf("\n\t\t\t\t\t|");
			}
		}
		if(cerca == true)
		{
			printf("\t\t>\tCerca");
			printf("\n\t\t\t\t\t|");
		}else
		{
			printf("\t\t\tCerca");
			printf("\n\t\t\t\t\t|");
		}
			
		if(base == 1)
			printf("\n\n\n\t\t\t\t>\t%cRegistra una canzone", 250);
		else
			printf("\n\n\n\t\t\t\t\t%cRegistra una canzone", 250);
			
		if(inWrite == true)
		{
			printf("\n\n\nStai scrivendo...");
			printf("\n\n\n\n\n");
		}else
			printf("\n\n\n\n\n\n\n\n");
				
		if(base == 2)
		
			printf("\t>\t%cHome", 250);
		else
			printf("\t\t%cHome", 250);
		if(base == 3)
			printf("\t\t\t>\t%cRicerca%c", 250, 250);
		else	
			printf("\t\t\t\t%cRicerca%c", 250, 250);
		if(base == 4)
			printf("\t\t>\t%cLa tua libreria", 250, 250);
		else
			printf("\t\t\t%cLa tua libreria", 250, 250);
printf("\n\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	if(inWrite == false)
		script = getch();
//77: destra  75: sinistra  72: su  80: giù
		if(script != 13)
		{
			if(base == 0 && script == 80)
				base = 1;
			else if(base == 0 && script == 77)
				cerca = true;
			else if(base == 1 && script == 80)
				base = 2;
			else if(base != 0 && script == 77 && base != 4 && base != 1)
				base++;
			else if(base != 0 && script == 75 && base != 1 && base != 2)
				base--;
			else if(base != 0 && script == 72 && base != 1)
				base = 1;
			else if(base == 1 && script == 72)
				base = 0;
			else if(base == 0 && script == 72)
				base = 2;//limitBase+1;
			else if(base != 0 && script == 80 && base != 1)
				base = 0;
			else if(base == 1 && script == 80)
				base = 0;
			else if(base == 2 && script == 75)
				base = 4;
			else if(base == 4 && script == 77)
				base = 2;
			if(cerca == true && script == 75 || cerca == true && script == 72 || cerca == true && script == 80)
				cerca = false;
		}else
		{
			if(base == 0)
			{
				if(cerca == false)
				{
					if(inWrite == true)
					{
						temp = getch();
						if(temp != 13)
							song[i] = temp;
						else
							inWrite = false;
						song[i+1] = 0;
						if(temp == 8)//da aggiungere il caso in cui cancella
						{
							song[i-1] = 0;
							song[i] = 0;
							i-=2;
						}
					i++;
					}
					else if(base == 0 || inWrite == false)
					{
						strcpy(song, "");
						song[1] = '\0';
						inWrite = true;
						temp = 0;
						i = 0;
					}
				}
					
			}else
			{
				if(cerca == false)//dato che quando cerca è true base è comunque 0 magari dava problemi
				{
					switch(base)
					{
						case 1:
							addSong(user);
						break;
						case 2:
							k = true;
						break;
						case 4:
							i = 0;
							j = 0;
							k = true;
							
						break;
					}
				}
//				{
					///stampa le canzoni che iniziano per quello cercato
//				}
			}
		}
song[strlen(song)] = '\0';
//printf("%s", song);
//system("PAUSE");
fflush(stdin);
		
	}
	if(base == 4)//per andare nella libreria
	{
		file = fopen(user, "r");
		while(fgets(ctrl, sizeof(ctrl), file))//conta quate cose ci sono scritte nel file(brani aggiunti), qunati mi piace e il numero complessivo di tempo delle canzoni
		{
			fscanf(file, "%s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike);
				if(strcmp("v", dataFile.likeDislike) == 0)
					j++;
			dataFile.durataCanzoneFloat += atof(dataFile.durataCanzoneString);//converto il valore del tempo della canzone in intero e li sommo
			i++;
		}
		fclose(file);
			library(i, j, user);
	}
		
}
void addSong(char u[])
{
	FILE *file;
	bool k = false;
	bool yes = false;
	bool nop = true;
	bool inWrite = false;
	bool x = false;//per controlli
	int xx = 0;
	int base = 0;
	int dC = 0;
	char script = 0;
	char temp = 0;
	int i = 0, j = 0;
	char ctrl[100];
	char yn = 0;
	char iString[3];
	HANDLE  hConsole;
  	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
strcpy(dataFile.nomeCanzone, "");
strcpy(dataFile.nomeAutore, "");
strcpy(dataFile.likeDislike, "");	
strcpy(dataFile.durataCanzoneString, "");
	while(k == false)
	{
		system("cls");
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		refyLogo();
		printf("\t\t\t\t\t%c Registra una canzone %c\n\n\n", 14, 14);
		if(base == 0)
			printf("\t\t\t\t>\tNome Canzone:\t%s", dataFile.nomeCanzone);
		else
			printf("\t\t\t\t\tNome Canzone:\t%s", dataFile.nomeCanzone);
		if(base == 1)
			printf("\n\n\t\t\t\t>\tNome Autore:\t%s", dataFile.nomeAutore);
		else
			printf("\n\n\t\t\t\t\tNome Autore:\t%s", dataFile.nomeAutore);
		if(base == 2)
			printf("\n\n\t\t\t\t>\tQuanto dura la canzone?(secondi):\t%s", dataFile.durataCanzoneString);
		else
			printf("\n\n\t\t\t\t\tQuanto dura la canzone?(secondi):\t%s", dataFile.durataCanzoneString);
		if(base == 3)
			printf("\n\n\t\t\t\t>\tTi piace questa canzone?\t");
		else
			printf("\n\n\t\t\t\t\tTi piace questa canzone?\t");
		if(base == 4)
		{
			if(yes == true)
			{
				printf(">\t");
				SetConsoleTextAttribute(hConsole, 1);
					printf("si");
				SetConsoleTextAttribute(hConsole, 3);
			}
			else
				printf(">\tsi");
		}else
		{
			if(yes == true)
			{
				printf("\t");
				SetConsoleTextAttribute(hConsole, 1);
					printf("si");
				SetConsoleTextAttribute(hConsole, 3);
			}
			else
				printf("\tsi");
		}
		if(base == 5)
		{
			if(nop == true)
			{
				printf("  >\t");
				SetConsoleTextAttribute(hConsole, 1);
					printf("no");
				SetConsoleTextAttribute(hConsole, 3);
			}
			else
				printf("  >\tno");
		}else
		{
			if(nop == true)
			{
				printf("   \t");
				SetConsoleTextAttribute(hConsole, 1);
					printf("no");
				SetConsoleTextAttribute(hConsole, 3);
			}
			else
				printf("   \tno");
		}
		
		if(base == 6)
			printf("\n\n\n\t\t\t\t\t>\tRegistra");
		else
			printf("\n\n\n\t\t\t\t\t\tRegistra");
		if(base == 7)
			printf("\n\n\t>\tIndietro");	
		else
			printf("\n\n\t\tIndietro");
		if(inWrite == true)
			printf("\n\nStai scrivendo...");
			printf("\n\n");
		if(x == true)
		{
			if(xx == 1)
				printf("\n\nLa canzone deve avere un nome.");
			else if(xx == 2)
				printf("\n\nLa canzone deve avere un'autore.");
			else if(xx == 3)
				printf("\n\nLa canzone deve avere una durata.");
			else if(xx == 4)
				printf("Canzone registrata.");
			x = false;
			xx = 0;
		}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				//77: destra  75: sinistra  72: su  80: giù
				if(inWrite == false)
					script = getch();
				if(script != 13)
				{
					if(base == 0 && script == 72)
						base = 7;
					else if(base < 3 && script == 80)
						base++;
					else if(base <= 3 && script == 72)
						base--;
					else if(base >= 4 && base <= 5 && script == 72)
						base = 2;
					else if(base >= 3 && base < 5 && script == 77)
						base++;
					else if(base > 3 && base <= 5 && script == 75)
						base--;
					else if(base == 5 && script == 77)
						base = 3;
					else if(base == 3 && script == 75)
						base = 5;
					else if(base >= 3 && base <= 5 && script == 80)
						base = 6;
					else if(base == 3 && script == 80)
						base = 6;
					else if(base == 6 && script == 72)
						base = 3;
					else if(base == 6 && script == 80)
						base = 7;
					else if(base == 7 && script == 80)
						base = 0;
					else if(base == 7 && script == 72)
						base = 6;
					else if(base == 6 && script == 75)
						base = 7;
				}else
				{
						
					switch(base)
					{
						case 7:
							k = true;
						break;
						case 0:
								
								if(inWrite == true)
								{
									temp = getch();
										if(temp != 13 && temp != 8)
											dataFile.nomeCanzone[i] = temp;
										else if(temp == 8)
										{
											dataFile.nomeCanzone[i-1] = 0;
											dataFile.nomeCanzone[i] = 0;
											i-=2;
										}
										else
											inWrite = false;
									dataFile.nomeCanzone[i+1] = 0;
									i++;
								}else
								{
									strcpy(dataFile.nomeCanzone, "");
									dataFile.nomeCanzone[1] = '\0';
									inWrite = true;
									temp = 0;
									i = 0;
								}
						break;
						case 1:
								if(inWrite == true)
								{
									temp = getch();
										if(temp != 13 && temp != 8)
											dataFile.nomeAutore[i] = temp;
										else if(temp == 8)
										{
											dataFile.nomeAutore[i-1] = 0;
											dataFile.nomeAutore[i] = 0;
											i-=2;
										}
										else
											inWrite = false;
									dataFile.nomeAutore[i+1] = 0;
									i++;
								}else
								{
									strcpy(dataFile.nomeAutore, "");
									dataFile.nomeAutore[1] = '\0';
									inWrite = true;
									temp = 0;
									i = 0;
								}
						break;
						case 2:
								if(inWrite == true)
								{
									temp = getch();
										if(temp != 13 && temp != 8)
											dataFile.durataCanzoneString[i] = temp;
										else if(temp == 8)
										{
											dataFile.durataCanzoneString[i-1] = 0;
											dataFile.durataCanzoneString[i] = 0;
											i-=2;
										}
										else
										{
											inWrite = false;
											//controllo che siano dei numeri
											for(j = 0; j < strlen(dataFile.durataCanzoneString); j++)
											{
												if(x == false)
												{
													if(dataFile.durataCanzoneString[j] < 48 || dataFile.durataCanzoneString[j] > 57)
														x = true;
														
												}
											}
											if(x == true)
											{
												x = false;
												strcpy(dataFile.durataCanzoneString, "");
												dataFile.durataCanzoneString[1] = '\0';
											}
										}
											
									dataFile.durataCanzoneString[i+1] = 0;
									i++;
								}else
								{
									strcpy(dataFile.durataCanzoneString, "");
									dataFile.durataCanzoneString[1] = '\0';
									inWrite = true;
									temp = 0;
									i = 0;
								}
						break;
						case 4:
							if(yes == false)
							{
								yes = true;
								nop = false;
							}
						break;
						case 5:
							if(nop == false)
							{
								nop = true;
								yes = false;
							}
						break;
						case 6:
								x = false;
									if(dataFile.nomeCanzone[0] > 33 && dataFile.nomeCanzone[0] < 126)
										x = false;
									else
									{
										x = true;
										xx = 1;
										//printf("\n\nLa canzone deve avere un nome.");
									}
									if(x == false)
									{
										if(dataFile.nomeAutore[0] > 33 && dataFile.nomeAutore[0] < 126)
											xx = false;
										else
										{
											x = true;
											xx = 2;
											//printf("\n\nLa canzone deve avere un autore");
										}
									}
									if(x == false)
									{
										if(dataFile.durataCanzoneString[0] > 33 && dataFile.durataCanzoneString[0] < 126)
											x = false;
										else
										{
											x = true;
											xx = 3;
											//printf("\n\nLa canzone deve avere una durata");
										}
									}
									if(x == false)
									{
										i = 0;
										x = true;
										xx = 4;
											file = fopen(u, "r");
										while(fgets(ctrl, sizeof(ctrl), file))
											i++;
										fclose(file);
										file = fopen(u, "a");
											if(yes == true)
												yn = 'v';
											else
												yn = 'x';
										i++;
										sprintf(iString, "%d", i);
										if(i == 1)
											fprintf(file, "%s %s %s %c %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, yn, iString);
										else
											fprintf(file, "\n%s %s %s %c %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, yn, iString);
										fclose(file);
									
									}
										
										
								//da fare la scrittura su file
						break;
					}
				}
			
			
				
				
	}
}



void library(int allSong, int allLike, char ui[])
{
FILE *file;
int i = 0;
int base = 0;
int limitBase = 1;//se non ci sono playlist rimane così sennò aumenta
int script = 0;
bool k = false;
system("cls");
bool oneJoin = false;
char nomeUtente[100];
char nomePlaylist[100];
char identificativo[3];
int ide = 0;

	while(k == false)
	{
		system("cls");
		refyLogo();
			printf("\t\t\t\t\t\t%c La tua libreria %c\n\n\n", 14, 14);
		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if(base == 0)
			printf("\t\t\t>\tLa mia raccolta:\t\t%d canzoni salvate\n", allSong);
		else
			printf("\t\t\t\tLa mia raccolta:\t\t%d canzoni salvate\n", allSong);
		if(base == 1)
			printf("\t\t\t>\tLe mie canzoni preferite:\t%d canzoni salvate\n", allLike);
		else
			printf("\t\t\t\tLe mie canzoni preferite:\t%d canzoni salvate\n", allLike);

		printf("\n\n\n\n\n\n\n\n");
		if(base == limitBase+1)
			printf("\t>\t%cHome", 250);
		else
			printf("\t\t%cHome", 250);
		if(base == limitBase+2)
			printf("\t\t\t>\t%cRicerca", 250);
		else
			printf("\t\t\t\t%cRicerca", 250);
		if(base == limitBase+3)
			printf("\t\t>\t%cLa tua libreria%c", 250, 250);
		else
			printf("\t\t\t%cLa tua libreria%c", 250, 250);
		
		printf("\n\n\n\n");
		
		//printf("\t\t\t\tChill anime playlist\n\n\n\n");
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
script = getch();

//77: destra  75: sinistra  72: su  80: giù
		if(script != 13)
		{
			if(script == 72 || script == 80 || script == 77 || script == 75)
			{
				if(script == 80)
				{
					if(base > limitBase)
						base = 0;
					else
						base++;
				}else if(script == 80 && base > limitBase)
				{
					base = 0;
				}else if(script == 72)
				{
					if(base <= limitBase)
					{
						if(base == 0)
							base = limitBase+3;
						else
							base--;
					}else
						base = limitBase;
				}else if(script == 77 && base > limitBase)
				{
					if(base == limitBase + 3)
						base = limitBase + 1;
					else
						base++;
				}else if(script == 75 && base > limitBase)
				{
					if(base == limitBase+1)
						base = limitBase+3;
					else
						base--;
				}
			}
		}
		
		if(script == 13)
		{
			switch(base)
			{
				case 0://la mia raccolta
					mySong(ui);
				break;
				case 1:
					myFavoriteSong(ui);
				break;
			}
			if(base == limitBase+1)
				k = true;
			else if(base == limitBase+2)
			{
				k = true;
				search(ui);
			}
				
		}
		
		
		
	}
}

void myFavoriteSong(char ui[])
{
	bool k = false;
int c = 0;//Contatore dei giri
int script = 0;
int base = 0;
int limitBase = 0;
char identificativo[3];
int ide = 0;
bool x = false;
char stringBase[3];
bool lastNot = false;
int i = 0;
FILE *file;
	while(k == false)
	{
		system("cls");
			refyLogo();
		printf("\t\t\t\t\t\t%c Brani che ti piacciono %c\n\n\n", 3, 3);
		file = fopen(ui, "r");
limitBase = 0;
		while(!feof(file))
		{
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
			if(strcmp(dataFile.likeDislike, "v") == 0)
			{
					ide = atoi(identificativo);
				dataFile.durataCanzoneFloat = atof(dataFile.durataCanzoneString);
					if(dataFile.durataCanzoneFloat > 60)
						dataFile.durataCanzoneFloat/=60;
					else
						dataFile.durataCanzoneFloat/=100;
					if(base == ide-1)
						printf("\t\t\t\t>\t%s di %s \t%d : %.0f", dataFile.nomeCanzone, dataFile.nomeAutore, (int)dataFile.durataCanzoneFloat, (float)(dataFile.durataCanzoneFloat - (int)dataFile.durataCanzoneFloat) * 100);
					else
						printf("\t\t\t\t\t%s di %s \t%d : %.0f", dataFile.nomeCanzone, dataFile.nomeAutore, (int)dataFile.durataCanzoneFloat, (float)(dataFile.durataCanzoneFloat - (int)dataFile.durataCanzoneFloat) * 100);
					
					printf("\t%c", 3);
					
					printf("\n");
			}
			limitBase++;
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		}
		//essendo già in ultima posizione dopo il ciclo controllo se l'ultimo likedislike è x in caso diminuisco il limitBase
		if(strcmp(dataFile.likeDislike, "x") == 0)
		{
			limitBase--;
			lastNot = true;//se l'ultimo non piace lastNot diventa true, questo serve per l'algoritmo sotto di movimento in cui se salta l'ultiumo perchè non c'è non arriva mai in "indietro"
		}else
			lastNot = false;
fclose(file);			

//controllo se ce almeno una canzone che piace, sennò limitBase è 0 così compare solo per l'indietro
file = fopen(ui, "r");
x = false;
	for(i = 0; i < limitBase; i++)
	{
		fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
			if(x != true)//diventa true se trova una canzone che piace, se esce con nessuna canzone che piace allora limitBase diventa 0 e stampo che non ci sono canzoni che piacciono
			{
				if(strcmp(dataFile.likeDislike, "v") == 0)
					x = true;
			}
	}
	if(x == false)
	{
		limitBase = 0;
		printf("\t\t\t\tNon ci sono canzoni che ti piacciono.");
	}
		
fclose(file);

x = false;
//limitBase--;
		printf("\n\n\n\n");
		if(base == limitBase)
		{
			printf("\t>\tIndietro\n\n");
				if(limitBase == 0)
				{
					getch();
					k = true;
				}
					
			
		}
		else
			printf("\t\tIndietro\n\n");	
		//*10 ci si sposta nei like(10 20 30)
//printf("\n\n%d %d ", base, limitBase);
		
if(k == false)
{
	if(c == 0)
	{
		file = fopen(ui, "r");
		fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
			while(strcmp(dataFile.likeDislike, "x") == 0)
			{
				if(strcmp(dataFile.likeDislike, "x") == 0)//se il primo non piace salta al prossimo base
				{
					base++;
				}
				fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
				//system("PAUSE");
			}
		fclose(file);
	}
		
			
	strcpy(stringBase, "");
	////////////////////////da fare//////////////////////se la prima canzone nella lista non piace si blocca in loop
			//77: destra  75: sinistra  72: su  80: giù	
			script = getch();
				if(script != 13)
				{//i pari sono i like, i dispari sono le canzoni
				
						
					do
					{
						x = false;
						
						if(script == 80)
						{
							if(base != limitBase)
								base++;
							else
								base = 0;
							
						}else if(script == 72)
						{
							if(base != 0)
								base--;
							else
								base = limitBase;
						}
	//controllo se la posizione seguente in cui mi trovo non piace, in caso bisogna saltarla
	//logica: scrollo con fscanf fino a qunando non trovo l'identificativo uguale alla base, se lo trovo e non ha la v nel likedislike allora rifaccio il ciclo per muoversi, in questo modo si salta
	//la posizione sbagliata
					file = fopen(ui, "r");
						itoa(base, stringBase, 10);
					
					while(strcmp(identificativo, stringBase) != 0)
					{
						fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
							identificativo[0]--;
					//	printf("\n%d\t%s\t%s\n\n", base, stringBase, identificativo);
						//system("PAUSE");
					}
					
					if(lastNot == false || base != limitBase)//leggi sopra nel controllo con il lastNot
					{
						if(strcmp(dataFile.likeDislike, "x") == 0)
						{
							x = true;
						//	system("PAUSE");
						}
					}
						
					//	printf("%d", x);
					//	system("PAUSE");	
					
					}while(x == true);
				}else
				{
					if(script == 13 && base == limitBase)//6 zeri
						k = true;
					else
						playSong(base, ui);
				}
			}//fine if(k == false)
	c++;
	}
}

void mySong(char ui[])
{
bool k = false;
int script = 0;
int base = 0;
int limitBase = 0;
char identificativo[3];
int ide = 0;

FILE *file;
	while(k == false)
	{
		system("cls");
			refyLogo();
		printf("\t\t\t\t\t\t%c La mia raccolta %c\n\n\n", 4, 4);
		file = fopen(ui, "r");
limitBase = 0;
		while(!feof(file))
		{
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
				ide = atoi(identificativo);
			dataFile.durataCanzoneFloat = atof(dataFile.durataCanzoneString);
			if(dataFile.durataCanzoneFloat > 60)
				dataFile.durataCanzoneFloat/=60;
			else
				dataFile.durataCanzoneFloat/=100;
				if(base == ide-1)
					printf("\t\t\t\t>\t%s di %s \t%d : %.0f", dataFile.nomeCanzone, dataFile.nomeAutore, (int)dataFile.durataCanzoneFloat, (float)(dataFile.durataCanzoneFloat - (int)dataFile.durataCanzoneFloat) * 100);
				else
					printf("\t\t\t\t\t%s di %s \t%d : %.0f", dataFile.nomeCanzone, dataFile.nomeAutore, (int)dataFile.durataCanzoneFloat, (float)(dataFile.durataCanzoneFloat - (int)dataFile.durataCanzoneFloat) * 100);
					if(strcmp(dataFile.likeDislike, "v") == 0)
						printf("\t%c", 3);
					limitBase++;
					printf("\n");
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		}
limitBase--;
		printf("\n\n\n\n");
		if(base == limitBase+1)
			printf("\t>\tIndietro\n\n");
		else
			printf("\t\tIndietro\n\n");
		fclose(file);
		//77: destra  75: sinistra  72: su  80: giù		
		//*10 ci si sposta nei like(10 20 30)
		script = getch();
			if(script != 13)
			{//i pari sono i like, i dispari sono le canzoni
				if(script == 80)
				{
					if(base != limitBase && base != limitBase+1)
						base++;
					else if(base == limitBase)
						base++;
					else if(base == limitBase+1)
						base = 0;
				}else if(script == 72)
				{
					if(base != 0)
						base--;
					else
						base = limitBase+1;
				}
				
				
			}else
			{
				if(script == 13 && base == limitBase+1)//6 zeri
					k = true;
				else
				{
					playSong(base, ui);
				}
					
			}
	}
}

void playSong(int base, char ui[])
{
	//funzione per ascolto canzone
FILE *file;
char identificativo[3];
int id;
int h = 0;
float displayH = 0;
file = fopen(ui, "r");
int i, cont = 0;
int j = 0;//variabile per tenere il conto e muoversi nella barra di progresso
bool k = false;
//cerco la canzone puntata
//printf("base: %d\n\n", base);
float calc;
float durataCanzone = 0;
float dC = 0;
float displayDc = 0;
int baseShift = 0;
float ctrlDue = 0, ctrl = 0;
float cost = 26;
int preN = 0;
j = 0;
char test = 0;
bool pause = false;
int idCmp = 0;
bool noRepeat = false;
int ctrl2 = 0;

char script = 0;
int basee = 0;//base per lo spostamento grafico
if(noRepeat == false)
{
	while(k == false)
	{
		fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
		id = atoi(identificativo);
			if(base+1 == id)
				k = true;
		//printf("%s\n%s\n%s\n%s\n\n\n %s:idenficativo\n\n %d:ide\nbase:%d\n", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo, id,base);
		//system("PAUSE");
	}

idCmp = id;
durataCanzone = atof(dataFile.durataCanzoneString);
baseShift = atoi(dataFile.durataCanzoneString);

dC = durataCanzone;
}
//printf("%f", durataCanzone);
//system("PAUSE");
fclose(file);


noRepeat = true;
//printf("%s\n%s\n%s\n%s\n\n\n %s:idenficativo\n\n %d:ide\n", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo, id);
//system("PAUSE");
srand(time(NULL));
int rnd = 0;
k = false;
	while(k == false)
	{
		system("cls");
////////////////////////////////////////////////////////////////GRAFICA/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		refyLogo();
			
			//printf("\t\t\t\t\t\t%cIn Ascolto%c\n\n\n", 14, 14);
			printf("\t\t\t\t\t\t%c In Ascolto %c\n\n\n", 14, 14);
			printf("\t\t\t\t\t _________________________\n");
			printf("\t\t\t\t\t|                         |\n"
					"\t\t\t\t\t|                         |\n");
				rnd = rand()%207+207+55;
					printf("\t\t\t\t\t|          %dhz          |\n",rnd);
					
					
					
			printf("\t\t\t\t\t|                         |\n"
					"\t\t\t\t\t|_________________________|\n\n\n");
			printf("\t\t\t\t%s\t\t\t\t\t", dataFile.nomeCanzone);
				if(strcmp(dataFile.likeDislike, "x") == 0)
					printf("%c", 'x');
				else
					printf("%c", 3);
			printf("\n\t\t\t\tdi %s", dataFile.nomeAutore);
			printf("\n\n");
			
			printf("\n\t\t\t\t");		
				if(pause == false)
				{
					preN = cost;
					calc = cost / dC;
					cost-=calc;
					dC--;
					j+=(int)preN-(int)cost;
				}
			displayH = h;
				if(displayH > 60)
					displayH/=60;
				else
					displayH/=100;
					
			printf("  %d : %.0f  ", (int)displayH, (float)(displayH - (int)displayH) * 100);//tempo che incrementa
			for(i = 0; i < 26; i++)//26 caratteri per la barra
			{		

					if((int)j != i)
						printf("_");
					else
						printf("%c", 15);
			}
				
			displayDc = dC;
			if(displayDc > 60)
				displayDc /= 60;
			else
				displayDc/=100;
			printf(" -%d : %.0f", (int)displayDc, (float)(displayDc - (int)displayDc) * 100);
			
			printf("\n\n");
			
			if(basee == 0)
				printf(">\tback\t\t\t\t      ");
			else
				printf("\tback\t\t\t\t      ");
			if(basee == 1)
				printf("> %c", 174);
			else
				printf("  %c", 174);
			if(basee == 2)
				if(pause == false)
					printf(" > %s", "||");//da fare che se si preme qui si ferma e che se si ripreme riparte
				else
					printf(" >  %c", 16);
			else
				if(pause == false)
					printf("   %s", "||");
				else
					printf("   %c", 16);
			if(basee == 3)
				printf(" > %c", 175); //da fare che ci si può spostare tra le canzoni, basta muoversi di cicli
			else
				printf("   %c", 175);
			
				
			
			printf("\n");
			
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
//77: destra  75: sinistra  72: su  80: giù				

		if(pause == false)
			{
				Sleep(500);
			if(kbhit())
				script = getch();
			}else
				script = getch();

			//script = kbhit();
			if(script != 13)
			{
				if(script == 77)
				{
					if(basee != 3)
						basee++;
					else
						basee = 0;
				}
				if(script == 75)
				{
					if(basee != 0)
						basee--;
					else	
						basee = 3;
				}
			}else
			{
				switch(basee)
				{
					case 0:
						k = true;
					break;
					case 1:
						if(strcmp(identificativo, "1") != 0)
						{
						file = fopen(ui, "r");
						i = 0;
						cont = 0;
						do
						{
							fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
								id = atoi(identificativo);
										
								i++;
							cont++;
						}while(idCmp != id && cont < 20);
						fclose(file);
						file = fopen(ui, "r");
						cont = 0;
						//i--;	
							do
							{
								fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
								id = atoi(identificativo);
								cont++;
							}while(cont != i-1 && cont < 20);
						
						fclose(file);
						h = 0;
						idCmp = id;
						durataCanzone = atof(dataFile.durataCanzoneString);
						baseShift = atoi(dataFile.durataCanzoneString);
						dC = durataCanzone;
						j = 0;
						preN = 0;
						calc = 0;
						cost = 26;
						}
						
					break;
					case 2:
						if(pause == true)
							pause = false;
						else if(pause == false)
							pause = true;
					break;
					case 3:
						//printf("%d", idCmp);
						//system("PAUSE");
						
						file = fopen(ui, "r");
						do
						{
							
							fscanf(file, "%s %s %s %s %s", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo);
								id = atoi(identificativo);
								
									if(ctrl2 == id)
									{
										id = idCmp+1;
									}
										
										
							ctrl2 = id;//controllo se è uguale allo stesso del ciclo prima e in caso esco
							//printf("%s %s %s %s %s %d", dataFile.nomeCanzone, dataFile.nomeAutore, dataFile.durataCanzoneString, dataFile.likeDislike, identificativo, id);
							//system("PAUSE");
								i++;
						}while(idCmp+1 != id);
						fclose(file);
						h = 0;
						idCmp = id;
						durataCanzone = atof(dataFile.durataCanzoneString);
						baseShift = atoi(dataFile.durataCanzoneString);
						dC = durataCanzone;
						j = 0;
						preN = 0;
						calc = 0;
						cost = 26;

					break;

				}
			}
script = 0;
		if(pause == false)
		{
			h++;//contatore di fine canzone
			
			if(dC == 0)
				k = true;
		}
		
		//fflush(stdin);
	 
	}
}

void settings(char userVisual[])
{
	bool k = false;
	int rnd;
	int i = 0, j = 0;
	srand(time(NULL));
	while(k == false)
	{
		system("cls");
			refyLogo();
		printf("\t\t\t\tNome Utente:\t%s", dataUser.username);
		printf("\n\t\t\t\tPassword Codificata:\t");
		//varie stampe random
			if(j == 0)
			rnd = rand()%20+1;
				if(rnd % 2 == 0)
				{
					printf("V7vla9:\"\"da0ò");
						for(i = 0; i < strlen(dataUser.password); i++)
							printf("%c",dataUser.password[i]+i-rnd/2);
					printf("/$d\f.-a*");
				}else if(rnd % 5 == 0)
				{
					printf("uaslk/q1|0b-");
						for(i = 0; i < strlen(dataUser.password); i++)
							printf("%c",dataUser.password[i]-i+rnd/2);
					printf("zgt&(mvèpA)");
				}else if(rnd % 3 == 0)
				{
					printf("òz");
						for(i = 0; i < strlen(dataUser.password); i++)
							printf("%c",dataUser.password[i]-2+rnd+8);
					printf(",:uy6%bcoa9(hckia).PUJkyt610kz;:");
				}else if(rnd % 7 == 0)
				{
					printf("òzxcvhjg7%210=ucn2109?dznctcv(&/x)");
						for(i = 0; i < strlen(dataUser.password); i++)
							printf("%c",dataUser.password[i]+11-rnd+4);
					printf(":;Y/");
				}else
				{
					printf("Bjkha8s08'90cJBYT7Y3I4K,SD\'SdG");
						for(i = 0; i < strlen(dataUser.password); i++)
							printf("%c",dataUser.password[i]-rnd+11);
					printf("dfA");
				}
				
				printf("\n\t\t\t\tMetodo ip:\tIPV4");
				printf("\n\t\t\t\tSalvataggio Cartella Dati:\t%s", userVisual);
				printf("\n\t\t\t\tSicurezza password:\t%d\n\n\n", rnd);
				printf("\n\t\t\t\tVersione:\t8.7.78.426\n\n\n\n\n");
			printf("\t>\tIndietro\n\n");
			if(getch() == 13)
				k = true;
		j++;
	}
	
		//printf("Coming Soon...\n");
}

void refyLogo()
{
	printf("\t\t\t\t\t\t __   ___  ___     \n"
			"\t\t\t\t\t\t|__) |__  |__  \\ / \n"
			"\t\t\t\t\t\t|  \\ |___ |     |  \n\n"
			"\t\t\t\t\t\t\t\tBruno Galimi\n\n\n\n\n\n\n");
}

void menuStart()
{
	 HANDLE  hConsole;
  	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 3);  	

int i;
int base = 0;
char script = 0;
int casi = 0;
int x;
bool k = false;
int cont = 0;
bool registra = false;
bool graphic = false;
bool passwordHide = false;
		while(k == false){
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Parte grafica
system("cls");
refyLogo();
		  	if(base == 0)
		  		printf("\t\t\t>\t%cUsername:\t%s", 250, dataUser.username);
		  	else
				printf("\t\t\t\t%cUsername:\t%s", 250, dataUser.username);
			if(base == 1)
			{
				if(passwordHide == false)
					printf("\n\t\t\t>\t%cPassword:\t%s\t %c", 250, dataUser.password, 155);
				else
				{
					printf("\n\t\t\t>\t%cPassword:\t", 250);
					for(i = 0; i < strlen(dataUser.password); i++)
						printf("*");
					printf("\t%c", 155);
				}
			}
			else if(base == 5)
			{
				if(passwordHide == false)
					printf("\n\t\t\t\t%cPassword:\t%s\t> %c", 250, dataUser.password, 155);
				else
				{
					printf("\n\t\t\t\t%cPassword:\t", 250);
					for(i = 0; i < strlen(dataUser.password); i++)
						printf("*");
					printf("\t>%c", 155);
				}
					
			}
			else
			{
				if(passwordHide == false)
					printf("\n\t\t\t\t%cPassword:\t%s\t %c", 250, dataUser.password, 155);
				else
				{
					printf("\n\t\t\t\t%cPassword:\t", 250);
					for(i = 0; i < strlen(dataUser.password); i++)
						printf("*");
					printf("\t%c", 155);
				}
					
			}
			if(registra == false)
			{
				if(base == 2)
					printf("\n\n\t\t\t\t>\t %cAccedi", 250);
				else
					printf("\n\n\t\t\t\t\t %cAccedi", 250);
			}else if(registra == true)
			{
				if(base == 2)
					printf("\n\n\t\t\t\t>\t%cRegistrati", 250);
				else
					printf("\n\n\t\t\t\t\t%cRegistrati", 250);
			}
			
			if(registra == false)
			{
				if(base == 3)
					printf("\n\n\t\t\t>\t%cRegistrati", 250);
				else
					printf("\n\n\t\t\t\t%cRegistrati", 250);
			}else if(registra == true)
			{
				if(base == 3)
					printf("\n\n\t\t\t>\t%cAccedi", 250);
				else
					printf("\n\n\t\t\t\t%cAccedi", 250);
			}
			if(base == 4)
				printf("\n\n\n\t\t\t>\t%cExit\n", 250);
			else
				printf("\n\n\n\t\t\t\t%cExit\n", 250);
			if(k == false && cont != 0 && registra == false)
			{
				printf("\n\nCredenziali Errate...");
				cont=0;	
			}else if(registra == true && dataUser.username[0] != 0 && dataUser.password[0] != 0 && cont!= 0)
			{
				printf("Registrazione completata...");
				cont = 0;
			}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////fine parte grafica
//printf("\n\t\t\t\t%cPassword:\t...\t>%c", 250 , 155);
graphic = false;
cont = 0;
//printf("\n\n\n\n%d", base);
		if(casi == 0)
			script = getch();
		if(script == 72 || script == 80 || script == 77 || script == 75)
		{
			if(script == 72)
			{
				if(base == 0)
					base = 4;
				else
				{
					if(base != 5)
						base--;
					else
						base = 0;
				}
			}else if(script == 80)
			{
				if(base == 4)
					base = 0;
				else
				{
					if(base != 5)
						base++;
					else
						base = 2;
				}
					
			}
			
//77: destra  75: sinistra  72: su  80: giù

			if(base == 1 && script == 77)
				base = 5;//destra password per non farla vedere
			if(base == 5 && script == 75)
				base = 1;
		}

		if(script == 13)
		{
			if(casi == 0)
			{
				switch(base)
				{
					case 0:
						casi = 1;
						////////////////////////////////
					//	system("PAUSE");
						x = 0;
					break;
					case 1:
						casi = 2;
						x = 0;
					break;
					case 2://caso "bottoni"
						if(registra == false)//caso in cui si accede
						{
							k = controlLogin(k);
						}else if(registra == true && dataUser.username[0] != 0 && dataUser.password[0] != 0)//caso in cui si registra
						{
							addProfile();//si registrazione completata...
						}
							
						cont++;
					break;
					case 3:
						//true --> registrazione mode
							if(registra == true)
							{
								registra = false;
							}
							else if(registra == false)
							{
								registra = true;
							}
								
					break;
					case 4:
						exit(0);
					break;
					case 5:
						if(passwordHide == false)
							passwordHide = true;
						else
							passwordHide = false;
					break;
				}
			}
			
		}
	
if(casi != 0)
printf("\n\nStai scrivendo...");	
		if(casi == 1)
		{
			script = getch();
				if(script != 13)
					dataUser.username[x] = script;
			dataUser.username[x+1] = 0;
			if(script == 13)
				casi = 0;
				
			if(dataUser.username[x] == 8)
			{
				dataUser.username[x-1] = 0;
				x-=2;
			}
			
			x++;
				
		}else if(casi == 2)
		{
			script = getch();
				if(script != 13)
					dataUser.password[x] = script;
			dataUser.password[x+1] = 0;
			if(script == 13)
			{
				casi = 0;
			}
				
				
			if(dataUser.password[x] == 8)
			{
				dataUser.password[x-1] = 0;
				x-=2;
			}
			
			x++;
		}
		
script = 0;
dataUser.username[strlen(dataUser.username)] = '\0';
dataUser.password[strlen(dataUser.password)] = '\0';
fflush(stdin);
		}

  	


}

bool controlLogin(bool k)
{
	FILE *f;
char u[LDATAUSER];
char p[LDATAUSER];
		f = fopen("registro.txt", "r");
			while(!feof(f))
			{
				fscanf(f, "%s %s", u, p);
				if(strcmp(u, dataUser.username) == 0 && strcmp(p, dataUser.password) == 0)
					if(k == false)
						k = true;
			}
fclose(f);
	return k;
}


void addProfile()
{
	FILE *file;

char txt[150];
		sprintf(txt, "User-%s.txt", dataUser.username);
	//printf("\n\n%s", txt);
	//system("PAUSE");
		file = fopen(txt, "w");//creato il file con User-nomeUser
fclose(file);
	file = fopen("registro.txt", "a");
		fprintf(file, "\n%s %s", dataUser.username, dataUser.password);//aggiunto utente e password associata al registro per ricerca accesso
fclose(file);
	
/*char buff[150];
int timestamp = 3;
sprintf(buff, "test-%d.txt", timestamp); per aggiungere file in base all'account
FILE *fout = fopen(buff, "w");*/	
	
}

void SetColor(short Color)
{ 
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon,Color);
}

