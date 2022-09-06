#include<stdio.h>

int main()
{
	int card_no[15];
	printf("Enter a card number (must be 16 digits)\n");

	for(int i=0; i<=15; i++)
		scanf("%1d", &card_no[i]);

	switch(card_no[0])
	{
		case 3: printf("\nAmerican Express\n");
		break;
		case 4: printf("\nVisa\n");
		break;
		case 5: printf("\nMasterCard\n");
		break;
		case 6: printf("\nDiscover\n");
		break;
		default: printf("\nNOT VALID");
	}
}