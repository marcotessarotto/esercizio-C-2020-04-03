#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 64
	#define PHONE_LEN 20

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

int id=0;

contact_type * create_contact(char * name, char * phone){

	contact_type * person=malloc(sizeof(contact_type));

	(*person).id=id;
	memcpy((*person).name,name,(NAME_LEN + 1) * sizeof(char));
	memcpy((*person).phone,phone,(PHONE_LEN + 1) * sizeof(char));

	id++;

	return person;

}

void print_contact (contact_type * person){

	printf("person: id=%d, name='%s', phone='%s\n\n",(*person).id,(*person).name,(*person).phone);

}


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

