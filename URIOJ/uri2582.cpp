/*
 * Leonardo Deliyannis Constantin
 * URI 2582 - System of a Download
*/

#include<stdio.h>
#include<string>
using namespace std;

string songs[11] = {
    "PROXYCITY",
    "P.Y.N.G.",
    "DNSUEY!",
    "SERVERS",
    "HOST!",
    "CRIPTONIZE",
    "OFFLINE DAY",
    "SALT",
    "ANSWER!",
    "RAR?",
    "WIFI ANTENNAS"
};

int main(){
    int c, x, y;
    scanf("%d", &c);
    while(c--){
        scanf("%d %d", &x, &y);
        printf("%s\n", songs[x+y].c_str());
    }
    return 0;
}
