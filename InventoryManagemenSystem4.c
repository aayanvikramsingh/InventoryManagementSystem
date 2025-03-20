#include <stdio.h>
#include <stdlib.h>
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

void saveToFile(Product products[], int productCount, Supplier suppliers[], int supplierCount, Transaction transactions[], int transactionCount);
void loadFromFile(Product products[], int *productCount, Supplier suppliers[], int *supplierCount, Transaction transactions[], int *transactionCount);

int main()
{
    Product products[MAX_PRODUCTS];
    Supplier suppliers[MAX_PRODUCTS];
    Transaction transactions[MAX_PRODUCTS];
    int productCount = 0, supplierCount = 0, transactionCount = 0;
    int choice;

    loadFromFile(products, &productCount, suppliers, &supplierCount, transactions, &transactionCount);

    while (1)
    {
        printf("\n*************** WELCOME TO INVENTORY MANAGEMENT ***************\n");
        printf("Enter [1] >>> PRODUCT DETAILS \n");
        printf("Enter [2] >>> SUPPLIER DETAILS\n");
        printf("Enter [3] >>> TRANSACTION DETAILS\n");
        printf("Enter [4] >>> SAVE DATA\n");
        printf("Enter [5] >>> EXIT\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int productChoice;
            printf("\n*************** PRODUCT DETAILS ***************\n");
            printf("Enter [1] >>> ADD PRODUCT\n");
            printf("Enter [2] >>> UPDATE PRODUCT\n");
            printf("Enter [3] >>> DELETE PRODUCT\n");
            printf("Enter [4] >>> DISPLAY PRODUCT\n");
            printf("Enter your choice: ");
            scanf("%d", &productChoice);

            switch (productChoice)
            {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                updateProduct(products, productCount);
                break;
            case 3:
                deleteProduct(products, &productCount);
                break;
            case 4:
                displayProduct(products, productCount);
                break;
            default:
                printf("INVALID CHOICE WITH RESPECT TO PRODUCT DETAILS !!!\n");
            }
            break;
        }

        case 2:
        {
            int supplierChoice;
            printf("\n*************** SUPPLIER DETAILS ***************\n");
            printf("Enter [1] >>> ADD SUPPLIER\n");
            printf("Enter [2] >>> UPDATE SUPPLIER\n");
            printf("Enter [3] >>> DELETE SUPPLIER\n");
            printf("Enter [4] >>> DISPLAY SUPPLIER\n");
            printf("Enter your choice: ");
            scanf("%d", &supplierChoice);

            switch (supplierChoice)
            {
            case 1:
                addSupplier(suppliers, &supplierCount);
                break;
            case 2:
                updateSupplier(suppliers, supplierCount);
                break;
            case 3:
                deleteSupplier(suppliers, &supplierCount);
                break;
            case 4:
                displaySupplier(suppliers, supplierCount);
                break;
            default:
                printf("INVALID CHOICE WITH RESPECT TO SUPPLIER DETAILS !!!\n");
            }
            break;
        }

        case 3:
        {
            int transactionChoice;
            printf("\n*************** TRANSACTION DETAILS ***************\n");
            printf("Enter [1] >>> RECORD NEW TRANSACTION\n");
            printf("Enter [2] >>> UPDATE TRANSACTION\n");
            printf("Enter [3] >>> DISPLAY TRANSACTION HISTORY\n");
            printf("Enter your choice: ");
            scanf("%d", &transactionChoice);

            switch (transactionChoice)
            {
            case 1:
                recordNewTransaction(transactions, &transactionCount);
                break;
            case 2:
                updateTransaction(transactions, transactionCount);
                break;
            case 3:
                displayTransactionHistory(transactions, transactionCount);
                break;
            default:
                printf("INVALID CHOICE WITH RESPECT TO TRANSACTION DETAILS !!!\n");
            }
            break;
        }

        case 4:
            saveToFile(products, productCount, suppliers, supplierCount, transactions, transactionCount);
            break;

        case 5:
            printf("Exiting ...\n");
            exit(0);

        default:
            printf("INVALID CHOICE !!!\n");
        }
    }
    return 0;
}

// Product Functions
void addProduct(Product products[], int *count)
{
    if (*count < MAX_PRODUCTS)
    {
        printf("Enter PRODUCT_ID: ");
        scanf("%d", &products[*count].id);
        printf("Enter PRODUCT_NAME: ");
        scanf("%s", products[*count].name);
        printf("Enter PRODUCT_PRICE: ");
        scanf("%f", &products[*count].price);
        printf("Enter PRODUCT_QUANTITY: ");
        scanf("%d", &products[*count].quantity);
        (*count)++;
        printf("Added Product Successfully !!!\n");
    }
    else
    {
        printf("Maximum number of products reached [%d]\n", MAX_PRODUCTS);
    }
}

void updateProduct(Product products[], int count)
{
    int productId;
    printf("Enter the PRODUCT_ID to update: ");
    scanf("%d", &productId);
    for (int i = 0; i < count; i++)
    {
        if (productId == products[i].id)
        {
            printf("Enter New PRODUCT_NAME: ");
            scanf("%s", products[i].name);
            printf("Enter New PRODUCT_PRICE: ");
            scanf("%f", &products[i].price);
            printf("Enter New PRODUCT_QUANTITY: ");
            scanf("%d", &products[i].quantity);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product with ID [%d] not found.\n", productId);
}

void deleteProduct(Product products[], int *count)
{
    int productId;
    printf("Enter the PRODUCT_ID to delete: ");
    scanf("%d", &productId);
    for (int i = 0; i < *count; i++)
    {
        if (productId == products[i].id)
        {
            for (int j = i; j < *count - 1; j++)
            {
                products[j] = products[j + 1];
            }
            (*count)--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with ID [%d] not found.\n", productId);
}

void displayProduct(Product products[], int count)
{
    printf("PRODUCT_ID\tPRODUCT_NAME\tPRICE\tQUANTITY\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

// Supplier Functions
void addSupplier(Supplier suppliers[], int *count)
{
    if (*count < MAX_PRODUCTS)
    {
        printf("Enter SUPPLIER_ID: ");
        scanf("%d", &suppliers[*count].id);
        printf("Enter SUPPLIER_NAME: ");
        scanf("%s", suppliers[*count].name);
        printf("Enter SUPPLIER_ADDRESS: ");
        scanf("%s", suppliers[*count].address);
        (*count)++;
        printf("Added Supplier Successfully !!!\n");
    }
    else
    {
        printf("Maximum number of suppliers reached [%d]\n", MAX_PRODUCTS);
    }
}

void updateSupplier(Supplier suppliers[], int count)
{
    int supplierId;
    printf("Enter SUPPLIER_ID to update: ");
    scanf("%d", &supplierId);
    for (int i = 0; i < count; i++)
    {
        if (supplierId == suppliers[i].id)
        {
            printf("Enter New SUPPLIER_NAME: ");
            scanf("%s", suppliers[i].name);
            printf("Enter New SUPPLIER_ADDRESS: ");
            scanf("%s", suppliers[i].address);
            printf("Supplier updated successfully!\n");
            return;
        }
    }
    printf("Supplier with ID [%d] not found.\n", supplierId);
}

void deleteSupplier(Supplier suppliers[], int *count)
{
    int supplierId;
    printf("Enter SUPPLIER_ID to delete: ");
    scanf("%d", &supplierId);
    for (int i = 0; i < *count; i++)
    {
        if (supplierId == suppliers[i].id)
        {
            for (int j = i; j < *count - 1; j++)
            {
                suppliers[j] = suppliers[j + 1];
            }
            (*count)--;
            printf("Supplier deleted successfully!\n");
            return;
        }
    }
    printf("Supplier with ID [%d] not found.\n", supplierId);
}

void displaySupplier(Supplier suppliers[], int count)
{
    printf("SUPPLIER_ID\tSUPPLIER_NAME\tADDRESS\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%s\n", suppliers[i].id, suppliers[i].name, suppliers[i].address);
    }
}

// Transaction Functions
void recordNewTransaction(Transaction transactions[], int *count)
{
    if (*count < MAX_PRODUCTS)
    {
        printf("Enter TRANSACTION_ID: ");
        scanf("%d", &transactions[*count].id);
        printf("Enter PRODUCT_ID: ");
        scanf("%d", &transactions[*count].productId);
        printf("Enter QUANTITY: ");
        scanf("%d", &transactions[*count].quantity);
        printf("Enter DATE: ");
        scanf("%s", transactions[*count].date);
        (*count)++;
        printf("Transaction recorded successfully!\n");
    }
    else
    {
        printf("Maximum number of transactions reached [%d]\n", MAX_PRODUCTS);
    }
}

void updateTransaction(Transaction transactions[], int count)
{
    int transactionId;
    printf("Enter TRANSACTION_ID to update: ");
    scanf("%d", &transactionId);
    for (int i = 0; i < count; i++)
    {
        if (transactionId == transactions[i].id)
        {
            printf("Enter New PRODUCT_ID: ");
            scanf("%d", &transactions[i].productId);
            printf("Enter New QUANTITY: ");
            scanf("%d", &transactions[i].quantity);
            printf("Enter New DATE: ");
            scanf("%s", transactions[i].date);
            printf("Transaction updated successfully!\n");
            return;
        }
    }
    printf("Transaction with ID [%d] not found.\n", transactionId);
}

void displayTransactionHistory(Transaction transactions[], int count)
{
    printf("TRANSACTION_ID\tPRODUCT_ID\tQUANTITY\tDATE\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%d\t%d\t%s\n", transactions[i].id, transactions[i].productId, transactions[i].quantity, transactions[i].date);
    }
}

// File Handling
void saveToFile(Product products[], int productCount, Supplier suppliers[], int supplierCount, Transaction transactions[], int transactionCount)
{
    FILE *fp = fopen("inventory_data.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%d\n", productCount);
    for (int i = 0; i < productCount; i++)
    {
        fprintf(fp, "%d %s %.2f %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    fprintf(fp, "%d\n", supplierCount);
    for (int i = 0; i < supplierCount; i++)
    {
        fprintf(fp, "%d %s %s\n", suppliers[i].id, suppliers[i].name, suppliers[i].address);
    }

    fprintf(fp, "%d\n", transactionCount);
    for (int i = 0; i < transactionCount; i++)
    {
        fprintf(fp, "%d %d %d %s\n", transactions[i].id, transactions[i].productId, transactions[i].quantity, transactions[i].date);
    }

    fclose(fp);
    printf("Data saved successfully!\n");
}

void loadFromFile(Product products[], int *productCount, Supplier suppliers[], int *supplierCount, Transaction transactions[], int *transactionCount)
{
    FILE *fp = fopen("inventory_data.txt", "r");
    if (fp == NULL)
    {
        printf("No previous data found.\n");
        return;
    }

    fscanf(fp, "%d", productCount);
    for (int i = 0; i < *productCount; i++)
    {
        fscanf(fp, "%d %s %f %d", &products[i].id, products[i].name, &products[i].price, &products[i].quantity);
    }

    fscanf(fp, "%d", supplierCount);
    for (int i = 0; i < *supplierCount; i++)
    {
        fscanf(fp, "%d %s %s", &suppliers[i].id, suppliers[i].name, suppliers[i].address);
    }

    fscanf(fp, "%d", transactionCount);
    for (int i = 0; i < *transactionCount; i++)
    {
        fscanf(fp, "%d %d %d %s", &transactions[i].id, &transactions[i].productId, &transactions[i].quantity, transactions[i].date);
    }

    fclose(fp);
    printf("Data loaded successfully!\n");
}
