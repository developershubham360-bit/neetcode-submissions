class LRUCache {
private:

    struct Node {
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

    int capacity;


    void remove(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }


    void insertFront(Node* node) {

        Node* first = head->next;

        node->next = first;
        node->prev = head;

        head->next = node;
        first->prev = node;
    }


public:

    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }


    int get(int key) {

        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];

        // Mark as recently used
        remove(node);
        insertFront(node);

        return node->value;
    }


    void put(int key, int value) {

        // Key already exists
        if (cache.find(key) != cache.end()) {

            Node* node = cache[key];

            node->value = value;

            // Mark as recently used
            remove(node);
            insertFront(node);

            return;
        }


        // Cache is full
        if (cache.size() == capacity) {

            Node* lru = tail->prev;

            remove(lru);

            cache.erase(lru->key);

            delete lru;
        }


        // Create new node
        Node* node = new Node(key, value);

        cache[key] = node;

        insertFront(node);
    }
};
