/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Sampreet Klair
Student ID#: 145031225
Email      : sklair2@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num){
    int val;
    do{
        scanf("%d", &val);
        if (val <= 0){
            printf("ERROR: Enter a positive value: ");
        }
    }while (val <=0);
    
    if (num!= NULL)
        *num = val;
    return val;
    
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num){
    double value;
    do{
        scanf("%lf", &value);
        if (value <= 0){
            printf("ERROR: Enter a positive value: ");
        }
    }while (value <=0);
    
    if (num!= NULL)
        *num = value;
    return value;
    
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product){
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
    printf("NOTE: A 'serving' is %dg\n\n", NUM_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_num) {
	struct CatFoodInfo food;
	int valid;
	printf("Cat Food Product #%d\n", sequence_num + 1);
	printf("--------------------\n");
	valid = 1;

	printf("SKU           : ");
	valid = 1;
	do{
		scanf("%d", &food.sku);
		if (food.sku <= 0){
			printf("ERROR: Enter a positive value: ");
		}
		else{
			valid = 0;
		} 
	} while (valid);

	printf("PRICE         : $");
	valid = 1;
	do{
		scanf("%lf", &food.price);
		if (food.price <= 0){
			printf("ERROR: Enter a positive value: ");
		}
		else{
			valid = 0;
		} 
	} while (valid);

	printf("WEIGHT (LBS)  : ");
	valid = 1;
	do{
		scanf("%lf", &food.weight);
		if (food.weight <= 0){
			printf("ERROR: Enter a positive value: ");
		}
		else{
			valid = 0;
		} 
	} while (valid);

	printf("CALORIES/SERV.: ");
	valid = 1;
	do{
		scanf("%d", &food.calories);
		if (food.calories <= 0){
			printf("ERROR: Enter a positive value: ");
		}
		else{
			valid = 0;
		}
	} while (valid);

	printf("\n");
	return food;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories){
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}





// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* result_lbstokg){
	double lbstokg = (*lbs) / LBS_KG_CONSTANT;
	if (result_lbstokg != NULL){
		*result_lbstokg = lbstokg;
	}
	return lbstokg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* result_lbstog){
	int lbstog = ((*lbs) / LBS_KG_CONSTANT) * 1000;
	if (result_lbstog != NULL){
		*result_lbstog = lbstog;
	}
	return lbstog;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* result_lbstokg, int* result_lbstog){
	double lbstokg = (*lbs) / LBS_KG_CONSTANT;
	int lbstog = ((*lbs) / LBS_KG_CONSTANT) * 1000;
	if (result_lbstog != NULL && result_lbstokg != NULL){
		*result_lbstog = lbstog;
		*result_lbstokg = lbstokg;
	}
}

// 11. calculate: servings based on gPerServ
double gm_per_serv(const int gm_size, const int total_gm, double* num_serv){
	double cal_serving = ((double) total_gm) / gm_size;
	if (num_serv != NULL)
	{
		*num_serv = cal_serving;
	}
	return cal_serving;
}

// 12. calculate: cost per serving
double cost_per_serv(const double* price, const double* num_serv, double* result){
	double cost_serving = (*price) / (*num_serv);
	if (result != NULL)
	{
		*result = cost_serving;
	}
	return cost_serving;
}

// 13. calculate: cost per calorie
double cost_per_cal(const double* price, const double* total_cal, double* result){
	double cost_cal = (*price) / (*total_cal);
	if (result != NULL)
	{
		*result = cost_cal;
	}
	return cost_cal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct data_reporting detail_record(struct CatFoodInfo food){

	struct data_reporting record;

	record.sku = food.sku;
	record.price = food.price;
	record.weight = food.weight;
	record.calories = food.calories;
	record.weight_kg = convertLbsKg(&record.weight, &record.weight_kg);
	record.weight_gm = convertLbsG(&record.weight, &record.weight_gm);
	record.servings = gm_per_serv(NUM_GRAMS, record.weight_gm, &record.servings);
	double totalCalories = record.calories * record.servings;
	record.cost_per_serving = cost_per_serv(&record.price, &record.servings, &record.cost_per_serving);
	record.cost_per_calories = cost_per_cal(&record.price, &totalCalories, &record.cost_per_calories);

	return record;
}

// 15. Display the formatted table header for the analysis results
void display_report_header(void){
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displaydata_reporting(const struct data_reporting record, const int cheapestProductCheck) {
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", record.sku, record.price, record.weight, record.weight_kg, record.weight_gm, record.calories, record.servings, record.cost_per_serving, record.cost_per_calories);
}

// 17. Display the findings (cheapest)
void display_findings(const struct CatFoodInfo food) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n\n", food.sku, food.price);
	printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct data_reporting record[MAX_PRODUCT] = { {0} };
	struct CatFoodInfo food[MAX_PRODUCT] = { {0} };
	int i, cheapestIndex = 0;
	openingMessage(MAX_PRODUCT);
 	for (i = 0; i < MAX_PRODUCT; i++){
		food[i] = getCatFoodInfo(i);
		record[i] = detail_record(food[i]);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCT; i++){
		displayCatFoodData(food[i].sku, &food[i].price,  &food[i].weight, food[i].calories); 
	}
	double cheapestprice = record[0].cost_per_serving;
	for (i = 0; i < MAX_PRODUCT; i++){
		if (record[i].cost_per_serving <= cheapestprice){
			cheapestprice = record[i].cost_per_serving;
			cheapestIndex = i;
		}
	}
	printf("\n");
	display_report_header();
	for (i = 0; i < MAX_PRODUCT; i++){
		displaydata_reporting(record[i], cheapestIndex);
		if (cheapestIndex == i){
			printf(" ***\n");
		}
		else{
			printf("\n");
		}
	}
	printf("\n");
	for (i = 0; i < MAX_PRODUCT; i++){
		if (i == cheapestIndex){
			display_findings(food[i]);
		}
	}
}

