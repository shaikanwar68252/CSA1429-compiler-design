#include <stdio.h>
int main() {
   int a = 10;
   int b = 11;
   int c = 9;
   int d = 7;
   int e;
   e = (a + b) * c / d;      
   printf("Value of (a + b) * c / d is : %d\n",  e );
   e = ((a + b) * c) / d;    
   printf("Value of ((a + b) * c) / d is  : %d\n" ,  e );
   e = (a + b) * (c / d);   
   printf("Value of (a + b) * (c / d) is  : %d\n",  e );
   e = a + (b * c) / d;     
   printf("Value of a + (b * c) / d is  : %d\n" ,  e );
   return 0;
}