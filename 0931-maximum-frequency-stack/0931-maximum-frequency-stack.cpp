#include <unordered_map>
#include <queue>
#include <tuple>

class FreqStack {
private:
    std::unordered_map<int, int> freq;  // value -> frequency
    int time;
    std::priority_queue<std::tuple<int,int,int>> pq;  // (freq, time, val)

public:
    FreqStack() {
        time = 0;
    }

    void push(int val) {
        freq[val]++;
        time++;
        pq.push({freq[val], time, val});
    }

    int pop() {
        auto [f, t, val] = pq.top();
        pq.pop();
        freq[val]--;
        return val;
    }
};
