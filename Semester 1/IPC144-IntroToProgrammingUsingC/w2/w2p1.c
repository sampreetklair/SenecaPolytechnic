#include <stdio.h>

int main(){

    double price_small, price_medium, price_large;
    int number;
    int sub_total, taxes, total;
    const double TAX = 0.13;

    printf("Set Shirt Prices"); printf("\n");
    printf("================"); printf("\n");
    printf("Enter the price for a SMALL shirt: $"); 
    scanf("%lf", &price_small);
    printf("Enter the price for a MEDIUM shirt: $"); 
    scanf("%lf", &price_medium);
    printf("Enter the price for a LARGE shirt: $"); 
    scanf("%lf", &price_large); printf("\n");
    printf("Shirt Store Price List"); printf("\n");
    printf("======================"); printf("\n");
    printf("SMALL  : $%.2lf",price_small); printf("\n");
    printf("MEDIUM : $%.2lf", price_medium); printf("\n");
    printf("LARGE  : $%.2lf", price_large); printf("\n\n");
    printf("Patty's shirt size is \'S\'"); printf("\n");
    printf("Number of shirts Patty is buying: "); 
    scanf("%d", &number); printf("\n");

    sub_total = (number * price_small * 100)+ 0.5;
    taxes = sub_total * TAX + 0.5;
    total = sub_total + taxes;


    printf("Patty's shopping cart..."); printf("\n");
    printf("Contains : %d shirts", number); printf("\n");
    printf("Sub-total: $%8.4lf", (double)sub_total/100); printf("\n");
    printf("Taxes    : $%8.4lf", (double)taxes/100); printf("\n");
    printf("Total    : $%8.4lf", (double)total/100); printf("\n");

    return 0;
}
