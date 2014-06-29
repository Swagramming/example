#include <cstddef>
#include <cstring>
#include <cstdio>

// function template
// typename
template <typename T>
void Swap(T* first, T* second)
{
    T temp = *first;
    *first = *second;
    *second = temp;
}

// struct template
template <typename T>
struct Vector2
{
    Vector2<T>(T x, T y) : x(x), y(y) { }
    Vector2<T> operator+(Vector2<T> Other)
    {
        return Vector2<T>(x + Other.x, y + Other.y);
    }

    T x;
    T y;
};

// template typedef
typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;

// class template
// class == typename
// multiple parameter
template <class T, class U>
class Pair
{
public:
    T first;
    U second;
};

template <typename T>
class Base
{
public:
    Base<T>(T a) : a(a) { }

private:
    T a;
};

// inheriting from template
template <typename T, typename U, typename V>
class Triplet : public Pair<T, U>
{
public:
    V third;
};

class ByteBuffer
{
public:
    ByteBuffer() : pData(0), Size(0) { }
    ~ByteBuffer() { delete[] pData; }

    template <class T>
    void Write(T Any)
    {
        Write(&Any, sizeof(Any));
    }

    // overload
    void Write(char* pData, std::size_t Size)
    {
        // this pointer
        char* pNewData = new char[this->Size + Size];
        // OPREZ: this->pData je nullptr kada je this->Size 0
        std::memcpy(pNewData, this->pData, this->Size);
        std::memcpy(pNewData + this->Size, pData, Size);
        this->Size += Size;
        delete[] this->pData;
        this->pData = pNewData;
    }

    // returning *this to chain operators
    template <class T>
    ByteBuffer& operator<<(T Any)
    {
        Write(Any);
        return *this;
    }

    const char* GetData() const { return pData; }

private:
    char* pData;
    std::size_t Size;
};

/* PITANJE ZA 100 BODOVA:
 * Što bi bilo je ovdje ByteBuffer a ne ByteBuffer* ?
 * */
// template specialization
template <>
void ByteBuffer::Write<ByteBuffer*>(ByteBuffer* Buff)
{
    Write(Buff->pData, Buff->Size);
}

template <>
void ByteBuffer::Write<const char*>(const char* pString)
{
    // including '\0' terminator!
    while (*pString)
        Write(*pString++);
}

template <typename T, int SIZE>
struct Buffer
{
    T Array[SIZE];
};

int main()
{
    // instantiating a template
    Triplet<int, float, bool> TestTriplet;
    TestTriplet.first = 3;
    TestTriplet.second = 4.5f;
    TestTriplet.third = false;
    Vector2i TestVector(3, 6);
    Swap(&TestVector.x, &TestVector.y);

    ByteBuffer a, b;
    // chaining operator<<
    a << "derp" << ' ' << "herp";
    /* PITANJE ZA 100 BODOVA:
     * Što bi bilo da je ovdje 65 a ne (char)65 ?
     * */
    b << &a << (char)65 << ' ' << (char)66;

    std::puts(a.GetData());
    std::puts(b.GetData());

    Buffer<char, 6> Buf;
    std::strcpy(Buf.Array, "Derp!");
    std::puts(Buf.Array);
}
