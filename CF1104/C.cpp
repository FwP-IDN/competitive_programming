#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

char ss[MAXN + 5];

int main() {
    int cnt0 = 0;
    int cnt1 = 0;
    scanf("%s", ss);
    int ss_len = strlen(ss);
    for(int i = 0; i < ss_len; i++) {
        if(ss[i] == '0') {
            if(cnt0 == 0) {
                puts("1 1");
            }
            else if(cnt0 == 1) {
                puts("3 1");
            }
            cnt0++; cnt0 &= 1;
        }
        else if(ss[i] == '1') {
            if(cnt1 == 0) {
                puts("1 2");
            }
            else if(cnt1 == 1) {
                puts("2 2");
            }
            else if(cnt1 == 2) {
                puts("3 2");
            }
            else if(cnt1 == 3) {
                puts("4 2");
            }
            cnt1++; cnt1 &= 3;
        }
    }
}