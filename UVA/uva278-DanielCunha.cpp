#include <cstdio>
#include <algorithm>
#include <cmath>

using std::min;

int main()
{
    int N, x, y, t;
    char p;   

    scanf("%d", &N);
    while(N--)
    {
        getchar();
        scanf("%c %d %d", &p, &x, &y);

        if(p == 'r' || p == 'Q')
            t = min(x, y);
        else if(p == 'k')
            t = ceil((x * y)/2.0);
        else if(p == 'K')
            t = ((x + 1)/2) * ((y + 1) / 2);

        printf("%d\n", t);
    }
}
