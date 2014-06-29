FLAGS="-Wall -ansi -std=c99 -pedantic"
for x in {a..j}
do
    gcc $FLAGS -o 1${x} 1${x}.c
done
gcc $FLAGS -o 1k 1k.c 1k2.c
gcc $FLAGS -o 1l 1l.c
gcc $FLAGS -o 1m 1m.c
