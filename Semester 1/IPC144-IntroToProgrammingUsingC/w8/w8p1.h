#define MAX_PRODUCT 3
#define NUM_GRAMS 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo{
    int sku;
    double price;
    int calories;
    double weight;
};

struct CatFoodInfo food;
// ----------------------------------------------------------------------------

// function prototypes
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

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories);

// 7. Logic entry point
void start(void);