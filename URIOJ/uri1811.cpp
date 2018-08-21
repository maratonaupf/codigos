/*
 * Leonardo Deliyannis Constantin
 * URI 1811 - O Óscar Vai Para...
*/

#include <stdio.h>
#define MAXN 1123
#define MAXM  112

struct result{
    int idx, len, st, end;
    result(){
        idx = st = end = 0;
        len = 0;
    }
    result(int idx, int len, int st, int end):
        idx(idx), len(len), st(st), end(end) {}
};

int b[MAXN][MAXM];

bool operator > (const result &x, const result &y){
    if(x.len != y.len)
        return x.len > y.len;
    int dif1 = b[x.idx][x.end] - b[x.idx][x.st];
    int dif2 = b[y.idx][y.end] - b[y.idx][y.st];
    if(dif1 != dif2)
        return dif1 > dif2;
    if(b[x.idx][x.end] != b[y.idx][y.end])
        return b[x.idx][x.end] > b[y.idx][y.end];
    return x.idx < y.idx;
}

int main(){
    int N, M, T = 0, i, j;
    while(scanf("%d", &N), N){
        scanf("%d", &M);
        result ans;
        for(i = 0; i < N; i++){
            if(M == 0) continue;
            result best, cur;
            best.idx = cur.idx = i;
            for(j = 0; j < M; j++){
                scanf("%d", &b[i][j]);
                if(j == 0) continue;
                if(b[i][j-1] <  b[i][j]){
                    cur.len++;
                    cur.end = j;
                }
                if(b[i][j-1] >= b[i][j] || j == N-1){
                    if(cur > best){
                        best = cur;
                    }
                    cur.len = 1;
                    cur.st = j;
                }
            }
            if(i == 0 || best > ans)
                ans = best;
        }
        printf("Instancia #%d\n", ++T);
        printf("%d\n\n", (M == 0) ? 1 : ans.idx + 1);
    }
    return 0;
}
