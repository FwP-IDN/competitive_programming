#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
// int counter = 0;

struct StructMath {
    int cas;
    long long N;
    long long prim[5761455];
    int notPrim[(100000000 >> 5) + 1];
    int sz_prim;
    static const int sqn = 10000;
    long long has, temp, x;

    long long p, a, r, d;

    void init() {
        d = p - 1;
        r = 0;
        while(!(d & (long long)1)) {
            d /= (long long)2;
            r++;
        }
    }

    __int128 pows(__int128 x, long long pan, __int128 mod) {
        __int128 y = 1;
        if(pan == 0) {
            return (__int128)1;
        }
        while(pan ^ (long long)1) {
            if(pan & (long long)1) {
                y *= x;
                y %= mod;
            }
            pan /= (long long)2;

            x *= x;
            x %= mod;
        }
        x *= y;
        x %= mod;
        return (__int128)x;
    }

    bool test() {
        __int128 num = pows(a, d, p);
        // cout << a << " " << d << " " << r << " " << (long long)num << "\n";

        if(num == (__int128)1) {
            return true;
        }
        for(int i = 0; i < r; i++) {
            if(num == (__int128)p-1) {
                return true;
            }
            num *= num;
            num %= (__int128)p;
        }
        return false;
    }

    bool millerRabin() {
        init();
        a = (((long long)RAND_MAX * rand() + rand()) % (p - 1)) + 1;
        if(!test()) {
            return false;
        }
        return true;
    }

    void staticInit() {
        sz_prim = -1;
        cas = 0;
        for(int i = 2; i <= sqn; ++i) {
            if(!(notPrim[i >> 5] >> (i & 31) & 1)) {
                prim[++sz_prim] = i;
            }
            else {
                continue;
            }
            for(int j = i * i; j <= 1e8; j += i) {
                notPrim[j >> 5] |= 1<<(j & 31);
                // counter++;
            }
            // cout << i << " " << counter << "\n";
            // string dum; cin >> dum;
        }
        for(int j = sqn + 1; j <= 1e8; ++j) {
            if(!(notPrim[j >> 5] >> (j & 31) & 1)) {
                prim[++sz_prim] = j;
            }
        }
        ++sz_prim;
    }

    void read() {
        scanf("%lld", &N);
    }

    void compute() {
        long long fly = N;
        char conn[4];
        int pan;
        has = 1;
        printf("%lld", N);
        strcpy(conn, " = ");
        for(int i = 0; i < sz_prim && prim[i] * prim[i] <= fly; i++) {
            if((fly % prim[i]) == 0) {
                pan = 0;
                printf("%s%lld", conn, prim[i]);
                conn[1] = '*';
                while((fly % prim[i]) == 0) {
                    fly /= prim[i];
                    ++pan;
                }
                if(pan > 1) {
                    printf("^%d", pan);
                }
                p = fly;
                if(fly < 1e8 && !(notPrim[fly >> 5] >> (fly & 31) & 1)) {
                    break;
                }
                else if(millerRabin()) {
                    break;
                }
            }
        }
        if(fly != 1) {
            printf("%s%lld", conn, fly);
        }
        printf("\n");
    }
} M;

int main() {
    int tes;
    int times = time(0);
    M.staticInit();
    // cout << "counter " << counter << "\n";
    // cout << time(0) - times << " vuk\n";
    scanf("%d", &tes);
    for(int cas = 1; cas <= tes; cas++) {
        M.read();
        M.compute();
    }
}