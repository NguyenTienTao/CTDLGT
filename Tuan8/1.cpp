#include <bits/stdc++.h>
using namespace std;

struct item {
    double value, weight;
};

item newItem(double v, double w) {
    item p;
    p.value = v;
    p.weight = w;
    return p;
}

void input(vector<item> &A, int N) {
    for (int i = 0; i < N; i++) {
        double v, w;
        cin >> v >> w;
        A.push_back(newItem(v, w));
    }
}

bool compare(item a, item b) {
    return a.value/a.weight > b.value/b.weight;
}

int greedy(vector<item> &A, int N, int W) {
    int totalValue = 0;
    sort(A.begin(), A.end(), compare);
    for (int i = 0; i < N; i++) {
        if (A.at(i).weight <= W) {
            totalValue += A.at(i).value;
            W -= A.at(i).weight;
        }
    }
    return totalValue;
}

int main()
{
    int N, W;
    cin >> N >> W;
    vector<item> Item;
    input(Item, N);
    cout << greedy(Item, N, W);


    return 0;
}
