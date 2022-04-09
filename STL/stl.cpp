#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // pairs
    cout << endl << "Pairs: " << endl;
    pair<int, int> p1;
    pair<int, int> p2;
    p1.first = 1;
    p1.second = 2;
    p2.first = 3;
    p2.second = 4;
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;
    p1.swap(p2);
    // p1 = p2; // copies the p1 into p2
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;

    // vectors
    cout << endl << "Vectors: " << endl;
    vector<int> v1;
    vector<int> v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    // cout << v1.at(1) << endl;
    v1.pop_back();
    cout << "Size: " << v1.size() << endl;
    for (auto i = v1.begin(); i != v1.end(); i++)
    {
        cout << *i << " ";
    } cout << endl;

    // maps
    cout << endl << "Maps: (maps, unordered_map, multimap)" << endl;
    cout << endl << "map: " << endl;
    map<int, string> m;
    m[1] = "Sufyaan";
    m[3] = "Raj";
    m[2] = "Preethi";
    m[4] = "Rahul";
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << " -> " << i->second << endl;
    }
    cout << m.find(2)->second << endl;
    m.erase(3);
    m[4] = "Rohit";
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << " -> " << i->second << endl;
    }

    cout << endl << "unordered_map: " << endl;
    unordered_map<int, string> u_m;
    u_m[1] = "Sufyaan";
    u_m[2] = "Raj";
    u_m[3] = "Preethi";
    u_m[4] = "Rahul";
    for (auto i = u_m.begin(); i != u_m.end(); i++) {
        cout << i->first << " -> " << i->second << endl;
    }

    cout << endl << "multimap: " << endl;
    multimap<int, string> m_m;
    m_m.insert(make_pair(1, "Sufyaan"));
    m_m.insert(make_pair(1, "Rohit"));

    for (auto i = m_m.begin(); i != m_m.end(); i++) {
        cout << i->first << " -> " << i->second << endl;
    }

    // sets
    cout << endl << "Sets: (set, unordered_set, multiset)" << endl;
    cout << endl << "set: " << endl;
    set<string> s;
    s.insert("abc");
    s.insert("hij");
    s.insert("efg");
    s.insert("cde");
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    } cout << endl;
    cout << *(s.find("abc")) << endl; //what is the use of this, it returns the iterator for that value
    s.erase(--s.end());
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    } cout << endl;

    cout << endl << "Unordered_set: " << endl;
    unordered_set<string> s1;
    s1.insert("abc");
    s1.insert("hij");
    s1.insert("efg");
    s1.insert("cde");
    for (auto i = s1.begin(); i != s1.end(); i++) {
        cout << *i << " ";
    } cout << endl;
    cout << *(s1.find("abc")) << endl; //what is the use of this, it returns the iterator for that value
    s1.erase("efg");
    for (auto i = s1.begin(); i != s1.end(); i++) {
        cout << *i << " ";
    } cout << endl;

    cout << endl << "multiset: " << endl;
    multiset<string> s2;
    s2.insert("abc");
    s2.insert("hij");
    s2.insert("hij");
    s2.insert("hij");
    s2.insert("efg");
    s2.insert("efg");
    s2.insert("cde");
    for (auto i = s2.begin(); i != s2.end(); i++) {
        cout << *i << " ";
    } cout << endl;
    cout << *(s2.find("abc")) << endl; //what is the use of this, it returns the iterator for that value
    s2.erase(--s2.end());
    for (auto i = s2.begin(); i != s2.end(); i++) {
        cout << *i << " ";
    } cout << endl;

    // Stack and Queues
    cout << endl << "Stack: " << endl;
    stack<int> mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    while (!mystack.empty()) {
        cout << mystack.top() << " ";
        mystack.pop();
    } cout << endl;

    cout << endl << "Queue: " << endl;
    queue<int> myqueue;
    myqueue.push(1);
    myqueue.push(2);
    myqueue.push(3);
    myqueue.push(4);
    while (!myqueue.empty()) {
        cout << myqueue.front() << " ";
        myqueue.pop();
    } cout << endl;

    // algorithms
    // sort
    cout << endl << "Sort: " << endl;
    vector<int> arr = { 3, 1, 2, 9, 5, 4 };
    cout << "Before sorting: ";
    for (auto& it : arr) {
        cout << it << " ";
    } cout << endl;
    sort(arr.begin(), arr.end());
    cout << "After sorting: ";
    for (auto& it : arr) {
        cout << it << " ";
    } cout << endl;

    auto customComparator = [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.first;
    };
    vector<pair<int, int>> v3 = { {2,3}, {1,4}, {5,2}, {2,1}, {4,1} };
    cout << "Before sorting: ";
    for (auto& it : v3) {
        cout << "{" << it.first << "," << it.second << "}" << " ";
    } cout << endl;

    cout << "After sorting using custom comparator: ";
    sort(v3.begin(), v3.end(), customComparator);
    for (auto& it : v3) {
        cout << "{" << it.first << "," << it.second << "}" << " ";
    } cout << endl;

    // Min, Max, accumulate, count and find
    vector<int> v4 = { 2, 1, 5, 10, 11, 8, 7, 2 };
    cout << endl << "Min, Max, accumulate, count and find: " << endl;
    cout << "Vector: ";
    for (auto& it : v4) {
        cout << it << " ";
    }cout << endl;
    cout << "Min. element: " << *(min_element(v4.begin(), v4.end())) << endl;
    cout << "Max. element: " << *(max_element(v4.begin(), v4.end())) << endl;
    cout << "Accumulate (sum): " << accumulate(v4.begin(), v4.end(), 0) << endl;
    cout << "Count of 2: " << count(v4.begin(), v4.end(), 2) << endl;
    cout << "Find (returns iterator): " << *find(v4.begin(), v4.end(), 10) << endl;

    // All_of, any_of, and none_of
    vector<int> v5 = { -1, -2, -3 };
    cout << endl << "All_of, any_of, and none_of: " << endl;
    cout << "Vector: ";
    for (auto& it : v5) {
        cout << it << " ";
    }cout << endl;
    auto myfunc = [](int x) {return x > 0;};
    cout << "all_of (all greater than 0): " << all_of(v5.begin(), v5.end(), myfunc) << endl;
    cout << "any_of (anyone greater than 0): " << any_of(v5.begin(), v5.end(), myfunc) << endl;
    cout << "none_of (none greater than 0): " << none_of(v5.begin(), v5.end(), myfunc) << endl;


    return 0;
}