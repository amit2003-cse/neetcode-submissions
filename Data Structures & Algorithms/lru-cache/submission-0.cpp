struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int,Node*> cache;
    Node* head;
    Node* tail;
    int capacity;

    void addnode(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }

    void remove(Node* node){
        Node* nodeprev = node->prev;
        Node* nodenext = node->next;
        nodeprev->next = nodenext;
        nodenext->prev = nodeprev;
    }

    Node* removetail(){
        Node* node = tail->prev;
        remove(node);
        return node;
    }

    void movetohead(Node* node){
        remove(node);
        addnode(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            movetohead(node);
            return node->value;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            movetohead(node);
        }else{
            Node* node = new Node(key,value);
            cache[key] = node;
            addnode(node);

            if(cache.size() > capacity){
                Node* tailnode = removetail();
                cache.erase(tailnode->key);
                delete tailnode;
            }

        }
        
        
    }
};
