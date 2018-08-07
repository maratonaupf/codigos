#include <stdio.h>
#include <vector>
#include <assert.h>
using namespace std;

typedef vector<int> vi;
int nmax, steps;
vector<vi> pin;

void setup(int N){
    nmax = N;
    steps = -1;
    pin.assign(3, vi());
    pin[0].assign(N, 0);
    for(int i = 0; i < N; i++){
        pin[0][i] = N-i;
    }
    assert(pin[0].back() == 1);
}

void print(){
    printf("Step #%d:\n", ++steps);
    for(int i = nmax-1; i >= 0; i--){
        for(int j = 0; j < 3; j++){
            if(i < (int)pin[j].size()){
                printf("%2d ", pin[j][i]);
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("-|--|--|-\n\n");
}

void move(vi &orig, vi &dest){
    dest.push_back(orig.back());
    orig.pop_back();
}

void hanoi(int N, vi &orig, vi &temp, vi &dest){
    if(N == 1){
        move(orig, dest);
        print();
        return;
    }
    hanoi(N-1, orig, dest, temp);
    move(orig, dest);
    print();
    hanoi(N-1, temp, orig, dest);
}

int main(){
    int N;
    while(scanf("%d", &N) != EOF && N > 0){
        setup(N);
        print();
        hanoi(N, pin[0], pin[1], pin[2]);
        printf("Completed in %d steps\n", steps);
    }
    return 0;
}
