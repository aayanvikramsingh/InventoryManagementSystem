// Inventory Management System(IMS)[UNIT1][UNIT2]
#include <stdio.h>
#include <string.h>
// Variables regarding Product Details.
int countprod = 0;
#define maxprod 100   // defines maxprod as 100 as a preprocessor directive.
#define maxstrlen 100 // defines max str len that is being added in a 2-D array
char prodname[maxprod][maxstrlen];
int prodid[maxprod];
float prodprice[maxprod];
int prodquantity[maxprod];

void addproduct();
void updateproduct();
void deleteproduct();
void displayproduct();

// Variables regarding Supplier Details.
int countsupp = 0;
#define maxsupp 100 // defines maxsupp as 100 as a preprocessor directive.
char suppname[maxsupp][maxstrlen];
char suppaddress[maxsupp][maxstrlen];
int suppid[maxsupp];

void addsupplier();
void updatesupplier();
void deletesupplier();
void displaysupplier();

// Variables regarding Transaction Details.
int counttrans = 0;
#define maxtrans 100 // defines maxtrans as 100 as a preprocessor directive.
char transdate[maxtrans][maxstrlen];
int transprodid[maxtrans];
int transid[maxtrans];
int transquantity[maxtrans];

void recordnewtransaction();
void updatetransaction();
void displaytransactionhistory();

int main()
{
    while (1)
    {
        int choice;
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$       WELCOME TO INVENTORY MANAGEMENT SYSTEM      $$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("Enter [1] >>> PRODUCT DETAILS \n");
        printf("Enter [2] >>> SUPPLIER DETAILS\n");
        printf("Enter [3] >>> TRANSACTION DETAILS\n");
        printf("Enter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("***************PRODUCT DETAILS***************\n");
            int choiceofproddetails;
            printf("Enter [1] >>> ADD PRODUCT\n");
            printf("Enter [2] >>> UPDATE PRODUCT\n");
            printf("Enter [3] >>> DELETE PRODUCT\n");
            printf("Enter [4] >>> DISPLAY PRODUCT\n");
            printf("Enter the choice with respect to Product Details:\n");
            scanf("%d", &choiceofproddetails);
            switch (choiceofproddetails)
            {
            case 1:
                printf("***************ADD PRODUCT***************\n");
                addproduct();
                break;
            case 2:
                printf("***************UPDATE PRODUCT***************\n");
                updateproduct();
                break;
            case 3:
                printf("***************DELETE PRODCUT***************\n");
                deleteproduct();
                break;
            case 4:
                printf("***************DISPLAY PRODUCT***************\n");
                displayproduct();
                break;
            default:
                printf("INVALID CHOICE WITH RESPECT TO PRODUCT DETAILS !!!\n");
            }
            break;

        case 2:
            printf("***************SUPPLIER DETAILS***************\n");
            int choiceofsuppdetails;
            printf("Enter [1] >>> ADD SUPPLIER\n");
            printf("Enter [2] >>> UPDATE SUPPLIER\n");
            printf("Enter [3] >>> DELETE SUPPLIER\n");
            printf("Enter [4] >>> DISPLAY SUPPLIER\n");
            printf("Enter the choice with respect to Supplier Details:\n");
            scanf("%d", &choiceofsuppdetails);
            switch (choiceofsuppdetails)
            {
            case 1:
                printf("***************ADD SUPPLIER***************\n");
                addsupplier();
                break;
            case 2:
                printf("***************UPDATE SUPPLIER***************\n");
                updatesupplier();
                break;
            case 3:
                printf("***************DELETE SUPPLIER***************\n");
                deletesupplier();
                break;
            case 4:
                printf("***************DISPLAY SUPPLIER***************\n");
                displaysupplier();
                break;
            default:
                printf("INVALID CHOICE WITH RESPECT TO SUPPLIER DETAILS !!!\n");
            }
            break;

        case 3:
            printf("***************TRANSACTION DETAILS***************\n");
            int choiceoftransdetails;
            printf("Enter [1] >>> RECORD NEW TRANSACTION\n");
            printf("Enter [2] >>> UPDATE TRANSACTION\n");
            printf("Enter [3] >>> DISPLAY TRANSACTION HISTORY\n");
            printf("Enter the choice with respect to Transaction Details:\n");
            scanf("%d", &choiceoftransdetails);
            switch (choiceoftransdetails)
            {
            case 1:
                printf("***************RECORD NEW TRANSACTION***************\n");
                recordnewtransaction();
                break;
            case 2:
                printf("***************UPDATE TRANSACTION HISTORY***************\n");
                updatetransaction();
                break;
            case 3:
                printf("***************DISPLAY TRANSACTION HISTORY***************\n");
                displaytransactionhistory();
                break;
            default:
                printf("INVALID CHOICE WITH RESPECT TO TRANSACTION DETAILS !!!\n");
            }
            break;

        default:
            printf("INVALID CHOICE!!!\n");
        }
    }
    return 0;
}

// Functions related to Product

void addproduct()
{
    int n;
    printf("Please add number of products below [%d]\n", maxprod);
    printf("Enter the number of products you want to add:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (countprod < maxprod)
        {
            printf("Enter Product No[%d]\n", i + 1);

            printf("Enter PRODUCT_ID:\n");
            scanf("%d", &prodid[countprod]);

            printf("Enter PROUCT_NAME:\n");
            scanf("%s", &prodname[countprod]); // here we are taking input for the rowpart only.

            printf("Enter PRODUCT_PRICE:\n");
            scanf("%f", &prodprice[countprod]);

            printf("Enter PRODUCT_QUANTITY:\n");
            scanf("%d", &prodquantity[countprod]);

            countprod++;

            printf("Added Product Number[%d] Successfully!!!\n", countprod);
        }
        else
        {
            printf("You have added Maximum Number of Products possible i.e [%d]", maxprod);
        }
    }
}

void updateproduct()
{
    int ProudctID, i;

    printf("Enter the PRODUCT_ID of the proudct that needs to be udpated:\n");
    scanf("%d", &ProudctID);

    for (i = 0; i < countprod; i++)
    {
        if (ProudctID == prodid[i])
        {
            printf("Enter New PROUCT_NAME:\n");
            scanf("%s", prodname[i]);
            printf("Enter New PRODUCT_PRICE:\n");
            scanf("%f", &prodprice[i]);
            printf("Enter New PRODUCT_QUANTITY:\n");
            scanf("%d", &prodquantity[i]);

            printf("Product with PRODUCT_ID[%d] updated successfully !!!", ProudctID);
        }
        else
        {
            printf("Product with PRODUCT_ID[%d] Not found !!!", ProudctID);
        }
    }
}

void deleteproduct()
{
    int ProudctID, i;

    printf("Enter the PRODUCT_ID of the proudct that needs to be deleted:\n");
    scanf("%d", &ProudctID);

    for (i = 0; i < countprod; i++)
    {
        if (ProudctID == prodid[i])
        {
            for (int j = i; j < countprod; j++)
            {
                prodid[j] = prodid[j + 1];
                strcpy(prodname[j], prodname[j + 1]);
                prodprice[j] = prodprice[j + 1];
                prodquantity[j] = prodquantity[j + 1];
            }
            countprod--;
            printf("Product with PRODUCT_ID[%d] deleted successfully !!!", ProudctID);
        }
        else
        {
            printf("Product with PRODUCT_ID[%d] Not found !!!", ProudctID);
        }
    }
}

void displayproduct()
{
    printf("DISPLAYING PRODUCT DETAILS:\n");
    printf("PRODUCT_ID\tPRODUCT_NAME\tPRODUCT_PRICE\tPRODUCT_QUANTITY\n");
    for (int i = 0; i < countprod; i++)
    {
        printf("%d\t%s\t%f\t%d\n", prodid[i], prodname[i], prodprice[i], prodquantity[i]);
    }
}

// Functions related to Supplier

void addsupplier()
{
    int n;
    printf("Please add number of suppliers below [%d]\n", maxsupp);
    printf("Enter the number of suppliers you want to add:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (countsupp < maxsupp)
        {
            printf("Enter Supplier No[%d]\n", i + 1);

            printf("Enter SUPPLIER_ID:\n");
            scanf("%d", &suppid[countsupp]);

            printf("EnterSUPPLIER_NAME:\n");
            scanf("%s", &suppname[countsupp]); // here we are taking input for the rowpart only.

            printf("Enter SUPPLIER_ADDRESS:\n");
            scanf("%s", &suppaddress[countsupp]);

            countsupp++;

            printf("Added Supplier Number[%d] Successfully!!!\n", countsupp);
        }
        else
        {
            printf("You have added Maximum Number of Suppliers possible i.e [%d]", countsupp);
        }
    }
}

void updatesupplier()
{
    int SupplierID, i;

    printf("Enter the SUPPLIER_ID of the Supplier that needs to be udpated:\n");
    scanf("%d", &SupplierID);

    for (i = 0; i < countsupp; i++)
    {
        if (SupplierID == suppid[i])
        {
            printf("Enter New SUPPLIER_NAME:\n");
            scanf("%s", suppname[i]);
            printf("Enter New SUPPLIER_ADDRESS:\n");
            scanf("%s", suppaddress[i]);

            printf("Product with SUPPLIER_ID[%d] updated successfully !!!", SupplierID);
        }
        else
        {
            printf("Product with SUPPLIER_ID[%d] Not found !!!", SupplierID);
        }
    }
}

void deletesupplier()
{
    int SupplierID, i;

    printf("Enter the SUPPLIER_ID of the supplier that needs to be deleted:\n");
    scanf("%d", &SupplierID);

    for (i = 0; i < countsupp; i++)
    {
        if (SupplierID == suppid[i])
        {
            for (int j = i; j < countsupp; j++)
            {
                suppid[j] = suppid[j + 1];
                strcpy(suppname[j], suppname[j + 1]);
                strcpy(suppaddress[j], suppaddress[j + 1]);
            }
            countsupp--;
            printf("Supplier with SUPPLIER_ID[%d] deleted successfully !!!", SupplierID);
        }
        else
        {
            printf("Supplier with SUPPLIER_ID[%d] Not found !!!", SupplierID);
        }
    }
}

void displaysupplier()
{
    printf("DISPLAYING SUPPLIER DETAILS:\n");
    printf("SUPPLIER_ID\tSUPPLIER_NAME\tSUPPLIER_ADDRESS\n");
    for (int i = 0; i < countsupp; i++)
    {
        printf("%d\t%s\t%s\n", suppid[i], suppname[i], suppaddress[i]);
    }
}

// Functions related to Transaction.

void recordnewtransaction()
{
    int n;
    printf("Please add number of transaction below [%d]\n", maxtrans);
    printf("Enter the number of transactions you want to add:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (counttrans < maxtrans)
        {
            printf("Enter Transaction No[%d]\n", i + 1);

            printf("Enter TRANSACTION_ID:\n");
            scanf("%d", &transid[counttrans]);

            printf("Enter TRANSACTION_PRODUCT_ID:\n");
            scanf("%d", &transprodid[counttrans]);

            printf("Enter TRANSACTION_QUANTITY:\n");
            scanf("%d", &transquantity[counttrans]);

            printf("Enter TRANSACTION_DATE:\n");
            scanf("%s", &transdate[counttrans]); // here we are taking input for the rowpart only.

            counttrans++;

            printf("Added Transaction Number[%d] Successfully!!!\n", counttrans);
        }
        else
        {
            printf("You have added Maximum Number of Transactions possible i.e [%d]", counttrans);
        }
    }
}

void updatetransaction()
{
    int TransactionID, i;

    printf("Enter the TRANSACTION_ID of the transaction that needs to be udpated:\n");
    scanf("%d", &TransactionID);

    for (i = 0; i < counttrans; i++)
    {
        if (TransactionID == transid[i])
        {
            printf("Enter TRANSACTION_PRODUCT_ID:\n");
            scanf("%d", &transprodid[i]);

            printf("Enter TRANSACTION_QUANTITY:\n");
            scanf("%d", &transquantity[i]);

            printf("Enter TRANSACTION_DATE:\n");
            scanf("%s", &transdate[i]);

            printf("Product with TRANSACTION_ID[%d] updated successfully !!!", TransactionID);
        }
        else
        {
            printf("Product with TRANSACTION_ID[%d] Not found !!!", TransactionID);
        }
    }
}

void displaytransactionhistory()
{
    printf("DISPLAYING TRANSACTION DETAILS:\n");
    printf("TRANSACTION_ID\tTRANSACTION_PRODUCT_ID\tTRANSACTION_QUANTITY\tTRANSACTION_DATE\n");
    for (int i = 0; i < counttrans; i++)
    {
        printf("%d\t%d\t%d\t%s\n", transid[i], transprodid[i], transquantity[i], transdate[i]);
    }
}