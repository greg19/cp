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

W generatorce należy pamiętać żeby nie używać `time(0)` - liczba ta zmienia się
zaledwie co sekundę, więc będziemy dostawać jeden nowy test na sekundę, a
chcemy pewnie tak 10-50. Zamiast tego, jako argument do `srand` można użyć
`chrono::high_resolution_clock::now().time_since_epoch().count()`.

