#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

class Node
{
public:
    int key = -1;
    int data = -1;
    Node *prev = nullptr;
    Node *next = nullptr;

    Node(int key, int d)
    {
        data = d;
        key = key;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache
{
private:
    unordered_map<int, Node *> map;
    Node *head, *tail;
    int cap = 0;

public:
    Node *insert_at_front(Node *n)
    {

        n->next = head->next;
        n->prev = head;

        head->next = n;
        n->next->prev = n;
    }

    Node *delete_from_list(Node *n)
    {
        n->next->prev = n->prev;
        n->prev->next = n->next;
    }

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            Node *n = map[key];
            delete_from_list(n);
            insert_at_front(n);
            return n->data;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            Node *n = map[key];
            n->data = value;

            delete_from_list(n);
            insert_at_front(n);
        }
        if (map.size() > cap)
        {
            Node *n = tail->prev;
            map.erase(n->key);
            delete_from_list(n);
        }

        Node *n = new Node(key, value);
        map[key] = n;
        insert_at_front(n);
    }
};

int main()
{

    return 0;
}