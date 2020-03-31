/* RUBRICA TELEFONICA */
/*  1) Inserire nuovo contatto
    2) Ricerca contatto - prende il nome e trova tutti i numeri con tale nome
                        - prende il cognome e trova tutti i numeri con tale cognome
                        - prende il numero, e trova il contatto con tale numero.
    3) uscita
Il programma utilizza un file, come mezzo per salvare le informazioni. E per leggere le informazioni.
*/

#include <stdio.h>
#include <string.h>
#define MAXCHAR 30
#define MAX 100

typedef struct {
	char name[MAXCHAR];
	char surname[MAXCHAR];
	int number;
}Contact;

typedef struct {
	Contact contact[MAX];
	int total;
}Library;

void newcontact(Library *library) {
	if (library->total==MAX) {
		printf("Not enough free space.\n");
	} else {
		printf("Insert name: ");
		scanf("%s", library->contact[(library->total)].name);
		printf("Insert surname: ");
		scanf("%s", library->contact[(library->total)].surname);
		printf("Insert number: ");
		scanf("%d", &(library->contact[(library->total)].number));
		library->total=(library->total)+1;
	}
}

void printer(Library *l) {
	int i;
	for (i=0; i<l->total; i=i+1) {
		printf("%s - %s - %d\n", l->contact[i].name, l->contact[i].surname, l->contact[i].number);
	}
}

int main() {
	Library library;
	char fileName[MAXCHAR];
	int i=0;
	int option;
	int turnback=0;
	int search;
	int number;
	char string[MAXCHAR];
	FILE *fp;
	
	
	printf("Insert database name: ");
	scanf("%s", fileName);
	fp=fopen(fileName, "r");
	if (fp) {
		while(!feof(fp)) {
			fscanf(fp, "%s - %s - %d\n", library.contact[i].name, library.contact[i].surname, &library.contact[i].number);
			i=i+1;
		}
		library.total=i;
	} else {
		printf("Can't read the file.\n");
	}
	fclose(fp);
	/*
	printf("Data Scanned:\n");
	printf("Scanned contacts: %d\n", library.total);
	for (i=0; i<library.total; i=i+1) {
		printf("%s - %s - %d\n", library.contact[i].name, library.contact[i].surname, library.contact[i].number);
	}
	*/
	do {
		printf("1) Insert a new contact.\n");
		printf("2) Show me all the contacts.\n");
		printf("3) Search a contact.\n");
		printf("4) Exit.\n");
		printf("Option: ");
		scanf("%d", &option);
		
		if (option==1) {
			newcontact(&library);
			printf("If you want to turnback to the main menu press 0.\n");
			printf("If you want to exit, press any other key.\n");
			printf("Option: ");
			scanf("%d", &turnback);
		} else if (option==2) {
			printf("Library Contacts: %d\n", library.total);
			printer(&library);
			printf("If you want to turnback to the main menu press 0.\n");
			printf("If you want to exit, press any other key.\n");
			printf("Option: ");
			scanf("%d", &turnback);
		} else if (option==3) {
			printf("1) Search a contact by number.\n");
			printf("2) Search a contact by name.\n");
			printf("3) Search a contact by surname.\n");
			scanf("%d", &search);
			if (search==1) {
				printf("Insert a number: ");
				scanf("%d", &number);
				for (i=0; i<library.total; i=i+1) {
					if (number==library.contact[i].number) {
						printf("%s - %s - %d\n", library.contact[i].name, library.contact[i].surname, library.contact[i].number);
					} else {
					}
				}
			} else if (search==2) {
				printf("Insert the name: ");
				scanf("%s", string);
				for (i=0; i<library.total; i=i+1) {
					if (strcmp(library.contact[i].name, string)==0) {
						printf("%s - %s - %d\n", library.contact[i].name, library.contact[i].surname, library.contact[i].number);
					} else {
					}
				}
			} else if (search==3) {
				printf("Insert the surname: ");
				scanf("%s", string);
				for (i=0; i<library.total; i=i+1) {
					if (strcmp(library.contact[i].surname, string)==0) {
						printf("%s - %s - %d\n", library.contact[i].name, library.contact[i].surname, library.contact[i].number);
					} else {
					}
				}
			} else {
			}
			printf("If you want to turnback to the main menu press 0.\n");
			printf("If you want to exit, press any other key.\n");
			printf("Option: ");
			scanf("%d", &turnback);
		} else {
			turnback=1;
		}
	} while (turnback==0);
	printf("Goodbye!\n");
	fp=fopen(fileName, "w");
	if (fp) {
		for (i=0; i<library.total; i=i+1) {
			fprintf(fp, "%s - %s - %d\n", library.contact[i].name, library.contact[i].surname, library.contact[i].number);
		}
	} else {
		printf("Can't read the outsource database file.\n");
		printf("All your saved data is going to be lost.\n");
	}
	fclose(fp);
	getch();
	return 0;
	
}


