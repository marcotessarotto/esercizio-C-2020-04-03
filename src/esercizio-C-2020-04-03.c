#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>


#define NAME_LEN 64
#define PHONE_LEN 20
#define NUM_CONTATTI 2

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

static int ident = 0;
contact_type rubrica[2];

// crea un oggetto di tipo contact_type e lo inizializza con name e phone

contact_type * create_contact(char * name, char * phone){
	rubrica[ident].id=ident;
	strcpy(rubrica[ident].name, name);
	strcpy(rubrica[ident].phone, phone);
	contact_type * ptr = &rubrica[ident];
	ident++;
	return ptr;
}

// scrive su stdout i contenuti dell'oggetto

void print_contact(contact_type * person){

	printf("PERSON:\t");
	printf("Id: %d, ", person->id);
	printf("Name: %s, ", person->name);
	printf("Phone: %s\n", person->phone);


}

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
