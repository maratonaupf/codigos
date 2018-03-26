/*
 * Leonardo Deliyannis Constantin
 * URI 1560 - Energia dos Triângulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
#define MAX 112

struct pt{
    int x, y;
    pt(){ x = y = 0; }
    pt(int _x, int _y): x(_x), y(_y) {}
};

struct triangle{
    pt a, b, c;
    triangle(){}
    triangle(pt _a, pt _b, pt _c): a(_a), b(_b), c(_c) {}
    int area() const{
        return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)));
    }
};

bool inside(pt x, triangle t){
    int a0 = t.area(),
        a1 = triangle(x, t.b, t.c).area(),
        a2 = triangle(t.a, x, t.c).area(),
        a3 = triangle(t.a, t.b, x).area();
    return a0 == a1 + a2 + a3;
}

int main(){
    int N, M, i, j, k, l;
    int ans, cnt;
    pt b[MAX], w[MAX];
    while(scanf("%d %d", &N, &M) != EOF){
        for(i = 0; i < N; i++){
            scanf("%d %d", &b[i].x, &b[i].y);
        }
        for(i = 0; i < M; i++){
            scanf("%d %d", &w[i].x, &w[i].y);
        }
        ans = 0;
        for(i = 0; i < N; i++){
            for(j = 0; j < i; j++){
                for(k = 0; k < j; k++){
                    cnt = 0;
                    for(l = 0; l < M; l++){
                        cnt += inside(w[l], triangle(b[i], b[j], b[k]));
                    }
                    ans += cnt * cnt;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
