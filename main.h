#ifndef __MAIN__H
#define __MAIN__H

/*-----------------INCLUDES-----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "std_types.h"

/*-----------------DEFINE-------------------------------*/

#define MAX_CONTAACT_NO 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUM_LENGTH 15
#define MAX_EMAIL_LENGTH 100

/*-----------------DATA_TYPES---------------------------*/

typedef struct Contact
{
    uint8 Name[MAX_NAME_LENGTH];
    uint8 Phone_number[MAX_PHONE_NUM_LENGTH];
    uint8 Email[MAX_EMAIL_LENGTH];

    struct Contact *next;
} _contact;

/*-----------------GLOBAL_VARIABLES---------------------*/

extern uint16 contacts, choice;

uint8 name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH], phone_num[MAX_PHONE_NUM_LENGTH];
uint8 search_info[MAX_NAME_LENGTH];

/*-----------------FUNCTIONS----------------------------*/

_contact *create_contact(const uint8 *name, const uint8 *phone_num, const uint8 *email);
_contact *add_contact(_contact *head, const uint8 *name, const uint8 *phone_num, const uint8 *email);
_contact *search_contact(_contact *head, const uint8 *search_info);
_contact *update_contact(_contact *head, const uint8 *name, const uint8 *phone_num, const uint8 *email);
_contact *delete_contact(_contact *head, const uint8 *search_info);
void display_contacts(_contact *head);
void free_all_contacts(_contact *head);
/*-----------------------------------------------------*/
void print_menu();
void ERROR_massage(const uint8 *wrong_name);

#endif