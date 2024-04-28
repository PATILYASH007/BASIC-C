#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Structure to represent a product
struct Product {
    char name[50];
    float price;
};

// Function to add a product to the list
void addProduct(struct Product productList[], int *size, char name[], float price) {
    if (*size >= MAX_PRODUCTS) {
        printf("Product list is full. Cannot add more products.\n");
        return;
    }

    // Initialize the new product
    strcpy(productList[*size].name, name);
    productList[*size].price = price;

    // Increment the size of the product list
    (*size)++;

    printf("Product added successfully.\n");
}

// Function to remove a product from the list
void removeProduct(struct Product productList[], int *size, char name[]) {
    if (*size <= 0) {
        printf("Product list is empty. Cannot remove products.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(productList[i].name, name) == 0) {
            // Shift elements to remove the product
            for (int j = i; j < *size - 1; j++) {
                productList[j] = productList[j + 1];
            }

            // Decrement the size of the product list
            (*size)--;
            
            printf("Product '%s' removed successfully.\n", name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product '%s' not found in the list.\n", name);
    }
}

// Function to count the number of products in the list
int countProducts(int size) {
    return size;
}

int main() {
    struct Product productList[MAX_PRODUCTS];
    int size = 0;

    // Adding products to the list
    addProduct(productList, &size, "Laptop", 999.99);
    addProduct(productList, &size, "Smartphone", 299.99);
    addProduct(productList, &size, "Headphones", 49.99);

    // Removing a product from the list
    removeProduct(productList, &size, "Smartphone");

    // Counting the number of products in the list
    int productCount = countProducts(size);
    printf("Number of products in the list: %d\n", productCount);

    return 0;
}
