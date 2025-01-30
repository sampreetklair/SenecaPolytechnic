#include <stdio.h>

int main(void)
{    
    char coffee1_type, coffee2_type, coffee3_type, urcoffee1_type, urcoffee2_type;
    int coffee1_weight, coffee2_weight, coffee3_weight, urcoffee1_serving, urcoffee2_serving;
    char coffee1_cream_suggested, coffee2_cream_suggested, coffee3_cream_suggested, urcoffee1_cream_liking, urcoffee2_cream_liking;
    const double GRAMS_IN_LBS = 453.5924;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee1_type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee1_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee1_cream_suggested);
    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2_type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee2_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee2_cream_suggested);
    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3_type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee3_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee3_cream_suggested);
    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee1_type == 'l' || coffee1_type ==  'L', coffee1_type == 'm' || coffee1_type == 'M', coffee1_type == 'r' || coffee1_type == 'R', coffee1_weight, coffee1_weight/GRAMS_IN_LBS, coffee1_cream_suggested == 'y' || coffee1_cream_suggested == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee2_type == 'l' || coffee2_type == 'L', coffee2_type == 'm' || coffee2_type == 'M', coffee2_type == 'r' || coffee2_type == 'R', coffee2_weight, coffee2_weight/GRAMS_IN_LBS, coffee2_cream_suggested == 'y' || coffee2_cream_suggested == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee3_type == 'l' || coffee3_type == 'L', coffee3_type == 'm' || coffee3_type == 'M', coffee3_type == 'r' || coffee3_type == 'R', coffee3_weight, coffee3_weight/GRAMS_IN_LBS, coffee3_cream_suggested == 'y' || coffee3_cream_suggested == 'Y');
    printf("\n");

    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &urcoffee1_type);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &urcoffee1_cream_liking);
    printf("Typical number of daily servings: ");
    scanf("%d", &urcoffee1_serving);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", urcoffee1_type == 'l' || urcoffee1_type == 'L', 1 <= urcoffee1_serving && urcoffee1_serving <= 4, urcoffee1_cream_liking == 'Y' || urcoffee1_cream_liking == 'y');
    printf(" 2|       %d         |      %d      |   %d   |\n", urcoffee1_type == 'r' || urcoffee1_type == 'R', 5 <= urcoffee1_serving && urcoffee1_serving <= 9, urcoffee1_cream_liking == 'N' || urcoffee1_cream_liking == 'n');
    printf(" 3|       %d         |      %d      |   %d   |\n", urcoffee1_type == 'm' || urcoffee1_type == 'M', 10 <= urcoffee1_serving, urcoffee1_cream_liking == 'N' || urcoffee1_cream_liking == 'n');
    printf("\n");

    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &urcoffee2_type);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &urcoffee2_cream_liking);
    printf("Typical number of daily servings: ");
    scanf("%d", &urcoffee2_serving);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", urcoffee2_type == 'l' || urcoffee2_type == 'L', 1 <= urcoffee2_serving && urcoffee2_serving <= 4, urcoffee2_cream_liking == 'Y' || urcoffee2_cream_liking == 'y');
    printf(" 2|       %d         |      %d      |   %d   |\n", urcoffee2_type == 'r' || urcoffee2_type == 'R', 5 <= urcoffee2_serving && urcoffee2_serving <= 9, urcoffee2_cream_liking == 'N' || urcoffee2_cream_liking == 'n');
    printf(" 3|       %d         |      %d      |   %d   |\n", urcoffee2_type == 'm' || urcoffee2_type == 'M', 10 <= urcoffee2_serving, urcoffee2_cream_liking == 'N' || urcoffee2_cream_liking == 'n');
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    printf("\n");
    
    return 0;
}
