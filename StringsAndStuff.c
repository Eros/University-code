#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

// Symbolic constants (#define):


//user-defined data types (structs)


// Function Declarations - must be consistent with Function Definitions!

void Clearstdin();
void ClearScreen();

char GetValidatedChar(char Min, char Max);
int GetValidatedInteger(int Min, int Max);
float GetValidatedFloat(float Min, float Max);
char GetValidatedString(char ValidatedString[], int MinLength, int MaxLength);
char GetValidatedYesNo();

int main()
{
	printf("This is file: \"StringsAndStuff.c\"\nPlease hit enter to continue:"); // print file name as work-around to VS bug not displaying excluded project files
	getchar();
	ClearScreen();

	// code goes here

    char FirstName[20] = "";
    char LastName[20] = "";
    char FullName[40] = "";

    fgets(FirstName, sizeof(FirstName), stdin);
    fgets(LastName, sizeof(LastName), stdin);

    strcpy(FullName, FirstName);
    strcpy(FullName, LastName);

    GetValidatedString(FirstName, 2, sizeof(FirstName) - 1);
    GetValidatedString(LastName, 2, sizeof(LastName) - 1);
    GetValidatedString(FullName, 2, sizeof(LastName) - 1);

    printf("%s", FullName);


	printf("\n\nPress the ENTER key to continue.");
	getchar();
	return(0);
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
float GetValidatedFloat(float Min, float Max)
{
	const int cTrue = 1;
	const int cFalse = 0;

	int ItemRead = cFalse;
	float Input = 0;
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