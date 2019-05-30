#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#include "../src/util/pch.h"

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<string> data;
    int n = 0;
    int q = 0;
    cin >> n >> q;
    string temp;
    int i = 0;
    while(getline(cin, temp) && n > i++){
        data.push_back(temp);
        // cout << typeid(data[i]).name() << " -- " << endl;
    }
    cout << data.size() << " - " << data;
    return 0;
}
