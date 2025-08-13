#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#define LDATAUSER 20


void menuStart();
bool controlLogin(bool k);
void codi(char str[]);
void addProfile();

struct s_dataUser{
	char username[LDATAUSER];
	char password[LDATAUSER];
}dataUser;

void main()
{
	FILE *file;
		file = fopen("registro.txt", "a");
if(file == NULL)
	fprintf(file, "%s %s", "admin", "admin");
fclose(file);



	menuStart();
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
////////////////////////////////////////////////////////////////////////////////////////////////////Parte grafica
system("cls");
			printf("\t\t\t\t\t\t __   ___  ___     \n"
			  		"\t\t\t\t\t\t|__) |__  |__  \\ / \n"
			  		"\t\t\t\t\t\t|  \\ |___ |     |  \n\n"
					  "\t\t\t\t\t\t\t\tBruno Galimi\n\n\n\n\n\n\n");
		  	
		  	
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
////////////////////////////////////////////////////////////////////////////////////////////////fine parte grafica
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
printf("\n\nScrivendo...");	
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



