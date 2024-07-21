

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };
    
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    std::unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        int val = mp[key]->val;
        Node* node = mp[key];
        deleteNode(node);
        insertNode(node);
        return val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertNode(node);
        } else {
            if (mp.size() == cap) {
                Node* node = tail->prev;
                mp.erase(node->key);
                deleteNode(node);
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            insertNode(node);
        }
    }

private:
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    void insertNode(Node* node) {
        Node* currAfterHead = head->next;
        head->next = node;
        node->next = currAfterHead;
        node->prev = head;
        currAfterHead->prev = node;
    }
};
