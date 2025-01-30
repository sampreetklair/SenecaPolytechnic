#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, recordFound = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            recordFound = 1;
        }
    }

    if (recordFound == 1)
    {
        displayPatientTableHeader();
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber != 0)
            {
                displayPatientData(&patient[i], fmt);
            }
        }
        printf("\n");
    }
    else if (recordFound == 0)
    {
        printf("\n*** No records found ***\n\n");
    }
}


// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int selection = -1;

    while (selection != 0)
    {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        scanf("%d", &selection);

        if (selection == 1)
        {
            printf("\n");
            searchPatientByPatientNumber(patient, max);
            printf("\n");
            clearInputBuffer();
            suspend();

        }
        else if (selection == 2)
        {
            printf("\n");
            searchPatientByPhoneNumber(patient, max);
            printf("\n");
            clearInputBuffer();
            suspend();
        }
    }
    printf("\n");
}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int i = 0, slotAvailable = -1;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            slotAvailable = i;
            i = max;
        }

    }
    if (slotAvailable == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[slotAvailable].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[slotAvailable]);
        printf("*** New patient record added ***\n\n");
    }
}


// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    int num, foundNumber;
    printf("Enter the patient number: ");
    scanf("%d", &num);
    printf("\n");
    foundNumber = findPatientIndexByPatientNum(num, patient, max);
    if (foundNumber == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        menuPatientEdit(&patient[foundNumber]);
    }
}


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int num, foundNumber;
    char selection;
    printf("Enter the patient number: ");
    scanf("%d", &num);
    foundNumber = findPatientIndexByPatientNum(num, patient, max);
    if (foundNumber == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        printf("\n");
        displayPatientData(&patient[foundNumber], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &selection);
        if (selection == 'n')
        {
            printf("Operation aborted.\n\n");
        }
        else if (selection == 'y')
        {
            patient[foundNumber].patientNumber = 0;
            strcpy(patient[foundNumber].name, "\0");
            strcpy(patient[foundNumber].phone.description, "\0");
            strcpy(patient[foundNumber].phone.number, "\0");
            printf("Patient record has been removed!\n\n");
        }
    }
    clearInputBuffer();
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    clearInputBuffer();
    int num, foundNumber;
    printf("Search by patient number: ");
    scanf("%d", &num);
    printf("\n");
    foundNumber = findPatientIndexByPatientNum(num, patient, max);
    if (foundNumber == -1)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        displayPatientData(&patient[foundNumber], FMT_FORM);
    }

}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    clearInputBuffer();

    int i, equalStr, foundMatch = 0;
    char phoneNum[11] = { '\0' };

    printf("Search by phone number: ");
    scanf("%[^\n]", phoneNum);
    printf("\n");

    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        equalStr = strcmp(patient[i].phone.number, phoneNum);

        if (equalStr == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            foundMatch = 1;

        }
    }

    if (foundMatch == 0)
    {
        printf("\n*** No records found ***\n");
    }
}

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, greatest;
    greatest = patient[0].patientNumber;
    for (i = 1; i < max; i++)
    {
        if (greatest < patient[i].patientNumber)
        {
            greatest = patient[i].patientNumber;
        }
    }
    greatest += 1;
    return greatest;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i, value = -1;
    for (i = 0; i < max; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            value = i;
        }
    }
    return value;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n"
        "Number: %05d\n"
        "Name  : ", patient->patientNumber);
    scanf("%[^\n]", patient->name);
    printf("\n");
    inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
    int selection;
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    scanf("%d", &selection);

    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");

        break;
    case 2:
        strcpy(phone->description, "HOME");

        break;
    case 3:
        strcpy(phone->description, "WORK");

        break;
    case 4:
        strcpy(phone->description, "TBD");
        strcpy(phone->number, "\0");
        printf("\n");

        break;
    }

    clearInputBuffer();
    if (selection != 4)
    {
        printf("\nContact: %s\n"
            "Number : ", phone->description);
        scanf("%[^\n]", phone->number);
        printf("\n");
        clearInputBuffer();
    }

}
