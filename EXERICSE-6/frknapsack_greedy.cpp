#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int profit, weight;

    // Constructor
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(struct Item it[], int w, int n)
{
    sort(it, it + n, cmp);

    int temp = w;
    double maxPrice = 0;

    for (int i = 0; i < n; i++)
    {
        if (it[i].weight <= temp)
        {
            maxPrice += it[i].profit;
            temp -= it[i].weight;
        }
        else
        {
            maxPrice += ((double)temp / (double)it[i].weight) * it[i].profit;
            break;
        }
    }
    return maxPrice;
}

int main()
{

    int W = 50; //    Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << "Maximum Profit we can obtain = "
         << fractionalKnapsack(arr, W, n);
    return 0;
}