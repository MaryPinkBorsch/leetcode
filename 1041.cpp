#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    enum Direction { L, R, U, D };
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        Direction dir = U;

        for (int i = 0; i < instructions.size(); i++) {
            if (instructions[i] == 'G') 
            {
                if (dir == U)
                    y++;
                if (dir == D)
                    y--;
                if (dir == R)
                    x++;
                if (dir == L)
                    x--;

            }
            else if (instructions[i] == 'L') {
                if (dir == U)
                    dir = L;
                else if (dir == D)
                    dir = R;
                else if (dir == R)
                    dir = U;
                else if (dir == L)
                    dir = D;

            } 
            else if (instructions[i] == 'R') {
                if (dir == U)
                    dir = R;
                else if (dir == D)
                    dir = L;
                else if (dir == R)
                    dir = D;
                else if (dir == L)
                    dir = U;
            }
        }
        if (x == 0 && y == 0)
            return true;
        else
            return false;
    }
};

int main()
{ 
    {
        Solution omg;
        std::string wtf = "GGLLGG";
        auto res = omg.isRobotBounded(wtf);
    }
    {
        Solution omg;
        std::string wtf = "GL";
        auto res = omg.isRobotBounded(wtf);
    }
    return 0;
}