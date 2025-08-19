#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

int knapsack_dp(int W, vector<Item> items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            }
        }
    }
    return dp[n][W];
}

int knapsack_greedy(int W, vector<Item> items) {
    sort(items.begin(), items.end(), [](Item a, Item b) { return a.value > b.value; });
    int n = items.size();
    int weight = 0;
    int value = 0;
    for (int i = 0; i < n; i++) {
        if (weight + items[i].weight <= W) {
            weight += items[i].weight;
            value += items[i].value;
        } else {
            break;
        }
    }
    return value;
}

int main() {
    int W = 50;
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    cout << "Using Dynamic Programming: " << knapsack_dp(W, items) << endl;
    cout << "Using Greedy: " << knapsack_greedy(W, items) << endl;
    return 0;
}