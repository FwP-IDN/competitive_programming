#include <bits/stdc++.h>
using namespace std;


struct tikus {
	string op;
	string leftChild;
	string rightChild;
};

tikus node(string A, string op, string B) {
	tikus ret;
	ret.op = op;
	ret.leftChild = A;
	ret.rightChild = B;
	return ret;
}

map<string, tikus> tree;



void walk(string nameNode, bool needPar) {
	tikus thisNode = tree[nameNode];
	if(thisNode.op == "") {
		cout << nameNode;
		return;
	}
	if(needPar) {
		cout << "(";
	}
	tikus leftNode = tree[thisNode.leftChild];
	tikus rightNode = tree[thisNode.rightChild];
	bool leftPar, rightPar;
	
	if(leftNode.op == "+" && thisNode.op == "*") {
		leftPar = 1;
	}
	else {
		leftPar = 0;
	}

	if(thisNode.op == "*") {
		if(rightNode.op == "") {
			rightPar = 0;
		}
		else {
			rightPar = 1;
		}
	}
	else {
		if(rightNode.op == "+") {
			rightPar = 1;
		}
		else {
			rightPar = 0;
		}
	}

	walk(thisNode.leftChild, leftPar);
	cout << thisNode.op;
	walk(thisNode.rightChild, rightPar);

	if(needPar) {
		cout << ")";
	}
}



int main() {
	int tes, N;
	string name, A, B, op;
	cin >> tes;
	for(int cas = 1; cas <= tes; cas++) {
		cin >> N;
		while(N--) {
			cin >> name >> op >> A >> op >> B;
			tree[name] = node(A, op, B);
		}
		cout << "Expression #" << cas << ": ";
		walk(name, 0);
		cout << "\n";
	}
}