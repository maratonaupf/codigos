/*
 * Leonardo Deliyannis Constantin
 * URI 2406 - Expressões
*/

#include <stdio.h>
#include <stack>
using namespace std;
#define MAX 112345

bool isValid(const char *s){
    stack<char> st;
    for(int i = 0; s[i]; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(st.empty())
                return false;
            char a = st.top();
            if(!((a == '(' && s[i] == ')') || 
                (a == '[' && s[i] == ']') || 
                (a == '{' && s[i] == '}')))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    int T;
    scanf("%d", &T);
    char s[MAX];
    while(T--){
        scanf(" %s", s);
        printf("%c\n", isValid(s) ? 'S' : 'N');
    }
    return 0;
}
