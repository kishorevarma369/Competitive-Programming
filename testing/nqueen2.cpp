#include<stdio.h>
#include<stdlib.h>
#include<queue>

int time_taken_by_winner(int n, int weights[])
{
    std::priority_queue<int, std::vector<int>, std::greater<int> > p;
    int ans=0,a,b;
    for(int i=0;i<n;i++)
    {   
        p.push(weights[i]);
    }
    while(p.size()>1){
        a=p.top();
        p.pop();
        a+=p.top();
        p.pop();
        p.push(a);
    }
    return p.top();

}

int main()
{
    int n = 7;
    int weights[7] = {8, 15, 25, 3, 11, 20, 30};
    int expected = 292;
    int actual = time_taken_by_winner(n, weights);
    return 0;
}