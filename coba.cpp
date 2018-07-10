#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int dr[4] = { -1, 1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };
int C, ansL[14], ansSr[14], ansSc[14], ansEr[14], ansEc[14];
bool P[4][100], ansP[14][4][100];

bool valid(int r, int c, int pr, int pc) {
    if (P[r][c])
        return false;
    for (int d = 0; d < 4; d++) {
        int r2 = r + dr[d];
        int c2 = c + dc[d];
        if (r2 < 0 || r2 >= 4 || c2 < 0 || c2 >= C || (r2 == pr && c2 == pc))
            continue;
        if (P[r2][c2])
            return false;
    }
    return true;
}

void rec(int sr, int sc, int r, int c, int len) {
    P[r][c] = true;
    if (len > ansL[C]) {
        ansL[C] = len;
        ansSr[C] = sr;
        ansSc[C] = sc;
        ansEr[C] = r;
        ansEc[C] = c;
        memcpy(ansP[C], P, sizeof P);
    }
    for (int d = 0; d < 4; d++) {
        int r2 = r + dr[d];
        int c2 = c + dc[d];
        if (r2 < 0 || r2 >= 4 || c2 < 0 || c2 >= C || !valid(r2, c2, r, c))
            continue;
        rec(sr, sc, r2, c2, len + 1);
    }
    P[r][c] = false;
}

const int rStrt[3] = { 0, 4, 5 };
const char rPat[4][7] = {
    ".#....",
    "...###",
    "###...",
    "....#."
};

int N;

int main() {
    cin >> N;
    while (N--) {
        cin >> C;
        int rep = max((C - 8) / 6, 0);
        C -= rep * 6;
        if (!ansL[C]) {
            memset(P, false, sizeof P);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < C; j++) {
                    rec(i, j, i, j, 0);
                }
            }
        }
        cout << (ansL[C] + rep * 16) << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < C; j++) {
                if (i == ansSr[C] && j == ansSc[C]) {
                    cout << "S";
                }
                else if (i == ansEr[C] && j == ansEc[C]) {
                    cout << "E";
                }
                else
                    cout << (ansP[C][i][j] ? '.' : '#');
                if (j == rStrt[C % 3]) {
                    for (int k = 0; k < rep; k++) {
                        cout << rPat[i];
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}