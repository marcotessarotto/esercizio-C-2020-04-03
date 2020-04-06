/*
 ho trovato delle difficolta a svolgerlo utilizzando i puntatori come da lei richiesto nelle specifiche
 è un problema o può andar bene lo stesso?
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define NAME_LEN 64
#define PHONE_LEN 20
int univoco = 0;

typedef
	struct {
		int id; // id numerico del contatto (valore univoco)
		char name[NAME_LEN + 1]; // nome della persona
		char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;


contact_type  create_contact(char * name, char * phone){
	contact_type  contact;

	contact.id = univoco ;


	memcpy(contact.name, name, 64 * sizeof(char));
	//contact.name = malloc(65 * sizeof(char))

	memcpy(contact.phone, phone, 20 * sizeof(char));

	univoco++;

	return contact;
}

void print_contact(contact_type  person){
	printf("person: id=%d, ", person.id);

	printf("	name = ");
	 for(int i = 0; i<64; i++){

		 	 if(person.name[i] == ' '){
		 		i= 65;
		 	 }else{
		 		 printf("%c",person.name[i]);
		 	 }

	}

	 printf("	phone = ");
	 	 for(int i = 0; i<20; i++){

	 		if(person.phone[i] == ' '){
	 			i=20;
	 	     }else{
	 	    	 printf("%c", person.phone[i]);
	 	     }

	 	}
	 	printf("\n ___________________ \n");


}


int main(int argc, char *argv[]) {

	contact_type pino = create_contact("pino rossi", "+393331234567");

	if (pino.name == NULL || pino.phone == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	contact_type gino = create_contact("gino verdi", "+393487654321");

	if (gino.name == NULL || gino.phone == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}



	print_contact(pino);

	print_contact(gino);

	return 0;
}
