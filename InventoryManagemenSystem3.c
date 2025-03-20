// Inventory Management System(IMS)[UNIT1][UNIT2][UNIT3]
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 100

// Structure for Product Details
typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

// Structure for Supplier Details
typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
} Supplier;

// Structure for Transaction Details
typedef struct
{
    int id;
    int productId;
    int quantity;
    char date[MAX_NAME_LENGTH];
} Transaction;

// Function prototypes
void addProduct(Product products[], int *count);
void updateProduct(Product products[], int count);
void deleteProduct(Product products[], int *count);
void displayProduct(Product products[], int count);

void addSupplier(Supplier suppliers[], int *count);
void updateSupplier(Supplier suppliers[], int count);
void deleteSupplier(Supplier suppliers[], int *count);
void displaySupplier(Supplier suppliers[], int count);

void recordNewTransaction(Transaction transactions[], int *count);
void updateTransaction(Transaction transactions[], int count);
void displayTransactionHistory(Transaction transactions[], int count);

int main()
{
    Product products[MAX_PRODUCTS];
    Supplier suppliers[MAX_PRODUCTS];
    Transaction transactions[MAX_PRODUCTS];
    int productCount = 0, supplierCount = 0, transactionCount = 0;
    int choice;

    while (1)
    {
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
            int productChoice;
            printf("Enter [1] >>> ADD PRODUCT\n");
            printf("Enter [2] >>> UPDATE PRODUCT\n");
            printf("Enter [3] >>> DELETE PRODUCT\n");
            printf("Enter [4] >>> DISPLAY PRODUCT\n");
            printf("Enter the choice with respect to Product Details:\n");
            scanf("%d", &productChoice);
            switch (productChoice)
            {
            case 1:
                printf("***************ADD PRODUCT***************\n");
                addProduct(products, &productCount);
                break;
            case 2:
                printf("***************UPDATE PRODUCT***************\n");
                updateProduct(products, productCount);
                break;
            case 3:
                printf("***************DELETE PRODUCT***************\n");
                deleteProduct(products, &productCount);
                break;
            case 4:
                printf("***************DISPLAY PRODUCT***************\n");
                displayProduct(products, productCount);
                break;
            default:
                printf("INVALID CHOICE WITH RESPECT TO PRODUCT DETAILS !!!\n");
            }
            break;

        case 2:
            printf("***************SUPPLIER DETAILS***************\n");
            int supplierChoice;
            printf("Enter [1] >>> ADD SUPPLIER\n");
            printf("Enter [2] >>> UPDATE SUPPLIER\n");
            printf("Enter [3] >>> DELETE SUPPLIER\n");
            printf("Enter [4] >>> DISPLAY SUPPLIER\n");
            printf("Enter the choice with respect to Supplier Details:\n");
            scanf("%d", &supplierChoice);
            switch (supplierChoice)
            {
            case 1:
                printf("***************ADD SUPPLIER***************\n");
                addSupplier(suppliers, &supplierCount);
                break;
            case 2:
                printf("***************UPDATE SUPPLIER***************\n");
                updateSupplier(suppliers, supplierCount);
                break;
            case 3:
                printf("***************DELETE SUPPLIER***************\n");
                deleteSupplier(suppliers, &supplierCount);
                break;
            case 4:
                printf("***************DISPLAY SUPPLIER***************\n");
                displaySupplier(suppliers, supplierCount);
                break;
            default:
                printf("INVALID CHOICE WITH RESPECT TO SUPPLIER DETAILS !!!\n");
            }
            break;

        case 3:
            printf("***************TRANSACTION DETAILS***************\n");
            int transactionChoice;
            printf("Enter [1] >>> RECORD NEW TRANSACTION\n");
            printf("Enter [2] >>> UPDATE TRANSACTION\n");
            printf("Enter [3] >>> DISPLAY TRANSACTION HISTORY\n");
            printf("Enter the choice with respect to Transaction Details:\n");
            scanf("%d", &transactionChoice);
            switch (transactionChoice)
            {
            case 1:
                printf("***************RECORD NEW TRANSACTION***************\n");
                recordNewTransaction(transactions, &transactionCount);
                break;
            case 2:
                printf("***************UPDATE TRANSACTION HISTORY***************\n");
                updateTransaction(transactions, transactionCount);
                break;
            case 3:
                printf("***************DISPLAY TRANSACTION HISTORY***************\n");
                displayTransactionHistory(transactions, transactionCount);
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

void addProduct(Product products[], int *count)
{
    if (*count < MAX_PRODUCTS)
    {
        printf("Enter Product No[%d]\n", *count + 1);
        printf("Enter PRODUCT_ID:\n");
        scanf("%d", &products[*count].id);
        printf("Enter PRODUCT_NAME:\n");
        scanf("%s", products[*count].name);
        printf("Enter PRODUCT_PRICE:\n");
        scanf("%f", &products[*count].price);
        printf("Enter PRODUCT_QUANTITY:\n");
        scanf("%d", &products[*count].quantity);
        (*count)++;
        printf("Added Product Successfully!!!\n");
    }
    else
    {
        printf("You have added Maximum Number of Products possible i.e [%d]\n", MAX_PRODUCTS);
    }
}

void updateProduct(Product products[], int count)
{
    int productId, i;
    printf("Enter the PRODUCT_ID of the product that needs to be updated:\n");
    scanf("%d", &productId);
    for (i = 0; i < count; i++)
    {
        if (productId == products[i].id)
        {
            printf("Enter New PRODUCT_NAME:\n");
            scanf("%s", products[i].name);
            printf("Enter New PRODUCT_PRICE:\n");
            scanf("%f", &products[i].price);
            printf("Enter New PRODUCT_QUANTITY:\n");
            scanf("%d", &products[i].quantity);
            printf("Product with PRODUCT_ID[%d] updated successfully !!!\n", productId);
            return;
        }
    }
    printf("Product with PRODUCT_ID[%d] Not found !!!\n", productId);
}

void deleteProduct(Product products[], int *count)
{
    int productId, i;
    printf("Enter the PRODUCT_ID of the product that needs to be deleted:\n");
    scanf("%d", &productId);
    for (i = 0; i < *count; i++)
    {
        if (productId == products[i].id)
        {
            for (int j = i; j < *count - 1; j++)
            {
                products[j] = products[j + 1];
            }
            (*count)--;
            printf("Product with PRODUCT_ID[%d] deleted successfully !!!\n", productId);
            return;
        }
    }
    printf("Product with PRODUCT_ID[%d] Not found !!!\n", productId);
}

void displayProduct(Product products[], int count)
{
    printf("DISPLAYING PRODUCT DETAILS:\n");
    printf("PRODUCT_ID\tPRODUCT_NAME\tPRODUCT_PRICE\tPRODUCT_QUANTITY\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}
// Functions related to Supplier
void addSupplier(Supplier suppliers[], int *count)
{
    if (*count < MAX_PRODUCTS)
    {
        printf("Enter Supplier No[%d]\n", *count + 1);
        printf("Enter SUPPLIER_ID:\n");
        scanf("%d", &suppliers[*count].id);
        printf("Enter SUPPLIER_NAME:\n");
        scanf("%s", suppliers[*count].name);
        printf("Enter SUPPLIER_ADDRESS:\n");
        scanf("%s", suppliers[*count].address);
        (*count)++;
        printf("Added Supplier Successfully!!!\n");
    }
    else
    {
        printf("You have added Maximum Number of Suppliers possible i.e [%d]\n", MAX_PRODUCTS);
    }
}

void updateSupplier(Supplier suppliers[], int count)
{
    int supplierId, i;
    printf("Enter the SUPPLIER_ID of the supplier that needs to be updated:\n");
    scanf("%d", &supplierId);
    for (i = 0; i < count; i++)
    {
        if (supplierId == suppliers[i].id)
        {
            printf("Enter New SUPPLIER_NAME:\n");
            scanf("%s", suppliers[i].name);
            printf("Enter New SUPPLIER_ADDRESS:\n");
            scanf("%s", suppliers[i].address);
            printf("Supplier with SUPPLIER_ID[%d] updated successfully !!!\n", supplierId);
            return;
        }
    }
    printf("Supplier with SUPPLIER_ID[%d] Not found !!!\n", supplierId);
}

void deleteSupplier(Supplier suppliers[], int *count)
{
    int supplierId, i;
    printf("Enter the SUPPLIER_ID of the supplier that needs to be deleted:\n");
    scanf("%d", &supplierId);
    for (i = 0; i < *count; i++)
    {
        if (supplierId == suppliers[i].id)
        {
            for (int j = i; j < *count - 1; j++)
            {
                suppliers[j] = suppliers[j + 1];
            }
            (*count)--;
            printf("Supplier with SUPPLIER_ID[%d] deleted successfully !!!\n", supplierId);
            return;
        }
    }
    printf("Supplier with SUPPLIER_ID[%d] Not found !!!\n", supplierId);
}

void displaySupplier(Supplier suppliers[], int count)
{
    printf("DISPLAYING SUPPLIER DETAILS:\n");
    printf("SUPPLIER_ID\tSUPPLIER_NAME\tSUPPLIER_ADDRESS\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%s\n", suppliers[i].id, suppliers[i].name, suppliers[i].address);
    }
}

// Functions related to Transaction
void recordNewTransaction(Transaction transactions[], int *count)
{
    if (*count < MAX_PRODUCTS)
    {
        printf("Enter Transaction No[%d]\n", *count + 1);
        printf("Enter TRANSACTION_ID:\n");
        scanf("%d", &transactions[*count].id);
        printf("Enter TRANSACTION_PRODUCT_ID:\n");
        scanf("%d", &transactions[*count].productId);
        printf("Enter TRANSACTION_QUANTITY:\n");
        scanf("%d", &transactions[*count].quantity);
        printf("Enter TRANSACTION_DATE:\n");
        scanf("%s", transactions[*count].date);
        (*count)++;
        printf("Added Transaction Successfully!!!\n");
    }
    else
    {
        printf("You have added Maximum Number of Transactions possible i.e [%d]\n", MAX_PRODUCTS);
    }
}

void updateTransaction(Transaction transactions[], int count)
{
    int transactionId, i;
    printf("Enter the TRANSACTION_ID of the transaction that needs to be updated:\n");
    scanf("%d", &transactionId);
    for (i = 0; i < count; i++)
    {
        if (transactionId == transactions[i].id)
        {
            printf("Enter TRANSACTION_PRODUCT_ID:\n");
            scanf("%d", &transactions[i].productId);
            printf("Enter TRANSACTION_QUANTITY:\n");
            scanf("%d", &transactions[i].quantity);
            printf("Enter TRANSACTION_DATE:\n");
            scanf("%s", transactions[i].date);
            printf("Transaction with TRANSACTION_ID[%d] updated successfully !!!\n", transactionId);
            return;
        }
    }
    printf("Transaction with TRANSACTION_ID[%d] Not found !!!\n", transactionId);
}

void displayTransactionHistory(Transaction transactions[], int count)
{
    printf("DISPLAYING TRANSACTION DETAILS:\n");
    printf("TRANSACTION_ID\tTRANSACTION_PRODUCT_ID\tTRANSACTION_QUANTITY\tTRANSACTION_DATE\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%d\t%d\t%s\n", transactions[i].id, transactions[i].productId, transactions[i].quantity, transactions[i].date);
    }
}