#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define error 1e-6

//posar casos i mirar que a la que un interval es <0, me'l guardi i passi al següent


int biseccio(double [2]);
// double f2(double x);
// double f4(double x);
double f6(double x);
// double f8(double x);
double mnewton(double xn);

int main()
{
    double inter[2];
    int n;
    int intcanviat=0;
    inter[0]=-1;
    inter[1]=1;
    
    double interval0;
    printf("Introdueix nombre d'iteracions màximes: ");
    scanf("%i", &n);

    for(int i=0; i<3; i++)
    {
        interval0=inter[intcanviat];
        intcanviat=biseccio(inter);
        if(fabs(interval0-inter[intcanviat])<=error) 
        {
            printf("\nNombre d'iteracions biseccio: %d\n", i);            
            break;
        }
            
    }
//     printf("L'aproximació és = %.16G\n", inter[intcanviat]);
    
    double x1=inter[intcanviat],x2;
    
    for(int i=0; i<n+1; i++)
    {
        x2=x1;
        x1=mnewton(x1);
        if(fabs(x2-x1)<=error) 
        {
        printf("Nombre d'iteracions per mètode de Newton: %d\n", i);
        break;
        }
    }
    
    printf("L'aproximació és = %.16G\n", x1);
    
    return 0;

}


int biseccio(double inter[2])
{
    double mig = (inter[0]+inter[1])/2;
    double signe= f6(inter[0])*f6(mig);
    if(signe<0) 
    {
        inter[1] = mig;
        printf("[%lf,%lf]",inter[0],inter[1]);
        printf("\n");
        return 1;
    }
    
    inter[0]=mig;
    printf("[%lf,%lf]",inter[0],inter[1]);
    printf("\n");
    return 0;
    
}

// double f2(double x)
// {
//     return ((3*x*x)-1)/2.;
// }
// 
// double f4(double x)
// {
//     return (35*x*x*x*x-30*x*x+3)/8.;
// }

double f6(double x)
{
    return (231*x*x*x*x*x*x-315*x*x*x*x+105*x*x-5)/16.;
}

// double f8(double x)
// {
//     return (15*x*((429*x*x*x*x*x*x*x-639*x*x*x*x*x+315*x*x*x-35*x)/16.)-7*((231*x*x*x*x*x*x-315*x*x*x*x+105*x*x-5)/16.))/8.;
// }

double mnewton(double xn)
{
    double xn1;
    
    xn1=xn-((231*xn*xn*xn*xn*xn*xn-315*xn*xn*xn*xn+105*xn*xn-5)/(231*6*xn*xn*xn*xn*xn-315*4*xn*xn*xn+105*2*xn));
    
//     xn1=xn-((35*xn*xn*xn*xn-30*xn*xn+3)/(4*35*xn*xn*xn-60*xn));
    return xn1;
}
