#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1000000000

int n, k;
int a[210], b[210], c[210];

int getM(int *a) {
	int ret = -INF;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		if(sum < 0) sum = a[i];
		else sum += a[i];

		if(sum > ret) ret = sum;
	}

	return ret;
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];

	int ans = getM(a);
	for(int l = 1; l <= n; l++) {
		for(int r = l; r <= n; r++) {
			int nb = 0;
			for(int i = l; i <= r; i++) b[nb++] = a[i];

			int nc = 0;
			for(int i = 1; i < l; i++) c[nc++] = a[i];
			for(int i = r + 1; i <= n; i++) c[nc++] = a[i];

			sort(b, b + nb); sort(c, c+ nc);
			for(int i = 0, ib = 0, ic = nc - 1; i < k && ib < nb && ic >= 0; i++, ib++, ic--) {
				if(b[ib] < c[ic]) {
					int tmp = b[ib];
					b[ib] = c[ic];
					c[ic] = tmp;
				}else break;
			}

			int sum = 0;
			for(int i = 0; i < nb; i++) sum += b[i];
			if(sum > ans) ans = sum;
		}
	}

	cout << ans << endl;

	return 0;
}
