#include <iostream>
using namespace std;

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

double Knapsack(Item it[], int w, int n)
{

    int temp = w;
    double maxPrice = 0;

    sort(it, it + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (temp >= it[i].weight)
        {
            maxPrice += it[i].profit;
            temp -= it[i].weight;
        }
        else
            break;
    }
    return maxPrice;
}

int main()
{
    int w = 15;
    Item arr[] = {{10, 2}, {15, 5}, {7, 2}, {9, 4}, {6, 1}, {20, 8}, {30, 6}};
    cout << "Maximum Profit we can obtain = "
         << Knapsack(arr, w, 7);

    return 0;
}