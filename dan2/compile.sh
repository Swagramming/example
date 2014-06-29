FLAGS="-Wall -Werror -Wfatal-errors -std=c99 -pedantic"
for x in {a..m}
do
    gcc $FLAGS -o 2${x} 2${x}.c -lm
done
