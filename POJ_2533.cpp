# longest increasing sub-sequence

#include <iostream>
#include <vector>

#define maxn 10010

using namespace std;

int arr[maxn];
int end_of_len[maxn];
int last[maxn];
int n;

int main() {
	cin >> n;
	for (int i=1;i <= n;i++) {
		cin >> arr[i];
	}
	end_of_len[1] = 1;
	last[1] = -1;
	
	int maxlen = 1;
	for (int i=2;i <= n;i++) {
		if (arr[i] < arr[end_of_len[1]]) {
			last[i] = -1;
			end_of_len[1] = i;
		} else if (arr[i] > arr[end_of_len[maxlen]]) {
			last[i] = end_of_len[maxlen];
			maxlen++;
			end_of_len[maxlen] = i;
		} else {
			int lbound = 1;
			int ubound = maxlen;
			int mid;
			while (lbound < ubound) {
				mid = (lbound + ubound + 1)/2;
				int k = end_of_len[mid];
				if (arr[k] > arr[i]) {
					ubound = mid-1;
				} else if (arr[k] == arr[i]) {
					ubound = mid-1;
				} else {
					lbound = mid;
				}
			}
			int k = end_of_len[lbound];
			if (arr[k] < arr[i]) {
				last[i] = k;
				int kk = end_of_len[lbound+1];
				if (kk > 0 && arr[kk] > arr[i]) {
					end_of_len[lbound+1] = i;
				}
			}
		}
		/*
		cout << "display: \n";
		for (int j=1;j <= n;j++) {
			cout << end_of_len[j] << " ";
		}
		cout << endl;
		for (int j=1;j <= n;j++) {
			cout << last[j] << " ";
		}
		cout << endl;
		*/
	}
	cout << maxlen;
	
	/*
	vector<int> vec;
	int ix = end_of_len[maxlen];
	while (true) {
		cout << "ix: " << ix << endl;
		vec.push_back(arr[ix]);
		if (last[ix] == -1) {
			break;
		} else {
			ix = last[ix];
		}
	}
	vec.size()-1;i >= 0;i--) {
		cout << vec[i] << " ";
	}
	cout << endl;
	*/
	return 0;
}
