// class RecentCounter {
// public:
//     RecentCounter() {
        
//     }
//     queue <int> signals;
//     static const int MAX_TIME = 3000;

//     int ping(int t) 
//     {
//         signals.push(t);
//         while(signals.back() - signals.front() > MAX_TIME)
//             signals.pop();

//         return signals.size();


        
//     }
// };

// /**
//  * Your RecentCounter object will be instantiated and called as such:
//  * RecentCounter* obj = new RecentCounter();
//  * int param_1 = obj->ping(t);
//  */

//https://leetcode.com/problems/number-of-recent-calls/description/?envType=study-plan-v2&envId=leetcode-75