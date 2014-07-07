// stdio.h -> cstdio
#include <cstdio>
#include <cstdlib>

namespace derp
{
    // default parameter
    void print(int n = 69)
    {
        std::printf("%d\n", n);
    }
}

namespace swag
{
    // no typedef
    struct entry
    {
        int num;
    };

    // reference
    void print(int& n)
    {
        derp::print(n);
        n -= 1;
    }

    // overload
    void print(entry& e)
    {
        print(e.num);
    }
}

void c_stil_alloc()
{
    // no implicit cast from void*
    int* array = (int*)malloc(2 * sizeof(int));
    // malloc -> free
    free(array);
}

void cpp_stil_alloc()
{
    // type safe
    int* array = new int[2];
    // new[] -> delete[]
    delete[] array;
}

void using_ns()
{
    // partial namespace import
    using swag::entry;
    entry e;
    e.num = 999;

    // complete namespace import
    using namespace derp;
    print(e.num); // derp::print();
}

// extending a namespace
namespace swag
{
    const int BROJ = 3;
}

const int BROJ = 4;

int main()
{
    // c++ style alloc
    swag::entry* obj = new swag::entry;
    obj->num = 123;
    swag::print(*obj);

    // naknadna deklaracija varijabli (C99/C++)
    for (int i = 0; i < 2; ++i)
        swag::print(obj->num);

    const int BROJ = 5;

    derp::print();
    derp::print(swag::BROJ);
    // scope resolution operator
    derp::print(::BROJ);
    derp::print(BROJ);
    // new -> delete
    delete obj;

    // bool type
    bool a = (BROJ < ::BROJ) || (swag::BROJ < ::BROJ);
    bool b = true, c = false;
    if (a && b && !c)
        std::puts("a && b && !c");
}
