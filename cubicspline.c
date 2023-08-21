#include<stdio.h>
#include<math.h>

int main(){
    int n,i,j;
    float h[10],a,b,c,d,sum=0,s[10]={0},x[10],F[10],f[10],p,m[10][10]={0},temp;
    
    printf("No of samples? ");
    scanf("%d",&n);
    printf("\nEnter all sample points: ");
    for(i=0;i<n;i++)
        scanf("%f%f",&x[i],&f[i]);
    for(i=n-1;i>0;i--){
        F[i]=(f[i]-f[i-1])/(x[i]-x[i-1]);
        h[i-1]=x[i]-x[i-1];
    }
    //*********** formation of h, s , f matrix **************//
    for(i=1;i<n-1;i++){
        m[i][i]=2*(h[i-1]+h[i]);
        if(i!=1){
            m[i][i-1]=h[i-1];
            m[i-1][i]=h[i-1];
        }
        m[i][n-1]=6*(F[i+1]-F[i]);
    }
//    *********** forward elimination **************//
    for(i=1;i<n-2;i++){
        temp=(m[i+1][i]/m[i][i]);
        for(j=1;j<=n-1;j++)
            m[i+1][j]-=temp*m[i][j];
    }
    //*********** backward substitution *********//
    for(i=n-2;i>0;i--){
        sum=0;
        for(j=i;j<=n-2;j++)
            sum+=m[i][j]*s[j];
        s[i]=(m[i][n-1]-sum)/m[i][i];
    }
    
    printf("\nEnter x : ");
    scanf("%f",&p);
    for(i=0;i<n-1;i++)
        if(x[i]<=p&&p<=x[i+1]){
            a=(s[i+1]-s[i])/(6*h[i]);
            b=s[i]/2;
            c=(f[i+1]-f[i])/h[i]-(2*h[i]*s[i]+s[i+1]*h[i])/6;
            d=f[i];
            sum=a*pow((p-x[i]),3)+b*pow((p-x[i]),2)+c*(p-x[i])+d;
        }
    
    printf("\nFunctional value is: %f",sum);

}
