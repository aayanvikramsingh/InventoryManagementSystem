// Inventory Management System(IMS)[UNIT1]

#include <stdio.h>
int main()
{
    int choice;
    printf("Welcome to Inventory Management System\n");
    printf("Enter [1] >>> PRODUCT DETAILS \n");
    printf("Enter [2] >>> SUPPLIER DETAILS\n");
    printf("Enter [3] >>> TRANSACTION DETAILS\n");
    printf("Enter Choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("*****PRODUCT DETAILS*****");
        break;
    case 2:
        printf("*****SUPPLIER DETAILS*****");
        break;
    case 3:
        printf("*****TRANSACTION DETAILS*****");
        break;
    default:
        printf("INVALID CHOICE!!!");
    }
    return 0;
}