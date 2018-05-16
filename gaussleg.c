#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define error 1e-6

int biseccio(double [2], double f);
double f2(double x);
double f4(double x);
double f6(double x);
double f8(double x);

int main()
{
    double inter[2];
    int n;
    int intcanviat=0;
    inter[0]=-1;
    inter[1]=1;
    
    int grau;
    printf("Quin grau vols calcular?\n");
    scanf("%i",&grau);
    
    double interval0;
    printf("Introdueix nombre d'iteracions màximes: ");
    scanf("%i", &n);
    
    if(grau==2)
    {
        for(int i=0; i<n+1; i++)
        {
            interval0=inter[intcanviat];
            intcanviat=biseccio(inter,f2);
            if(fabs(interval0-inter[intcanviat])<=error) 
            {
                printf("\nNombre d'iteracions biseccio: %d\n", i);            
                break;
            }
                
        }
        printf("L'aproximació és = %.16G\n", inter[intcanviat]);
        return 0;
    }
    
    if(grau==4)
    {
        for(int i=0; i<n+1; i++)
        {
            interval0=inter[intcanviat];
            intcanviat=biseccio(inter,f4);
            if(fabs(interval0-inter[intcanviat])<=error) 
            {
                printf("\nNombre d'iteracions biseccio: %d\n", i);            
                break;
            }
                
        }
        printf("L'aproximació és = %.16G\n", inter[intcanviat]);
        return 1;
    }
    
    if(grau==6)
    {
        for(int i=0; i<n+1; i++)
        {
            interval0=inter[intcanviat];
            intcanviat=biseccio(inter,f6);
            if(fabs(interval0-inter[intcanviat])<=error) 
            {
                printf("\nNombre d'iteracions biseccio: %d\n", i);            
                break;
            }
                
        }
        printf("L'aproximació és = %.16G\n", inter[intcanviat]);
        return 2;
    }
    
    if(grau==8)
    {
        for(int i=0; i<n+1; i++)
        {
            interval0=inter[intcanviat];
            intcanviat=biseccio(inter,f8);
            if(fabs(interval0-inter[intcanviat])<=error) 
            {
                printf("\nNombre d'iteracions biseccio: %d\n", i);            
                break;
            }
                
        }
        printf("L'aproximació és = %.16G\n", inter[intcanviat]);
        return 3;
    }
    
    return 5;
}


int biseccio(double inter[2], double f)
{
    double mig = (inter[0]+inter[1])/2;
    double signe= f(inter[0])*f(mig);
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

double f2(double x)
{
    return ((3*x*x)-1)/2.;
}

double f4(double x)
{
    return (35*x*x*x*x-30*x*+3)/8.;
}

double f6(double x)
{
    return (231*x*x*x*x*x*x-315*x*x*x*x+105*x*x-5)/16.;
}

double f8(double x)
{
    return (15*x*((429*x*x*x*x*x*x*x-639*x*x*x*x*x+315*x*x*x-35*x)/16.)-7*((231*x*x*x*x*x*x-315*x*x*x*x+105*x*x-5)/16.))/8.;
}
