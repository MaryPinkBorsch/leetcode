#include <list>
#include <vector>

using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        list<int> students_list;
        list<int> sandwiches_list;
        students_list.insert(students_list.end(), students.begin(), students.end());
        sandwiches_list.insert(sandwiches_list.end(), sandwiches.begin(), sandwiches.end());

        int counter = 0;
        while (students_list.size())
        {
            if (students_list.front() == sandwiches_list.front())
            {
                students_list.pop_front();
                sandwiches_list.pop_front();
                counter = 0; // снова пусть смотрит сколько челов подряд не хочет брать бутерброд
            }
            else
            {
                int tmp = students_list.front();
                students_list.pop_front();
                students_list.push_back(tmp);
                counter++;
                if (counter == students_list.size())
                    break;
            }
        }
        return students_list.size();
    }
};

int main(int argc, char * argv[]) 
{
    Solution tmp;
    std::vector<int> students = {1,1,1,0,0,1};
    std::vector<int> sandwiches = {1,0,0,0,1,1};
    return tmp.countStudents(students, sandwiches);
}



// class Solution {
// public:
//     int countStudents(vector<int>& students, vector<int>& sandwiches) 
//     {
//         list<int> students_list;
//         list<int> sandwiches_list;
//         students_list.insert(students_list.end(), students.begin(), students.end());
//         sandwiches_list.insert(sandwiches_list.end(), sandwiches.begin(), sandwiches.end());

//         int counter= 0;
//         while(students_list.size())
//         {
//             if(students_list.front() == sandwiches_list.front())
//             {
//                 students_list.pop_front();
//                 sandwiches_list.pop_front();
//                 counter= 0; // снова пусть смотрит сколько челов подряд не хочет брать бутерброд
//             }
//             else
//             {
//                 int tmp =students_list.front();
//                 students_list.pop_front();
//                 students_list.push_back(tmp);
//                 counter++;
//                 if(counter==students_list.size())
//                     break;
//             }
//         }
//         return students_list.size();
//     }
// };