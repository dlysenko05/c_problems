#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int set_size()
{
    int size = 0;
    while (size < 1)
    {
        printf("Enter the size of an array:\n");
        scanf("%d", &size);
    }
    return size;
}

int select_sort_type()
{
    int ch = 2;
    printf("Please select sort type:\n");
    printf("[1] for ascending\n[0] for absolute value\n[-1] for descending\n");
    // while (ch != 1 || ch != 0 || ch != -1)
    // {
        scanf("%d", &ch);
    // }
    return ch;
}


int select_optimization()
{
    int flag = 2;
    printf("Please choose which mode to run:\n");
    printf("[1] for optimized\n[0] for unoptimized\n");
    getchar();
    // while (flag != 1 || flag != 0)
    // {
        scanf("%d", &flag);
    // }
    return flag;
}

int compare_increasing(int* parray, int i, int j)
{
    if (parray[i] > parray[j]) return 1;
}

int compare_decreasing(int* parray, int i, int j)
{
    if (parray[i] < parray[j]) return 1;
}

int compare_absolute(int* parray, int i, int j)
{
    if (abs(parray[i]) > abs(parray[j])) return 1;
}

void swap_elements(int* parray, int i, int j)
{
    int temp;
    temp = parray[i];
    parray[i] = parray[j];
    parray[j] = temp;
}

void sort_array(int* parray, int size, int optimization_type, int compare(int*, int, int))
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<(size-1); j++)
        {
            if (optimization_type == 1)
            {
                int swapped = 1;
                if (swapped != 0)
                {
                    if (compare(parray, j, j+1) == 1) 
                    {
                        swap_elements(parray, j, j+1);
                        swapped = 1;
                    }
                    if ((compare(parray, j, j+1) != 1) && j == size-1) swapped = 0;
                }
            }
            else if (optimization_type == 0)
            {
                if (compare(parray, j, j+1) == 1) swap_elements(parray, j, j+1);
            }
        }
    }
}

void print_array(int* parray, int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", *(parray+i));
    }
}

void main()
{
    int size;
    size = set_size();
    int arr[size];
    int* parr;
    parr = arr;
    parr = malloc(sizeof(int) * size);
    if (parr == NULL) printf("Cannot allocate memory!\n");
    for (int i=0; i < size; i++)
    {
        scanf("%d", (parr + i));
    }
    int sort_type, optimization_type;
    sort_type = select_sort_type();
    optimization_type = select_optimization();
    if (sort_type == 1) sort_array(parr, size, optimization_type, compare_increasing);
    else if (sort_type == 0) sort_array(parr, size, optimization_type, compare_absolute);
    else if (sort_type == -1) sort_array(parr, size, optimization_type, compare_decreasing);
    print_array(parr, size);
    printf("\n");
    free(parr);
}