#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

double f(double, int);

int main()
{
    double suma=0, aux=0;
    
    int funcio;
    printf("De quina funció vols fer-ne trapezis? (1 o 2)\n");
    scanf("%i",&funcio);
    
    int particions;
    printf("Quantes particions vols fer?\n");
    scanf("%i",&particions);
    
    double h;
    if(funcio==1) h=1.98/particions;
    else h=2./particions;
     //canviarho si funcio==1
    
    double nodes[particions+1];
    double fnodes[particions+1];
    
    for(int i=0; i<particions+1; i++)
    {
        if(funcio==1) nodes[i]=-0.99+aux;
        else nodes[i]=-1+aux;
        aux+=h;
        printf("nodes[%i]=%.16G\n",i,nodes[i]);
    }
    
    for(int i=0; i<particions+1;i++)
    {
        fnodes[i]=f(nodes[i],funcio);
//         printf("fnodes[%i]=%.16G\n",i,fnodes[i]);
    }
    
    for(int i=1; i<particions;i++)  //termes amb trapezis
    {
        suma+=fnodes[i]*2;
    }
    
    suma=(suma+fnodes[0]+fnodes[particions])*(h/2);   //fórmula dels trapezis
    
    printf("El resultat amb %d particions és %.16G\n", particions, suma);
    
    return 0;
}

double f(double x, int funcio)
{
    if(funcio==1) return exp(-x*x)/sqrt(1-x*x);
    else return fabs(x);
}

