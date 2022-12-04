// Online C compiler to run C program online
#include <stdio.h>

void Print(int line){
    printf("\nChristmas Tree!\n");
    
    int cnt = 1;
    for(int i = 1; i <= line; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1) for(int k = 0; k < (line - i) * 2; k++) printf(" ");
            cnt < 10 ? printf("%d   ", cnt++) : printf("%d  ", cnt++);
            
        }
        printf("\n");
        for(int j = 0; j < (line - i) * 2 - 1; j++) printf(" ");
        if(i != line) for(int j = 1; j <= i; j++) printf("/ \\ ");
        printf("\n");
    }
}

int main() {
    // Write C code here
    int line;
    scanf("%d", &line);
    Print(line);

    return 0;
}