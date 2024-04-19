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

float mean(int* parray, int size)
{
    float mean;
    float sum = 0;
    for (int i=0; i < size; i++)
    {
        sum += *(parray + i);
    }
    mean = (float)(sum/size);
    return mean;
}

int max(int* parray, int size)
{
    int max_value = 0;
    for (int i=0; i < size; i++)
    {
        if (max_value < parray[i]) max_value = parray[i];
    }
    return max_value;
}

int min(int* parray, int size)
{
    int min_value = max(parray, size);
    for (int i=0; i < size; i++)
    {
        if (min_value > parray[i]) min_value = parray[i];
    }
    return min_value;
}

float sum_rms(int* parray, int size)
{
    float sum = 0;
    float mean_value;
    mean_value = mean(parray, size);
    for (int i=0; i < size; i++)
    {
        sum += pow(*(parray + i) - mean_value, 2);
    }
    return sum;
}

float rms(int* parray, int size)
{
    float sigma;
    sigma = sqrt((1/(float)size) * sum_rms(parray, size));
    return sigma;
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
    printf("Max: %d.\n", max(parr, size));
    printf("Min: %d.\n", min(parr, size));
    printf("Mean: %f.\n", mean(parr, size));
    printf("RMS: %f.\n", rms(parr, size));
    free(parr);
}