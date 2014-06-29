#ifndef _3B2_HPP
#define _3B2_HPP

// forward declaration
class Object;

// no typedef
struct Vector2i
{
    // constructor, initialization list
    Vector2i(int x, int y) : x(x), y(y) { }

    // operator overload
    Vector2i operator+(const Vector2i& Other)
    {
        return Vector2i(x + Other.x, y + Other.y);
    }

    void operator+=(const Vector2i& Other)
    {
        x += Other.x;
        y += Other.y;
    }

    bool operator==(const Vector2i& Other)
    {
        return Other.x == x && Other.y == y;
    }

    bool operator!=(const Vector2i& Other)
    {
        return !(*this == Other);
    }

    int x, y;
};


class Map
{
public:
    Map(int Width, int Height);
    ~Map();

    void Load(const char* Data);
    void AddObject(Object* pObject);
    void RemoveObject(Object* pObject);
    void MoveObject(Object* pObject, Vector2i Offset);
    void Draw();

    Object* GetObject(Vector2i Position);

private:
    int Width, Height;
    // 2d array of pointers
    Object*** Objects;
};

#endif
