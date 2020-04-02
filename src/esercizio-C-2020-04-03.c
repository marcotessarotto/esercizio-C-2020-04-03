#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAME_LEN 64
#define PHONE_LEN 20

typedef struct {
   int id;
   char name[NAME_LEN + 1];
   char phone[PHONE_LEN + 1];
} contact_type;


/**
 * Creates and init a contact_type stucture
 */
int counter = 0;
contact_type * create_contact(char * name, char * phone) {
	// Malloc
	contact_type * obj = malloc(sizeof(contact_type));
	if (obj == NULL) {
		return NULL;
	}
	// Init
	obj->id = counter++; // id
	memcpy(obj->name, name, NAME_LEN + 1);
	memcpy(obj->phone, phone, PHONE_LEN + 1);
	// or
	// strcpy(obj->name, "Bourt");
	// strcpy(obj->phone, "Svara");
	// Output
	return obj;
}

/**
 * Print a contact_type
 */
void print_contact(contact_type * person) {
	printf("person: id=%d, name=%s, phone=%s\n", person->id, person->name, person->phone);
}

/**
 * Test
 */
int main(int argc, char **argv) {

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


