//
// Created by George on 03-Nov-17.
//

#include <stdio.h>

#define GREETING "\n BOOOK CATALOGUE\n --------------\n\n"
#define POUND_SIGN 156

#define MAX_NUM_RECORDS 20
#define MAX_LEN_NAME_TITLE 8
#define MAX_LEN_NAME_FIRST 10
#define MAX_LEN_NAME_LAST 20
#define MAX_LEN_BOOK_TITLE
#define MIN_PRICE (float) 0.00
#define MAX_PRICE (float) 200.00
#define MIN_YEAR 1900
#define MAX_YEAR 2017 //durrr

void ShowMainMenu();
void Pause();
void DisplayRecordsAll();
void AddRecords();
void DisplayRecordsSelected();
void UpdateRecords();
void DeleteRecords();
void SaveRecordsToFile();
int GetValidatedInteger(int Min, int Max);

struct NAME
{
    char Title[MAX_LEN_NAME_TITLE + 1];
    char FirstName[MAX_LEN_NAME_FIRST];
    char LastName[MAX_LEN_NAME_LAST];
};

struct BOOK
{
    struct NAME author;
    int PublicationYear; //min year - max year
    float Price; //min price - max price
    char Title[MAX_LEN_BOOK_TITLE + 1];
};

//need to add the methods

int main()
{

    struct BOOK AllRecords[MAX_NUM_RECORDS];
    int NumRecords = 0;

    int MenuChoice = 0;

    ReadAllRecordsFromFile();

    do
    {
        ShowMainMenu();
        MenuChoice = GetValidatedInteger(0, 5);

        switch(MenuChoice)
        {
            case 1:
                DisplayRecordsAll();
                break;
            case 2:
                DisplayRecordsSelected();
                break;
            case 3:
                UpdateRecords();
                SaveAllRecordsToFile();
                break;
            case 4:
                AddRecords();
                SaveAllRecordsToFile();
                break;
            case 5:
                DeleteRecords();
                SaveAllRecordsToFile();
                break;
            case 0:
                printf("\nQuitting program");
                printf("\n\n");
                Pause();
                break;
        }
    } while(MenuChoice != 0);

    return 0;
}

void ShowMainMenu()
{
    system("cls");
    printf("%s", GREETING);
    printf("\n MAIN MENU\n-------");
    printf("\n1. Display all");
    printf("\n2.Display all by selected author");
    printf("\n3.Update a entry");
    printf("\n4.Add entry");
    printf("\n5.Delete entry");
    printf("\n0.Exit program");
    printf("\nEnter your choice: ");
}

void DisplayRecordsAll()
{
    printf("\nCalled: Display all records"); Pause();
}

void DisplayRecordsSelected()
{
    printf("Called: Selected records to be displayed"); Pause();
}

void AddRecords()
{
    printf("Called: AddRecord"); Pause();
}

void UpdateRecords()
{
    printf("Called: UpdateRecord"); Pause();
}

void DeleteRecords()
{
    printf("Called: DeleteRecord"); Pause();
}

void SaveAllRecordsToFile()
{
    printf("Called: SaveAllRecordsToFile"); Pause();
}

void Pause()
{
    getchar();
    system("pause");
}

int GetValidatedInteger(int Min, int Max)
{
    const int cTrue = 1, cFalse = 0;

    float Input = 0;

    int ItemRead = cFalse;
    int Valid = cFalse;
    do {
        ItemRead = scanf("%f", &Input);
        Clearstdin();
        if (ItemRead == cFalse) {
            printf("Invalid - must be a number! Please try again (%d-%d): ", Min, Max);
        }
            /* Validate - Not whole number? */
        else if (Input != (int)Input) /* NB (int)Input truncates a float value */
        {
            printf("Invalid - must be an integer! Please try again (%d-%d): ", Min, Max);
        }

        else if ((Input < Min) || (Input > Max))
        {
            printf("Invalid - out-of-range! Please try again (%d-%d): ", Min, Max);
        }
        else
        {
            Valid = cTrue;
        }
    } while (Valid == cFalse);
    return((int)Input);
}