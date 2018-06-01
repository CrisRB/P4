#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define tol 5e-9
#define PI 3.14159265359

double p1(double);
double pol(double, int, int);
double dpol(double, int, int);
double mnewton(double, int, int);
double f1(double, int);

int main()
{
    int metode=1;
//     printf("Quin mètode vols utilitzar?\n 1: Legendre\n 2: Chebyshev\n");
//     scanf("%i",&metode);
    
    int n;
    printf("Quin grau vols calcular?\n");
    scanf("%i", &n);
    int z=100;   //iteracions maximes
    
    int particions=100, canvisdesigne=0;
    double dist=1.98/particions, puntsmig[n], arrels[n];
    
    double nodes[particions+1];
    
    while(metode<3)
    {
    for(int l=0;l<particions+1;l++)
    {
        nodes[l]=0;
    }
    
    for(int h=0;h<n;h++)
    {
        puntsmig[h]=0;            
    }
    
    double k=0;
    for(int i=0;i<particions+1;i++) //calculem els nodes
    {
        nodes[i]=-0.99+k;
        k+=dist;
    }
    
    int t=0;
    for(int j=0;j<particions;j++)
    {
        double signe=0;
        signe=pol(nodes[j],n-1,metode)*pol(nodes[j+1],n-1,metode);
//         printf("(%.16G,%.16G) signe es %lf\n",nodes[j],nodes[j+1],signe);
        if(signe<0)
        {
//             printf("(%.16G,%.16G)\n",nodes[j],nodes[j+1]);
            puntsmig[t]=(nodes[j]+nodes[j+1])/2;
//                 printf("puntsmig[%i]=%.16G\n",t,puntsmig[t]);
            canvisdesigne+=1;
//             printf("canvis de signe=%i\n",canvisdesigne);
            t+=1;
        }
    }
    
    int y=0;
    for(int j=0;j<n;j++)
    {
        double x1=puntsmig[j], x2=0;
        for(int i=0; i<z+1; i++)
        {
            x2=x1;
//             printf("x1=%lf\n",x2);
            x1=mnewton(x1,n,metode);
//             printf("x1=%lf\n",x1);
            if(fabs(x2-x1)<=tol) 
            {
                arrels[y]=x1;
                printf("Arrel %i és %.16G\n", y, arrels[y]);
                y+=1;
                break;
            }
        }
    }
    
    double a[n];
    for(int r=0;r<n;r++)    //calculem a_i
    {
        if(metode==1)
        {
            a[r]=2/((1-arrels[r]*arrels[r])*dpol(arrels[r],n,metode)*dpol(arrels[r],n,metode));
        }
        else
        {
            a[r]=PI/n;
        }
    }
    
    double result1=0;
    for(int e=0;e<n;e++)
    {
        result1+=a[e]*f1(arrels[e],metode);
    }
    
    printf("Resultat integral 1 amb el mètode %i = %.16G\n",metode,result1);
    
    metode+=1;
    }
    return 0;
}

double pol(double x, int n, int metode) //introduir n-1
{
    double a=1,b=x,c=0;
    if(n==0) c=1;
    if(n==1) c=x;
    for(int i=1;i<n+1;i++)
    {
        if(metode==1)
        {
            c=((2*i+1)*x*b-(i*a))/(i+1);
            a=b;
            b=c;
        }
        else
        {
            c=(2*x*b-a);
            a=b;
            b=c;
        }
    }
    return c;
}

double dpol(double x, int n, int metode)    //aquí la n és la que toca
{
    double a,b;
    if(n==1) a=1, b=x;
    if(n==2) a=x, b=pol(x,n-1,metode);
    else
    {
        a=pol(x,n-2,metode);
        b=pol(x,n-1,metode);
    }
    
    return (-n*x*b+n*a)/(1-x*x);
}

double mnewton(double xn, int n, int metode)    //n grau
{
    double xn1;
    xn1=xn-(pol(xn,n-1,metode)/dpol(xn,n,metode));
    return xn1;
}

double f1(double x, int metode)
{
    if(metode==1) return exp(-x*x)/sqrt(1-x*x);
    else return exp(-x*x);
}
