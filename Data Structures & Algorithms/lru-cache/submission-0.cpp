#include <unordered_map>

class Node {
public:
    int key;    // We MUST store the key to remove it from the map during eviction
    int val;
    Node* prev;
    Node* next;
    
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Helper function to remove an existing node from the linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper function to insert a node right after the dummy head
    void addNodeToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        // Initialize dummy head and tail nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        Node* node = cache[key];
        
        // Move the accessed node to the front (Most Recently Used)
        removeNode(node);
        addNodeToHead(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If key exists, update value and move to front
            Node* node = cache[key];
            node->val = value;
            removeNode(node);
            addNodeToHead(node);
        } else {
            // If at capacity, evict the Least Recently Used item (right before tail)
            if (cache.size() == capacity) {
                Node* lru = tail->prev;
                cache.erase(lru->key); // This is why we need the key in the Node
                removeNode(lru);
                delete lru;
            }
            
            // Create new node, add to map, and add to front
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNodeToHead(newNode);
        }
    }
    
    // Optional: Destructor to clean up memory
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};