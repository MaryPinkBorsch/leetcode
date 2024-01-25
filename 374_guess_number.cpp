/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        unsigned int l = 1;
        unsigned int r = n;
        unsigned int num = 0;
        int pick = 0;
        bool found = false;
        while (found == false && l <= r)
        {

            num = l + (r - l) / 2; // == l + r/2 - l/2 == l/2 + r/2
            int a = guess(num);
            if (a == -1)
            {
                r = num - 1;
            }
            if (a == 1)
            {
                l = num + 1;
            }
            if (a == 0)
            {
                found = 1;
                return num;
            }
        }

        return pick;
    }
};