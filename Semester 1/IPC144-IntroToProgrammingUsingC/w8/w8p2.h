/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Sampreet Klair
Student ID#: 145031225
Email      : sklair2@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3record party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define MAX_PRODUCT 3
#define NUM_GRAMS 64
#define LBS_KG_CONSTANT 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo{
    int sku;
    double price;
    int calories;
    double weight;
};

struct data_reporting
{
    int sku;
    double price;
    int calories;
    double weight;
    double weight_kg;
    int weight_gm;
    double servings;
    double cost_per_serving;
    double cost_per_calories;
};

// ----------------------------------------------------------------------------

// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_num);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted recorecord of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* result_lbstokg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* result_lbstog);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* result_lbstokg, int* result_lbstog);

// 11. calculate: servings based on gPerServ
double gm_per_serv(const int gm_size, const int total_gm, double* num_serv);

// 12. calculate: cost per serving
double cost_per_serv(const double* price, const double* num_serv, double* result);

// 13. calculate: cost per calorie
double cost_per_cal(const double* price, const double* total_cal, double* result);

// 14. Derive a reporting detail recorecord based on the cat food product data
struct data_reporting detail_record(struct CatFoodInfo food);

// 15. Display the formatted table header for the analysis results
void display_report_header(void);

// 16. Display the formatted data row in the analysis table
void displaydata_reporting(const struct data_reporting record, const int cheapestProductCheck);

// 17. Display the findings (cheapest)
void display_findings(const struct CatFoodInfo food);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);