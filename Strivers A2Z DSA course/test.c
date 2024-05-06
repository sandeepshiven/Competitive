#include "stdio.h"

int f(int n){
    if(n == 0){
        return 0;
    }
    else{
        printf("a");
        f(n-1);
    }
} 
void main()
{
    int x = f(10);
    
    printf("%d", x);
    
}


