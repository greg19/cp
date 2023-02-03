/*
 * Generatorka losowych spójnych grafów bez multikrawędzi i pętli. Najpierw
 * generujemy drzewo, a potem dodajemy krawędzie losowo na seta. Aby nie mieć
 * na secie zarówno krawędzi (a,b) jak i (b,a), w parze najpierw występuje
 * mniejszy wierzchołek.
 */

#include <bits/stdc++.h>
using namespace std;

// Zwraca losową liczbę z przedziału [a,b]
int rnd(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int n = rnd(5, 8);
    int m = rnd(n-1, 2*n);
    set<pair<int, int>> E;

    for (int i = 2; i <= n; i++)
        E.insert({rnd(1,i-1), i});

    while (E.size() < m) {
        int a = rnd(1, n-1);
        int b = rnd(a+1, n);
        E.insert({a,b});
    }

    cout << n << ' ' << m << '\n';
    for (auto [a,b] : E)
        cout << a << ' ' << b << '\n';
}
