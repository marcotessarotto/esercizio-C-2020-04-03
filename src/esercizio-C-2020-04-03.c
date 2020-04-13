#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// variabile globale usata da create_contact()
int id_counter; // già inizializzato a 0

#define NAME_LEN 64
#define PHONE_LEN 20

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;


// crea un oggetto di tipo contact_type e lo inizializza con name e phone
contact_type * create_contact(char * name, char * phone);

// scrive su stdout i contenuti dell'oggetto
void print_contact(contact_type * person);


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

/*
il risultato dell'esecuzione del programma sarà questo:

person: id=0, name='pino rossi', phone='+393331234567'
person: id=1, name='gino verdi', phone='+393487654321'
 */

// crea un oggetto di tipo contact_type e lo inizializza con name e phone
contact_type * create_contact(char * name, char * phone) {
	contact_type * result;

	result = calloc(1, sizeof(contact_type));

	result->id = id_counter;
	id_counter++;
	// oppure:
	// result->id = id_counter++;

	/*
	NB:
	   result->id = ++id_counter;
	equivale a:
	   id_counter++;
	   result->id = id_counter;
	 */

	if (name != NULL)
		strncpy(result->name, name, NAME_LEN);

	if (phone != NULL)
		strncpy(result->phone, phone, PHONE_LEN);

	return result;
}

// scrive su stdout i contenuti dell'oggetto
void print_contact(contact_type * person) {
	printf("person: id=%d, name='%s', phone='%s'\n", person->id, person->name, person->phone);
}




