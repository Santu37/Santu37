#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct Customer {
    int cust_id;
    char name[100];
    float account_balance;
};

struct Customer customer_records[MAX_CUSTOMERS];
int num_customers = 0;

void add_customer_record() {
    if (num_customers >= MAX_CUSTOMERS) {
        printf("Maximum number of customers reached.\n");
        return;
    }

    struct Customer new_customer;

    printf("Enter Customer ID: ");
    scanf("%d", &new_customer.cust_id);

    printf("Enter Name: ");
    scanf(" %[^\n]s", new_customer.name);

    printf("Enter Initial Account Balance: ");
    scanf("%f", &new_customer.account_balance);

    customer_records[num_customers++] = new_customer;
    printf("Customer record added successfully.\n");
}

void update_customer_record() {
    int cust_id;
    float amount;
    bool found = false;

    printf("Enter Customer ID: ");
    scanf("%d", &cust_id);

    for (int i = 0; i < num_customers; i++) {
        if (customer_records[i].cust_id == cust_id) {
            printf("Enter Amount: ");
            scanf("%f", &amount);

            customer_records[i].account_balance += amount;
            found = true;
            break;
        }
    }

    if (found) {
        printf("Customer record updated successfully.\n");
    } else {
        printf("Customer not found.\n");
    }
}

void display_customer_records() {
    for (int i = 0; i < num_customers; i++) {
        printf("Customer ID: %d\n", customer_records[i].cust_id);
        printf("Name: %s\n", customer_records[i].name);
        printf("Account Balance: %.2f\n", customer_records[i].account_balance);
        printf("------------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("Bank Customer Records\n");
        printf("1. Add Customer\n");
        printf("2. Update Customer\n");
        printf("3. Display Customer Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer_record();
                break;
            case 2:
                update_customer_record();
                break;
            case 3:
                display_customer_records();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}
