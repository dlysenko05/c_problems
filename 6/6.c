#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10000

int array[MAX_SIZE];

int set_size()
{
    int size = 0;
    while (size < 1)
    {
        printf("Enter the size of an array (Maximum size is %d):\n", MAX_SIZE);
        scanf("%d", &size);
    }
    if (size > MAX_SIZE)
    {
        printf("The maximum size exeeded! Setting it to %d\n", MAX_SIZE);
        size = MAX_SIZE;
    }
    return size;
}

void init_array(int size)
{
    for (int i=0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int sum(int size)
{
    int total_sum = 0;
    for (int i=0; i < size; i++)
    {
        total_sum += array[i];
    }
    return total_sum;
}

float mean(int size)
{
    float mean;
    mean = (float)(sum(size))/size;
    return mean;
}

int max(int size)
{
    int max_value = 0;
    int* pmax_value = &array[0];
    for (int i=0; i < size; i++)
    {
        if (max_value < *(pmax_value + i)) max_value = *(pmax_value + i);
    }
    return max_value;
}

int min(int size)
{
    int min_value = max(size);
    int *pmin_value = &array[0];
    for (int i=0; i < size; i++)
    {
        if (min_value > *(pmin_value + i)) min_value = *(pmin_value + i);
    }
    return min_value;
}

float sum_rms(int size)
{
    float sum = 0;
    float mean_value;
    mean_value = mean(size);
    for (int i=0; i < size; i++)
    {
        sum += pow(array[i]-mean_value, 2);
    }
    return sum;
}

float rms(int size)
{
    float sigma;
    sigma = sqrt((1/(float)size) * sum_rms(size));
    return sigma;
}

void main()
{
    int size;
    size = set_size();
    init_array(size);
    printf("Max: %d.\n", max(size));
    printf("Min: %d.\n", min(size));
    printf("Mean: %f.\n", mean(size));
    printf("RMS: %f.\n", rms(size));
}