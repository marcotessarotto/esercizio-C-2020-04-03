//

#include <stdio.h>
#include<locale.h>
#include<stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


/*
 è dato il tipo dati contact_type, dovrebbe servire ad implementare una rubrica telefonica molto semplice:

#define NAME_LEN 64
#define PHONE_LEN 20

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

scrivere le seguenti funzioni:

// crea un oggetto di tipo contact_type e lo inizializza con name e phone
contact_type * create_contact(char * name, char * phone);

// scrive su stdout i contenuti dell'oggetto
void print_contact(contact_type * person);

.....

// utilizzare questa implementazione di main:

int main(int argc, char *argv[]) {

	contact_type * pino = create_contact("pino rossi", "+393331234567");

	if (pino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	contact_type * gino = create_contact("gino verdi", "+393487654321");

	if (gino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	print_contact(pino);

	print_contact(gino);

	return 0;
}


il risultato dell'esecuzione del programma sarà questo:

person: id=0, name='pino rossi', phone='+393331234567'
person: id=1, name='gino verdi', phone='+393487654321'
 */
#define NAME_LEN 64
#define PHONE_LEN 20


typedef struct {
	int id; // id numerico del contatto (valore univoco)
	char name[NAME_LEN + 1]; // nome della persona
	char phone[PHONE_LEN + 1]; // numero di telefono
}contact_type;

// crea un oggetto di tipo contact_type e lo inizializza con name e phone
int* ptr_count;
int count=0;


contact_type* create_contact(char * name, char * phone){


contact_type* temp;
temp=(contact_type*)malloc(sizeof(contact_type));
memcpy(temp->name,name,(NAME_LEN + 1)*sizeof(char));
//printf("%s\n",temp->name);
memcpy(temp->phone,phone,(PHONE_LEN+1)*sizeof(char));
//printf("%s\n",temp->phone);

temp->id=count;
//printf("%d\n",temp->id);



return temp;
}


// scrive su stdout i contenuti dell'oggetto

void print_contact(contact_type * person){

	printf("\nperson: id='%d'\tname='%s'\tphone='%s'\n",person->id,person->name,person->phone);
}


int main(int argc, char *argv[]) {
	count=0;
	ptr_count=&count;
	contact_type * pino;
	pino= create_contact("pino rossi", "+393331234567");
	//printf("\n sono vivo");

	if (pino == NULL) {
		printf("errore in create_contact pino!\n");
		exit(EXIT_FAILURE);
	}
	*ptr_count=*ptr_count+1;
	contact_type * gino;
	gino= create_contact("gino verdi", "+393487654321");

	if (gino == NULL) {
		printf("errore in create_contact gino!\n");
		exit(EXIT_FAILURE);
	}

	print_contact(pino);

	print_contact(gino);
	free(pino);
	free(gino);

	return 0;
}
