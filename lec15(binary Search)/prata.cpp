#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool test(vector<int>& rank, int n, int m, int mid) {
    int totaldishes = 0;
    int dishes;
    for (int i = 0; i < n; i++)
    {
        dishes = (-1 + sqrt(1 + (8 * mid) / rank[i])) / 2;
        cout << dishes << endl;
        totaldishes += dishes;
        if (totaldishes >= m) return true;
    }
    cout << totaldishes << endl;
    return false;
}

// solving  ---time = rank(prata * (prata + 1))/2--- , we get
// prata = (-1 + sqrt(1 - 8*(time/rank)))/2
bool cancookintime(vector<int>& rank, int n, int m, int mid) {
    int totaldishes = 0;
    int dishes;
    for (int i = 0; i < n; i++)
    {
        dishes = (-1 + sqrt(1 + (8 * mid) / rank[i])) / 2;
        // cout << dishes << endl;
        totaldishes += dishes;
        if (totaldishes >= m) return true;
    }
    // cout << totaldishes << endl;
    return false;
}

int minCookTime(vector<int>& rank, int m)
{
    long long int s = 0;
    //     sort(rank.begin(),rank.end());
    long long int e = (rank[rank.size() - 1]) * (m) * (m + 1) / 2;
    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        if (cancookintime(rank, rank.size(), m, mid)) {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return s;
}


int main() {
    vector<int> rank = { 1, 2, 3, 4 };
    int n = 4;
    int m = 11;
    // cout << test(rank,n,m,12);
    cout << minCookTime(rank, m);

    return 0;
}
