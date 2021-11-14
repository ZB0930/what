#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 50
int main(){
    int post[MAXNUM] = {0};
    int len_post = 0;
    int i,j;
    int rootN;
    while( (scanf("%d",&post[len_post])) != EOF){
        len_post ++;
    }
    rootN = post[len_post-1];
    for( i = 0; i < len_post; i++){
        if( post[i] > rootN)
        break;
    }

    for( j = i; j < len_post; j++){
        if( post[j] < rootN ){
        printf("false");
        break;
        }}
    if( j == len_post )
        printf("true");
    return 0;

}
