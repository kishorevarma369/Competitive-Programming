#include<bits/stdc++.h>

using namespace std;

map<char,pair<int,int>> questions;

int cmp(tuple<int,float,float> &a,tuple<int,float,float> &b)
{
    int c,d,e,f,g,h;
    tie(c,d,e)=a;
    tie(h,f,g)=b;
    if(d==f)
    {
        if(e==g) return c<h;
        return e>g;
    } 
    return d>f;
}

int main(int argc, char const *argv[])
{
    int nq,score,tests,nu,ns;
    char ch;
    cin>>nq;
    for(int i=0;i<nq;i++)
    {
        cin>>ch>>score>>tests;
        questions[ch]={score,tests};
    } 
    cin>>nu>>ns;
    int user,submissionid,no_of_tests_passed;
    char ques;
    string state;
    float marks=0;
    auto question=questions.begin()->second;
    map<int,map<char,float>> scoreboard;
    vector<tuple<int,float,float>> finalboard;
    float prevres;
    for(int i=0;i<ns;i++)
    {
        cin>>user>>ques>>submissionid;
        question=questions[ques];
        tests=question.second;
        no_of_tests_passed=0;
        marks=0;
        for(int i=0;i<tests;i++)
        {
            cin>>state;
            if(state=="A") no_of_tests_passed++;
        }
        marks=float(question.first*no_of_tests_passed)/tests;
        prevres=scoreboard[user][ques];
        if(marks>prevres) scoreboard[user][ques]=marks;
    }
    map<char,float> userres;
    for(auto &player:scoreboard)
    {
        user=player.first;
        auto userres=player.second;
        pair<float,float> pr;
        for(auto question:userres)
        {
            if(question.second!=float(questions[question.first].first)) pr.second+=question.second;
            else pr.first+=question.second;
        }
        if(pr.first+pr.second) finalboard.push_back(tuple<int,float,float>(user,pr.first,pr.second));
    }
    sort(finalboard.begin(),finalboard.end(),cmp);
    int rank=1,tprank=1;
    float fullpoints,partialpoints,prevfullpoints,prevpartialpoints;
    auto it=finalboard.begin();
    tie(user,prevfullpoints,prevpartialpoints)=*it;
    cout<<rank<<' '<<user<<' '<<prevfullpoints<<' ';
    printf("%.2f\n",prevpartialpoints);
    tprank++;
    it++;
    int tmp1,tmp2;
    while(it!=finalboard.end())
    {
        tie(user,fullpoints,partialpoints)=*it;
        if(prevfullpoints==fullpoints&&prevpartialpoints==partialpoints)
        {
            cout<<rank<<' '<<user<<' '<<fullpoints<<' ';
            printf("%.2f\n",partialpoints);
            it++;
            tprank++;
            continue;
        }
        rank=tprank;
        cout<<rank<<' '<<user<<' '<<fullpoints<<' ';
        tmp1=partialpoints;
        tmp1=(partialpoints-tmp1)*100;
        //printf("%.2f\n",partialpoints);
        if((tmp1%10)==0) printf("%.1f\n",partialpoints);
        else printf("%.2f\n",partialpoints);
        prevfullpoints=fullpoints;
        prevpartialpoints==partialpoints;
        tprank++;
        it++;
    }
    return 0;
}
