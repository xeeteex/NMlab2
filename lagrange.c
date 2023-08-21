#include<stdio.h>


int main()
{
     float x[100], f[100], xp, fp=0, li;
     int i,j,n;
     /* Input Section */
     printf("Enter number of data: ");
     scanf("%d", &n);
     printf("Enter data:\n");
     for(i=1;i<=n;i++)
     {
          printf("x[%d] = ", i);
          scanf("%f", &x[i]);
          printf("y[%d] = ", i);
          scanf("%f", &f[i]);
     }
     printf("Enter interpolation point: ");
     scanf("%f", &xp);
     /* Implementing Lagrange Interpolation */
     for(i=1;i<=n;i++)
     {
          li=1;
          for(j=1;j<=n;j++)
          {
               if(i!=j)
               {
                    li = li* (xp - x[j])/(x[i] - x[j]);
               }
          }
          fp = fp + li * f[i];
     }
     printf("Interpolated value at %.3f is %.3f.", xp, fp);
}
