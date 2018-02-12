#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;
using std::next_permutation;

int main()
{
    int n;
    char s[11];

    scanf("%d", &n);
    while (n--)
    {
        getchar();
        scanf("%s", &s);

        sort(s, s + strlen(s));
        
        printf("%s\n", s);
        while(next_permutation(s, s + strlen(s)))
            printf("%s\n", s);

        printf("\n");
    }

    return 0;
}
