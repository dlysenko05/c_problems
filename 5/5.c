#include <stdio.h>
#include <math.h>


float func(float x)
{
    //float function = tan(0.5*x + 0.2) - x*x;
    float function = cos(x);
    return function;
}

float d_d_func(float x)
{
    // float d_d_function = 0.5*(tan(0.5*x + 0.2)/pow(cos(0.5*x + 0.2), 2)) - 2;
    float d_d_function = -cos(x);
    return d_d_function;
}

float max_d_d_func(float a, float b)
{
    float max = 0;
    for (float i=a; i<=b; i+=0.001)
    {
        float temp;
        temp = fabs(d_d_func(i));
        if (temp > max) max = temp;
    }
    return max;
}

float x_value(int i, float a, float h)
{
    float x = a + i*h;
    return x;
}

float h_value(int n, float a, float b)
{
    float h = (b-a)/n;
    return h;
}

float calc(int n, float a, float b)
{
    float total_sum = 0;
    float current_sum;
    float h = h_value(n, a, b);

    for (int i=0; i<=n; i++)
    {
        float x1 = x_value(i, a, h);
        float x2 = x_value(i+1, a, h);
        current_sum = (h*(func(x1) + func(x2)))/2;
        total_sum += current_sum;
    }
    return total_sum;
}

float approximation_error(float a, float b, float h)
{
    float error = ((h*h)*(b-a))/12 * max_d_d_func(a, b);
    return error;
}

void main()
{
    float a,b;
    char ch = 'y';
    printf("This program calculates an integral for a function tg(0.5x + 0.2) = x^2.\n");
    while (ch == 'y')
    {
        int n = 0;
        while (n < 1)
        {
            printf("Please enter n:\n");
            scanf("%d", &n);
        }
        printf("Please enter a, b:\n");
        scanf("%f", &a);
        scanf("%f", &b);
        float result;
        if (a > b) result = -calc(n, a, b);
        else result = calc(n, a, b);
        printf("Here's your result: %f\n", result);
        printf("Approximation error : <= %f\n", approximation_error(a, b, h_value(n, a, b)));
        printf("Do you want to continue? (y or n):\n");
        getchar();
        scanf("%c", &ch);
    }
}
