#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_NUMBER_OF_ITEMS 10
#define MIN_NUMBER_OF_ITEMS 1

int main(void)
{
    const double MAX_INCOME = 400000.00;
    const double MIN_INCOME = 500.00;
    double income;
    int valid;
    int numOfItems;
    int i;
    const double MIN_COST = 100;
    const int MAX_PRIORITY = 3;
    const int MIN_PRIORITY = 1;
    int priority[MAX_NUMBER_OF_ITEMS];
    double cost [MAX_NUMBER_OF_ITEMS];
    char finance[MAX_NUMBER_OF_ITEMS];
    double total_cost = 0;
    const char YES = 'y';
    const char NO = 'n';

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

    do
    {
        valid = 1;
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < MIN_INCOME)
        {
            valid = 0;
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_INCOME);
        }
        if (income > MAX_INCOME)
        {
            valid = 0;
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_INCOME);
        }
        
        
    } while (valid == 0);
    

    printf("\n");

    do
    {
        valid = 1;
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numOfItems);
        if (numOfItems < MIN_NUMBER_OF_ITEMS || numOfItems > MAX_NUMBER_OF_ITEMS)
        {
            valid = 0;
            printf("ERROR: List is restricted to between %d and %d items.\n", MIN_NUMBER_OF_ITEMS, MAX_NUMBER_OF_ITEMS);
            printf("\n");
        }
        
    } while (valid == 0);
    


    for (i = 0; i < numOfItems; i++)
    {
        printf("\n");
        printf("Item-%d Details:\n", i + 1);

    do
    {
        valid =1;
        printf("   Item cost: $");
        scanf("%lf", &cost[i]);
        if (cost[i] < MIN_COST)
        {
            valid = 0;
            printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
        }
        
    } while (valid ==0);

    do
    {
        valid =1;
        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
        scanf("%d", &priority[i]);
        if (priority[i] < MIN_PRIORITY || priority[i] > MAX_PRIORITY)
        {
            valid = 0;
            printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY, MAX_PRIORITY);
        }
        
    } while (valid ==0);

    do
    {
        valid =1;
        printf("   Does this item have financing options? [y/n]: ");
        scanf(" %c", &finance[i]);
        if (finance[i] != YES && finance[i] != NO)
        {
            valid = 0;
            printf("      ERROR: Must be a lowercase \'y\' or \'n\'\n");
        }
        
    } while (valid ==0);
    
    }

    // report

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numOfItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i+1, priority[i], finance[i], cost[i]);
        total_cost = total_cost + cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total_cost);
    printf("Best of luck in all your future endeavours!\n\n");
    
    return 0;
}