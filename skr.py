import os;

os.system("g++ wzo.cpp -o wzo.e -O3")
os.system("g++ brt.cpp -o brt.e -O3")
os.system("g++ gen.cpp -o gen.e -O3")

i = 1
while True:
    print("Test numer", i)
    os.system("./gen.e > tst.in")
    os.system("./wzo.e < tst.in > tst.wzo.out")
    os.system("./brt.e < tst.in > tst.brt.out")
    if os.system("diff tst.wzo.out tst.brt.out"):
        break
    i = i+1

print("Zabugowane :(\nDane wejściowe w pliku tst.in")
