#include <bits/stdc++.h>
using namespace std;

char A[2005], B[10005];
char IMPOS[] = "Impossible";

void work() {
	static int cas = 0;
	scanf("%s", A);
	int A_len = strlen(A);
	int occ = -1;
	for(int i = 1; i < A_len; i++) {
		if(A[i] == A[0]) {
			occ = i;
			break;
		}
	}
	if(occ == -1) {
		strcpy(B, IMPOS);
	}
	else {
		strncpy(B, A, occ);
		strcpy(B+occ, A);
		if(!strncmp(B, A, A_len)) {
			strcpy(B, IMPOS);
		}
	}
	printf("Case #%d: %s\n", ++cas, B);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		work();
	}
}