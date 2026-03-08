// 146: LRU Cache - Medium

#include <unordered_map>
using namespace std;

class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    int cacheSize;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* nodeAfterHead = head->next;
        head->next = node;
        node->prev = head;

        node->next = nodeAfterHead;
        nodeAfterHead->prev = node;
    }

public:
    LRUCache(int capacity) {
        cacheSize = capacity;
        cache.clear();

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // end() represent not found
        if (cache.find(key) == cache.end()) return -1;

        Node* newNode = cache[key];
        removeNode(newNode);
        insertAfterHead(newNode);

        return newNode->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* temp = cache[key];
            temp->val = value;
            removeNode(temp);
            insertAfterHead(temp);
        }

        else if (cache.size() == cacheSize) {
            Node* temp = tail->prev;
            cache.erase(temp->key);
            removeNode(temp);
            
            temp->key = key;
            temp->val = value;

            insertAfterHead(temp);
            cache[key] = temp;
        }

        else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};
