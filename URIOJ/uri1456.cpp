/*
 * Leonardo Deliyannis Constantin
 * URI 1456 - Brainfuck
*/

#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
#define LEN 112345
#define MAX 30000

char mem[MAX];
char in[LEN], prog[LEN];
int ptr, reader, cmd, inputSize, progSize;
string out;
unordered_map<int, int> loop;

void run(int op){
    if(op == '>') ptr++;
    if(op == '<') ptr--;
    if(op == '+') mem[ptr]++;
    if(op == '-') mem[ptr]--;
    if(op == '.') out.push_back(mem[ptr]);
    if(op == ',') mem[ptr] = (reader < inputSize) ? in[reader++] : 0;
    if(op == '[' && mem[ptr] == 0) cmd = loop[cmd];
    if(op == ']') cmd = loop[cmd] - 1;
    if(op == '#') out.append(mem, mem+10);
    cmd++;
}

int main(){
    int T, tc;
    fgets(in, LEN, stdin);
    sscanf(in, "%d", &T);
    for(tc = 1; tc <= T; tc++){
        fgets(in, LEN, stdin);
        fgets(in, LEN, stdin);
        fgets(prog, LEN, stdin);
        printf("Instancia %d\n", tc);
        inputSize = strlen(in) - 1;
        progSize = strlen(prog) - 1;
        cmd = reader = 0;
        out.clear();
        stack<int> st;
        for(int i = 0; i < progSize; i++){
            if(prog[i] == '[') st.push(i);
            if(prog[i] == ']'){
                loop[i] = st.top();
                loop[st.top()] = i;
                st.pop();
            }
        }
        memset(mem, 0, sizeof(mem));
        while(cmd < progSize){
            run(prog[cmd]);
        }
        printf("%s\n\n", out.c_str());
    }
    return 0;
}
