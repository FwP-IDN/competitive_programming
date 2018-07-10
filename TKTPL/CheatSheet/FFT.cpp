#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define cd complex<double>
#define dbl double

vector<cd> FFT(vector<cd> inp, cd w, int sis) {
    if (sis == 1) {
        return inp;
    }
    int i;
    vector<cd> inpod(sis >> 1), inpev(sis >> 1);
    for (i = 0; i <= sis - 1; i += 2) {
        inpev[i >> 1] = inp[i];
    }
    for (i = 1; i <= sis - 1; i += 2) {
        inpod[i >> 1] = inp[i];
    }
    vector<cd> fev = FFT(inpev, w * w, sis >> 1);
    vector<cd> fod = FFT(inpod, w * w, sis >> 1);
    vector<cd> ff(sis);
    cd x = cd(1, 0);
    for(int i = 0; i < sis / 2; i++) {
        ff[i] = fev[i] + x * fod[i];
        ff[i + (sis >> 1)] = fev[i] - x * fod[i];
        x *= w;
    }
    return ff;
}

vector<cd> ar, br, cr, fa, fb, fc;
dbl pi = acos(-1), sud;

int main() {
    int tes, da = 0, db = 0, dc, n, m, aa, bb, sis;
    cin >> tes;
    while (tes--) {
        cin >> n;
        ar.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            cin >> aa;
            if (aa != 0) {
                da = i;
            }
            ar[i] = cd(aa, 0);
        }
        cin >> m;
        br.resize(m + 1);
        for(int i = 0; i <= m; i++) {
            cin >> bb;
            if (bb != 0) {
                db = i;
            }
            br[i] = cd(bb, 0);
        }
        sis = max(n, m) + 1;
        while (sis != (sis & (-sis))) {
            sis += (sis & (-sis));
        }
        sis <<= 1;
        ar.resize(sis);
        br.resize(sis);
        sud = 2 * pi;
        sud /= (dbl)sis;
        cd w(cos(sud), sin(sud));
        fa = FFT(ar, w, sis);
        fb = FFT(br, w, sis);
        fc.resize(sis);
        for(int i = 0; i < sis; i++) {
            fc[i] = fa[i] * fb[i];
        }
        cr = FFT(fc, (dbl)1 / w, sis);
        dc = da + db;
        for(int i = 0; i < sis; i++) {
            cr[i] /= (dbl)sis;
        }
        cout << dc << "\n";
        cout << fixed << setprecision(0) << cr[0].real();
        for(int i = 1; i <= dc; i++) {
            cout << fixed << setprecision(0) << " " << cr[i].real();
        }
        cout << "\n";
    }
}
