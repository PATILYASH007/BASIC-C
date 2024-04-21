#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure to represent a product
struct Product {
    char name[50];
    float price;
    int quantity;
    struct Product* next;
};

// Function to add a product to the product list
void addProduct(struct Product** productList, char name[], float price, int quantity) {
    struct Product* newNode = (struct Product*)malloc(sizeof(struct Product));
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to add product.\n");
        return;
    }

    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->quantity = quantity;
    newNode->next = *productList;

    *productList = newNode;

    printf("Product '%s' added to the list.\n", name);
}

// Function to generate and display the product bill
void generateBill(struct Product* productList) {
    printf("\n========== Product Bill ==========\n");
    printf("%-20s %-10s %-10s %-10s\n", "Product", "Price", "Quantity", "Total");
    printf("-------------------------------------------------\n");

    float totalBill = 0.0;

    while (productList != NULL) {
        float productTotal = productList->price * productList->quantity;
        totalBill += productTotal;

        printf("%-20s $%-9.2f %-10d $%-9.2f\n", productList->name, productList->price, productList->quantity, productTotal);

        productList = productList->next;
    }

    printf("-------------------------------------------------\n");
    printf("Total Bill: $%.2f\n", totalBill);
    printf("=================================\n");
}

// Function to free the memory allocated for the product list
void freeProductList(struct Product* productList) {
    struct Product* current = productList;
    struct Product* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Product* productList = NULL;

    // Add products to the list
    addProduct(&productList, "Laptop", 999.99, 2);
    addProduct(&productList, "Smartphone", 299.99, 1);
    addProduct(&productList, "Headphones", 49.99, 3);

    // Generate and display the bill
    generateBill(productList);

    // Free the memory allocated for the product list
    freeProductList(productList);

    return 0;
}
