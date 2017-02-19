#include<iostream>
#include<vector>
#include<string.h>    // ".h" >> memset, preencher vetor com 0
#include<stdio.h>

using namespace std;

    vector <int> t[1000010];

int main(void)
{
    int n, m;
    while(cin >> n >> m)
    {
        memset(t, 0, sizeof t);

        for(int i=1; i<=n; i++)
        {
            int temp;
            cin >> temp;
            t[temp].push_back(i); //adiciona um novo elemento no final do vetor
        }

        while(m--)
        {
            int k, v;

            cin >> k >> v;
            k--;
            if (k<t[v].size())          //retorna o tamanho corrente da string

            printf("%d\n", t[v][k]);
            else
                cout << 0 << endl;
        }

    }
return 0;
}
