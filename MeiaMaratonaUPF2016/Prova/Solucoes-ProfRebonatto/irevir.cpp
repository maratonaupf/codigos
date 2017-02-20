#include <iostream>
#include <cstring>
#define TOT 1010
using namespace std;
 
bool ver[TOT], s[TOT][TOT];
int w[TOT], id, ni, nr;
 
 
void funcaod(int v, bool tt){
    bool ret;
    ver[v] = true;
    for(int i = 1; i <= ni; i++){
        if(tt){
            ret = s[v][i];
        }else{
            ret = s[i][v];
        }
        if (ret && !ver[i])
            funcaod(i, tt);
    }
    if(tt){
        w[++id] = v;
    }
}
 
void mem(){
    memset(s, 0, sizeof(s)); 
    memset(ver, 0, sizeof(ver));
    memset(w, 0, sizeof(w));
}
 
void percni(){
    for(int i = 1; i <= ni; i++){
        if(!ver[i]){
            funcaod(i, true);
        }
    }
}
 
void percentr(){
    int i1, i2, mu;
    for(int i = 1; i <= nr; i++){
            cin >> i1 >> i2 >> mu;
            s[i1][i2] = true;
            if (mu==2)
               s[i2][i1] = true;
    }
}
 
 
int main() {    
    while(cin >> ni >> nr, ni|nr) {  
        int i1, i2, mu;
        mem();
        id = 0;   
        int p = 0; 
        percentr();
        percni();
        memset(ver, 0, sizeof(ver));
        for(int i = ni; i > 0; i--){
            if(!ver[w[i]]) {
                p++;
                funcaod(w[i], false);
            }
        }
        cout << (p==1) << endl;
    }
 
    return 0;
}
