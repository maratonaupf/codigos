#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

int main()
{
    int card;
    vector<int> s(3), p(2);
    vector<bool> av;

    while(scanf("%d %d %d %d %d", &s[0], &s[1], &s[2], &p[0], &p[1]) && s[0] != 0)
    {
        av.clear();
        av.resize(53, true);

        for(int i = 0; i < 3; ++i)
        {
            av[s[i]] = false;

            if(i < 2)
                av[p[i]] = false;
        }

        // Ordena as mãos em ordem ascendente
        sort(s.begin(), s.end());
        sort(p.begin(), p.end());
        card = 53;

        // Caso as duas cartas já sejam maiores que as da princesa, qualquer carta serve
        if(p[0] > s[2])
            for(int i = 1; i <= 52 && i < card; ++i)
                if(av[i])
                    card = i;

        // Caso apenas uma carta for maior que a maior da princesa
        // Esse caso só ocorre caso o primeiro IF seja falso, caso contrário o valor de card 
        // será diferente de 53 e o laço provavelmente não irá acontecer
        if(p[1] > s[2])
            for(int i = s[2] + 1; i <= 52 && i < card; ++i)
                if(av[i])
                    card = i;

        // Último caso: as duas cartas do príncipe são maiores que pelo menos duas da princesa
        // Mesmo caso do segundo IF: caso tenha sido alterado o valor de card, o laço não irá acontecer
        if(p[0] > s[1])
            for(int i = s[1] + 1; i <= 52 && i < card; ++i)
                if(av[i])
                    card = i;

        // Caso após os três testes o valor de card continue 53, então não será possível o príncipe vencer
        if(card == 53)
            card = -1;

        printf("%d\n", card);
    }

    return 0;
}
