//github:https://github.com/jspw

#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ull unsigned long long


//Sort array in discending order (n to 1)
bool decSort(ll a, ll b) {
    return a > b;
}


//find the maximum element of a array
ll llmax_of_array(ll a[], ll n) {
    ll mx = a[0];
    for (ll i = 0;i < n;i++) {
        if (a[i] > mx) mx = a[i];
    }
    return mx;
}

ll max_of_array(int a[], int n) {
    ll mx = a[0];
    for (ll i = 0;i < n;i++) {
        if (a[i] > mx) mx = a[i];
    }
    return mx;
}


//find the minimum element of a array
ll llmin_of_array(ll a[], ll n) {
    ll mn = a[0];
    for (ll i = 0;i < n;i++) {
        if (a[i] < mn) mn = a[i];
    }
    return mn;
}

ll min_of_array(int a[], int n) {
    ll mn = a[0];
    for (ll i = 0;i < n;i++) {
        if (a[i] < mn) mn = a[i];
    }
    return mn;
}


bool isPrime(ll n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (ll i = 2;i * i <= n;i++) {
        if (n % i == 0)return false;
    }
    return true;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif

    int arr[] = { 5, 4, 10, 2, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> varr = { 5, 4, 10, 2, 11 };
    sort(varr.begin(), varr.end(), decSort);
    for (int i = 0; i < varr.size(); i++)
    {
        cout << varr[i] << " ";
    }
    cout << endl;
    cout << min_of_array(arr, size) << endl;
    cout << gcd((int)10,(int)20) << endl;
    cout << lcm((int)10,(int)20) << endl;
    return 0;
}
