#include <stdio.h>
int n,k;
int a[100];
//int cnt;
//int v;
void solution(){
    //cnt += 1;
    for(int i = 1; i <= k; i++) printf("%d ",a[i]);
    printf("\n");
}
int check(int v, int i){
    //return v > a[i-1];
    return 1;
}
void Try(int i){
    int v;
    for(v = a[i-1] + 1; v <= n-k+i; v++){
        //if(check(v,i)){
            a[i] = v;
            if(i == k) solution();
            else Try(i+1);
        //}
    }
}
int main(){
    k = 6; n = 10;
    a[0] = 0; //cnt = 0;
    Try(1);
    //printf("number of solutions = %d\n", cnt);
    return 0;
}

