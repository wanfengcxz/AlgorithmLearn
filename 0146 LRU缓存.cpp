// 不能使用单链表
// 单链表找前驱结点复杂度为O(n)
// 不符合题目要求
struct DoubleListNode{
    int key, value;
    DoubleListNode *pre;
    DoubleListNode *next;

    DoubleListNode(int key, int value):key(key),value(value),pre(nullptr),next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, DoubleListNode*> cache;
    DoubleListNode *head;
    DoubleListNode *tail;
    int capacity;
    int size;

    void moveToHead(DoubleListNode *node){
        node->next->pre = node->pre;
        node->pre->next = node->next;
        head->next->pre = node;
        node->next = head->next;
        node->pre = head;
        head->next = node;
    }

    DoubleListNode* insertNode(int key, int value){
        DoubleListNode *tmp = new DoubleListNode(key, value);
        head->next->pre = tmp;
        tmp->next = head->next;
        head->next = tmp;
        tmp->pre = head;
        return tmp;
    }

    DoubleListNode *removeTail(){
        DoubleListNode *tmp = tail->pre;
        tail->pre = tmp->pre;
        tmp->pre->next = tail;
        return tmp;
    }

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        size = 0;
        head = new DoubleListNode(0,0);
        tail = new DoubleListNode(0,0);
        tail->pre = head;
        head->next = tail;
    }
    
    int get(int key) {
        if (cache.count(key)<=0){
            return -1;
        }else {
            moveToHead(cache[key]);
            return cache[key]->value;
        }
    }
    
    void put(int key, int value) {
        if (cache.count(key)<=0){
            DoubleListNode *tmp;
            tmp = insertNode(key, value);
            cache[key] = tmp;
            size++;
            if (size>capacity){
                tmp = removeTail();
                cache.erase(tmp->key);
                size--;
                delete tmp;
            }
        }
        // 更新结点
        else{
            cache[key]->value = value;
            moveToHead(cache[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




struct DoubleListNode{
    int key;
    DoubleListNode *pre;
    DoubleListNode *next;

    DoubleListNode():key(-1),pre(nullptr),next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, int> hashmap;
    DoubleListNode *head;
    DoubleListNode *tail;
    int capacity_;
    int curNodeNum;

    bool advanceNode(int key){
        DoubleListNode *tmp = head->next;
        // 此处线性查找，如果容量大，则每次都需要花费大量
        // 时间查找，因此不可取，应该把链表的地址存储在hashmap中
        // 而且导致Put和get时间不是O(1)
        while(tmp!=nullptr && tmp->key != key){
            tmp = tmp->next;
        }
        if (tmp==nullptr)
            return false;
        // 取下当前key对应的结点
        tmp->next->pre = tmp->pre;
        tmp->pre->next = tmp->next;
        // 将key插入链表头部
        head->next->pre = tmp;
        tmp->next = head->next;
        tmp->pre = head;
        head->next = tmp;
        return true;
    }
public:
    LRUCache(int capacity) {
        capacity_=capacity;
        curNodeNum = 0;
        head = new DoubleListNode();
        tail = new DoubleListNode();
        tail->pre = head;
        head->next = tail;
    }
    
    int get(int key) {
        if (hashmap.count(key)<=0){
            return -1;
        }else {
            if (advanceNode(key))
                return hashmap[key];
            return -1;
        }
    }
    
    void put(int key, int value) {
        // 插入结点
        if (hashmap.count(key)<=0){
            DoubleListNode *tmp;
            // 缓存已满
            if (curNodeNum>=capacity_){
                tmp = tail->pre;
                tail->pre = tmp->pre;
                tmp->pre->next = tail;
                // 别忘了要删除 而且删除的是tmp->key不是key
                hashmap.erase(tmp->key);
                delete tmp; 
                curNodeNum--;
            }
            // 插入新节点
            tmp = new DoubleListNode();
            tmp->key = key;
            head->next->pre = tmp;
            tmp->next = head->next;
            tmp->pre = head;
            head->next = tmp;
            hashmap[key] = value;
            curNodeNum++;
        }
        // 更新结点
        else{
            if (advanceNode(key)){
                hashmap[key] = value;
            }
        }
    }
};
