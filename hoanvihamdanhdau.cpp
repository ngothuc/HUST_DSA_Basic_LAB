#include <stdio.h>
int n;
int a[100];
int mark[100];
void solution(){
    for(int i = 1; i <= n; i++) printf("%d ",a[i]);
    printf("\n");
}
int check(int v, int k){
    return mark[v] == 0;
}
void Try(int k){
    for(int v = 1; v <= n; v++){
        if(check(v,k)){
            a[k] = v;
            mark[v] = 1;// update status of value v
            if(k == n) solution();
            else Try(k+1);
            mark[v] = 0; // recover when backtracking
        }
    }
}
int main(){
    n = 6;
    for(int v = 1; v <= n; v++) mark[v] = 0;
    Try(1);
    return 0;
}
