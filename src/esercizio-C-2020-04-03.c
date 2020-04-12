// Diaa Nehme  IN0500345  esercizio20200403

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 64
#define PHONE_LEN 20

unsigned int counter = 0;
typedef
	struct {
		unsigned int id; // id contact number (unique value)
		char name[NAME_LEN + 1]; // person name
		char phone[PHONE_LEN + 1]; // phone number
	} contact_type;

// Create Contact Function
contact_type * create_contact(char * name, char * phone){

	contact_type * person;

	person = malloc(sizeof(contact_type));
	if( person == NULL){
		return NULL;
	}

	person->id = counter;
	strcpy(person->name, name);
	strcpy(person->phone, phone);

	counter++;
	return person;

}

// Print Contact Function
void print_contact(contact_type * person){

	printf("Person id: %u, name: %s, phone: %s\n",person->id, person->name, person->phone);
}


int main(int argc, char *argv[]) {

contact_type * pino = create_contact("Pino Rossi", "+393331234567");

	if (pino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

contact_type * gino = create_contact("Gino Verdi", "+393487654321");

	if (gino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

print_contact(pino);
print_contact(gino);

return 0;
}
