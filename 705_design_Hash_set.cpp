struct MASYAListNode
{
    int key;
    MASYAListNode * next = 0; // = nullptr

};
class MyHashSet {
    public:
    static const int NUM_BUCKETS = 5000;
    MASYAListNode * buckets [NUM_BUCKETS] = {nullptr};

    int MyHash(int key)
    {
        static const int prime1 = 31;
        static const int prime2 = 65521;

        return(key*prime1 + prime2);
    }


    MyHashSet() {
        
    }
    
    void add(int key) 
    {
        int bucket = MyHash(key) % NUM_BUCKETS;
        if(buckets[bucket] == nullptr)
        {
            buckets[bucket] = new MASYAListNode();
            buckets[bucket]-> key = key;           
        }
        else
        {
            MASYAListNode * cur = buckets[bucket];
            while (cur != nullptr)
            {
                if(cur->key == key)
                    break;
                cur = cur->next;
           }
            if(cur == nullptr)          
            {
                cur = new MASYAListNode();
                cur->key = key;                
                cur->next =  buckets[bucket]; // указывает на прошлую голову которая хранилась в массиве списков
                buckets[bucket] = cur; // кур записываем в массив (он стал новой головой)
            }      
        }           
    }
    
    void remove(int key) 
    {
        int bucket_idx = MyHash(key) % NUM_BUCKETS;
        MASYAListNode * cur =  buckets[bucket_idx];
        MASYAListNode * prev = nullptr;
        while(cur!= nullptr)
        {            
            if(cur->key == key)
                break;
            prev = cur;
            cur = cur->next;
        }
        if(cur!= nullptr)
        {
            if(prev != nullptr)
            {
                prev->next = cur->next;
                delete cur;
            }
            else
            {
                buckets[bucket_idx] = cur->next;
                delete cur;
            }
        }
        
    }
    
    bool contains(int key)
    {
        int bucket_idx = MyHash(key) % NUM_BUCKETS;
        MASYAListNode * cur =  buckets[bucket_idx];
        while(cur != nullptr)
        {
            if(cur->key == key)
                break;
            cur = cur->next;
        }
        if(cur!= nullptr)
        {
            return true;
        }
        else
            return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */