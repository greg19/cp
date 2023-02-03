# Testowanie

## Skrypt testujący

[Skrypt w bashu](skr.sh)

[Skrypt w pythonie](skr.sh)

Oba skrypty na początku kompilują wszystkie binarki, można równie dobrze usunąć
te linijki i kompilować samemu przed użyciem skryptu.

Skrypt w pythonie jest tak na prawdę skryptem w bashu wklejonym do pythona, nie
ma jakiś szczególnych zalet. Ale jak ktoś się boi basha to python jest równie
dobry.

## Generatorka testów

Warto testować na małych testach, z liczbami rzędu 5-15. Dużo łatwiej wtedy
wylosować jakiś przypadeg brzegowy. Jak nam przechodzą testy małe, to możemy
sukcesywnie zwiększać rozmiar, chociaż jak na małych działa to na dużych pewnie
też będzie.

Trzeba pamiętać że na małych testach możemy nie wychwycić overflow, a niektóre
bruty mogą w ogóle się nie kończyć na testach które powodują overflow.

### Seed

W generatorce należy pamiętać żeby nie używać `time(0)` - liczba ta zmienia się
zaledwie co sekundę, więc będziemy dostawać jeden nowy test na sekundę, a
chcemy pewnie tak 10-50. 

#### High resolution clock

Jako seed można użyć
`chrono::high_resolution_clock::now().time_since_epoch().count()`. Ma
wystarczającą rozdzielczość, żeby za każdym razem dać nam inny test.

#### Z linii poleceń

Można też brać seed jako argument do programu, z linii poleceń:

```cpp
// gen.cpp
int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    // ...
}
```

```sh
./gen.e $i > tst.in
```

## Generowanie skomplikowanych struktur

Aby wygenerować drzewo można użyć [tej metody](tree.cpp).

Generowanie bardzie zaawansowanych struktur może wydawać się trudne, choć wcale
takie nie jest. Przykład generowania grafu można znaleźć [tutaj](graph.cpp).

