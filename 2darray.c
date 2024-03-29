/*
 --> 2-Dimensional arrayA two-Dimanesional array is specified using two subscripts where one subscript denotes
     row and the other denottes column.
 --> A one-dimensional array is organized linearly and only in one direction.
 --> But at times, we need to store data in the form of matrices or tables. Here the concept of
     one-dimension array is extended to incorporate two-dimansional data structures.

*/

// Some important operations in two - Dimensional array
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// --> operat1() :- To red and display a 3 x 3 matrix.
void operat1();
void operat2();
void operat3();
void operat4();
int main()
{
    int ch;
    printf("Enter choice = ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        operat1();
        break;
    case 2:
        operat2();
        break;
    case 3:
        operat3();
        break;
    case 4:
        operat4();
        break;
    default:
        printf("Wrong input");
    }
}
void operat1()
{
    // To red and display a 3 x 3 matrix.

    int i, j, mat[3][3];
    printf("Enter the elements which you enter in the 3 x 3 matrix = \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter element [%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("The elements of the matrix are :- \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d", mat[i][j]);
        printf("\n");
    }
}

void operat2()
{

    // Transpose
    // Program to transpose a 3x 3 matrix
    printf("Transpose of a matrix....\n");
    printf("Enter elements for a 3 x 3 matrix --> ");
    int i, j, mat[3][3], t_mat[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter [%d][%d] element = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Your Matrix..\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d", mat[i][j]);
        printf("\n");
    }
    printf("\nTransposing your matrix.....\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            t_mat[i][j] = mat[j][i];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d", t_mat[i][j]);
        printf("\n");
    }
}
void operat3()
{
    // To take two m x n matrices and calculate the sum of their respective elements and stre it in a third m x n matrix.
    printf("Sum of two matrices....\n");
    int n1, n2, i, j;
    printf("Enter the number of row and column you want in both matrix...\n");
    printf("Rows = ");
    scanf("%d", &n1);
    printf("Columns = ");
    scanf("%d", &n2);
    int mat1[n1][n2];
    int mat2[n1][n2];
    int s_mat[n1][n2];
    printf("Enter elements for 1st matrix:- \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements for 2nd matrix:- \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
            s_mat[i][j] = mat1[i][j] + mat2[i][j];
    }

    printf("Sum of both the matrix :-\n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
            printf("%3d", mat1[i][j]);
        if (i == floor(n1 / 2))
            printf("\t+\t");
        else
            printf("\t \t");
        for (j = 0; j < n2; j++)
            printf("%3d", mat2[i][j]);
        if (i == floor(n1 / 2))
            printf("\t=\t");
        else
            printf("\t \t");
        for (j = 0; j < n2; j++)
            printf("%3d", s_mat[i][j]);
        printf("\n");
    }
}


void operat4()
{
    // Program to multiply two  m x n matrices
    printf("Product of two matrices...\n");
    int n1, n2, m1, m2, res_r, res_c, i, j, sum;
    printf("Enter the number of row and column you want in 1st matrix...\n");
    printf("Rows = ");
    scanf("%d", &n1);
    printf("Columns = ");
    scanf("%d", &n2);
    printf("\n-----------------------------------------------------\n");
    printf("Enter the number of row and column you want in 2nd matrix...\n");
    printf("Rows = ");
    scanf("%d", &m1);
    printf("Columns = ");
    scanf("%d", &m2);
    if (n2 != m1)
    {
        printf("The number of columns in the first matrix must be equal to the number of rows in the secomd matrix\n");
        exit(1);
    }

    res_r = n1; res_c = m2;

    int mat1[n1][n2];
    int mat2[m1][m2];

    printf("Enter elements for 1st matrix:- \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements for 2nd matrix:- \n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    int m_mat[res_r][res_c];

    for (i = 0; i < res_r; i++)
    {
        j=0;
        for (j = 0; j < res_c; j++)
        {
            m_mat[i][j] = 0;
            for(int k=0; k<res_c; k++)
            m_mat[i][j] += mat1[i][k] * mat2[k][j];
        }
            
    }

    printf("Product of both the matrices :-\n");
    for (i = 0; i < res_r; i++)
    {
        for (j = 0; j < res_c; j++)
        printf("%5d", m_mat[i][j]);
        printf("\n");
    }
}