// ZADATAK: Napravite dinamicni stack
#include <cstdio>

template <typename T, std::size_t N>
class Stack
{
public:
    class BadOp {};
    class BadPush : BadOp {};
    class BadPop : BadOp {};

    Stack() : Pos(0)
    {
    }

    void Push(T Elem)
    {
        if (Pos == N)
            throw BadPush();
        A[Pos++] = Elem;
    }

    T Pop()
    {
        if (Empty())
            throw BadPop();
        return A[--Pos];
    }

    bool Empty() const
    {
        return Pos == 0;
    }

private:
    std::size_t Pos;
    T A[N];
};

int main()
{
    Stack<int, 3> S;

    try
    {
        S.Push(1);
        S.Push(3);
        S.Push(2);
        while (!S.Empty())
            std::printf("%d\n", S.Pop());
    }
    catch (Stack<int, 3>::BadOp& e)
    {
        std::puts("Stack::BadOp caught!");
    }
}
