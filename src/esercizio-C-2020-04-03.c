#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20
#define ADDRESS_BOOK_SIZE 256

int global_id = 0;


typedef struct {
   int id;
   char name[NAME_LEN + 1];
   char phone[PHONE_LEN + 1];
} contact_type;

contact_type * address_book[ADDRESS_BOOK_SIZE];

contact_type * create_contact(char * name, char * phone)
{
	contact_type* contact = calloc(1, sizeof(contact_type));
	if (contact == NULL) {
		perror("calloc() failed. Quitting.");
		exit(EXIT_FAILURE);
	}

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

int compare_contacts(contact_type * c1, contact_type * c2)
{
	if (c1 == NULL || c2 == NULL)
		return -1;

	int ret = strcmp(c1->name, c2->name);
	if (!ret)
		ret = strcmp(c1->phone, c2->phone);
	return ret;
}

int add_to_address_book(contact_type * c)
{
	if (c == NULL)
		return -1;

	int i = 0;
	while (address_book[i] != NULL) {
		i++;
		if (i == ADDRESS_BOOK_SIZE)
			return -1;
	}
	address_book[i] = c;
	return i;
}

int remove_from_address_book(contact_type * c)
{
	for (int i = 0; i < ADDRESS_BOOK_SIZE; i++) {
		if (!compare_contacts(address_book[i], c)) {
			address_book[i] = NULL;
			return i;
		}
	}
	return -1;
}

int search_in_address_book(contact_type * c)
{
	for (int i = 0; i < ADDRESS_BOOK_SIZE; i++) {
		if (!compare_contacts(address_book[i], c))
			return i;
	}
	return -1;
}

// Sorting implemented through "insertion sort"
void sort_by_name()
{
	for (int i = 1; i < ADDRESS_BOOK_SIZE; i++) {
		contact_type * key = address_book[i];
		int j = i - 1;
		while (j >= 0 && compare_contacts(address_book[j], key) > 0) {
			address_book[j + 1] = address_book[j];
			j--;
		}
		address_book[j + 1] = key;
	}
}

int main(int argc, char *argv[]) {
	contact_type * dino = create_contact("dino", "+391237");
	contact_type * filippo = create_contact("filippo", "+391239");
	contact_type * barbara = create_contact("barbara", "+391235");
	contact_type * antonio = create_contact("antonio", "+391234");
	contact_type * enrico = create_contact("enrico", "+391238");
	contact_type * chiara = create_contact("chiara", "+391236");

	add_to_address_book(dino);
	add_to_address_book(filippo);
	add_to_address_book(barbara);
	add_to_address_book(antonio);
	add_to_address_book(enrico);
	add_to_address_book(chiara);

	if (search_in_address_book(antonio) >= 0)
		printf("Removed from pos %d\n", remove_from_address_book(antonio));

	contact_type * pino = create_contact("pino", "+399999");
	add_to_address_book(pino);

	puts("Address book:");
	for (int i = 0; i < ADDRESS_BOOK_SIZE; i++) {
		if (address_book[i] != NULL)
			print_contact(address_book[i]);
	}

	add_to_address_book(antonio);

	sort_by_name();
	puts("Sorted address book:");
	for (int i = 0; i < ADDRESS_BOOK_SIZE; i++) {
		if (address_book[i] != NULL)
			print_contact(address_book[i]);
	}

	return 0;
}
