#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define tol 5e-7

double p1(double);
double pol(double, int);
double dpol(double, int);
double mnewton(double, int);
double f1(double x);

int main()
{
    int n;
    printf("Quin grau vols calcular?\n");
    scanf("%i", &n);
    int z;
    printf("Introdueix nombre d'iteracions màximes: ");
    scanf("%i", &z);

    int particions=0;
    double dist=0, puntsmig[n], arrels[n];
    int canvisdesigne=0;
    
    while(canvisdesigne<n)
    {
        canvisdesigne=0;
        particions+=2;
        dist=1.98/particions;
        
        double nodes[particions+1];
        for(int l=0;l<particions+1;l++)
        {
            nodes[l]=0;
//            printf("nodes[%i]=%.16G\n",l,nodes[l]);
        }
        
        for(int h=0;h<n;h++)
        {
            puntsmig[h]=0;            
        }
        
        double k=0;
        for(int i=0;i<particions+1;i++)
        {
            nodes[i]=-0.99+k;
            k+=dist;
        }
        
        int t=0;
        for(int j=0;j<particions;j++)
        {
            double signe=0;
            signe=pol(nodes[j],n-1)*pol(nodes[j+1],n-1);
            if(signe<0)
            {
//                 printf("Hi ha una arrel entre %.16G i %.16G\n",nodes[j],nodes[j+1]);
                puntsmig[t]=(nodes[j]+nodes[j+1])/2;
//                 printf("puntmig[%i] = %.16G\n",t,puntsmig[t]);
                canvisdesigne+=1;
                t+=1;
            }
        }
//         printf("canvis de signe=%i\n",canvisdesigne);
    }
//     for(int j=0;j<n;j++)
//     {
//         printf("\npuntsmig[%i] = %.16G\n",j,puntsmig[j]);
//         printf("pol en puntmig[%i] = %.16G\n",j,pol(puntsmig[j],n-1));
//         printf("dpol en puntmig[%i] = %.16G\n",j,dpol(puntsmig[j],n));
//     }
    
    int y=0;
    for(int j=0;j<n;j++)
    {
        double x1=puntsmig[j], x2=0;
        for(int i=0; i<z+1; i++)
        {
            x2=x1;
            x1=mnewton(x1,n);
            if(fabs(x2-x1)<=tol) 
            {
                arrels[y]=x1;
                printf("Arrel %i és %.16G\n", y+1, arrels[y]);
                y+=1;
                break;
            }
        }
    }
    
    double a[n];
    for(int r=0;r<n;r++)
    {
        a[r]=2/((1-arrels[r]*arrels[r])*dpol(arrels[r],n)*dpol(arrels[r],n));
        printf("a[%i]=%.16G\n",r,a[r]);
    }
    
    double resultleg1=0;
    for(int e=0;e<n;e++)
    {
        resultleg1+=a[e]*f1(arrels[e]);
    }
    
    printf("Resultat integral 1 amb legendre = %.16G\n",resultleg1);
    return 0;
}

double pol(double x, int n) //introduir n-1
{
    double a=1,b=x,c=0;
    for(int i=1;i<n+1;i++)
    {
        c=((2*i+1)*x*b-(i*a))/(i+1);
        a=b;
        b=c;
    }
    return c;
}

double dpol(double x, int n)    //aquí la n és la que toca
{
    double a,b;
    if(n==1) a=1, b=x;
    if(n==2) a=x, b=pol(x,n-1);
    else
    {
        a=pol(x,n-2);
        b=pol(x,n-1);
    }
    
    return (-n*x*b+n*a)/(1-x*x);
}

double mnewton(double xn, int n)    //n grau
{
    double xn1;
    xn1=xn-(pol(xn,n-1)/dpol(xn,n));
    return xn1;
}

double f1(double x)
{
    return exp(-x*x)/sqrt(1-x*x);
}
