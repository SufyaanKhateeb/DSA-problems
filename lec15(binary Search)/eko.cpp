#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canObtainEnough(vector<int>& height, int n, int m, long long int mid) {
	long long int woodsum = 0;
	for (int i = 0; i < n; i++) {
		if (height[i] > mid) {
			woodsum += (height[i] - mid);
		}
		if (woodsum >= m)
			return true;
	}
	return false;

}

long long int minHeightRequired(vector<int>& height, int n, int m) {
	long long int s = 0;
	sort(height.begin(), height.end());
	long long int e = height[height.size() - 1];
	while (s <= e) {
		long long int mid = s + (e - s) / 2;
		if (canObtainEnough(height, n, m, mid))
			s = mid + 1;
		else
			e = mid - 1;
	}
	return e;
}

int main() {
	vector<int> height = { 4, 42, 40, 26, 46 };
	int n = 5;
	int m = 20;
	cout << minHeightRequired(height, n, m);

	return 0;
}