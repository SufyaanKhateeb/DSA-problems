#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isInTimeLimit(vector<int>& time, int n, int m,long long int mid) {
    int day = 1, timer = 0;
    for(int i = 0;i < n; i++) {
        if(timer + time[i] > mid) {
            day++;
            if(day > m || time[i] > mid) return false;
            timer = time[i];
        } else
            timer += time[i];
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long int s = 0;
    long long int sum = 0;
    for(int i = 0;i < n;i++)
        sum += time[i];
    long long int e = sum;
    while(s<=e) {
        long long int mid = s + (e - s)/2;
        if(isInTimeLimit(time,n,m,mid))
			e = mid - 1;
        else
            s = mid + 1;
    }
    return s;
}

int main() {
    vector<int> time = { 1, 2, 2, 3, 1 };
    int n = 5;
    int m = 3;
    cout << ayushGivesNinjatest(m,n,time);


    return 0;
}