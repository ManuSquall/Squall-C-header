#include "squall.h"



int main()
{
    int *nbl=(int*)malloc(sizeof(int*));
    int *nbc=(int*)malloc(sizeof(int*));
    
    do
    {
        puts("Saisissez le nombre de ligne");
        scanf("%d", nbl);
    } while (*nbl<1);

    do
    {
        puts("Saisissez le nombre de colonne");
        scanf("%d", nbc);
    } while (*nbc<1);

    //##################################################

    int **M=(int**)malloc((*nbl)*sizeof(int**));
    

    for(int i = 0; i < (*nbl); i++)
    {
        *(M+i)=(int*)malloc(sizeof(int*));

        puts("\n\n");

        for(int j = 0; j < (*nbc); j++)
        {
            printf("Saisissez la colonne %d de la ligne %d \n", i+1, j+1);
            scanf("%d", *(M+i)+j);
        }
    }



    for(int i = 0; i < (*nbl); i++)
    {
        
        puts("\n\n");

        for(int j = 0; j < (*nbc); j++)
        {
            printf("| %3d |", *(*(M+i)+j));
        }
    }
    

    
    
    

    

    return 0;
}