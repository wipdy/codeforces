#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int app[110];

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	memset(app, 0, (n + 5) * sizeof(int));
	for(int i = 0; i < a; i++) {
		int x;
		scanf("%d", &x);
		app[x] = 1;
	}

	for(int i = 0; i < b; i++) {
		int x;
		scanf("%d", &x);
		if(app[x] != 1) app[x] = 2;
	}

	for(int i = 1; i <= n; i++) printf("%d ", app[i]);

	return 0;	
}


