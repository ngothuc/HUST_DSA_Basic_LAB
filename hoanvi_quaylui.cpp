#include <stdio.h>
int n;
int a[100];
void solution(){
    for(int i = 1; i <= n; i++) printf("%d ",a[i]);
    printf("\n");
}
int check(int v, int k){
    for(int i = 1; i <= k-1; i++)
        if(a[i] == v) return 0;
    return 1;
}
void Try(int k){
    for(int v = 1; v <= n; v++){
        if(check(v,k)){
            a[k] = v;
            if(k == n) solution();
            else Try(k+1);
        }
    }
}
int main(){
    n = 10;
    Try(1);
    return 0;
}

