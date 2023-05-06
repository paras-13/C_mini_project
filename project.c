/* @author :- Paras Upadhyay */

// Studence Attendance Calculator

//Header Files 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

// Global Structures
struct details
{
    int reg_no; 
    char username[20];
    char pass[20];
} user;

struct student
{
    char name[20];
    int reg_no;
    char class_section[10];
    int roll_no;
    float cgpa;
    int att;
    char elig;
} stu;

// Global variables
int r_num, n, net_att;

// Global arrays
char course[10][10];
int class[10], attended[10], course_att[10];

// Functions
int entry();
void Register();
int Login();
int reg_check(int reg_no);
int Insert();
void calc();
void Display();
void Search(); 
void Delete();
void Check_Status();

// Function Declaration
// Entry function welcomes the user, provides choice for registeration / login, and finally returns success or not
int entry()
{
    int result;
    printf(" \n\t\t\t################ Welcome to STUDENT ATTENDANCE CALCULATOR #####################\n\n");
    printf("With the help of this portal user can check attendance update, attendance record maintained in each course and total net attendance.\n");\
    printf("--> User can Insert a new student record\n");
    printf("--> User can Delete existing student record\n");
    printf("--> User can Display all existing student record\n");
    printf("--> User can Search for a particular student record\n");

    char entry[20];
    printf("\nIf you are new to this portal REGISTER yourself; if pre-registered then LOGIN :-\n");
    printf("Enter '--register' command to register your self otherwise type '--login' command to login\n> ");
    fflush(stdin);
    scanf("%s", entry);

    if (strcmp(entry, "--login") == 0)
    {
        printf("Welcome you are here to login yourself ....\n");
        result = Login(); // Directs user to Login.
        if (result)
            return 1; // If success it returns 1 to the main function.
        else
            return 0; // If not success it returns 0 to the main function.
    }
    else if (strcmp(entry, "--register") == 0)
    {
        printf("Welcome you are here to register yourself\n"); // Directs user to Register.
        Register();
    }
    else
    {
        printf(" xxxxxxxxxxx Sorry! No such command xxxxxxxxxxxx\n\n"); // If command is not appropriately given.
        exit(1);
    }
}

// This function allows user to register, and later directs him/her to Login function as well.
void Register()
{
    FILE *fp;
    int allow;
    fp = fopen("details.txt", "a");
    printf("Register yourself :- \n");
    struct details;
    printf("Registration Number :- ");
    scanf("%d", &user.reg_no);
    r_num = user.reg_no;
    allow = reg_check(user.reg_no); // this is to check whether the user is pre - registered or not

    if (allow)
    {
        printf("You have already register, Redirecting you to LOGIN\n ");
        Login();
    }
    else
    {
        user.reg_no = r_num;
        printf("Username :- ");
        scanf("%s", user.username);
        printf("Set a password, (Min length =8, Max = 20) :- ");
        scanf("%s", user.pass);
        fwrite(&user, sizeof(user), 1, fp);
        fclose(fp);
        printf("\n xxxxxxxxxxx Registered Successfully xxxxxxxxxxxxxxxx\n");
        printf("Directing you toward login page //\n");
        Login(); // Finally user is directed to Login after successfully registering him/her self.
    }
}

// This function checks for pre-registered user trying to register again.
int reg_check(int reg_no)
{
    FILE *fp;
    int flag = 0;
    fp = fopen("details.txt", "r");
    struct details;
    while (fread(&user, sizeof(user), 1, fp))
    {
        if (user.reg_no == reg_no)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    return 1;
    else
    return 0;
}

// This function allows user to Login. After successfully logged in this function directs user to perform further other functionalities.
int Login()
{

    struct details;
    FILE *fp;
    int reg, flag = 0, inreg;
    char pas[20], inpas[20];

    printf("Enter you reg_no = ");
    scanf("%d", &reg);
    printf("Enter your password = ");
    scanf("%s", pas);

    fp = fopen("details.txt", "r");
    while (fread(&user, sizeof(user), 1, fp))
    {
        inreg = user.reg_no;
        strcpy(inpas, user.pass);
        if (inreg == reg && strcmp(inpas, pas) == 0)
        {
            flag = 1;
            break;
        }
    }
    fclose(fp);
    if (flag == 1)
    {
        printf("\n * * * *  USER IDENTIFIED * * * * ,successfully logged in\n");
        return 1;
    }
    else
    {
        printf("Not an authorised user\n");
        return 0;
    }
}

// This function calculates course-wise as well total net attendance.
void calc()
{
    int week, left, att_sum = 0;
    printf("\n--> Enter the current number of week = \n");
    scanf("%d", &week);
    for (int i = 0; i < n; i++)
    {
        printf("> Enter the number of classes missed till now in %s = ", course[i]);
        scanf("%d", &left);
        attended[i] = (class[i] * week) - left;
    }
    printf("\n xxxxxxxxxxxxxx Your attendance in respective courses is :-xxxxxxxxxxxxxxxxxxxxx\n");
    for (int j = 0; j < n; j++)
    {
        course_att[j] = (attended[j] * 100) / (class[j] * week);

        printf("--> %s = %d\n", course[j], course_att[j]);
        att_sum += course_att[j];
    }
    net_att = att_sum / n;
    printf("\n\nYour total net aggregrate atendance is = %d%%", net_att);
}

// This function allows user to enter his/her class details, course code and classes attended, calculation of net attendance and saving them in a file
int Insert()
{
    FILE *fp;
    struct student;
    fflush(stdin);
    printf("\nEnter student name :- ");
    gets(stu.name);
    printf("Enter your registration number:-");
    scanf("%d",&stu.reg_no);
    fflush(stdin);
    printf("Enter class and section name :- ");
    gets(stu.class_section);
    printf("Enter roll no :- ");
    scanf("%d", &stu.roll_no);
    printf("Enter  cgpa :- ");
    scanf("%f", &stu.cgpa);
    printf("\n\n-------NOW :- Enter data to calculate your net and subjective attendance------\n");
    printf("Enter the total no of courses you have = ");
    scanf("%d", &n);
    printf("Enter the Total no of class in a week for the particular course \n");
    printf("xxxxx Kindly enter the course name in UPPERCASE only xxxxx\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d Course code = ", i + 1);
        scanf("%s", course[i]);
        fflush(stdin);
        printf("Classes to attend per week in %s = ", course[i]);
        scanf("%d", &class[i]);
        printf("\n");
    }
    calc(); // Directing towards calc function
    stu.att = net_att;
    if (net_att >= 75)
        stu.elig = 'T';
    else
        stu.elig = 'F';
    fp = fopen("data.txt", "a");
    fwrite(&stu, sizeof(stu), 1, fp);
    printf("\nxxxxxxxxxxxxxxx Record inserted successfully xxxxxxxxxxxxxxxxxxxxxx\n");
    fclose(fp);
}

// To display all record entered
void Display()
{
    int test;
    printf("\nDisplaying all student record ........\n");
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("File not found! or maybe you have't inserted you data yet\n");
        Login();
    }
    else
    {
        Sleep(2000);
        printf("\t\tName\t\tRegistration_no \tClass_Section\tRoll_no \tCGPA\tAttendance\tStatus\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&stu, sizeof(stu), 1, fp))
        {
            printf("\t\t%s\t %d\t\t %s\t\t %d\t\t %.2f\t %d\t\t %c\n", stu.name, stu.reg_no, stu.class_section, stu.roll_no, stu.cgpa, stu.att, stu.elig);
        }
    }
    printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Here --> \n T:- represents = eligible for End Term Examinations\nF :- represents not eligible for End Term Examinations");
    fclose(fp);
}

// To search details of a particular user.
void Search()
{
    FILE *fp;
    struct student;
    int reg_no, flag = 0;
    printf("Search for the student detail you want to find :-\n");
    printf("Enter registration number to display record = ");
    scanf("%d", &reg_no);
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exit!");
        Login();
    }
    else
    {
        while (fread(&stu, sizeof(stu), 1, fp))
        {
            if (stu.reg_no == reg_no)
            {
                flag = 1;
                printf(" \nxxxxxxxxxxxxxxxxxxx Record Found xxxxxxxxxxxxxxxxxxx\n");
                printf("> Name :- %s\n", stu.name);
                printf("> Registration No :- %d\n", stu.reg_no);
                printf("> Class & Section  :- %s\n", stu.class_section);
                printf("> Roll No :- %d\n", stu.roll_no);
                printf("> CGPA :- %.2f\n", stu.cgpa);
                printf("> Overall Attendance :- %d%%\n", stu.att);
                if (stu.elig == 'T')
                    printf("You are **ELIGIBLE**  to sit for End Term Examinations\n");
                else
                    printf("Your total attendance is less than 75%%. Hence you are **NOT ELIGIBLE**  to sit for End-Term Examinations\n");
                break;
            }
        }
        if (flag == 0)
            printf("Invalid Registration number");
    }
}

// To delete a particular entry made.
void Delete()
{
    FILE *fp, *fp1;
    int reg;
    struct student;
    printf("Enter registration number for whom you want to delete the record = ");
    scanf("%d", &reg);

    fp = fopen("data.txt", "r");
    fp1 = fopen("data1.txt", "a");

    while (fread(&stu, sizeof(stu), 1, fp))
    {
        if (stu.reg_no != reg)
        {
            fwrite(&stu, sizeof(stu), 1, fp1);
        }
        else
            continue;
    }
    printf("Deleting the record\n");
    Sleep(2000);
    fclose(fp);
    fclose(fp1);
    remove("data.txt");
    rename("data1.txt", "data.txt");
    printf(" xxxxxxxxxxxxxxxRecord succefully deletedxxxxxxxxxxxx\n");
    printf("Displaying new record :- \n");
    Display();
}

void Check_Status()
{
    FILE *fp;
    struct student;
    printf("\n Printing name, attendance and status of users who are eligible for end term examinations :- \n");
    fp = fopen("data.txt", "r");
    printf("\nName\t\tAttendance\tStatus\n");
    while (fread(&stu, sizeof(stu), 1, fp))
    {
        if (stu.elig == 'T')
        {
            printf("%s\t%d\t\tEligible to give End-Term Examination\n",stu.name, stu.att);
        }
    }
    printf("\n\nNow Printing name, attendance and status of users who are NOT ELIGIBLE for end term examinations\n");
    fp = fopen("data.txt", "r");
    printf("\nName\t\tAttendance\tStatus\n");
    while (fread(&stu, sizeof(stu), 1, fp))
    {
        if (stu.elig == 'F')
        {
            printf("%s\t%d\t\tNot-Eligible to give End-Term Examination\n",stu.name, stu.att);
        }
    }
}
// Main function
int main()
{
    int access, choice, flag = 1;
    char ch;
    access = entry();
    if (access == 1)
    {
    label:
        while (flag)
        {
            printf("\n\nEnter your choice : Press :- \n(1) to Insert record\n(2) to Display record\n(3) to Search record\n(4) to Delete record\n(5) to Check_Status record\n(6) to Exit\n> ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                Insert();
                break;
            case 2:
                Display();
                break;
            case 3:
                Search();
                break;
            case 4:
                fflush(stdin);
                printf("CAUTION :- Please verify ones again before deleting any record\n");
                printf("Press 1 --> to recheck the record. || Press ANY key excluding 1 to continue deleting the record\n");
                scanf("%c", &ch);
                if (ch == '1')
                {
                    Display();
                    fflush(stdin);
                    printf("\nOnce you have verified --> Press enter key to continue deleting OR  Press 1 to exit deleting a record = ");
                    scanf("%c", &ch);
                    if (ch == '1')
                        goto label;
                    else
                        Delete();
                }
                else
                    Delete();
                break;
            case 5:
                Check_Status();
                break;
            case 6:
                printf("\n xxxxxxxxxxxxxxxxxxxxxxxxxx Thank you, Program ends xxxxxxxxxxxxxxxxxxxxxxxxx\n");
                flag = 0;
                break;
            }
        }
    }
    else
    {
        printf(" xxxxxxxxxxxxxxx You are not a verified user; Kindly Re-enter the details :- xxxxxxxxxxxxxxxxx\n");
        main();
    }
}