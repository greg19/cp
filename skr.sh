g++ wzo.cpp -o wzo.e -O3
g++ brt.cpp -o brt.e -O3
g++ gen.cpp -o gen.e -O3

i = 1
while true; do
    echo "Test numer $i"
    ./gen.e > tst.in
    ./wzo.e < tst.in > tst.wzo.out
    ./brt.e < tst.in > tst.brt.out
    # Ze względu na leniwą ewaluację, wyrażenia x || y można używać jak ifa.
    # Często spotykany trik w bashu, bo ify wyglądają okropnie.
    diff tst.wzo.out tst.brt.out || break
    ((i++))
done

echo "Zabugowane :("
echo "Dane wejściowe w pliku test.in"
