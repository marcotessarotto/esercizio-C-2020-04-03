#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NAME_LEN 64
#define PHONE_LEN 20

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

int n_contact=0;

// crea un oggetto di tipo contact_type e lo inizializza con name e phone
contact_type * create_contact(char * name, char * phone){
	if((name==NULL) || (strlen(name)>NAME_LEN)){
		return NULL;
	}
	if((phone==NULL) || (strlen(phone)>PHONE_LEN)){
		return NULL;
	}
	contact_type * ptr_to_contact;
	ptr_to_contact=malloc(sizeof(contact_type));
	if(ptr_to_contact==NULL){
		return NULL;
	}
	n_contact++;
	strcpy(ptr_to_contact->name, name);
	strcpy(ptr_to_contact->phone, phone);
	ptr_to_contact->id=n_contact;
	return ptr_to_contact;
}


// scrive su stdout i contenuti dell'oggetto
void print_contact(contact_type * person){
	if(person==NULL){
		printf("Contatto non valido\n");
	}
	else{
		printf("person: id=%d, name='%s', phone='%s'\n", person->id, person->name, person->phone);
	}
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

/*il risultato dell'esecuzione del programma sarà questo:
 *person: id=0, name='pino rossi', phone='+393331234567'
 *person: id=1, name='gino verdi', phone='+393487654321'
 */
