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

}