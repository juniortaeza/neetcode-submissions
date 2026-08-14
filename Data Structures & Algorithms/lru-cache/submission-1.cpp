class LRUCache {
private:
    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode (int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, ListNode*> cache;
    int cap;
    ListNode* left;
    ListNode* right;

    void insert(ListNode* node){
        ListNode* prev = right->prev;
        node->next = right;
        node->prev = prev;
        prev->next = node;
        right->prev = node;
    }

    void remove(ListNode* node){
        ListNode* prev = node->prev;
        ListNode* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new ListNode(0, 0);
        right = new ListNode(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        ListNode* node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){ // if already exists, overwrite
            ListNode* node = cache[key];
            remove(node);
        }
        ListNode* newNode = new ListNode(key, value); // create new cache entry
        cache[key] = newNode;
        insert(newNode); // add to DLL

        if(cache.size() > cap){ // evict LRU node
            ListNode* lru = left->next;
            remove(lru); // remove from DLL
            cache.erase(lru->key); // remove from cache
            delete lru;     // free memory
        }
    }
};
