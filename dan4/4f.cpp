// ZADATAK: Napravite dinamicni queue
#include <cstdio>

template <typename T, std::size_t N>
class Queue
{
public:
    class BadOp {};
    class BadEnqueue {};
    class BadDequeue {};

    Queue() : Front(0), Back(0)
    {
    }

    void Enqueue(T Elem)
    {
        if (PlusOne(Back) == Front)
            throw BadEnqueue();
        A[PostIncrement(Back)] = Elem;
    }

    T Dequeue()
    {
        if (Front == Back)
            throw BadDequeue();
        return A[PostIncrement(Front)];
    }

    bool Empty() const
    {
        return Front == Back;
    }

private:
    std::size_t PostIncrement(std::size_t& Val)
    {
        std::size_t Ret = Val;
        Val = PlusOne(Val);
        return Ret;
    }

    std::size_t PlusOne(std::size_t Val)
    {
        Val++;
        if (Val == N + 1)
            Val = 0;
        return Val;
    }

    std::size_t Front, Back;
    T A[N];
};

int main()
{
    Queue<int, 3> Q;

    try
    {
        Q.Enqueue(1);
        Q.Enqueue(3);
        Q.Enqueue(4);
        while (!Q.Empty())
            std::printf("%d\n", Q.Dequeue());
    }
    catch (Queue<int, 3>::BadOp& e)
    {
        std::puts("Queue::BadOp caught!");
    }
}
