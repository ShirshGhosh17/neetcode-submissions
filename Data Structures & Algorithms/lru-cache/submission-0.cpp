class LRUCache {
public:

    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            val = v;
        }
    };

    void addnode(Node* node){
        Node* next = head->next;
        head->next = node;
        node->prev = head;

        node->next = next;
        next->prev = node;
    }

    void delnode(Node* node){
        Node* oldprev = node->prev;
        Node* oldnext = node->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int limit;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        Node* node = m[key];
        delnode(node);
        addnode(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            m.erase(key);
            delnode(node);

            Node* newnode = new Node(key,value);
            addnode(newnode);
            m[key] = newnode;
        }

        else{
            if(m.size() == limit){
                m.erase(tail->prev->key);
                delnode(tail->prev);
            }
            Node* newnode = new Node(key,value);
            addnode(newnode);
            m[key] = newnode;
        }
    }
};
