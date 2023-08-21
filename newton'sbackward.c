#include <stdio.h>
void backward(float x[5], float y[5][5], int n);
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

    backward(x, y, n);

    return 0;
}
void BackWard(float x[5], float y[5][5], int n)
{
    int i, j;
    float a =25; // interpolation point
    float h, u, sum, p;
    for (j = 1; j < n; j++) {
        for (i = j; i < n; i++) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }
    printf("\nThe backward difference table is:\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j <= i; j++) {
            printf("%f\t", y[i][j]);
        }
    }

    p = 1.0;
    sum = y[n - 1][0];
    h = x[1] - x[0];
    u = (a - x[n - 1]) / h;
    for (j = 1; j < n; j++) {
        p = p * (u + j - 1) / j;
        sum = sum + p * y[n - 1][j];
    }

    printf("\nThe value of y at x=%f is %0.3f", a, sum);
}
