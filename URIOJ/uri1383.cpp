#include<stdio.h>
#include<string.h>
#define MSET(arr,val) memset(arr,val,sizeof(arr))

int isValid(int *count){
    int i;
    for(i = 1; i <= 9; i++){
        if(count[i] != 1){
            return 0;
        }
    }
    return 1;
}

int main() {
    int instance, N, i, j, m[9][9], a, b;
    int count[10];
    int isSolution;
    
    scanf("%d", &N);
    
    for(instance = 1; instance <= N; instance++){
        isSolution = 1;
        
        for(i = 0; i < 9; i++){
            MSET(count, 0);
            for(j = 0; j < 9; j++){
                scanf("%d", m[i]+j);
                count[m[i][j]]++;
            }
            isSolution &= isValid(count);
        }
        
        for(j = 0; j < 9; j++){
            MSET(count, 0);
            for(i = 0; i < 9; i++){
                count[m[i][j]]++;
            }
            isSolution &= isValid(count);
        }
        
        for(a = 0; a < 9; a+=3){
            for(b = 0; b < 9; b+=3){
                MSET(count, 0);
                for(i = a; i < a+3; i++){
                    for(j = b; j < b+3; j++){
                        count[m[i][j]]++;
                    }
                }
                isSolution &= isValid(count);
            }
        }
        
        printf("Instancia %d\n%s\n\n", instance, isSolution ? "SIM" : "NAO");
    }
    return 0;
}
