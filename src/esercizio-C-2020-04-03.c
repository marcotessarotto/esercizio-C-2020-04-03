#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20


typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

int counter = 0;
contact_type * create_contact(char * name, char * phone) {
	contact_type * result = malloc(sizeof(contact_type));
	memset(result, 0, sizeof(contact_type));
	(*result).id = counter;
	memcpy((*result).name, name , NAME_LEN+1);
	memcpy((*result).phone, phone, PHONE_LEN+1);

	counter++;

	return result;

}

void print_contact(contact_type * person) {
	printf("\nEcco il contenuto del contatto:\n");
	printf("person: id=%d, name='%s', phone='%s'", (*person).id, (*person).name, (*person).phone);
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
