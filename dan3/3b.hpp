#ifndef _3B_HPP
#define _3B_HPP

#include <cstdio>
#include "3b2.hpp"

// no typedef
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Object
{
    // friend function
    friend void Map::MoveObject(Object* pObject, Vector2i Offset);
public:
    // nested type declaration
    enum Flag_t
    {
        DEAD = 1 << 0
    };

    // default parameter
    Object(Vector2i Pos = Vector2i(0, 0)) : Position(Pos) { }
    // pure virtual destructor
    virtual ~Object() = 0;

    // const function
    Vector2i GetPosition() const { return Position; }
    int GetX() const { return Position.x; }
    int GetY() const { return Position.y; }

    // pure virtual member function
    virtual char GetCharacter() = 0;

    // static member function
    static const char* Identifier() { return "Object"; }

    bool HasFlag(unsigned char Flag) const { return StateMask & Flag; }
    void SetFlag(unsigned char Flag) { StateMask |= Flag; }

protected:
    void Relocate(Vector2i Where)
    {
        Position = Where;
    }

    Vector2i Position;

private:
    unsigned char StateMask;
};

class StaticObject : public Object
{
public:
    enum Type_t
    {
        WALL,
        DOOR
    };

    // passing parameter to parent constructor
    StaticObject(Type_t Type, Vector2i Pos = Vector2i(0, 0)) : Object(Pos), Type(Type) { }
    // virtual destructor
    virtual ~StaticObject() { }

    Type_t GetType() const
    {
        return Type;
    }

    // virtual member function
    virtual char GetCharacter()
    {
        // static local variable
        static char CharMap[][2] =
        {
            { 'Z', 'z' },
            { 'V', 'v' }
        };
        return CharMap[Type][HasFlag(Object::DEAD)];
    }

private:
    Type_t Type;
};

class Unit : public Object
{
public:
    Unit(Map* pMap, Vector2i Pos = Vector2i(0, 0)) : Object(Pos), pMap(pMap) { }
    virtual ~Unit() { }

    void Move(Direction Where)
    {
        // passing this as parameter
        pMap->MoveObject(this, DirMap[Where]);
    }

protected:
    // const static member variable
    const static Vector2i DirMap[];
    Map* pMap;
};

class Creature : public Unit
{
public:
    enum Type_t
    {
        MONSTER,
        ASSASIAN
    };

    Creature(Type_t Type, Map* pMap, Vector2i Pos) : Unit(pMap, Pos), Type(Type) { }
    virtual ~Creature() { }

    Type_t GetType() const
    {
        return Type;
    }

    virtual char GetCharacter()
    {
        static char CharMap[][2] =
        {
            { 'M', 'm' },
            { 'A', 'a' }
        };
        return CharMap[Type][HasFlag(Object::DEAD)];
    }

private:
    Type_t Type;
};

class Player : public Unit
{
public:
    Player(Map* pMap, Vector2i Pos) : Unit(pMap, Pos) { }
    virtual ~Player() { }

    void Act(Direction Where)
    {
        Vector2i NewPos = Position + DirMap[Where];
        if (Object* pObject = pMap->GetObject(NewPos))
        {
            // dynamic_cast
            if (Creature* pCreature = dynamic_cast<Creature*>(pObject))
            {
                if (!pCreature->HasFlag(Object::DEAD))
                {
                    pCreature->SetFlag(Object::DEAD);
                    std::printf("You killed %s!\n", pCreature->GetType() == Creature::MONSTER ?
                                                    "a monster" : "an assasian");
                }
            }
            else if (StaticObject* pStaticObject = dynamic_cast<StaticObject*>(pObject))
                if (pStaticObject->GetType() == StaticObject::DOOR)
                    pStaticObject->SetFlag(StaticObject::DEAD);
        }
    }

    virtual char GetCharacter()
    {
        return 'P';
    }
};

#endif
