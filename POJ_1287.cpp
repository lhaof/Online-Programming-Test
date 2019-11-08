// minimum spanning tree
// POJ 1287

#include <iostream>

#define maxn 55
#define maxw 1000

using namespace std;

int P, R;
int mat[maxn][maxn];

int MST() {
	int total_weights = 0;
	bool inTree[maxn];
	for (int i=0; i <= P; i++) {
		inTree[i] = false;
	}
	
	inTree[1] = true;
	int minDist[maxn];
	for (int i=2; i <= P; i++) {
		if (mat[1][i] != -1) {
			minDist[i] = mat[1][i];
		} else {
			minDist[i] = -1;
		}
	}
	
	for (int i=2; i <= P; i++) {
		int next_node = -1;
		int min_dist = -1;
		for (int j=2; j <= P; j++) {
			if (inTree[j]) continue;
			if (minDist[j] != -1) {
				if (next_node == -1 || minDist[j] < min_dist) {
					next_node = j;
					min_dist = minDist[j];
				}
			}
		}
		if (next_node == -1) break;
		inTree[next_node] = true;
		total_weights += min_dist;
		for (int j=2; j <= P; j++) {
			if (!inTree[j] && mat[next_node][j] != -1) {
				if (minDist[j] == -1 || mat[next_node][j] < minDist[j]) {
					minDist[j] = mat[next_node][j];
				}
			}
		}
	}
	return total_weights;
}

int main() {
	while (cin >> P) {
		if (!P) break;
		cin >> R;
		for (int i=0; i <= P; i++) {
			for (int j=0; j <= P; j++) {
				mat[i][j] = -1;
			}
		}
		
		for (int i=0; i < R; i++) {
			int u,v,w;
			cin >> u >> v >> w;
			if (mat[u][v] == -1) {
				mat[u][v] = mat[v][u] = w;
			} else if (w < mat[u][v]) {
				mat[u][v] = mat[v][u] = w;
			}
		}
		int ans = MST();
		cout << ans << endl;
	}
	return 0;
}
