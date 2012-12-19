#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

bool myfunction (pair<pair<int,int>,int> i,pair<pair<int,int>,int> j) { return (i.second<j.second); }

int main(){
    vector<pair<pair<int,int>,int> >edges;
    int n,m,t1,t2,t3;
    ifstream fin("edges1.txt");
    fin>>n>>m;
    int *nodes = new int[n];
    int *id = new int[n];
    for(int i=0;i<n;i++)    id[i]=i;    //every node is a leader of itself
    int *size = new int[n];
    for(int i=0;i<n;i++)    size[i]=1;

    while(1)
    {
        fin>>t1>>t2>>t3;
        if(fin.eof())break;
        edges.push_back(make_pair(make_pair(t1,t2),t3));
    }
    sort(edges.begin(),edges.end(),myfunction);
 //   for(int i=0;i<edges.size();i++)
   //     cout<<edges[i].first.first<<" "<<edges[i].first.second<<" "<<edges[i].second<<endl;

    long long ans=0;
    for(int i=0;i<edges.size();i++)
    {
        t1=edges[i].first.first;
        t2=edges[i].first.second;
        t3=edges[i].second;
        if(id[t1-1]==id[t2-1])continue;
        ans+=t3;
        if(size[id[t1-1]] > size[id[t2-1]])
        {
            size[id[t1-1]]+=size[id[t2-1]];
            size[id[t2-1]]=0;
            int pid=id[t2-1];
            for(int i=0;i<n;i++)
                if(id[i]==pid)
                    id[i]=id[t1-1];
        }
        else
        {
            size[id[t2-1]]+=size[id[t1-1]];
            size[id[t1-1]]=0;
            int pid=id[t1-1];
            for(int i=0;i<n;i++)
                if(id[i]==pid)
                    id[i]=id[t2-1];
        }

    }
    cout<<ans;
}
