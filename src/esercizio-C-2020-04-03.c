#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20
#define CONTACTS_LIMIT 2

typedef struct{
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
}contact_type;

// method signatures
contact_type * create_contact(char * name, char * phone);
void print_contact(contact_type * person);

// global variables
static int contacts_active = 0;
contact_type contacts[CONTACTS_LIMIT];

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

// creates an object of type contact_type and initializes it with name and phone
contact_type * create_contact(char * name, char * phone){
	contacts[contacts_active].id = contacts_active;
	strcpy(contacts[contacts_active].name, name);
	strcpy(contacts[contacts_active].phone, phone);
	contact_type *ptr_contact;
	ptr_contact = &contacts[contacts_active];
	contacts_active++;
	return ptr_contact;
}

// writes the contents of the object on stdout
void print_contact(contact_type * person){
	if(person == NULL){
		printf("pointer to NULL in print_contact\n");
	}else{
		printf("person: id=%d, name='%s', phone='%s'\n", person->id, person->name, person->phone);
	}
}


