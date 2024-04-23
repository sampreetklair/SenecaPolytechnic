/***********************
-- Student1 Name: Harsahbaj Singh ID: 146457221
-- Student2 Name: Arshdeep Kaur ID: 139566228
-- Student3 Name: Sampreet Klair ID: 145031225
-- Student4 Name: Ritish Sharma ID: 146407226
-- Student5 Name: Viralika ID: 145387221
-- Date: 10 April 2024
-- Purpose: Assignment 2 - DBS311
***********************/

// Including necessary libraries for database connectivity and input/output
#include <iostream>
#include <string>
#include <occi.h>
#include <cctype>

// Using specific namespaces for Oracle OCCI and standard input/output
using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

// Struct definition for shopping cart items
struct ShoppingCart {
    int product_id; // Product ID
    double price;   // Price of the product
    int quantity;   // Quantity of the product
};

// Function declarations
int mainMenu();                         // Main menu function
int customerLogin(Connection* conn, int customerId); // Customer login function
int addToCart(Connection* conn, struct ShoppingCart cart[]); // Add to cart function
double findProduct(Connection* conn, int product_id); // Find product function
void displayProducts(struct ShoppingCart cart[], int productCount); // Display products function
int checkout(Connection* conn, struct ShoppingCart cart[], int customerId, int productCount); // Checkout function

// Main menu function definition
int mainMenu() {
    int option = 0;
    // Displaying the main menu options
    do {
        cout << "******************* Main Menu *******************\n"
             << "1)\tLogin\n"
             << "0)\tExit\n";

        // Prompting the user for input and handling incorrect input
        if (option != 0 && option != 1) {
            cout << "You entered a wrong value. Enter an option (0-1): ";
        } else {
            cout << "Enter an option (0-1): ";
        }
        cin >> option;
    } while (option != 0 && option != 1);

    return option;
}

// Customer login function definition
int customerLogin(Connection* conn, int customerId) {
    // Creating a statement for database interaction
    Statement* stmt = conn->createStatement();

    // Setting up SQL query for finding customer
    stmt->setSQL("BEGIN find_customer(:1, :2); END;");
    int found;

    // Setting up IN parameter for stored procedure
    stmt->setInt(1, customerId);

    // Setting up OUT parameter for storing the result
    stmt->registerOutParam(2, Type::OCCIINT, sizeof(found));

    // Executing the stored procedure
    stmt->executeUpdate();
    found = stmt->getInt(2);

    // Terminating the statement
    conn->terminateStatement(stmt);

    // Returning the result
    return found;
}

// Function to add products to cart
int addToCart(Connection* conn, struct ShoppingCart cart[]) {
    cout << "-------------- Add Products to Cart --------------" << endl;
    // Iterating through available products
    for (int i = 0; i < 5; ++i) {
        int productId;
        int quantity;
        ShoppingCart item;
        int choose;

        // Prompting user for product ID and validating its existence
        do {
            cout << "Enter the product ID: ";
            cin >> productId;
            if (findProduct(conn, productId) == 0) {
                cout << "The product does not exist. Try again..." << endl;
            }
        } while (findProduct(conn, productId) == 0);

        // Retrieving and displaying product price
        cout << "Product Price: " << findProduct(conn, productId) << endl;
        cout << "Enter the product Quantity: ";
        cin >> quantity;

        // Storing product details in the cart
        item.product_id = productId;
        item.price = findProduct(conn, productId);   
        item.quantity = quantity;
        cart[i] = item;

        // Checking if user wants to add more products or checkout
        if (i == 4)
            return i + 1;
        else {
            do {
                cout << "Enter 1 to add more products or 0 to check out: ";
                cin >> choose;
            } while (choose != 0 && choose != 1);
        }

        if (choose == 0)
            return i + 1;
    }
}

// Function to find product details
double findProduct(Connection* conn, int product_id) {
    // Creating a statement for database interaction
    Statement* stmt = conn->createStatement();

    // Setting up SQL query for finding product
    stmt->setSQL("BEGIN find_product(:1, :2); END;");
    double price;

    // Setting up IN parameter for stored procedure
    stmt->setInt(1, product_id);

    // Setting up OUT parameter for storing the result
    stmt->registerOutParam(2, Type::OCCIDOUBLE, sizeof(price));

    // Executing the stored procedure
    stmt->executeUpdate();

    // Retrieving the price of the product
    price = stmt->getDouble(2);

    // Terminating the statement
    conn->terminateStatement(stmt);

    // Returning the price (0 if not found)
    if (price > 0) {
        return price;
    } else {
        return 0;
    }
}

// Function to display products in the cart
void displayProducts(struct ShoppingCart cart[], int productCount) {
    if (productCount > 0) {
        double totalPrice = 0.0;
        // Displaying the list of ordered items and calculating total price
        cout << "------- Ordered Products ---------" << endl;
        for (int i = 0; i < productCount; ++i) {
            cout << "---Item " << i + 1 << endl;
            cout << "Product ID: " << cart[i].product_id << endl;
            cout << "Price: " << cart[i].price << endl;
            cout << "Quantity: " << cart[i].quantity << endl;
            totalPrice += cart[i].price * cart[i].quantity;
        }
        cout << "----------------------------------\nTotal: " << totalPrice << endl;
    }
}

// Function for checkout process
int checkout(Connection* conn, struct ShoppingCart cart[], int customerId, int productCount) {
    char choice;
    // Prompting user for checkout confirmation
    do {
        cout << "Would you like to checkout ? (Y/y or N/n) ";
        cin >> choice;

        if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
            cout << "Wrong input. Try again..." << endl;
    } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

    // Handling checkout based on user choice
    if (choice == 'N' || choice == 'n') {
        cout << "The order is cancelled." << endl;
        return 0;
    } else {
        // Creating a statement for database interaction
        Statement* stmt = conn->createStatement();

        // Setting up SQL query for adding order
        stmt->setSQL("BEGIN add_order(:1, :2); END;");
        int next_order_id;

        // Setting up IN parameter for stored procedure
        stmt->setInt(1, customerId);

        // Setting up OUT parameter for storing the result
        stmt->registerOutParam(2, Type::OCCIINT, sizeof(next_order_id));

        // Executing the stored procedure
        stmt->executeUpdate();

        // Retrieving the next order ID
        next_order_id = stmt->getInt(2);

        // Adding order items to the database
        for (int i = 0; i < productCount; ++i) {
            stmt->setSQL("BEGIN add_order_item(:1, :2, :3, :4, :5); END;");

            // Setting up IN parameters for order items
            stmt->setInt(1, next_order_id);
            stmt->setInt(2, i + 1);
            stmt->setInt(3, cart[i].product_id);
            stmt->setInt(4, cart[i].quantity);
            stmt->setDouble(5, cart[i].price);

            // Executing the stored procedure
            stmt->executeUpdate();
        }

        cout << "The order is successfully completed." << endl;

        // Terminating the statement
        conn->terminateStatement(stmt);

        return 1;
    }
}

// Main function
int main() {
    // Database connection variables
    Environment* env = nullptr;
    Connection* conn = nullptr;

    // Database credentials
    string user = "dbs311_241zra19";
    string pass = "<password>";
    string constr = "myoracle12c.senecacollege.ca:1521/oracle12c";

    try {
        // Creating Oracle environment and establishing connection
        env = Environment::createEnvironment(Environment::DEFAULT);
        conn = env->createConnection(user, pass, constr);

        int choose; // Variable to store user's choice
        int customerId; // Variable to store customer ID

        // Main loop for menu options
        do {
            choose = mainMenu(); // Displaying main menu and getting user's choice

            // Handling user's choice
            if (choose == 1) {
                cout << "Enter the customer ID: ";
                cin >> customerId;

                // Validating customer login
                if (customerLogin(conn, customerId) == 0) {
                    cout << "The customer does not exist." << endl;
                } else {
                    // Creating cart and performing shopping operations
                    ShoppingCart cart[5];
                    int count = addToCart(conn, cart);
                    displayProducts(cart, count);
                    checkout(conn, cart, customerId, count);
                }
            }
        } while (choose != 0); // Loop until user chooses to exit

        cout << "Good bye!..." << endl;

        // Terminating database connection
        env->terminateConnection(conn);
        Environment::terminateEnvironment(env);
    } catch (SQLException& sqlExcp) {
        // Handling SQL exceptions
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }

    return 0;
	
}