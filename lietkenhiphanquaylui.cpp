#include <stdio.h>
int n;// length of the binary sequence
int a[100];
int cnt;
int check(int v, int k){// return true if value v can be assigned to a[k] without violating
                                        // the given constraints
    if(k == 1) return 1;
    //return a[k-1] + v <= 1;
    if(a[k-1] == 1 && v == 1) return 0;
    return 1;
}
void solution(){
    cnt += 1;
    for(int i = 1; i <= n; i++) printf("%d",a[i]);
    printf("\n");
}
void Try(int k){// try all values for a[k]
    int v;
    for(v = 0; v <= 1; v++){
        if(check(v,k)){
            a[k] = v;
            if(k == n) solution();
            else Try(k+1);
        }
    }
}
int main(){
    n = 5;
    Try(1);
    printf("number of solutions = %d\n", cnt);
    return 0;
}

