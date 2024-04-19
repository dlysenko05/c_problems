#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

struct matrix
{
    int data[3][3];
    float data_reversed[3][3];
    int sum;
    int determinant;
};

void init_matrix(struct matrix* matrixes, int matrix_number)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            int temp;
            scanf("%d", &temp);
            matrixes[matrix_number].data[i][j] = temp;
        }
    }
}

void sum(struct matrix* matrixes, int matrix_number)
{
    int sum = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            sum += matrixes[matrix_number].data[i][j];
        }
    }
    matrixes[matrix_number].sum = sum;
}

int sub_determinant(struct matrix* matrixes, int matrix_number, int i)
{
    int sub_determinant = 0;
    struct matrix matrix = matrixes[matrix_number];
    sub_determinant += matrix.data[ (i == 1) ? 0 : (i != 2 ? i+1 : 0)][1] * matrix.data[ (i == 1) ? 2 : (i == 0 ? i+2 : 1)][2] -
                        matrix.data[ (i == 1) ? 2 : (i == 0 ? i+2 : 1)][1] * matrix.data[ (i == 1) ? 0 : (i != 2 ? i+1 : 0)][2];  // i,j  0,0 0,1 0,2
                                                                                            //      1,0 1,1 1,2
                                                                                            //      2,0 2,1 2,2
    // if i == 1 jump to i = 0 and  i = 2
    // printf("%d,", sub_determinant);
    return sub_determinant;
}

int sub_determinant_reverse(struct matrix* matrixes, int matrix_number, int i1, int i2, int j1, int j2)
{
    int sub_determinant_reversed;
    struct matrix matrix = matrixes[matrix_number];
    sub_determinant_reversed = matrix.data[i1][j1]*matrix.data[i2][j2] - matrix.data[i2][j1]*matrix.data[i1][j2];
    // printf("%d, ", sub_determinant_reversed);
    return sub_determinant_reversed;
}

void determinant(struct matrix* matrixes, int matrix_number)
{
    int determinant = 0;
    for(int i=0; i<3; i++)
    {
        if (i%2 == 0) determinant += (matrixes[matrix_number].data[i][0])*sub_determinant(matrixes, matrix_number, i);
        else determinant -= (matrixes[matrix_number].data[i][0])*sub_determinant(matrixes, matrix_number, i);
    }
    matrixes[matrix_number].determinant = determinant;
}

void reverse(struct matrix* matrixes, int matrix_number)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matrixes[matrix_number].data_reversed[i][j] = pow(-1, i+j)*((float)1/matrixes[matrix_number].determinant)*(float)sub_determinant_reverse(matrixes, matrix_number, j==0 ? 1 : 0, j<2 ? 2 : 1, i==0 ? 1 : 0, i<2 ? 2 : 1);
        }  
    }
}

void sum_matrixes(struct matrix* matrixes)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matrixes[2].data[i][j] = matrixes[0].data[i][j] + matrixes[1].data[i][j];
        }
    }
}

void multiply(struct matrix* matrixes)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            float temp = 0;
            for(int k=0; k<3; k++)
            {
                temp += matrixes[0].data[i][k]*matrixes[1].data[k][j];
            }
            matrixes[3].data[i][j] = temp;
        }
    }
}

void print_matrix(struct matrix* matrixes, int matrix_number, int reversed)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (reversed) printf("%f ", matrixes[matrix_number].data_reversed[i][j]);
            else printf("%d ", matrixes[matrix_number].data[i][j]);
        }
        printf("\n");
    }
}

char* init_file()
{
    char *name;
    name = (char*) malloc(MAX_SIZE*sizeof(char));
    printf("Enter the name of your file:\n");
    scanf("%999s", name);
    return name;
}

void init_matrix_file(struct matrix* matrixes, int matrix_number, FILE *fp)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            fscanf(fp, "%d", &matrixes[matrix_number].data[i][j]);
        }
    }
}

void save_matrix_file(struct matrix* matrixes, int matrix_number, FILE *fp)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            fprintf(fp, "%d\t", matrixes[matrix_number].data[i][j]);
        }
        fprintf(fp, "\n");
    }
}

void save_matrix_reversed_file(struct matrix* matrixes, int matrix_number, FILE *fp)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            fprintf(fp, "%f\t", matrixes[matrix_number].data_reversed[i][j]);
        }
        fprintf(fp, "\n");
    }
}

void save_det_file(struct matrix* matrixes, int matrix_number, FILE *fp)
{
    fprintf(fp, "%d", matrixes[matrix_number].determinant);
}

void print(struct matrix* matrixes)
{
    for(int i=0; i<2; i++)
    {
        printf("Matrix #%d:\n", i+1);
        print_matrix(matrixes, i, 0);
        determinant(matrixes, i);
        printf("\n\n");
        printf("Determinant of matrix #%d:\n", i+1);
        printf("%d", matrixes[i].determinant);
        printf("\n\n");
        reverse(matrixes, i);
        printf("Reversed matrix #%d:\n", i+1);
        print_matrix(matrixes, i, 1);
        printf("\n\n");
    }
    sum_matrixes(matrixes);
    printf("Sum of matrixes #1 and #2:\n");
    print_matrix(matrixes, 2, 0);
    printf("\n\n");
    multiply(matrixes);
    printf("Multiplication of matrixes #1 and #2:\n");
    print_matrix(matrixes, 3, 0);
}

void print_to_file(struct matrix* matrixes, FILE *fp)
{
    for(int i=0; i<2; i++)
    {
        fprintf(fp, "Matrix #%d:\n", i+1);
        save_matrix_file(matrixes, i, fp);
        determinant(matrixes, i);
        fprintf(fp, "\n\n");
        fprintf(fp, "Determinant of matrix #%d:\n", i+1);
        save_det_file(matrixes, i, fp);
        fprintf(fp, "\n\n");
        reverse(matrixes, i);
        fprintf(fp, "Reversed matrix #%d:\n", i+1);
        save_matrix_reversed_file(matrixes, i, fp);
        fprintf(fp, "\n\n");
    }
    sum_matrixes(matrixes);
    fprintf(fp, "Sum of matrixes #1 and #2:\n");
    save_matrix_file(matrixes, 2, fp);
    fprintf(fp, "\n\n");
    multiply(matrixes);
    fprintf(fp, "Multiplication of matrixes #1 and #2:\n");
    save_matrix_file(matrixes, 3, fp);
}

void main()
{
    FILE *fp;
    char *name;
    name = init_file();
    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Error while creating the file!\n");
        return;
    }
    struct matrix matrixes[4];
    init_matrix_file(matrixes, 0, fp);
    init_matrix_file(matrixes, 1, fp);

    FILE *fp_save;
    char *save_name;
    save_name = init_file();
    if ((fp_save = fopen(save_name, "w")) == NULL)
    {
        printf("Error while creating the file!\n");
        return;
    }
    print_to_file(matrixes, fp_save);

    print(matrixes);
    fclose(fp);
    fclose(fp_save);
}