#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class String {
private:
    char* str;
    int len;
public:
    String() : str(new char[1]), len(0) {
        str[0] = '\0';
    }
    String(char* str2) {
        len = strlen(str2);
        str = new char[len + 1];
        strcpy(str, str2);
    }
    String(const String& str2) {
        str = new char[str2.len + 1];
        len = str2.len;
        strcpy(str, str2.str);
    }
    String(String&& str2) {
        str = str2.str;
        len = str2.len;
        str2.str = nullptr;
        str2.len = 0;
    }
    String& operator=(char *str2) {
        char *temp = this->str;
        len = strlen(str2);
        str = new char[len+1];
        strcpy(str,str2);
        delete[] temp;
        return *this;
    }
    String& operator=(const String& str2) {
        if (this != &str2) {
            char* temp = this->str;
            len = str2.len;
            str = new char[len + 1];
            strcpy(str, str2.str);
            delete[] temp;
        }
        return *this;
    }
    String& operator=(String&& str2) {
        str = str2.str;
        len = str2.len;
        str2.len = 0;
        str2.str = nullptr;
        return *this;
    }
    int length() {
        return len;
    }
    friend ostream& operator<<(ostream& out, const String& str);
    friend istream& operator<<(istream& in, const String& str);
    ~String() {
        if(str) {
            delete[] str;
            len = 0;
        }
    }
};

ostream& operator<<(ostream& out, const String& str) {
    if(str.str)
        cout << str.str;
    return out;
}

istream& operator<<(istream& in, const String& str) {
    cin >> str.str;
    return in;
}

int main() {
    String s1;
    cout << s1 << endl;
    
    String s2 = "helloworld";
    cout << s2 << endl;
    
    String s3 = s2;
    cout << s3 << endl;
    
    s1 = s2;
    cout << s1 << endl;

    s2 = "See this too";
    cout << s2 << endl;

    String s4 = std::move(s3);
    cout << s4 << endl;
    cout << s3 << endl;

    s1 = std::move(s2);
    cout << s1 << endl;
    cout << s2 << endl;


    return 0;
}