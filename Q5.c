// Write a program to sort n randomly generated elements using Heapsort method.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i)
{
    int largest, left, right;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (i = n - 1; i >= 0; i--)
    {
        swap(a, &a[i]);
        heapify(a, i, 0);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int *a, n;

    printf("Enter number to genrate random values: ");
    scanf("%d", &n);

    a = (int)malloc(sizeof(int) * n);
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;

    printArray(a, n);
    heapsort(a, n);
    printArray(a, n);
    
}