#include <bits/stdc++.h>
using namespace std;

char command[16];
char resp[16];

int main() {
    while(true) {
        scanf("%s", command);
        if(!strcmp(command, "start")) {
            int msb = 0;
            while(true) {
                printf("? %d %d\n", (1<<msb)-1, (1<< (msb+1))-1);
                fflush(stdout);
                scanf("%s", resp);
                if(!strcmp(resp, "x")) {
                    break;
                }
                else if(!strcmp(resp, "y")) {
                    // lanjut bor
                    msb++;
                }
            }
            int ans = (1 << msb);
            for(int i = msb; i >= 1; i--) {
                printf("? %d %d\n", ans+(1<<i)-1,ans+(1<<(i-1))-1);
                fflush(stdout);
                scanf("%s", resp);
                if(!strcmp(resp, "x")) {
                    // njuk?
                }
                else if(!strcmp(resp, "y")) {
                    ans |= (1 << (i-1));
                }
            }
            printf("! %d\n", ans);
            fflush(stdout);
        }
        else if(!strcmp(command, "end") || !strcmp(command, "mistake")) {
            return 0;
        }
    }
}