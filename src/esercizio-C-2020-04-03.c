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

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 64
#define PHONE_LEN 20

	typedef
		struct {
			int id; // id numerico del contatto (valore univoco)
			char name[NAME_LEN + 1]; // nome della persona
			char phone[PHONE_LEN + 1]; // numero di telefono
		} contact_type;

	unsigned int counter=0;
	contact_type * create_contact(char *name, char *phone){

		contact_type *person= malloc(sizeof(contact_type));
		if( person == NULL){
			return NULL;
		}

		person->id = counter;
		strcpy(person->name, name);
		strcpy(person->phone, phone);

		counter++;
		return person;

	}

	void print_contact(contact_type * person){

		printf("Person id: %u, name: %s, phone: %s\n",person->id, person->name, person->phone);
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
