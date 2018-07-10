#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

string str;
set<char> sen;

int main(int argc, char** argv) {
	cin >> str;
	bool bisa = false;
	for(int i = 2; i < (int)str.length(); i++) {
		sen.clear();
		for(int j = i - 2; j <= i; j++) {
			if(str[j] != '.') {
				sen.insert(str[j]);
			}
		}
		if(sen.size() == 3) {
			bisa = true;
		}
	}
	if(bisa) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
}