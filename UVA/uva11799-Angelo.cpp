#include <iostream>
#include <cstdlib>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){

    int t;

    cin >> t;

    for(int i = 1; i <=t; i++){

        int n;

        cin >> n;

        int s[n];

        for(int j = 0; j < n; j++)
            cin >> s[j];

        qsort(s, n, sizeof(int), compare);

        cout << "Case " << i << ": " << s[n-1] << endl;

    }

}
