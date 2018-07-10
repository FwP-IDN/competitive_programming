#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

struct StructMath {
    int cas;
    long long N;
    long long prim[664579];
    bitset<10000001> notPrim;
    int sz_prim, sz_f2;
    static const int sqn = 3162;
    pair<long long, int> f2[13];
    long long has, temp, x;


    void staticInit() {
        sz_prim = -1;
        cas = 0;
        for(int i = 2; i <= sqn; ++i) {
            if(!notPrim[i]) {
                prim[++sz_prim] = i;
            }
            for(int j = i * i; j <= 1e7; j += i) {
                notPrim[j] = 1;
            }
        }
        for(int j = sqn + 1; j <= 1e7; ++j) {
            if(!notPrim[j]) {
                prim[++sz_prim] = j;
            }
        }
        ++sz_prim;
    }

    void init() {
        sz_f2 = -1;
    }

    void read() {
        scanf("%lld", &N);
    }

    void compute() {
        long long fly = N;
        has = 1;
        for(int i = 0; i < sz_prim && prim[i] * prim[i] <= fly; i++) {
            if((fly % prim[i]) == 0) {
                f2[++sz_f2].f = prim[i];
                f2[sz_f2].s = 0;
                while((fly % prim[i]) == 0) {
                    fly /= prim[i];
                    ++f2[sz_f2].s;
                }
            }
        }
        if(fly != 1) {
            f2[++sz_f2].f = fly;
            f2[sz_f2].s = 1;
        }
        ++sz_f2;
        for(int i = 0; i < sz_f2; ++i) {
            temp = 0;
            x = 1;
            for(int j = f2[i].s * 2 + 1; j >= 1; j -= 2) {
                temp += (x * j);
                x *= f2[i].f;
            }
            has *= temp;
        }
    }

    void print() {
        printf("Case %d: %lld\n", ++cas, has);
    }
} M;

int main() {
    int tes;
    M.staticInit();
    scanf("%d", &tes);
    for(int cas = 1; cas <= tes; cas++) {
        M.init();
        M.read();
        M.compute();
        M.print();
    }
}