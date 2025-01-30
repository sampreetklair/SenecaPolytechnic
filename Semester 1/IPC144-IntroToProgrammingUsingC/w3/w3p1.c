#include <stdio.h>

int main()
{
    const double testValue = 330.99;
    const int product1_id = 111, product2_id = 222, product3_id= 111;
    const char product1_taxed = 'Y', product2_taxed ='N', product3_taxed='N';
    const double price1=111.4900, price2=222.9900, price3=334.4900;
    double avg_price = (price1+price2+price3)/3.0;


    printf("Product Information\n");
    printf("===================\n");

    printf("Product-1 (ID:%d)\n", product1_id);
    printf("  Taxed: %c\n", product1_taxed);
    printf("  Price: $%.4lf\n", price1);
    printf("\n");

    printf("Product-2 (ID:%d)\n", product2_id);
    printf("  Taxed: %c\n", product2_taxed);
    printf("  Price: $%.4lf\n", price2);
    printf("\n");

    printf("Product-3 (ID:%d)\n", product3_id);
    printf("  Taxed: %c\n", product3_taxed);
    printf("  Price: $%.4lf\n", price3);
    printf("\n");

    printf("The average of all prices is: $%.4lf", avg_price);
    printf("\n\n");

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", product1_taxed == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", product2_taxed && product3_taxed == 'N');
    printf("3. Is product 3 less than testValue ($330.99)? -> %d\n\n", price3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", price3 > price1+price2);
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", price1>=price3-price2, price3-price2);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", price2 >= avg_price);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", product1_id != product2_id && product1_id != product3_id);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", product2_id != product1_id && product2_id != product3_id);
    printf("9. Based on product ID, product 3 is unique -> %d\n", product3_id != product1_id && product3_id != product2_id);

    return 0;
}
