#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // creation
    map<string, int> m;
    // unordered_map<string, int> m;

    // insertion
    // 1
    pair<string, int> p = make_pair("sufyaan", 3);
    m.insert(p);

    // 2
    pair<string, int> p1("sufyaan", 3);
    m.insert(p1);

    // 3
    m["mera"] = 1;

    // updates
    m["mera"] = 10;

    //search
    cout << m["mera"] << endl;
    cout << m.at("sufyaan") << endl;


    // cout << m.at("unknowKey") << endl;   // will throw uncaught exception
    cout << m["unknowKey"] << endl;
    // cout << m.at("unknowKey") << endl;   // will not throw anything

    // size
    cout << m.size() << endl;

    // to check presence
    cout << m.count("sufyaan") << endl;
    cout << m.count("notpresent") << endl;

    // erase
    m.erase("sufyaan");
    cout << m.size() << endl;

    // iterate over
    for (auto i : m) {
        cout << i.first << " -> " << i.second << endl;
    }

    // using iterator
    map<string, int> ::iterator it = m.begin();
    // unordered_map<string, int> ::iterator it = m.begin();

    for (; it != m.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }

    return 0;
}