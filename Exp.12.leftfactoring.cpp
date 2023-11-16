#include<stdio.h>
#include<string.h>
int main()
{
	char non,be1,be2,al1,al2,pro[10][10];
	int index=3,i,num;
	printf("Enter Number of Production : ");  
    scanf("%d",&num);  
    printf("Enter the grammar as E->BC|BD:\n");  
    for(i=0;i<num;i++)
	{  
        scanf("%s",pro[i]);  
    }  
    for(i=0;i<num;i++)
    {
    	printf("\n The grammer :: %s",pro[i]);
    	non=pro[i][0];
    	al1=pro[i][index];
    	be1=pro[i][index+1];
    	while(pro[i][index]!=0 && pro[i][index]!='|')
    			index++;
    	al2=pro[i][index+1];
    	be2=pro[i][index+2];
    	if(al1==al2)
    	{
    		printf(" is left factoring.\n");
    		printf("Grammar without left factoring is:\n");  
            printf("%c->%c%c\'",non,al1,non);  
            printf("\n%c\'->%c|%c\n",non,be1,be2);  
		}
		else
			printf(" is not left factoring.\n");
	}
}