#include<stdio.h>
#include "gtktemplate.h"
//compile with gcc -Wall -g validator.c -o validator `pkg-config --cflags --libs gtk+-3.0`
void validate();
void company_check(int card_no[]);

#define LENGTH 15
#define base 10
gchar *labels[] = {"Card #", "CVV"};
size_t len = arraysize(labels); 
GtkWidget *entries[2];
const gchar *entry_text[2];

int main(int argc, char *argv[])
{
	gchar *button_label[] = {"Validate"};
	void *callback[] ={validate};

	gtk_init(&argc, &argv); //initializes GTK

	GtkWidget *window = createwindow("Card Validator", GTK_WIN_POS_CENTER, "test.png"); 
	GtkWidget *entry_labels = createlabels(labels, len);
	set_spacing(entry_labels, 10,20); 
	GtkWidget *entrygrid = gtk_grid_new();
	create_entries(len, entries, entrygrid);
	GtkWidget *button = createsinglesizegrid(button_label, callback, NULL, 1, 1);

	GtkWidget *entrybox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1); //creates a horizontal box without autosizing
	GtkWidget *buttonbox =  gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	gtk_container_add(GTK_CONTAINER(window), buttonbox);
	gtk_box_pack_start(GTK_BOX(buttonbox),  entrybox, FALSE, FALSE, 0); 
	gtk_box_pack_start(GTK_BOX(entrybox),  entry_labels, FALSE, FALSE, 0); 
	gtk_box_pack_start(GTK_BOX(entrybox),  entrygrid, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(buttonbox),  button, FALSE, FALSE, 0); 

	show_and_destroy(window);
}

void validate()
{
	get_entry_text(entries, entry_text, len); //need to work on this
	char* end;
	long int first_card_holder = strtol(entry_text[0], &end, base);
	long int first_cvv_holder = strtol(entry_text[1], &end, base);
	int card_no[LENGTH];
	int second_card_holder[LENGTH];
	int total = 0;

	for(int i=0; first_card_holder!=0; i++)
	{
		card_no[LENGTH-i] = first_card_holder % 10;
		second_card_holder[LENGTH-i] = first_card_holder %10;
		first_card_holder /= 10;

		if(i==0 || i%2==0)
		{
			second_card_holder[LENGTH-i] = second_card_holder[LENGTH-i]*2;
			if(second_card_holder[LENGTH-i] > 9)
			{
				int first_num = second_card_holder[LENGTH-i]/10;
				int sec_num = second_card_holder[LENGTH-i]%10;
				second_card_holder[LENGTH-i] = first_num+sec_num;
			}
		}
		total += second_card_holder[LENGTH-i];
	}

	if(total % 10 == 0)
		company_check(card_no);
	else
		printf("\nCard Is NOT VALID\n");
	printf("CHECKSUM: %d\n", total);
}

void company_check(int card_no[])
{
	switch(card_no[0])
		{
			case 3: printf("Card Number Is VALID\nCard Type:American Express\n");
			break;
			case 4: printf("Card Number Is VALID\nCard Type:Visa\n");
			break;
			case 5: printf("Card Number Is VALID\nCard Type:MasterCard\n");
			break;
			case 6: printf("Card Number Is VALID\nCard Type:Discover\n");
			break;
			default: printf("Card Number Is VALID\nCard Type:NOT VALID");
		}
}