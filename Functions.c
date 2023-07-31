#include "main.h"

/**
 * createContact - Creates a new contact with the given information.
 *
 * @name: The name of the contact.
 * @phone_num: The phone number of the contact.
 * @email: The email address of the contact.
 *
 * Return: A pointer to the newly created contact, or NULL if memory allocation fails or maximum contacts are reached.
 */
_contact *create_contact(uint8 const *name, uint8 const *phone_num, const uint8 *email)
{

    if (contacts >= MAX_CONTAACT_NO)
    {
        printf("================================\n");
        printf("***** Database is full *****\n");
        printf("================================\n");
        return (NULL);
    }

    _contact *create_contact = (_contact *)malloc(sizeof(_contact));

    if (create_contact == NULL)
    {
        printf("================================\n");
        printf("**** Memory allocation Failed ****\n");
        printf("================================\n");
        return (NULL);
    }

    strcpy(create_contact->Name, name);
    strcpy(create_contact->Phone_number, phone_num);
    strcpy(create_contact->Email, email);
    create_contact->next = NULL;

    contacts++;

    return (create_contact);
}

/**
 * addContact - Adds a new contact to the linked list.
 *
 * @head: The head of the linked list.
 * @name: The name of the contact.
 * @phone_num: The phone number of the contact.
 * @email: The email address of the contact.
 *
 * Return: A pointer to the updated head of the linked list, or NULL if maximum contacts are reached.
 */
_contact *add_contact(_contact *head, const uint8 *name, const uint8 *phone_num, const uint8 *email)
{
    _contact *current = head;
    while (current != NULL)
    {
        if (strcmp(current->Name, name) == 0 && strcmp(current->Phone_number, phone_num) == 0 && strcmp(current->Email, email) == 0)
        {
            printf("================================\n");
            printf("*** Contact already exists. ***\n");
            printf("================================\n");
            return head;
        }
        current = current->next;
    }
    if (head == NULL)
    {
        printf("================================\n");
        printf("*** Contact added successfully. ***\n");
        printf("================================\n");
        return (create_contact(name, phone_num, email));
    }
	current = head; 
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = create_contact(name, phone_num, email);
    printf("================================\n");
    printf("*** Contact added successfully. ***\n");
    printf("================================\n");
    return (head);
}

/**
 * search_contact - Searches for a contact in the linked list based on the provided search_info.
 *
 * @head: The head pointer of the linked list, representing the starting point of the contacts list.
 * @search_info: The search information, which can be either the name or the phone number of the contact to be searched.
 *
 * Return: A pointer to the contact node in the linked list that matches the provided query.
 *         If no match is found, the function returns NULL.
 */
_contact *search_contact(_contact *head, const uint8 *search_info)
{
    _contact *current = head;

    while (current != NULL)
    {
        if (strcmp(current->Name, search_info) == 0 || strcmp(current->Phone_number, search_info) == 0)
            return (current);

        current = current->next;
    }

    return (NULL);
}

/**
 * update_contact - Updates the phone number and email of an existing contact in the linked list.
 *
 * @head: The head pointer of the linked list, representing the starting point of the contacts list.
 * @name: The name of the contact to be updated.
 * @phone_num: The new phone number to be updated.
 * @email: The new email to be updated.
 *
 * Return: The head pointer of the linked list after updating the contact's information.
 */
_contact *update_contact(_contact *head, const uint8 *name, const uint8 *phone_num, const uint8 *email)
{
    _contact *current = search_contact(head, name);

    if (current != NULL)
    {
        strcpy(current->Phone_number, phone_num);
        strcpy(current->Email, email);
        printf("================================\n");
        printf("*** Contact updated successfully ***\n");
        printf("================================\n");
    }
    else
    {
        ERROR_massage(name);
    }

    return (head);
}

/**
 * delete_contact -Deletes data of an existing contact in the linked list.
 *
 * @head: The head pointer of the linked list, representing the starting point of the contacts list.
 * @name: The name of the contact to be updated.
 * @phone_num: The new phone number to be updated.
 * @email: The new email to be updated.
 *
 * Return: The head pointer of the linked list after updating the contact's information.
 */
_contact *delete_contact(_contact *head, const uint8 *search_info)
{

    _contact *current = search_contact(head, search_info);

    if (current != NULL)
    {
        if (head == current)

        {
            head = current->next;
        }

        else

        {
            _contact *temp = head;

            while (temp->next != current)

            {

                temp = temp->next;
            }

            temp->next = current->next;
        }
        free(current);
        current = NULL;
        contacts--;

        printf("================================\n");
        printf("*** Contact deleted successfully ***\n");
        printf("================================\n");
    }
    else
    {
        ERROR_massage(search_info);
    }

    return head;
}

/**
 * display_contacts - Display out all of contacts in linked list.
 *
 * @head: The head pointer of the linked list, representing the starting point of the contacts list.
 *
 * Return: no return.
 */
void display_contacts(_contact *head)
{

    if (contacts == 0)
    {
        printf("================================\n");
        printf("*** There is no contacts in database ***\n");
        printf("================================\n");
    }

    printf("================================\n");
    printf("***** Displaying contacts. *****\n");
    printf("================================\n");
    while (head != NULL)
    {
        printf("Name :%s\n", head->Name);
        printf("Phone number :%s\n", head->Phone_number);
        printf("Email :%s\n", head->Email);
        printf("--------------------------------\n");
        head = head->next;
    }
}

/**
 * free_all_contacts - Frees the memory allocated for all contacts in the linked list.
 *
 * @head: A pointer to the head of the linked list, representing the starting point of the contacts list.
 *
 * Return: no return.
 */
void free_all_contacts(_contact *head)
{
    _contact *current = head;

    while (current != NULL)
    {
        _contact *temp = current;
        current = current->next;
        free(temp);
    }
}

/*-----------------------------------------------------------------------------*/

void print_menu()
{
    printf("================================\n");
    printf("Enter (1) to add new contact.\n");
    printf("Enter (2) to search an existing contact.\n");
    printf("Enter (3) to update phone and mail of an existing contact.\n");
    printf("Enter (4) to delete an existing contact.\n");
    printf("Enter (5) to display all contacts.\n");
    printf("Enter (6) to exit from the program.\n");
    printf("================================\n");
}

void ERROR_massage(const uint8 *wrong_name)
{
    if (contacts == 0)
    {
        printf("================================\n");
        printf("***** There is no contacts in database. *****\n");
        printf("================================\n");
    }
    else
    {
        printf("================================\n");
        printf("The Contact information of \"%s\" does not exist in the database.\n",wrong_name);
        printf("To add the Contact in the database choose choice number (1).\n");
        printf("================================\n");
    }
}
