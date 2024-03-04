#include <math.h>
#include <random>

struct MASYAListNode
{
    int key;
    int val;
    MASYAListNode * next = 0; // = nullptr

};
class MyHashMap 
{
public:
    static const int NUM_BUCKETS = 5000;
    MASYAListNode * buckets [NUM_BUCKETS] = {nullptr};

    int MyHash(int key)
    {
        static const int prime1 = 31;
        static const int prime2 = 65521;

        return(key*prime1 + prime2);
    }

    MyHashMap() {
        
    }
    
    void put(int key, int value)
    {
        int bucket = MyHash(key) % NUM_BUCKETS;
        if(buckets[bucket] == nullptr)
        {
            buckets[bucket] = new MASYAListNode();
            buckets[bucket]-> key = key;
            buckets[bucket]-> val = value;
        }
        else
        {
            MASYAListNode * cur = buckets[bucket];
            while (cur != nullptr)
            {
                if(cur->key== key)
                    break;
                cur = cur->next;
            }
            if(cur != nullptr)
            {
                cur->val = value;
            }
            else
            {
                cur = new MASYAListNode();
                cur->key = key;
                cur->val = value;
                cur->next =  buckets[bucket]; // указывает на прошлую голову которая хранилась в массиве списков
                buckets[bucket] = cur; // кур записываем в массив (он стал новой головой)
            }      
        }        
    }
    
    int get(int key)
    {
        int bucket_idx = MyHash(key) % NUM_BUCKETS;
        MASYAListNode * cur =  buckets[bucket_idx];
        while(cur!= nullptr)
        {
            if(cur->key == key)
                break;
            cur = cur->next;
        }
        if(cur!= nullptr)
        {
            return cur->val;
        }
        else
            return -1;
        
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
            if(prev != 0)
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
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int argc, char * argv[]) 
{
    MyHashMap wtf;
    for (int i = 0; i < 10000; ++i) 
    {
        wtf.put(rand()%10000, i);
    }
    return 0;
}