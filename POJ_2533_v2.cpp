# longest increasing sub-sequence

#include <iostream>

#define maxn 1010

using namespace std;

int arr[maxn];
int len[maxn];
int last[maxn];
int n;

int main() {
	cin >> n;
	for (int i=1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i=1; i <= n; i++) {
		len[i] = 1;
		last[i] = -1;
	}
	for (int i=2; i <= n; i++) {
		int maxlen = 1;
		int ix = -1;
		for (int j=1; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (ix == -1 || len[j] > maxlen) {
					ix = j;
					maxlen = len[j];
				}
			}
		}
		if (ix != -1) {
			len[i] = len[ix] + 1;
			last[i] = ix;
		}
	}
	
	int maxlen = len[1];
	for (int i=2; i <= n; i++) {
		if (len[i] > maxlen) {
			maxlen = len[i];
		}
	}
	//cout << "hello\n";
	cout << maxlen << endl;
	return 0;
}
