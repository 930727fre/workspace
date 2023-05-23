#ifndef TOTAL_H
#define TOTAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUF 4096

struct books 
{
    char *book_name;
    char *author;
    char *translator;
    char *publisher;
    int publish_year;
    int amount;        //amount might larger than 1
    float call_number;
    char *isbn;
    int viewer_count;
    int accession_number;
    char **borrower;
    int expiry_date[MAX_BUF];

}book[MAX_BUF];

struct administrators
{
    char *ad_name;
    char *ad_account;
    char *ad_password;
} administrator[MAX_BUF];


struct readers
{
    char *re_name;
    int student_id;
    char *grade; 
    char *email;
    char *re_account;
    char *re_password;
    char **borrow_history;
    int credit;
    struct readers *next;
    struct readers *prev;
    struct readers *link;
};

struct readers *first = NULL;
#endif