/*
 * Generatorka losowych drzew. Iteruje się po wierzchołkach, dołączając kolejne
 * wierzchołki do losowego miejsca w drzewie.
 *
 * Jest to najprostsza metoda, chociaż ma swoje wady (np. średnica takiego
 * drzewa będzie rzędu logn). Mimo to na konkursy spokojnie wystarczy.
 */

#include <bits/stdc++.h>
using namespace std;

// Zwraca losową liczbę z przedziału [a,b]
int rnd(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n = rnd(5, 10);
    cout << n << '\n';
    for (int i = 2; i <= n; i++)
        cout << i << ' ' << rnd(1, i-1) << '\n';
}
