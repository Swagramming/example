#include "3b.hpp"

Map::Map(int Width, int Height) : Width(Width), Height(Height)
{
    Objects = new Object**[Height];
    for (int y = 0; y < Height; ++y)
    {
        Objects[y] = new Object*[Width];
        for (int x = 0; x < Width; ++x)
            Objects[y][x] = 0;
    }
}

Map::~Map()
{
    for (int y = 0; y < Height; ++y)
    {
        for (int x = 0; x < Width; ++x)
            delete Objects[y][x];
        delete[] Objects[y];
    }
    delete[] Objects;
}

void Map::Load(const char* Data)
{
    // implicit pointer to bool
    for (int i = 0; Data[i]; ++i)
    {
        int y = i / Height, x = i % Height;
        switch (Data[i])
        {
            case 'Z':
                Objects[y][x] = new StaticObject(StaticObject::WALL, Vector2i(x, y));
                break;
            case 'V':
                Objects[y][x] = new StaticObject(StaticObject::DOOR, Vector2i(x, y));
                break;
            case '.':
            default:
                break;
        }
    }
}

void Map::AddObject(Object* pObject)
{
    Objects[pObject->GetY()][pObject->GetX()] = pObject;
}

void Map::RemoveObject(Object* pObject)
{
    Objects[pObject->GetY()][pObject->GetX()] = 0;
}

void Map::MoveObject(Object* pObject, Vector2i Offset)
{
    Vector2i NewPos = pObject->GetPosition() + Offset;

    if (NewPos.x >= Width || NewPos.y >= Height || NewPos.x < 0 || NewPos.y < 0)
        return;

    if (Object* pAdjacentObject = GetObject(NewPos))
    {
        if (!pAdjacentObject->HasFlag(Object::DEAD))
        {
            // dynamic_cast
            if (Player* pPlayer = dynamic_cast<Player*>(pObject))
                if (dynamic_cast<Creature*>(pAdjacentObject))
                    pPlayer->SetFlag(Object::DEAD);
            return;
        }
    }

    RemoveObject(pObject);
    pObject->Relocate(NewPos);
    AddObject(pObject);
}

void Map::Draw()
{
    for (int y = 0; y < Height; ++y)
    {
        for (int x = 0; x < Width; ++x)
        {
            // pointer check
            if (Object* pObject = Objects[y][x])
                std::putchar(pObject->GetCharacter());
            else std::putchar('.');
        }
        std::putchar('\n');
    }
}

Object* Map::GetObject(Vector2i Position)
{
    return Objects[Position.y][Position.x];
}
