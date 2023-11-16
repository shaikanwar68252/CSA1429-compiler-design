#include<stdio.h>  
#include<string.h>  
//#define SIZE 10  
int main ()
{  
    char non,be,al;  
    int num;  
    char pro[10][10];  
    int index=3,i;  
    printf("Enter Number of Production : ");  
    scanf("%d",&num);  
    printf("Enter the grammar as E->E-A :\n");  
    for(i=0;i<num;i++)
	{  
        scanf("%s",pro[i]);  
    }  
    for(i=0;i<num;i++)
	{  
        printf("\nGRAMMAR :: %s",pro[i]);  
        non=pro[i][0];  
        if(non==pro[i][index])
		{  
            al=pro[i][index+1];  
            printf(" is left recursive.\n");  
            while(pro[i][index]!=0 && pro[i][index]!='|')  
                index++;  
            if(pro[i][index]!=0)
			{  
                be=pro[i][index+1];  
                printf("Grammar without left recursion:\n");  
                printf("%c->%c%c\'",non,be,non);  
                printf("\n%c\'->%c%c\'|E\n",non,al,non);  
            }  
            else  
                printf(" can't be reduced\n");  
        }  
        else  
            printf(" is not left recursive.\n");  
        index=3;  
    }  
}