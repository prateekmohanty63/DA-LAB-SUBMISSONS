#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Greedy algorithm always picks the activity whose finish time is least among the remaining activities

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> activityTime;
    vector<int> start, end;

    // sorting the end time in ascending order

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        start.push_back(a);
        end.push_back(b);

        activityTime.push_back(make_pair(start[i], end[i]));
    }

    sort(activityTime.begin(), activityTime.end(),sortbysec);

    // for(int i=0;i<n;i++){
    //     cout<<activityTime[i].first<<" "<<activityTime[i].second<<endl;
    // }

    // applying the greedy algorithm we get

    int activityCompleted=1;

    for(int i=1;i<n;i++){
        
        if(activityTime[i].first>=activityTime[i-1].second){
            activityCompleted++;
        }
    }

    cout<<"Maximum number of activities that can be completed by a person is: ";
    cout<<activityCompleted+1;

    return 0;
}