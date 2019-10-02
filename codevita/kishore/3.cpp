#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int number_of_players;
    cin>>number_of_players;
    int number_of_slots;
    cin>>number_of_slots;
    int val;
    vector<vector<ll>> players(number_of_players,vector<ll>(number_of_slots));
    vector<int> size_of_step;
    for(auto &player:players)
    {
        for(auto &step:player) cin>>step;
        cin>>val;
        size_of_step.push_back(val);
    }
    vector<int> wins(number_of_players,0);
    vector<ll> travelled(number_of_players,0);
    for(int i=1;i<number_of_slots;i+=2)
    {
        ll mymax=0;
        vector<int> winners;
        for(int j=0;j<number_of_players;j++)
        {
            travelled[j]+=(players[j][i]+players[j][i-1])*size_of_step[j];
            if(travelled[j]>mymax)
            {
                mymax=travelled[j];
                winners.clear();
                winners.push_back(j);
            }
            else if(travelled[j]==mymax)
            {
                winners.push_back(j);
            }
        }
        for(auto winner:winners) wins[winner]++;
    }
    int ans=0,max_wins=wins[0];
    for(int i=0;i<wins.size();i++)
    {
        if(wins[i]>max_wins)
        {
            max_wins=wins[i];
            ans=i;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}