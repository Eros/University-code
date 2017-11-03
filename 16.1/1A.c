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