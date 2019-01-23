#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

char ss[MAXN + 5];


int main() {
    stack<char> st; st.push('@');
    scanf("%s", ss);
    int ss_len = strlen(ss);
    int cnt = 0;
    for(int i = 0; i < ss_len; i++) {
        if(st.top() != ss[i]) {
            st.push(ss[i]);
        }
        else {
            cnt++;
            st.pop();
        }
    }
    if(cnt & 1) {
        puts("Yes");
    }
    else {
        puts("No");
    }
}