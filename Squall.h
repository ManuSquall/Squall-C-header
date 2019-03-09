//########################################################################################################################################



//ManuSquall


#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>



//########################################################################################################################################

//                  DEFINE

//########################################################################################################################################


#define sul_cls system("cls")
#define sul_pause system("pause")
#define sul_flush fflush(stdin)








//########################################################################################################################################

//                  FONCTION

//########################################################################################################################################

void create_N_NAMED_files_in_NAMED_DIR(int n, char *fiName, char *foName);//L49
void create_N_Parts_in_menu(int a);//L97
int is_first_number(int a);//L124
int is_perfect_number(int a);//L140
void matrice_x_line_n_column();//L191




//create n files in a directory;
//first param: number of file to create;
//second param: name of the N files;
//third param: name of the directory;
void create_N_NAMED_files_in_NAMED_DIR(int n, char *fiName, char *foName)
{
    char *a=(char*)malloc(sizeof(char));
    char *b=(char*)malloc(sizeof(char));
    char *c=(char*)malloc(sizeof(char));
    char *d=(char*)malloc(sizeof(char));
    char *e=(char*)malloc(sizeof(char));
    // char a[65];
    // char d[10];
    // char c[10];
    // char b[30];
    // char e[55];
    
    //personaliser le nom du dossier
    // puts("Entrez le nom du dossier");
    // gets(b);
    strcpy(b,foName);
    strcpy(a,"mkdir ");
    strcat(a,b);
    system(a);
    
    //personnaliser le nom du fichier 
    strcat(b,"/");
    strcpy(e,"echo 1 >");
    strcat(e,b);
    // puts("Nom du fichier");
    // gets(b);
    strcpy(b,fiName);
    strcat(b,"_");
    strcat(e,b);

    //créer n fichier
    for(int i=0;i<n;i++)
    {
        strcpy(a,e);
        strcpy(c,".txt");
        sprintf(d,"%d",i+1);
        strcat(a,d);
        strcat(a,c);
        system(a);
    }

    
}

//########################################################################################################################################

// display a menu with a part
void create_N_Parts_in_menu(int a)
{
    puts("\n\n\n");
        puts("\t\t\t\t\t\t**********************************************************");
        puts("\t\t\t\t\t\t**********************************************************");
        puts("\t\t\t\t\t\t****                                                  ****");
        puts("\t\t\t\t\t\t****                **MENU PRINCIPAL**                ****");
        puts("\t\t\t\t\t\t****                                                  ****");
        puts("\t\t\t\t\t\t**********************************************************");
        puts("\t\t\t\t\t\t****                                                  ****");
        for(int i=0; i<a; i++)
        {
        printf("\t\t\t\t\t\t****                   %d- Part %d                      ****\n", i+1, i+1);
        }
        puts("\t\t\t\t\t\t****__________________________________________________****");
        puts("\t\t\t\t\t\t**********************************************************");
        puts("\t\t\t\t\t\t****                                                  ****");
        puts("\t\t\t\t\t\t****                FAITES VOTRE CHOIX                ****");
        puts("\t\t\t\t\t\t****                                                  ****");
        puts("");
}

//########################################################################################################################################

// know if an integer is a "first number"
//  1:first
//  X:not first
int is_first_number(int a)
{
    int nbr=0;
    for(int j = 1; j <=(a/2); j++)
    {
        if(a%j==0) nbr++;
    }
    return (nbr==1)? 1 : 0;
}


//########################################################################################################################################

// know if an integer is a "perfect number"
//  1:first
//  X:not first
int is_perfect_number(int a)
{
    int som=0;
    for(int j = 1; j <=(a/2); j++)
    {
        if(a%j==0) som+=j;
    }
    return (som==a)? 1 : 0;
}

//########################################################################################################################################



//########################################################################################################################################

/*

// yes or no reload
// -mettre le process a recommencer dans  "process"
void yes_or_no_reload()
{
    fflush(stdin);
    char *rep=(char*)malloc(sizeof(char));

    do
    {
        //  <"process">



        do
        {
            fflush(stdin);
            puts("\n\nVoulez vous recommencer?\n[oui / non]");
            gets(rep);
        } while (strcmp("oui",rep)!=0 && strcmp("non",rep));
        

    } while (strcmp("oui",rep)==0);
    fflush(stdin);
}   
//*/

//########################################################################################################################################

//creer une matrice de N lignes
//-avec un nombre de col defini pour chaque ligne
void matrice_x_line_n_column()
{
    int *nbl=(int*)malloc(sizeof(int*));
    
    do
    {
        puts("Combien de ligne voulez vous saisir?");
        scanf("%d", nbl);
    } while (*nbl<1);

    int **M=(int**)malloc((*nbl)*sizeof(int**));

    int *nbc=(int*)malloc((*nbl)*sizeof(int*));
    
    for(int i = 0; i < (*nbl); i++)
    {
        printf("\nLigne %d \n", i+1);
        do
        {
            printf("Combien de colonnes voulez vous saisir a la ligne %d \n",i+1);
            scanf("%d", nbc+i);
        }while(*(nbc+i)<1);

        *(M+i)=(int*)malloc((*(nbc+i))*sizeof(int*));

        for(int j = 0; j < (*(nbc+i)); j++)
        {
            printf("Saisissez la colonne %d \n", j+1);
            scanf("%d",(*(M+i)+j));
            //T[i]=*(t+i)
        }    
    }

    puts("\n Affichage");

    for(int i = 0; i < (*nbl); i++)
    {
        for(int j = 0; j < *(nbc+i); j++)
        {
            printf("| %d |", *(*(M+i)+j) );
        }
        puts("");
    }

}


//########################################################################################################################################

int **matrice_create(int *nbl, int *nbc)
{
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

    return M;
}



