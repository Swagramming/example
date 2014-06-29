#include <cstdio>
#include <cstdlib>

struct Vector2f
{
    Vector2f(float x, float y) : x(x), y(y) { }
    float x, y;
};

struct Vector2i
{
    Vector2i(int x, int y) :  x(x), y(y) { }

    // typecast overload
    operator Vector2f()
    {
        return Vector2f(x, y);
    }

    int x, y;
};

// global operator overload
Vector2i operator+(const Vector2i& First, const Vector2i& Second)
{
    return Vector2i(First.x + Second.x, First.y + Second.y);
}

// global operator new overload
void* operator new(std::size_t sz)
{
    std::printf("global op new called, size = %lu\n", sz);
    return std::malloc(sz);
}

// global operator delete overload
void operator delete(void* ptr)
{
    std::puts("global op delete called");
    std::free(ptr);
}

struct Something
{
    // additional placement forms (string for example)
    static void* operator new(std::size_t sz, const char* string)
    {
        std::printf("local op new called: %s, size = %lu\n", string, sz);
        return ::operator new(sz);
    }

    static void* operator new[](std::size_t sz)
    {
        std::printf("local op new[] called, size = %lu\n", sz);
        return ::operator new(sz);
    }

    static void operator delete(void* ptr)
    {
        std::puts("local op delete called");
        ::operator delete(ptr);
    }

    static void operator delete[](void* ptr)
    {
        std::puts("local op delete[] called");
        ::operator delete[](ptr);
    }
};

void Func(Vector2f Vec)
{
    std::printf("(%f, %f)\n", Vec.x, Vec.y);
}

int main()
{
    Vector2i Vec1(2, 3), Vec2(4, 5);
    // implicit cast from Vector2i to Vector2f
    Func(Vec1 + Vec2);

    Something* ptr = new ("DERP") Something, *ptr2 = new Something[2];
    delete ptr; delete[] ptr2;
}
