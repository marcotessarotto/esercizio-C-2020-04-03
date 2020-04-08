#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20

int global_id = 0;

typedef struct {
   int id;
   char name[NAME_LEN + 1];
   char phone[PHONE_LEN + 1];
} contact_type;

contact_type * create_contact(char * name, char * phone)
{
	contact_type* contact = calloc(1, sizeof(contact_type));

	contact->id = global_id;
	strcpy(contact->name, name);
	strcpy(contact->phone, phone);

	global_id++;
	return contact;
}

void print_contact(contact_type * person)
{
	printf("person: id=%d, name='%s', phone='%s'\n", person->id, person->name, person->phone);
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
