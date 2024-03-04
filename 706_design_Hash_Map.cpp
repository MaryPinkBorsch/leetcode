#include <math.h>
#include <random>
//хэш мап это массив из списков, элементы которых каждый содержат ключи
// и соответствующие им значения 
//выбор списка в массиве осуществляется "хэшированием" ключа 
//(разные ключи могут захешироваться в 1 число и один список)


struct MASYAListNode // элемент списка с значением и "ключом"
{
    int key;
    int val;
    MASYAListNode * next = 0; // = nullptr

};
class MyHashMap 
{
public:
    static const int NUM_BUCKETS = 5000; // кол-во списоков (бУкетов = корзинок)
    MASYAListNode * buckets [NUM_BUCKETS] = {nullptr}; // массив БУкетов-списков

    int MyHash(int key) // функция ХЭШИРОВАНИЯ (ставит в соответсвтвие каждому ключу число)
    {
        static const int prime1 = 31;
        static const int prime2 = 65521;
        //это простые числа
        return(key*prime1 + prime2);
    }

    MyHashMap() {
        
    }
    //добавление ключа и валуе
    void put(int key, int value)
    {
        int bucket_idx = MyHash(key) % NUM_BUCKETS; // вычисление  индекса списка в массиве бУкетов
        if(buckets[bucket_idx] == nullptr) // новый эелемент если список пустой
        {
            buckets[bucket_idx] = new MASYAListNode();
            buckets[bucket_idx]-> key = key;
            buckets[bucket_idx]-> val = value;
        }
        else
        {   // проход по списку и попытка найти там элемент с нужным ключом
            MASYAListNode * cur = buckets[bucket_idx];
            while (cur != nullptr)
            {
                if(cur->key== key)
                    break;
                cur = cur->next;
            }
            if(cur != nullptr)
            {
                cur->val = value; // нашли и записали новое значение
            }
            else
            {   // создали новый элемент и делаем его новоой головой в списке котроый лежит в массиве
                cur = new MASYAListNode();
                cur->key = key;
                cur->val = value;
                cur->next =  buckets[bucket_idx]; // указывает на прошлую голову которая хранилась в массиве списков
                buckets[bucket_idx] = cur; // кур записываем в массив (он стал новой головой)
            }      
        }        
    }
    
    int get(int key) // поиск по ключу
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