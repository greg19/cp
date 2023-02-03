#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    cout << rand() % 100 << '\n';
}
