#define MAX_NAME_LENGTH 20

typedef struct admin {
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];
}Admin;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char lname[MAX_NAME_LENGTH];
    char status[MAX_NAME_LENGTH];
    char operation[MAX_NAME_LENGTH];
    char age[15];
    char event_name[100];
    char event_time[15]; // format : 16:00 - 19:00
    char phone_no[15]; //format : +91 1234567890
    char email[50];
    char event_date[11]; // format: yyyy-mm-dd
    int isAccepted;
} Booking;