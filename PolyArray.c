#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
struct Term
{
    int coefficient;
    int exponent;
};

// Function to add two polynomials
struct Term *addPolynomials(struct Term *poly1, int size1, struct Term *poly2, int size2, int *resultSize)
{
    // Initialize result polynomial
    *resultSize = 0;
    int maxSize = size1 + size2;
    struct Term *result = (struct Term *)malloc(maxSize * sizeof(struct Term));
    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Merge polynomials
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (poly1[i].exponent > poly2[j].exponent)
        {
            result[k++] = poly1[i++];
        }
        else if (poly1[i].exponent < poly2[j].exponent)
        {
            result[k++] = poly2[j++];
        }
        else
        {
            result[k].exponent = poly1[i].exponent;
            result[k++].coefficient = poly1[i++].coefficient + poly2[j++].coefficient;
        }
    }

    // Copy remaining terms from the first polynomial
    while (i < size1)
    {
        result[k++] = poly1[i++];
    }

    // Copy remaining terms from the second polynomial
    while (j < size2)
    {
        result[k++] = poly2[j++];
    }

    // Update result size
    *resultSize = k;

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term *poly, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (poly[i].coefficient != 0)
        {
            printf("%d", poly[i].coefficient);
            if (poly[i].exponent != 0)
            {
                printf("x^%d", poly[i].exponent);
            }
            if (i < size - 1)
            {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main()
{
    struct Term poly1[] = {{5, 2}, {4, 1}, {2, 0}}; // 5x^2 + 4x + 2
    struct Term poly2[] = {{3, 3}, {2, 1}, {1, 0}}; // 3x^3 + 2x + 1
    int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);

    int resultSize;
    struct Term *result = addPolynomials(poly1, size1, poly2, size2, &resultSize);

    printf("Polynomial 1: ");
    displayPolynomial(poly1, size1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2, size2);
    printf("Resultant Polynomial: ");
    displayPolynomial(result, resultSize);

    free(result); // Free dynamically allocated memory

    return 0;
}
