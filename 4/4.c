#include <stdio.h>
#include <math.h>

float func(float x)
{
    float function = tan(0.5*x + 0.2) - x*x;
    return function;
}

float d_func(float x)
{
    float d_function = 0.5*(1/(pow(cos(0.5*x + 0.2),2)));
    return d_function;
}

float solve(float x0, int accuracy)
{
    float x_next;
    x_next = x0 - func(x0)/d_func(x0);
    return x_next;
}

void main()
{
    float x0, x_final;
    int accuracy;
    char ch = 'y';
    printf("This program calculates an approximate solution for the function tg(0.5x + 0.2) = x^2.\n");
    while (ch == 'y')
    {
        accuracy = 0;
        while (accuracy < 1)
        {
            printf("Please enter an approximate solution and up to which decimal number to calculate:\n");
            scanf("%f", &x0);
            scanf("%d", &accuracy);
        }
        for (int i=1; i<=accuracy; i++)
        {
            x_final = solve(x0, accuracy);
            x0 = x_final;
        }
        x_final = floor(x0*pow(10, accuracy))/pow(10, accuracy);
        printf("%f\n", x_final);
        printf("Do you want to continue (y or n)?\n");
        getchar();
        scanf("%c", &ch);
    }
}