#include <cstdio>
#include <new> // std::nothrow_t, std::bad_alloc, std::nothrow

struct Exception
{
    Exception(const char* Error) : Error(Error) { }
    const char* Error;
};

struct DivByZero : public Exception
{
    DivByZero() : Exception("Nemoguce dijeliti s nulom!") { }
};

int Div(int a, int b)
{
    if (b == 0)
        throw DivByZero();
    return a / b;
}

int main()
{
    try
    {
        std::printf("%d\n", Div(9, 3));
        std::printf("%d\n", Div(1, 0));
        std::printf("%d\n", Div(8, 4));
    }
    catch (const Exception& e)
    {
        std::puts(e.Error);
    }

    try
    {
        //throw false;
        throw 1;
    }
    catch (int)
    {
        std::puts("Uhvatio int!");
    }
    // catch all
    catch (...)
    {
        std::puts("Uhvatio nesto...");
    }

    try
    {
        new int[-1];
    }
    catch (const std::bad_alloc& ba)
    {
        std::puts(ba.what());
    }


    int* ptr = new (std::nothrow) int[-1];
    if (!ptr)
        std::puts("Oops!");

    // crash!
    throw true;
}
