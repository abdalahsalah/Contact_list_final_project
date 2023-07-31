#include "main.h"

uint16 contacts = 0;

int main()
{
    uint16 choice = 0;
    _contact *contact_list = NULL;
    
    printf("\n ----------------------------------------------\n");
    printf("|     Welcome to Contact Management System     |\n");
    printf(" ----------------------------------------------\n\n");

    print_menu();

    while (choice != 6)
    {

        if (choice!=0)
        {
            printf("================================\n");
            printf("Enter (0) to show available commands.\n");
            printf("Enter (6) to Exit program.\n");
            printf("================================\n");
        }
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            print_menu();
            break;
        case 1:

            printf("================================\n");
            printf("Enter contact name: ");
            scanf(" %[^\n]", name);
            printf("Enter contact phone number: ");
            scanf("%s", phone_num);
            printf("Enter contact email: ");
            scanf("%s", email);

            contact_list = add_contact(contact_list, name, phone_num, email);
            break;
        case 2:

            printf("================================\n");
            printf("Enter contact name or phone number: ");
            scanf(" %[^\n]", search_info);

            _contact *contact_recieve = search_contact(contact_list, search_info);
            if (contact_recieve != NULL)
            {
                printf("================================\n");
                printf("Name: %s\n", contact_recieve->Name);
                printf("Phone number: %s\n", contact_recieve->Phone_number);
                printf("Email is: %s\n", contact_recieve->Email);
                printf("================================\n");
            }
            else
            {
                ERROR_massage(search_info);
            }
            break;

        case 3:
            printf("================================\n");
            printf("Enter contact name to update: ");
            scanf(" %[^\n]", name);
            printf("Enter new phone number: ");
            scanf("%s", phone_num);
            printf("Enter new contact email: ");
            scanf("%s", email);
            printf("================================\n");

            contact_list = update_contact(contact_list, name, phone_num, email);
            break;

        case 4:
            printf("================================\n");
            printf("Enter contact name or phone number: ");
            scanf(" %[^\n]", search_info);

            contact_list = delete_contact(contact_list, search_info);
            break;
        case 5:
            display_contacts(contact_list);
            break;
        case 6:
            printf("================================\n");
            printf("Exiting program ... ");
            free_all_contacts(contact_list);
            break;
        default:
            printf("Invalid choice \n");
            
        }
    }
}