#include <stdio.h>

#define MIN_ITEM 1
#define MAX_ITEM 10
#define MIN_INCOME 500
#define MAX_INCOME 400000
#define MIN_COST 100.00

int main(void)
{
	int valid = 1;
	int financing_done;
	double income;
	double months;
	int noOfItems;
	int selection;
	int i, years;
	int items[MAX_ITEM];
	double cost;
	double cost_count[MAX_ITEM];
	double total_cost = 0, cost_priority_1 = 0, cost_priority_2 = 0, cost_priority_3 = 0;
	int priority, priority_count[MAX_ITEM];
	char finance, finance_count[MAX_ITEM];

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &income);
		if (income < MIN_INCOME)
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		else if (income > MAX_INCOME)
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		else
			valid = 0;
	} while (valid);
	valid = 1;

	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &noOfItems);
		if (noOfItems < MIN_ITEM || noOfItems > MAX_ITEM)
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		else
			valid = 0;
	} while (valid);

	for (i = 0; i < noOfItems; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);
		valid = 1;
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &cost);
			if (cost < MIN_COST)
				printf("      ERROR: Cost must be at least $100.00\n");
			else
			{
				total_cost += cost;
				cost_count[i] = cost;
				valid = 0;
			}
		} while (valid);
		valid = 1;

		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority);
			if (priority < 1 || priority > 3)
				printf("      ERROR: Value must be between 1 and 3\n");
			else
			{
				priority_count[i] = priority;
				switch (priority)
				{
				case 1:
					cost_priority_1 += cost_count[i];
					break;

				case 2:
					cost_priority_2 += cost_count[i];
					break;

				case 3:
					cost_priority_3 += cost_count[i];
					break;

				default:
					break;
				}
				valid = 0;
			}
		} while (valid);
		valid = 1;

		do
		{
			scanf("%*c");
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%c", &finance);
			switch (finance)
			{
			case 'y':
			case 'n':
				finance_count[i] = finance;
				valid = 0;
				break;
			default:
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (valid);
		items[i] = i + 1;
	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < noOfItems; i++)
		printf("%3d  %5d    %5c    %11.2lf\n", items[i], priority_count[i], finance_count[i], cost_count[i]);
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total_cost);
	valid = 1;

	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selection);

		if (selection == 0)
			valid = 0;
		else if (selection == 1)
		{
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", total_cost);
			total_cost *= 100;
			income *= 100;
			years = (int)total_cost / (int)(income * 12);
			months = ((int)total_cost % (int)(income * 12)) / income;
			printf("Forecast: %d years, %.0lf months\n", years, months);
			total_cost /= 100;
			income /= 100;
			financing_done = 0;
			for (i = 0; i < noOfItems; i++)
				if (finance_count[i] == 'y')
					financing_done = 1;
			if (financing_done)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
		}

		else if (selection == 2)
		{
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &priority);
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", priority);
			financing_done = 0;

			switch (priority)
			{
			case 1:
				printf("Amount:   $%1.2lf\n", cost_priority_1);
				cost_priority_1 *= 100;
				income *= 100;
				years = (int)cost_priority_1 / (int)(income * 12);
				months = ((int)cost_priority_1 % (int)(income * 12)) / income;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				cost_priority_1 /= 100;
				income /= 100;
				for (i = 0; i < noOfItems; i++)
					if (priority_count[i] == priority)
						if (finance_count[i] == 'y')
							financing_done = 1;
				break;

			case 2:
				printf("Amount:   $%1.2lf\n", cost_priority_2);
				cost_priority_2 *= 100;
				income *= 100;
				years = (int)cost_priority_2 / (int)(income * 12);
				months = (((int)cost_priority_2 % (int)(income * 12)) / income) + 1;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				cost_priority_2 /= 100;
				income /= 100;
				for (i = 0; i < noOfItems; i++)
					if (priority_count[i] == priority)
						if (finance_count[i] == 'y')
							financing_done = 1;
				break;

			case 3:
				printf("Amount:   $%1.2lf\n", cost_priority_3);
				cost_priority_3 *= 100;
				income *= 100;
				years = (int)cost_priority_3 / (int)(income * 12);
				months = ((int)cost_priority_3 % (int)(income * 12)) / income;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				cost_priority_3 /= 100;
				income /= 100;
				for (i = 0; i < noOfItems; i++)
					if (priority_count[i] == priority)
						if (finance_count[i] == 'y')
							financing_done = 1;
				break;

			default:
				break;
			}

			if (financing_done)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
		}
		else
			printf("\nERROR: Invalid menu selection.\n");
		printf("\n");
	} while (valid);

	printf("Best of luck in all your future endeavours!\n\n");

	return 0;
}