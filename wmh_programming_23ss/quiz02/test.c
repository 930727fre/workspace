#include<stdio.h>
#include<string.h>
#include<ctype.h>
int parent[100000];
int find(int a){
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}
void merge(int a, int b){
    parent[find(b)] = parent[find(a)];
}
int main(){
    int n, m;
    scanf("%d %d", &n , &m);
    char arr[100];
    int num[100][100];
    for(int i = 0; i <= n + 1 ; i++){
        for(int j = 0; j <= m + 1 ; j++){
            num[i][j] = 1;
            parent[i * 10 + j] = i * 10 + j;
        }
    }
    for(int i = 1; i <= n ; i++){
        scanf("%s", arr);
        for(int j = 1; j <= m; j++)
            num[i][j] = (int)(arr[j - 1] - '0');
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            if(num[i][j] != 1){
                if(num[i + 1][j] != 1) merge(i * 10 + j, (i + 1) * 10 + j);
                if(num[i][j + 1] != 1) merge(i * 10 + j, i * 10 + (j + 1));
            }
            if(num[i][j] != 1 && num[i][j] != 0)
                for(int k = 1; k <= n ; k++)
                    for(int l = 1; l <= n ; l++)
                        if(num[i][j] == num[k][l])
                            merge(i * 10 + j, k * 10 + l);
        }
    }
    (find(11) == find(n * 10 + m)) ? printf("Yes\n") : printf("No\n");
}