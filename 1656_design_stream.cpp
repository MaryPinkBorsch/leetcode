#include <vector>
#include <string>
#include <iostream>

using namespace std;

class OrderedStream
{
public:
    OrderedStream(int n)
    {
        n_ = n;
        massiv.resize(n_);
    }

    vector<string> massiv;

    int last_idx = 0; // ptr

    vector<string> insert(int idKey, string value)
    {
        vector<string> res;
        massiv[idKey - 1] = value;

        while (last_idx < n_ && massiv[last_idx].size() != 0 )
        {
            res.push_back(massiv[last_idx]);
            last_idx++;
        }
        return res;
    }

    int n_;
};

int main(int argc, char *argv[])
{
    //[[5],[3,"ccccc"],[1,"aaaaa"],[2,"bbbbb"],[5,"eeeee"],[4,"ddddd"]]

    vector<string> om;
    OrderedStream wtf(5);
    om = wtf.insert(3, "ccccc");
    om = wtf.insert(1, "aaaaa");
    om = wtf.insert(2, "bbbbb");
    om = wtf.insert(5, "eeeee");
    om = wtf.insert(4, "ddddd");

    return 0;
}