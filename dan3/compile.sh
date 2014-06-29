FLAGS="-Wall -Werror -Wfatal-errors -pedantic"
g++ $FLAGS -o 3a 3a.cpp
g++ $FLAGS -o 3b 3b.cpp 3b2.cpp
for x in {c..f}
do
    g++ $FLAGS -o 3${x} 3${x}.cpp
done
