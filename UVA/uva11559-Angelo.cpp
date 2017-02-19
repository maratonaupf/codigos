#include <iostream>

using namespace std;

int main(){

    int n, b, h, w;
    unsigned int value=-1;

    while(cin >> n >> b >> h >> w){
        value = -1;
        int hotel[h][w+1];

        for(int i = 0; i < h; i++){
            cin >> hotel[i][0];
            for(int j = 1; j <= w; j++){
                cin >> hotel[i][j];
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 1; j <= w; j++){
                if(n <= hotel[i][j] && n*hotel[i][0] < value)
                    value = n*hotel[i][0];
            }
        }

        if(value <= b) cout << value;
        else cout << "stay home";
        cout << endl;
    }

}
