#include "3b.hpp"

// pure virtual destructor definition
Object::~Object()
{
}

// const static member initialization
const Vector2i Unit::DirMap[] =
{
    Vector2i(0, -1),
    Vector2i(0, 1),
    Vector2i(-1, 0),
    Vector2i(1, 0)
};

class Game
{
public:
    Game()
    {
        pMap = new Map(5, 5);
        pPlayer = new Player(pMap, Vector2i(4, 0));
        // multiline string constant
        pMap->Load("Z...."
                   "ZVZZZ"
                   "Z..Z."
                   "ZZ.V."
                   "ZZZZZ");
        pMap->AddObject(new Creature(Creature::MONSTER, pMap, Vector2i(1, 0)));
        pMap->AddObject(new Creature(Creature::MONSTER, pMap, Vector2i(1, 2)));
        pMap->AddObject(new Creature(Creature::ASSASIAN, pMap, Vector2i(4, 3)));
        pMap->AddObject(pPlayer);
    }

    ~Game()
    {
        delete pMap;
    }

    void Run()
    {
        Vector2i VictoryPosition(4, 2);
        int Input;
        do
        {
            pMap->Draw();
            std::scanf("%d", &Input);
            switch (Input)
            {
                case 8: pPlayer->Move(UP); break;
                case 2: pPlayer->Move(DOWN); break;
                case 4: pPlayer->Move(LEFT); break;
                case 6: pPlayer->Move(RIGHT); break;

                case -8: pPlayer->Act(UP); break;
                case -2: pPlayer->Act(DOWN); break;
                case -4: pPlayer->Act(LEFT); break;
                case -6: pPlayer->Act(RIGHT); break;
            }
        } while (!pPlayer->HasFlag(Object::DEAD) && pPlayer->GetPosition() != VictoryPosition);

        pMap->Draw();
        if (pPlayer->HasFlag(Object::DEAD))
            std::puts("YOU LOSE!");
        else std::puts("YOU WIN");
    }

private:
    Player* pPlayer;
    Map* pMap;
};

int main()
{
    // using static member
    std::puts(Object::Identifier());
    Game* pGame = new Game;
    pGame->Run();
    delete pGame;
}
