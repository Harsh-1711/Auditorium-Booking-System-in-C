#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

#include "structs.c" //importing file struct.c

void setcolor(int ForgC);
bool validateMobileNumber(const char *mobileNumber);
int CopyAdminPass(char *rafname, char *txtname);
void updateStatus();
void loadingBar(char *text);
void login();
int user_booking();
int booking_view();void admin_view();
void change_pass(char *new_password);
int check_pass(char *password);
void attractiveExit();

void mmenu()
{
    system("cls");
    setcolor(15);
    int choice, i;
    char temp, text[15];
    time_t t;
    time(&t);
    system("cls");

    do
    {

        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("   ******************************  MAIN MENU  ***************************** \n");
        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("\t\t *Please enter your choice*");
        printf("\n\n");
        printf("\nEnter 1 -> Admin");
        printf("\n------------------------");
        printf("\nEnter 2 -> User");
        printf("\n------------------------");
        printf("\nEnter 3 -> Contact us");
        printf("\n------------------------");
        printf("\n\n");
        for (i = 0; i < 80; i++)
            printf("-");
        printf("\nCurrent date and time : %s", ctime(&t));
        for (i = 0; i < 80; i++)
            printf("-");
        choice = getche();
        choice = toupper(choice);
        switch (choice)
        {
        case '1':
        {
            login();
            break;
        }
        case '2':
        {
            user_booking();
        }
        case '3':
        {
            system("cls");
            printf("\n                              CONTACT US                                    ");
            printf("\n||=======================================================================||");
            printf("\n||                                                                       ||");
            printf("\n||     Tel No. : 25284396, 25286442, Ext No. : 203,261                   ||");
            printf("\n||     Email : imr@bharatividyapeeth.edu / bvimr@del3.vsnl.net.in        ||");
            printf("\n||     Website : www.bvimr.com                                           ||");
            printf("\n||                                                                       ||");
            printf("\n||=======================================================================||");
            printf("\n\nEnter any key to continue.");
            getch();
            system("cls");
            break;
        }
        default:
        {
            printf("\nInvalid choice. Please try again.\n");
            Sleep(1000);
            system("cls");
        }
        }
    } while (1);
}
int main()
{
    system("cls");
    setcolor(15);
    int choice, i;
    char temp, text[15];
    time_t t;
    time(&t);
    printf("\t\t*********************************************************\n");
    printf("\t\t*                                                       *\n");
    printf("\t\t*                                                       *\n");
    printf("\t\t*       ------------------------------------------      *\n");
    printf("\t\t*        WELCOME TO BHARATI VIDYAPEETH AUDITORIUM       *\n");
    printf("\t\t*       ------------------------------------------      *\n");
    printf("\t\t*                                                       *\n");
    printf("\t\t*                                                       *\n");
    printf("\t\t*                                                       *\n");
    printf("\t\t*********************************************************\n\n\n");
    for (i = 0; i < 90; i++)
        printf("-");
    printf("\n\t\tCurrent date and time : %s", ctime(&t));
    for (i = 0; i < 90; i++)
        printf("-");
    loadingBar("Starting");
    system("cls");

    do
    {

        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("   ******************************  MAIN MENU  ***************************** \n");
        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("\t\t *Please enter your choice*");
        printf("\n\n");
        printf("\nEnter 1 -> Admin");
        printf("\n------------------------");
        printf("\nEnter 2 -> User");
        printf("\n------------------------");
        printf("\nEnter 3 -> Contact us");
        printf("\n------------------------");
        printf("\n\n");
        for (i = 0; i < 80; i++)
            printf("-");
        printf("\nCurrent date and time : %s", ctime(&t));
        for (i = 0; i < 80; i++)
            printf("-");
        choice = getche();
        choice = toupper(choice);
        switch (choice)
        {
        case '1':
        {
            login();
            break;
        }
        case '2':
        {
            user_booking();
        }
        case '3':
        {
            system("cls");
            printf("\n                              CONTACT US                                    ");
            printf("\n||=======================================================================||");
            printf("\n||                                                                       ||");
            printf("\n||     Tel No. : 25284396, 25286442, Ext No. : 203,261                   ||");
            printf("\n||     Email : imr@bharatividyapeeth.edu / bvimr@del3.vsnl.net.in        ||");
            printf("\n||     Website : www.bvimr.com                                           ||");
            printf("\n||                                                                       ||");
            printf("\n||=======================================================================||");
            printf("\n\nEnter any key to continue.");
            getch();
            system("cls");
            break;
        }
        default:
        {
            printf("\nInvalid choice. Please try again.\n");
            Sleep(1000);
            system("cls");
        }
        }
    } while (1);
    return 0;
}

int booking_view()
{
    FILE *fp, *ft, *log;
    char another, choice;
    int f;

    Booking b1;
    char name[MAX_NAME_LENGTH], email[100], temp;
    long int bsize = sizeof(b1);

    // create the file if it does not exist
    fp = fopen("record.dat", "ab");
    if (fp == NULL)
    {
        puts("Cannot create file");
        attractiveExit();
        exit(0);
    }
    fclose(fp);

    // now open the file in  both reading and writing

    while (1)
    {
        system("cls"); // clears the screen and this function work with gcc compiler
        printf("   ****************************** Admin Booking Panel ***************************** \n");
        for (int i = 0; i < 80; i++)
            printf("-");
        printf("\nEnter 1 -> Add Booking");
        printf("\n------------------------");
        printf("\nEnter 2 -> List Booking");
        printf("\n------------------------");
        printf("\nEnter 3 -> Edit Booking");
        printf("\n------------------------");
        printf("\nEnter 4 -> Delete Booking");
        printf("\n------------------------");
        printf("\nEnter 5 -> Search Booking");
        printf("\n------------------------");
        printf("\nEnter 6 -> Go Back");
        printf("\n------------------------");
        printf("\nEnter 7 -> Go to Main menu");
        printf("\n------------------------");
        printf("\nEnter 8 -> Exit");
        printf("\n------------------------");
        printf("\n\nEnter Your Choice : ");
        fflush(stdin);
        choice = getche();
        getch();

        switch (choice)
        {
        case '1':
            fp = fopen("record.dat", "rb+");
            log= fopen("RequestLog.txt","a");
            if (fp == NULL)
            {
                puts("Cannot open file");
                attractiveExit();
                exit(0);
            }
            if(log== NULL){
                puts("\nCannot open backup file");
                fclose(log);
            }
            system("cls");
            fseek(fp, 0, SEEK_END);
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                printf("\nEnter the details of the organizer\n");
            name:
                printf("First Name : ");
                scanf("%s", b1.name);

                for (int i = 0; i < strlen(b1.name); i++)

                {

                    int j = b1.name[i];

                    if ((j >= 97 && j <= 122) || (j >= 65 && j <= 90) || (j == 32 && j == 92))

                    {

                        // printf("\n%d",n[i]);

                        continue;
                    }

                    else

                    {

                        printf("\nFirst name is invalid! Enter alphabets only!!!");

                        Sleep(1500);

                        system("cls");

                        goto name;
                    }
                }

            lname:
                printf("Last Name : ");
                scanf("%s", b1.lname);
                for (int i = 0; i < strlen(b1.lname); i++)

                {

                    int k = b1.lname[i];

                    if ((k >= 97 && k <= 122) || (k >= 65 && k <= 90) || (k == 32 && k == 92))

                    {

                        continue;
                    }

                    else

                    {

                        printf("\nLast name invalid! Enter alphabets only!!!");

                        goto lname;
                    }
                }
                printf("Age : ");
                scanf("%s", &b1.age);
            contact1:
                printf("Contact number ( only numbers, e.g. 1234567890 ): ");
                scanf("%s", b1.phone_no);
                if (!validateMobileNumber(b1.phone_no))
                {
                    printf("Invalid mobile number\n");
                    goto contact1;
                }
                printf("Email address : ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%[^\n]", b1.email);
                printf("Event name : ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%[^\n]", b1.event_name);
                printf("Date of event (yyyy-mm-dd): ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%[^\n]", b1.event_date);
                printf("Event time (In 24 hr format, e.g. 16:00-19:00 ) : ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%[^\n]", b1.event_time);
                b1.isAccepted = 0;
                strcpy(b1.operation, "Added");
                if (b1.isAccepted == 0)
                    strcpy(b1.status, "Pending");
                if (b1.isAccepted == 1)
                    strcpy(b1.status, "Approved");
                if (b1.isAccepted == -1)
                    strcpy(b1.status, "Declined");
                fwrite(&b1, bsize, 1, fp);
                fprintf(log, "\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-20s %-10s", b1.name, b1.lname, b1.age, b1.phone_no, b1.email, b1.event_name, b1.event_date, b1.event_time, b1.status, b1.operation);
                printf("\nRequest sent successfully... \n");
                fclose(fp);
                fclose(log);
                fflush(stdout);
                printf("\nAdd another booking request (Y/N) ");
                fflush(stdin);
                another = getche();
            }
            break;

        case '2':
            system("cls");
            fp = fopen("record.dat", "rb+");
            if (fp == NULL)
            {
                puts("Cannot open file");
                attractiveExit();
                exit(0);
                fclose(fp);
            }
            rewind(fp);
            f = 0;

            printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-10s", "Name", "Last_Name", "Age", "Phone number", "Email", "Event Name", "Event date", "Event Time", "Status");
            printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
            while (fread(&b1, bsize, 1, fp) == 1)
            {
                f = 1;
                if (b1.isAccepted == 0)
                    strcpy(b1.status, "Pending");
                if (b1.isAccepted == 1)
                    strcpy(b1.status, "Approved");
                if (b1.isAccepted == -1)
                    strcpy(b1.status, "Declined");
                printf("\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-10s", b1.name, b1.lname, b1.age, b1.phone_no, b1.email, b1.event_name, b1.event_date, b1.event_time, b1.status);
            }
            if (f == 0)
            {
                printf("\nRecord does not exist\n");
            }
            printf("\n\nPress any key to continue...");
            fclose(fp);
            getch();
            break;

        case '3':
            fp = fopen("record.dat", "rb+");
            if (fp == NULL)
            {
                puts("Cannot open file");
                attractiveExit();
                exit(0);
            }
            log= fopen("RequestLog.txt","a");
            if(log== NULL){
                puts("\nCannot open backup file");
                fclose(log);
            }
            system("cls");
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                f = 0;
            name2:
                printf("\n\nEnter name of organizer to modify : ");
                scanf("%s", name);
                rewind(fp);
                while (fread(&b1, bsize, 1, fp) == 1)
                {
                    if (strcmpi(b1.name, name) == 0)
                    {
                        f = 1;
                        printf("Record found enter new details\n\n");
                        printf("First Name : ");
                        scanf("%s", b1.name);
                        for (int i = 0; i < strlen(b1.name); i++)

                        {

                            int j = b1.name[i];

                            if ((j >= 97 && j <= 122) || (j >= 65 && j <= 90) || (j == 32 && j == 92))

                            {

                                // printf("\n%d",n[i]);

                                continue;
                            }

                            else

                            {

                                printf("\nFirst name is invalid! Enter alphabets only!!!");

                                Sleep(1500);

                                system("cls");

                                goto name2;
                            }
                        }

                    lname2:
                        printf("Last Name : ");
                        scanf("%s", b1.lname);
                        for (int i = 0; i < strlen(b1.lname); i++)

                        {

                            int k = b1.lname[i];

                            if ((k >= 97 && k <= 122) || (k >= 65 && k <= 90) || (k == 32 && k == 92))

                            {

                                continue;
                            }

                            else

                            {

                                printf("\nLast name invalid! Enter alphabets only!!!");

                                goto lname2;
                            }
                        }
                        printf("Age: ");
                        scanf("%s", &b1.age);
                    contact2:
                        printf("Contact number ( only numbers, e.g. 1234567890 ): ");
                        scanf("%s", b1.phone_no);
                        if (!validateMobileNumber(b1.phone_no))
                        {
                            printf("Invalid mobile number\n");
                            goto contact2;
                        }
                        fflush(stdin);
                        printf("Email address : ");
                        scanf("%[^\n]", b1.email);
                        fflush(stdin);
                        printf("Event name : ");
                        scanf("%[^\n]", b1.event_name);
                        fflush(stdin);
                        printf("Date of event (yyyy-mm-dd): : ");
                        scanf("%[^\n]", b1.event_date);
                        fflush(stdin);
                        printf("Event time (16:00-19:00) : ");
                        scanf("%[^\n]", b1.event_time);
                        fflush(stdin);
                        strcpy(b1.operation, "Updated");
                        if (b1.isAccepted == 0)
                            strcpy(b1.status, "Pending");
                        if (b1.isAccepted == 1)
                            strcpy(b1.status, "Approved");
                        if (b1.isAccepted == -1)
                            strcpy(b1.status, "Declined");
                        b1.isAccepted = 0;
                        fseek(fp, -bsize, SEEK_CUR);
                        fwrite(&b1, bsize, 1, fp);
                        fprintf(log, "\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-20s %-10s", b1.name, b1.lname, b1.age, b1.phone_no, b1.email, b1.event_name, b1.event_date, b1.event_time, b1.status, b1.operation);
                        fflush(stdout);
                        fclose(log);
                        fclose(fp);
                        break;
                    }
                }
                if (f == 0)
                {
                    printf("Record not found\n");
                    printf("\n\nPress any key to continue...");
                }
                    printf("\nModify another Record (Y/N) ");
                fflush(stdin);
                another = getche();
            }
            break;

        case '4':{
            log= fopen("RequestLog.txt","a");
            if(log== NULL){
                puts("\nCannot open backup file");
                fclose(log);
            }
            
            system("cls");
            another = 'Y';
            Booking b2;
            while (another == 'Y' || another == 'y')
            {
                f = 0;
                printf("\nEnter Email of organizer to delete : ");
                scanf("%s", email);
                ft = fopen("temp.dat", "wb");
                if(ft== NULL){
                    printf("Error creating temporary file.\n");
                    fclose(ft);
                }
                fp = fopen("record.dat", "r");
                if (fp == NULL)
                {
                    puts("Cannot open file");
                    fclose(fp);
                }
                rewind(fp);
                while (fread(&b2, sizeof(Booking), 1, fp) == 1)
                {
                    if (strcmpi(b2.email, email) != 0)
                    {
                        fwrite(&b2, sizeof(Booking), 1, ft);
                    }
                    else
                    {
                        strcpy(b1.operation, "Deleted");
                        fprintf(log, "\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-20s %-10s", b1.name, b1.lname, b1.age, b1.phone_no, b1.email, b1.event_name, b1.event_date, b1.event_time, b1.status, b1.operation);
                        fclose(log);
                        fflush(stdout);
                        fflush(stdin);
                        printf("\n\nSuccessfully record deleted!!\n\n");
                        f = 1;
                    }
                }

                if (f == 0)
                {
                    
                    printf("Record Not found");
                    fclose(ft);
                    fclose(fp);
                    remove("C:\\Users\\Jarvis\\OneDrive\\Desktop\\Minor Project - Auditorium\\temp.dat");
                    fflush(stdout);
                }
                else
                {
                    fclose(fp);
                    fclose(ft);
                    remove("record.dat");
                    rename("temp.dat", "record.dat");
                    printf("Delete another Record (Y/N) ");
                }
                fflush(stdin);
                another = getche();
            break;
        }
        fclose(log);
        break;
        }

        case '5':
            fp = fopen("record.dat", "rb");
            if (fp == NULL)
            {
                puts("Cannot open file");
                attractiveExit();
                exit(0);
            }
            fflush(stdin);
            system("cls");
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                f = 0;
                printf("\nEnter Email of organizer to search : ");
                scanf("%s", email);
                rewind(fp);
                while (fread(&b1, bsize, 1, fp) == 1)
                {
                    if (strcmpi(b1.email, email) == 0)
                    {
                        if (b1.isAccepted == 0)
                            strcpy(b1.status, "Pending");
                        if (b1.isAccepted == 1)
                            strcpy(b1.status, "Approved");
                        if (b1.isAccepted == -1)
                            strcpy(b1.status, "Declined");
                        printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
                        printf("\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-10s", "Name", "Last_Name", "Age", "Phone number", "Email", "Event Name", "Event date", "Event Time", "Status");
                        printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
                        printf("\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-10s", b1.name, b1.lname, b1.age, b1.phone_no, b1.email, b1.event_name, b1.event_date, b1.event_time, b1.status);
                        f = 1;
                        break;
                    }
                }
                if (f == 0)
                {
                    printf("Record not found\n");
                }
                printf("\nSearch another Record (Y/N) ");
                fflush(stdin);
                another = getche();
            }
            fclose(fp);
            break;

        case '6':
            system("cls");
            admin_view();
            fclose(fp);
            break;
        case '7':
            system("cls");
            fclose(fp);
            mmenu();
            break;
        case '8':
            attractiveExit();
            exit(0);
            break;
        }
    }
}
int user_booking()
{
    FILE *fp, *ft,*log;
    char another, choice;
    int f;

    Booking b1;
    char name[MAX_NAME_LENGTH], email[100], temp;
    long int bsize = sizeof(b1);

    // create the file if it does not exist
    fp = fopen("record.dat", "ab");
    if (fp == NULL)
    {
        puts("Cannot create file");
        exit(0);
    }
    fclose(fp);

    while (1)
    {
        system("cls");
        printf("   ****************************** User Panel ***************************** \n");
        for (int i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("\nEnter 0 -> Guidelines\n");
        printf("--------------------------------");
        printf("\nEnter 1 -> Add Booking\n");
        printf("--------------------------------");
        printf("\nEnter 2 -> View Booking\n");
        printf("--------------------------------");
        printf("\nEnter 3 -> Search Booking\n");
        printf("--------------------------------");
        printf("\nEnter 4 -> Go to Main Menu\n");
        printf("--------------------------------");
        printf("\nEnter 5 -> Exit\n");
        printf("--------------------------------");
        printf("\n\nEnter Your Choice : ");
        fflush(stdin);
        choice = getche();
        getch();

        switch (choice)
        {
        case '0':
        {
            system("cls");
            printf("\n                                                GUIDELINES");
            printf("\n-----------------------------------------------------------------------------------------------------------------------------");
            printf("\n|| 1. First Name/ Last Name: You should enter characters only without spaces, number or special characters are not allowed ||");
            printf("\n|| 2. Age: Numbers and characters both are allowed                                                                         ||");
            printf("\n|| 3. Contact Number: You should enter numbers only without spaces, characters or special characters are not allowed       ||");
            printf("\n|| 4. Email Address: You should enter a personal email for booking                                                         ||");
            printf("\n|| 5. Event Name : Characters,Numbers,Special Characters and Spaces are allowed                                            ||");
            printf("\n|| 6. Event Date : Booking can be done at least 07 days prior to the event.                                                ||");
            printf("\n|| 7. Event Time : Allotment is valid from 10:00 a.m. to 9:00 p.m. of the specified dates. when full payment is made       ||");
            printf("\n-----------------------------------------------------------------------------------------------------------------------------");
            printf("\n\n\nPress any key to go back..");
            getch();
            user_booking();
        }
        case '1':
            fp = fopen("record.dat", "rb+");
            if (fp == NULL)
            {
                puts("Cannot open file");
                exit(0);
            }
            log= fopen("RequestLog.txt","a");
            if(log== NULL){
                puts("\nCannot open backup file");
                fclose(log);
            }
            system("cls");
            fseek(fp, 0, SEEK_END);
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                printf("\nEnter the details of the organizer\n");
            name:
                printf("First Name : ");
                scanf("%s", b1.name);

                for (int i = 0; i < strlen(b1.name); i++)

                {

                    int j = b1.name[i];

                    if ((j >= 97 && j <= 122) || (j >= 65 && j <= 90) || (j == 32 && j == 92))

                    {

                        // printf("\n%d",n[i]);

                        continue;
                    }

                    else

                    {

                        printf("\nFirst name is invalid! Enter alphabets only!!!");

                        Sleep(1500);

                        system("cls");

                        goto name;
                    }
                }

            lname:
                printf("Last Name : ");
                scanf("%s", b1.lname);
                for (int i = 0; i < strlen(b1.lname); i++)

                {

                    int k = b1.lname[i];

                    if ((k >= 97 && k <= 122) || (k >= 65 && k <= 90) || (k == 32 && k == 92))

                    {

                        continue;
                    }

                    else

                    {

                        printf("\nLast name invalid! Enter alphabets only!!!");

                        goto lname;
                    }
                }
                printf("Age : ");
                scanf("%s", &b1.age);
            contact1:
                printf("Contact number ( only numbers, e.g. 1234567890 ): ");
                scanf("%s", b1.phone_no);
                if (!validateMobileNumber(b1.phone_no))
                {
                    printf("Invalid mobile number\n");
                    goto contact1;
                }
                printf("Email address : ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%[^\n]", b1.email);
                printf("Event name : ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%[^\n]", b1.event_name);
                printf("Date of event (yyyy-mm-dd): ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%[^\n]", b1.event_date);
                printf("Event time (In 24 hr format, e.g. 16:00-19:00 ) : ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%[^\n]", b1.event_time);
                b1.isAccepted = 0;
                strcpy(b1.operation, "Added");
                if (b1.isAccepted == 0)
                    strcpy(b1.status, "Pending");
                if (b1.isAccepted == 1)
                    strcpy(b1.status, "Approved");
                if (b1.isAccepted == -1)
                    strcpy(b1.status, "Declined");
                fwrite(&b1, bsize, 1, fp);
                fprintf(log, "\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-20s %-10s", b1.name, b1.lname, b1.age, b1.phone_no, b1.email, b1.event_name, b1.event_date, b1.event_time, b1.status, b1.operation);
                printf("\nRequest sent successfully... \n");
                fclose(fp);
                fclose(log);
                fflush(stdout);
                printf("\nAdd another booking request (Y/N) ");
                fflush(stdin);
                another = getche();
            }
            break;

        case '2':
            fp = fopen("record.dat", "rb");
            if (fp == NULL)
            {
                puts("Cannot open file");
                exit(0);
            }
            system("cls");
            printf("\n   ****************************** UPCOMING EVENTS ***************************** \n\n");
            rewind(fp);
            f = 0;
            printf("--------------------------------------------------------------------------");
            printf("\n%-15s %-20s %-20s %-20s", "Name", "Event Name", "Event date", "Event Time");
            printf("\n--------------------------------------------------------------------------\n");
            while (fread(&b1, bsize, 1, fp) == 1)
            {
                f = 1;
                if (b1.isAccepted == 0)
                    strcpy(b1.status, "Pending");
                if (b1.isAccepted == 1)
                    strcpy(b1.status, "Approved");
                if (b1.isAccepted == -1)
                    strcpy(b1.status, "Declined");
                if (strcmp(b1.status, "Approved") == 0)
                    printf("\n%-15s  %-20s %-20s %-20s", b1.name, b1.event_name, b1.event_date, b1.event_time);
            }
            if (f == 0)
            {
                printf("\nRecord does not exist\n");
            }
            printf("\n\nPress any key to continue...");
            getch();
            fclose(fp);
            break;

        case '3':
            fp = fopen("record.dat", "rb+");
            if (fp == NULL)
            {
                puts("Cannot open file");
                exit(0);
            }
            system("cls");
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                f = 0;
                printf("\nEnter Email of organizer to search : ");
                scanf("%s", email);
                rewind(fp);
                while (fread(&b1, bsize, 1, fp) == 1)
                {
                    if (strcmpi(b1.email, email) == 0)
                    {
                        if (b1.isAccepted == 0)
                            strcpy(b1.status, "Pending");
                        if (b1.isAccepted == 1)
                            strcpy(b1.status, "Approved");
                        if (b1.isAccepted == -1)
                            strcpy(b1.status, "Declined");
                        printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
                        printf("\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-10s", "Name", "Last_Name", "Age", "Phone number", "Email", "Event Name", "Event date", "Event Time", "Status");
                        printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
                        printf("\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-10s", b1.name, b1.lname, b1.age, b1.phone_no, b1.email, b1.event_name, b1.event_date, b1.event_time, b1.status);
                        f = 1;
                        break;
                    }
                }
                if (f == 0)
                {
                    printf("Record not found\n");
                }
                printf("\nSearch another Record (Y/N) ");
                fflush(stdin);
                another = getche();
            }
            fclose(fp);
            break;

        case '4':
            system("cls");
            fclose(fp);
            mmenu();
            break;

        case '5':
            system("cls");
            attractiveExit();
            exit(0);
            break;

        default:
            printf("\nInvalid choice \n\n Try Again !!\n");
        }
    }
}
void login()
{
    Admin a1;
    FILE *fp;
    int a = 0;
    char temp2, ch, p2[100];
    int l;
    system("cls");
    char uname[MAX_NAME_LENGTH], upass[MAX_NAME_LENGTH];
    while (a == 0)
    {
        l = 0;
        printf("   ******************************  LOGIN PORTAL  ***************************** \n");
        for (int i = 0; i < 80; i++)
            printf("-");
        printf("\n\n");
        printf("Enter username : ");
        scanf("%s", uname);
        printf("Enter password : ");
        // scanf("%s", upass);
        while (1)

        {

            temp2 = getch();

            if (temp2 == '\r')

            {

                upass[l] = '\0';

                break;
            }

            else if (temp2 == '\b')

            {

                if (l > 0)

                {

                    l--;

                    printf("\b \b");
                }
            }

            else if (temp2 == '\t' || temp2 == ' ')

            {

                continue;
            }

            else

            {

                upass[l] = temp2;

                l++;

                printf("*");
            }
        }
        fp = fopen("credential.dat", "ab+");
        if (fp == NULL)
            {
                
            }
        while (fread(&a1, sizeof(a1), 1, fp) == 1)
        {
            if (strcmp(uname, a1.username) == 0 && strcmp(upass, a1.password) == 0)
            {
                a = 1;
                printf("\n\nSuccesfully logged in !!");
                admin_view();
                fclose(fp);

                break;
            }
            if (strcmp(uname, a1.username) == 0 && strcmp(upass, a1.password) != 0)
            {
                printf("\n\nIncorrect password \nTry Again !!\n");
                Sleep(1000);
                system("cls");
            }
            else
            {
                printf("\n\nInvalid user \n");
                Sleep(1000);
                system("cls");
            }
        }
    }
}

void admin_view()
{
    char name[MAX_NAME_LENGTH], status[10];

    Sleep(1000);
    Admin a1;
    system("cls");
    int choice, choice1, a = 1;
    char new_password[MAX_NAME_LENGTH], pass[MAX_NAME_LENGTH], temp;
    FILE *fp;
    fp = fopen("credential.dat", "ab+");
    while (a == 1)
    {
        printf("   ****************************** ADMIN PANEL  ***************************** \n");
        for (int i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("\n\nEnter 1 -> Change password\n");
        printf("--------------------------------");
        printf("\nEnter 2 -> Manage Booking\n");
        printf("--------------------------------");
        printf("\nEnter 3 -> Booking Approval\n");
        printf("--------------------------------");
        printf("\nEnter 4 -> Exit\n");
        printf("--------------------------------");
        printf("\n\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            while (a == 1)
            {
                fp = fopen("credential.dat", "ab+");
                while (fread(&a1, sizeof(a1), 1, fp) == 1)
                {
                    printf("\n\nPress any key to continue..");
                    getch();
                    system("cls");
                    printf("Enter old password : ");
                    scanf("%s", pass);
                    printf("Enter new password : ");
                    scanf("%s", new_password);
                    if (strcmp(a1.password, pass) == 0)
                    {
                        if (strcmp(a1.password, new_password) == 0)
                        {
                            printf("\nOld password and new password should be different");
                            printf("\n\nPress any key to continue..");
                            getch();
                            break;
                        }

                        if (!check_pass(new_password))
                        {
                            a = 0;
                            change_pass(new_password);
                            fclose(fp);
                            break;
                        }
                    }
                    else
                    {
                        printf("Old password is incorrect");
                        Sleep(1000);
                        break;
                    }
                }
            }
            break;
        }
        case 2:
            booking_view();
            break;
            //fix this
        case 3:{
            system("cls");
            char name1[50];
            Booking b1;
            FILE *fp = fopen("record.dat", "r+b");
            if (fp == NULL)
            {
                printf("Error opening file\n");
                fclose(fp);
            }
            printf("   ****************************** Approve / Disapprove Booking ***************************** \n");
            for (int i = 0; i < 80; i++)
                printf("-");
            printf("\n\nEnter Name to grant permission: ");
            scanf("%s", name1);
            updateStatus(name1);
            FILE *log= fopen("RequestLog.txt","a");
            if(log== NULL){
                puts("\nCannot open backup file");
                fclose(log);
                }
            while (fread(&b1, sizeof(Booking), 1, fp) == 1)
            {
                if (strcmpi(b1.name, name) == 0)
                {
                    if (b1.isAccepted == 0)
                            strcpy(b1.status, "Pending");
                        if (b1.isAccepted == 1)
                            strcpy(b1.status, "Approved");
                        if (b1.isAccepted == -1)
                            strcpy(b1.status, "Declined");
                        b1.isAccepted = 0;
                fprintf(log, "\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-20s %-10s", b1.name, b1.lname, b1.age, b1.phone_no, b1.email, b1.event_name, b1.event_date, b1.event_time, b1.status, b1.operation);
                }
            }
                fclose(fp);
                fclose(log);
                fflush(stdout);
            break;
        }
        case 4:
            printf("\nQuitting..");
            a = 0;
            attractiveExit();
            exit(0);
            break;
        default:
            printf("Invalid option");
        }
    }
}

void change_pass(char *new_password)
{
    Admin account;
    FILE *file = fopen("credential.dat", "r+b");
    if (file == NULL)
    {
        printf("Account file does not exist\n");
    }
    while (fread(&account, sizeof(account), 1, file) == 1)
    {
        strncpy(account.password, new_password, sizeof(account.password));
        fseek(file, -sizeof(account), SEEK_CUR);
        fwrite(&account, sizeof(account), 1, file);
        fclose(file);
        if (CopyAdminPass("credential.dat", "AdminLog.txt") == 1)
        {
            printf("\n\nPassword Changed Successfully\n");
            admin_view();
        }
        else
        {
            printf("\nTry Again");
            printf("\n\nPress any key to continue..");
            getch();
            admin_view();
        }
    }
}
int check_pass(char *password)
{
    Sleep(2000);
    int length = strlen(password);
    if (length < 8 && length > 14)
    {
        printf("\nPassword Should be between 8 - 14 characters\n");
        return 1;
    }
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_schar = 0;
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_uppercase = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lowercase = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_number = 1;
        }
        else if (!isalpha(password[i]))
        {
            has_schar = 1;
        }
    }

    if (!has_uppercase)
    {
        printf("\nPassword should contain atleast one uppercase letter\n");
        return 1;
    }
    if (!has_lowercase)
    {
        printf("\nPassword should contain atleast one uppercase letter\n");
        return 1;
    }
    if (!has_number)
    {
        printf("\nPassword should contain atleast one number\n");
        return 1;
    }
    if (!has_schar)
    {
        printf("\nPassword should contain atleast one special character ( @ , # , $ ) \n");
        return 1;
    }
    else
        return 0;
}

void loadingBar(char *text)
{
    char a = 177, b = 219;
    printf("\n\t\t\t\t\t%s...\n\n", text);
    printf("\t\t\t\t");

    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        printf("%c", a);

    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t");

    // Print loading bar progress
    for (int i = 0; i < 26; i++)
    {
        printf("%c", b);
        Sleep(100);
    }
}

void updateStatus(char *name)
{
    Booking b1;
    Booking foundUser;
    int a = 0;
    FILE *file = fopen("record.dat", "r+b");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    
    while (fread(&b1, sizeof(Booking), 1, file) == 1)
    {
        if (strcmpi(b1.name, name) == 0)
        {
            foundUser = b1;
            if (foundUser.isAccepted == 0)
            {
                a = 1;
                printf("Booking request Found:\n");
                printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
                printf("\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-10s", "Name", "Last_Name", "Age", "Phone number", "Email", "Event Name", "Event date", "Event Time", "Status");
                printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
                printf("\n%-15s %-15s %-5s %-15s %-30s %-20s %-20s %-20s %-10s", b1.name, b1.lname, b1.age, b1.phone_no, b1.email, b1.event_name, b1.event_date, b1.event_time, b1.status);

                printf("\n\nDo you want to approve request for this booking? (Y/N): ");
                char choice[2];
                scanf("%s", &choice);
                if (strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0)
                {
                    foundUser.isAccepted = 1;
                    printf("\n\nPermission Granted.\n");
                    Sleep(1000);
                }
                else
                {
                    foundUser.isAccepted = -1;
                    printf("\n\nPermission Denied.\n");
                    Sleep(1000);
                }
                // Update the user's status in the file
                fseek(file, -sizeof(Booking), SEEK_CUR);
                fwrite(&foundUser, sizeof(Booking), 1, file);
                fclose(file);
                fflush(stdout);
                break;
            }
            else
            {
                printf("Registration has already been processed.\n");
            }
        }
    }
    if (a == 0)
    {
        printf("\n\nNo Booking request found with the name : %s", name);
        fclose(file);
        Sleep(2000);
    }
    system("cls");
}

int CopyAdminPass(char *rafname, char *txtname) // changed return value
{
    FILE *fraf, *ftxt;
    struct admin p;
    if ((fraf = fopen(rafname, "rb")) == NULL)
        return 0; // failure

    if ((ftxt = fopen(txtname, "a")) == NULL)
    { // changed mode
        fclose(fraf);
        return 0; // failure
    }
    fprintf(ftxt, "------------------------\n");
    while (fread(&p, sizeof(p), 1, fraf) == 1) // use return value to loop
        fprintf(ftxt, "%-15s\t%-15s\n", p.username, p.password);
    fclose(ftxt);

    fclose(fraf);
    return 1; // success
}


bool validateMobileNumber(const char *mobileNumber)
{
    int i = 0;
    while (mobileNumber[i] != '\0')
    {
        if (mobileNumber[i] < '0' || mobileNumber[i] > '9')
        {
            // Check if each character is a digit (0-9)
            return false;
        }
        i++;
    }

    if (i != 10)
    {
        // Check if the length is exactly 10 digits
        return false;
    }

    return true;
}

void setcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xB0) + (ForgC & 0x0B);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void attractiveExit()
{
    system("cls");
    printf("\n\t\t\t    *********************************\n");
    printf("\t\t\t    *                               *\n");
    printf("\t\t\t    *    Thank you for using        *\n");
    printf("\t\t\t    *         our System            *\n");
    printf("\t\t\t    *                               *\n");
    printf("\t\t\t    *      Have a great day!        *\n");
    printf("\t\t\t    *                               *\n");
    printf("\t\t\t    *********************************\n");
    loadingBar("Exiting");
}