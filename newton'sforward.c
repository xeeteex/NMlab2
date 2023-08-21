#include <stdio.h>
void forward(float x[5], float y[5][5], int n);
int main()
{
    int n = 5; // number of arguments
    float x[5] = { 10,20,30,40,50 };
    float y[5][5] ={
        { 0.1736, 0, 0, 0,0 },
        { 0.3420, 0, 0, 0, 0 },
        { 0.5, 0, 0, 0, 0 },
        { 0.6428, 0, 0, 0, 0 },
        {0.7666, 0, 0, 0, 0},
    };

    forward(x, y, n);

    return 0;
}
void forward(float x[5], float y[5][5], int n)
{
    int i, j;
    float a;
    printf("enter the interpolation point:");
    scanf("%f",&a);
    float h, u, sum, p;
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    printf("\n The forward difference table is:\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n - i; j++) {
            printf("%f\t", y[i][j]);
        }
    }

    p = 1.0;
    sum = y[0][0];
    h = x[1] - x[0];
    u = (a - x[0]) / h;
    for (j = 1; j < n; j++) {
        p = p * (u - j + 1) / j;
        sum = sum + p * y[0][j];
    }
    printf("\nThe value of y at x=%f is %0.3f", a, sum);
}
