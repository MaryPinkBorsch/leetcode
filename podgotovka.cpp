#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

// мар - упорядоченный "словарь",  unordered_map - неупорядоченный "словарь"

struct A
{
    int a;
};

int main(int argc, char *argv[])
{
    A array[10];
    vector<A> nums1;
    vector<A> array2;
    array[1].a = 1;
    array[5].a = 5;

    array2.resize(10); // автоматически добавляет пустые элементы (созданные по умолчанию)
    array2[2].a = 2;
    // у массива "ключом" является инт - индекс
    // у словварей ключом может быть что угодно, что можно сравнить

    unordered_map<int, A> hash_map1; // если в хэш мар обратиться через индексом,
    // которого еще нет - он автоматичекси создается
    hash_map1[3].a = 3;
    hash_map1[45].a = 45;

    unordered_map<string, A> hash_map2;
    hash_map2["aboba"].a = 666;

    unordered_map<int, A> map1;
    for (int i = 0; i < nums1.size(); i++)
    {
        map1[nums1[i].a].a += 1; // создаем хэш таблтцу с ключами - значениями из массива
        // и значениями - кол-во вхождения этого числа в данный массив (для первого)
    }

    //  for (auto it = map1.begin(); it != map1.end(); it++) // !!!! идем по элементам мар1   // @@@@@@@@@@@@
    //     {
    //         if (map2.find(it->first) != map2.end())
    //             ans2 += map2[it->first];
    //     }

    for (unordered_map<int, A>::iterator it = hash_map1.begin(); it != hash_map1.end(); it++)
    {
        // end() - возвращает итератор указывающий на элемент, который после последнего
        // begin() - возвращает итератор указывающий на первый элемент мар
        // если мар пустой ---> end = begin
        // все имя итератора можно заменить на тип  auto если лень "@@@@"

        // содержимое мар = пара (std::pair <ключ, значение> *какое-то имя*  )
        cout << "kluch " << it->first << " znachenie.a " << it->second.a << endl; // вывод ключа и значения

        // it->first = ключ элемента мар у итератора, а it->second = значение, соотвтествующее этому ключу
    }
    return 0;
}
