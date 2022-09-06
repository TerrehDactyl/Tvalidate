#include<stdio.h>

int main()
{
	int card_no[15];
	printf("Enter a card number (must be 16 digits)\n");

	for(int i=0; i<=15; i++)
		scanf("%1d", &card_no[i]);

	for(int i=0; i<=15; i++)
		printf("%d", card_no[i]);

	int total = 0;
	for(int i=0; i<15; i++)
	{
		if(i==0 || i%2==0)
		{
			card_no[i] = card_no[i]*2;
			if(card_no[i] > 9)
			{
				int first_num = card_no[i]/10;
				int sec_num = card_no[i]%10;
				card_no[i] = first_num+sec_num;
			}
		}
		total += card_no[i];
	}
	total += card_no[15];

	if(total % 10 == 0)
		printf("\nCard Is VALID\n");
	else
		printf("\nCard Is NOT VALID\n");

	printf("CHECKSUM: %d\n", total);
}