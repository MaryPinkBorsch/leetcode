// class StockSpanner1 {
// public:
//     StockSpanner1() {
//         std::ios_base::sync_with_stdio(false);
//         std::cin.tie(NULL);
//         std::cout.tie(NULL);
//         prices.reserve(10000);
//         spans.reserve(10000);
//     }
//     std::vector<int> prices;
//     std::vector<int> spans;
    
//     int next(int price) {
//         int idx = prices.size();
//         prices.push_back(price);
//         int span = 1;
//         while(idx - span >= 0 &&  prices[idx - span] <= prices[idx])
//             span += spans[idx - span]; // тк наша цена больше или равна для всего предыдущего спана текущего числа мы ее приплюсовываем и перепрыгиваем
//         spans.push_back(span);
//         return spans[idx];
//     }
// };

// class StockSpanner {
// public:
//     // StockSpanner() {
//     //     std::ios_base::sync_with_stdio(false);
//     //     std::cin.tie(NULL);
//     //     std::cout.tie(NULL);
//     //     prices.reserve(10000);
//     // }
//     std::vector<int> prices;
    
//     int next(int price) {
//         int idx = prices.size();
//         prices.push_back(price);
//         int span = 1;
//         while(idx - span >= 0 &&  prices[idx - span] <= prices[idx])
//             ++span;
//         return span;
//     }
// };
// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */