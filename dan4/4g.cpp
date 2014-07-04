#include <cassert>

template <typename T>
class List
{
    struct Node
    {
        Node(T Elem) : pNext(nullptr), Elem(Elem) { }
        Node* pNext;
        T Elem;
    };
public:
    List() : pHead(nullptr)
    {
    }

    void Insert(T Elem)
    {
        Node** ppIter = &pHead;
        while (*ppIter) ppIter = &(*ppIter)->pNext;
        *ppIter = new Node(Elem);
    }

    void Delete(T Elem)
    {
        for (Node** pIter = &pHead; *pIter; pIter = &(*pIter)->pNext)
        {
            if ((*pIter)->Elem == Elem)
            {
                Node* pNext = (*pIter)->pNext;
                delete *pIter;
                *pIter = pNext;
                return;
            }
        }
    }

    T* Search(T Elem)
    {
        Node* pIter = pHead;
        do if (pIter->Elem == Elem)
            return &pIter->Elem;
        while (pIter = pIter->pNext);
        return nullptr;
    }

private:
    Node* pHead;
};

int main()
{
    List<char> L;
    L.Insert('k');
    L.Insert('a');

    assert(L.Search('k'));
    assert(L.Search('a'));

    L.Delete('a');
    L.Insert('b');

    assert(L.Search('b'));
    assert(!L.Search('a'));
    assert(!L.Search('c'));
}
