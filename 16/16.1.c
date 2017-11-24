//
// Created by George Marr on 03/11/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>

void ShowMainMenu();
void ReadAllRecordsFromFile(struct BOOK AllRecords[]);
void Exit();
void Clearstdin();
void ClearScreen();
char GetValidatedChar(char Min, char Max);
int GetValidatedInteger(int Min, int Max);
const char * GetValidatedFloat(float Min, float Max);
char GetValidatedString(char ValidatedString[], int MinLength, int MaxLength);
char GetValidatedYesNo();
int DisplayMainOptions();

#define MAX_LEN_TITLE 5
#define POUND_SIGN 156
#define MAX_LEN_TITLE_NAME 8
#define MAX_LEN_NAME_FIRST 10
#define MAX_LEN_NAME_LAST 20
#define MAX_LEN_BOOK_TITLE 20
#define MAX_PRICE (float) 200.0
#define MIN_PRICE (float) 0.00
#define MAX_NUM_RECORDS
#define MIN_YEAR 1900
#define MAX_YEAR 2017

int main()
{
   // struct BOOK AllRecords[MAX_NUM_RECORDS];
    ClearScreen();
    Clearstdin();
    DisplayMainOptions();
}

int DisplayMainOptions()
{
    int Choice = 0;

    do {
        ShowMainMenu();
        switch(Choice)
        {
            case 1:
               // ReadAllRecordsFromFile(struct BOOK AllRecords[]);
                break;
            case 2:
                //display records selected
                break;
            case 3:
                //update
                //sallalltofile
                break;
            case 4:
                //savealltofile
                break;
            case 5:
                //delete
                //save
                break;
            case 0:
                Exit();
                break;
        }
    } while (Choice != 0);
    return Choice;
}

struct NAME
{
    char Title[MAX_LEN_TITLE_NAME + 1];
    char FirstName[MAX_LEN_NAME_FIRST + 1];
    char LastName[MAX_LEN_NAME_LAST + 1];
};

struct BOOK
{
    struct NAME Author;
    int PubliccationYear;
    char Title[MAX_LEN_TITLE_NAME + 1];
    const char *Price;
};

void ShowMainMenu()
{
    printf("---- Book Catalogue ----");
    printf("1 >> Display all records ");
    printf("2 >> Display all selected records");
    printf("3 >> Update all files & save");
    printf("4 >> Add records & save");
    printf("5 >> Delete all records & save");
    printf("0 >> Exit programme");
}

void ReadAllRecordsFromFile(struct BOOK AllRecords[])
{

    char AuthorFirstName = (char) AllRecords->Author.FirstName;
    char AuthorLastName = (char) AllRecords->Author.LastName;

    printf(AllRecords->Title);
    printf((const char *) AllRecords->PubliccationYear);
    printf((const char *) AuthorFirstName, AuthorLastName);
    printf(POUND_SIGN, AllRecords->Price);
}

void Exit()
{
    getchar_unlocked();
    system("exit");
}

void AddRecords(struct BOOK AllRecords[], const int *pNumRecords, int NumRecords)
{
    char AddAnother; //yay or nay
    int CFR = 0;
    FILE * fp;

    if(fopen(&fp, "b.txt") != (FILE *) CFR)
    {
        printf("Cannot open file!");
        return;
    }

    do
    {
        if(*pNumRecords == NumRecords)
        {
            printf("The catalogue is full\n");
            return;
        }
        //append a new single record
        printf("Enter the Authors title: ");
        char *atInput = GetValidatedString(AllRecords[*pNumRecords].Author.Title, 1, MAX_LEN_TITLE) + "\n";
        fprintf(fp, *atInput);

        printf("Enter the Authors first name: ");
        char *afInput = GetValidatedString(AllRecords[*pNumRecords].Author.FirstName, 1, MAX_LEN_NAME_FIRST) + "\n";
        fprintf(fp, *afInput);

        printf("Enter the Authors last name: ");
        char *alInput = GetValidatedString(AllRecords[*pNumRecords].Author.LastName, 1, MAX_LEN_NAME_LAST) + "\n";
        fprintf(fp, alInput);

        printf("Enter the publication year: (%d - %d) ", MIN_YEAR, MAX_YEAR);
        char *pyInput = AllRecords[*pNumRecords].PubliccationYear = GetValidatedInteger(MIN_YEAR, MAX_YEAR) + "\n";
        fprintf(fp, pyInput);

        printf("Enter the price: %f");
        char *prInput = AllRecords[*pNumRecords].Price = GetValidatedFloat(MIN_PRICE, MAX_PRICE);
        fprintf(fp, *prInput);

        printf("Enter the title: ");
        char *titInput = GetValidatedString(AllRecords[*pNumRecords].Title, 1, MAX_LEN_BOOK_TITLE);
        fprintf(fp, *titInput);

        (NumRecords++);

        AddAnother = 'N';

        if(*pNumRecords < NumRecords)
        {
            printf("Do you want to add another record? (Y/N)");
            AddAnother = GetValidatedYesNo();

            if(AddAnother == 'N')
            {
                ShowMainMenu();
                printf("4\n");
            }
        } else {
            printf("The catalogue is now full. You cannot add anymore records");
            ShowMainMenu();
        }
    } while (AddAnother == 'Y');
}

// FUNCTION DEFINITIONS:-
void Clearstdin()
{
    char Discard[255] = "";
    fgets(Discard, sizeof(Discard), stdin);
}

// windows specific method of clearing the console window.
void ClearScreen()
{
    system("cls");
}

/* Gets user-inputted character. Validated as value (upper/lower case) between Min and Max (ASCII values). */
char GetValidatedChar(char Min, char Max)
{
    char Input = '\0';

    Min = (char) toupper(Min);
    Max = (char) toupper(Max);

    do
    {
        scanf("%c", &Input, 1);
        Clearstdin();

        Input = (char) toupper(Input);
        if ((Input < Min) || (Input > Max))
        {
            printf("Invalid! Please try again  (%c - %c): ", Min, Max);
        }

    } while ((Input < Min) || (Input > Max));

    return(Input);
}

// Gets user-inputted integer value. Validated for data type & value (Min->Max).
int GetValidatedInteger(int Min, int Max)
{ //DECLARATIONS + INITILISATION of values
    // Local Constants:
    const int cTrue = 1, cFalse = 0;
    // Input Variables:
    float Input = 0; // NB Input read into a FLOAT
    // Intermediate Variables:
    int ItemRead = cFalse; //Flag
    int Valid = cFalse; //Flag - Mandatory initialisation to cFalse
    // Output Variables: // None //-----------------------------------------------------------
    do {
        /* Read. NB scanf_s() returns the number of items successfully read. */
        ItemRead = scanf("%f", &Input);
        Clearstdin();
        /* Validate - Non-numeric? (In which case scanf_s() will not have read in anything) */
        if (ItemRead == cFalse) {
            printf("Invalid - must be a number! Please try again (%d-%d): ", Min, Max);
        }
            /* Validate - Not whole number? */
        else if (Input != (int)Input) /* NB (int)Input truncates a float value */
        {
            printf("Invalid - must be an integer! Please try again (%d-%d): ", Min, Max);
        }
            /* Validate - Invalid value? (ie Not in range Min->Max) */
        else if ((Input < Min) || (Input > Max))
        {
            printf("Invalid - out-of-range! Please try again (%d-%d): ", Min, Max);
        }
        else
        {
            Valid = cTrue;
        }
    } while (Valid == cFalse);
    return((int)Input); /* NB Cast (store) as int before returning */
}

/* Gets user-inputted float value. Validated for data type & value (Min->Max). */
const char * GetValidatedFloat(float Min, float Max)
{
    const int cTrue = 1;
    const int cFalse = 0;

    int ItemRead = cFalse;
    const char *Input = 0;
    int Valid = cFalse; /* MUST be initialised to cFalse */

    /* NB Context-specific request - in calling function */
    do
    {
        /* Read */
        ItemRead = scanf("%f", &Input); /* Recall, scanf_s() returns the number of items successfully read */
        Clearstdin();

        /* Validate - Non-numeric? (In which case scanf_s() will not have read in anything) */
        if (ItemRead == cFalse)
        {
            printf("Invalid - must be a number! Please try again (%f-%f): ", Min, Max);
        }

            /* Validate - Invalid value? (ie Not in range Min->Max) */
        else if ((Input < Min) || (Input > Max))
        {
            printf("Invalid - out-of-range! Please try again (%f-%f): ", Min, Max);
        }
        else
        {
            Valid = cTrue;
        }

    } while (Valid == cFalse);

    return(Input);

}

// Gets user-inputted string, validating it for string length ONLY.
char GetValidatedString(char ValidatedString[], int MinLength, int MaxLength)
{
    const char cFalse = 0, cTrue = 1;
    char Success = cFalse; //Mandatory initialisation to cFalse
    char YesorNo;
    char Input[255];// Very big to avoid array over-run.
    // IMPT: MAX input length = sizeof(Input) - 2 (as last 2 characters of input = "\n\0"):
    size_t InputArrayMaxLen = sizeof(Input) - 2; //= Index of PENULTIMATE array element
    size_t Length; //.. of input read into Input[]
    // (NB size_t is an unsigned integer data type defined in <stddef.h>.
    // It is the return value for sizeof() and strlen().)
    // Check that requested maximum length is shorter than InputArrayMaxLen
    if (MaxLength > (int)InputArrayMaxLen)
    {
        printf("\n\nRequired maximum length for called GetValidatedString() function""\ncannot exceed %d characters", (int) InputArrayMaxLen);
        printf("\nData not read. Please contact developer.");
        getchar();
        return(Success);
    }
    do
    { //Ensure that input not longer than InputArrayMaxLen
        do
        {
            //(Re-)initialisations:
            YesorNo = 'Y';
            Input[InputArrayMaxLen + 1] = 'z'; //} Set to any values ("zz" here)
            Input[InputArrayMaxLen] = 'z'; //} != "\n\0" ready for test below.
            fgets(Input, sizeof(Input), stdin); //NB fgets() - reads in '\n' from stdin (unless input is longer than sizeof(Input) in // which case it truncates the input storing '\0' in the final byte of // Input[] to create a string).
            Clearstdin(); //Clear any remaining data in stdin buffer.

            //If Input was too long to store in Input[] (=> fgets() truncated it)
            if ((Input[InputArrayMaxLen + 1] == '\0') && (Input[InputArrayMaxLen] != '\n'))
            {
                printf("\n\nRequired maximum length for called GetValidatedString() function " "\ncannot exceed %d characters", (int) InputArrayMaxLen);
                printf("\n\nDo you wish to try again (Y/N)?: ");
                YesorNo = GetValidatedYesNo(); //Use your version
                if (YesorNo == 'N')
                {
                    printf("Data not read. Please contact developer.");
                    getchar();
                    return(Success); //Returns cFalse
                }
                else
                {
                    printf("\nRe-enter(%d - %d characters): ", MinLength, MaxLength);
                }
            }
            else //Input not longer than InputArrayMaxLen
            {
                YesorNo = 'N';
            }
        } while (YesorNo == 'Y');

        //At this stage should have a character array, where meaningful input end in "....\n\0..."
        //Replace '\n' with '\0' to create the required string
        Length = strlen(Input) - 1; //NB Length contains the correct updated string length
        Input[Length] = '\0';

        //String length validation (MinLength -> Maxlength)
        if ((Length < (size_t)MinLength) || (Length >(size_t)MaxLength))
        {
            printf("Invalid! Please try again (Length %d-%d): ", MinLength, MaxLength);
        }
        else
        {
            Success = cTrue;
        }
    } while (Success == cFalse);
    //Transfer validated string to ValidatedString
    strcpy(ValidatedString, sizeof(MaxLength) + 1, Input);
    return(Success); // Returns cTrue
}

// Gets user-inputted character. Validated as value 'Y'/'y'/'N'/'n'. */
char GetValidatedYesNo()
{
    char reply;
    do
    {
        scanf("%c", &reply, 1);
        Clearstdin();
        reply = (char) toupper(reply);
    } while ((reply != 'Y') && (reply != 'N'));

    return reply;
}