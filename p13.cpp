#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
#define INF       (int)1e9

class node{
    public:
    int key;
    int status;
    vector<pair<int,int> > adj;
    node(){
        key=INF;
        status=1;
    }
};

node *nodes;

struct myclass
 {
        bool operator() (node *a,node *b) {
            return (a->key) > (b->key);
         }
 }myobject;

int main(){

    int n,m,t1,t2,t3;
    vector<node*> x,y;
    ifstream fin("edges1.txt");
    fin>>n>>m;
    nodes = new node[n];
    while(1)
    {
        fin>>t1>>t2>>t3;
        if(fin.eof())break;
        pair<int ,int > p(t2,t3);
        nodes[t1-1].adj.push_back(p);
        pair<int ,int > r(t1,t3);
        nodes[t2-1].adj.push_back(r);

    }

    int st=7  ;  //from 0

    nodes[st].status=0;
    x.push_back(&nodes[st]);

    for(int i=0;i<n;i++)
        if(i!=st)
            y.push_back(&nodes[i]);


    for(unsigned int i=0;i<nodes[st].adj.size();i++)
        if(nodes[st].adj[i].second < nodes[nodes[st].adj[i].first-1].key)
            nodes[nodes[st].adj[i].first-1].key = nodes[st].adj[i].second;

    make_heap(y.begin(),y.end(),myobject);

    node *temp;
    long long int ans=0;

   while(!y.empty()){

        temp=y.front();
        ans+=temp->key;
        temp->key=INF;
        temp->status=0;
        x.push_back(temp);

        for(unsigned int i=0;i<temp->adj.size();i++)
            if(nodes[temp->adj[i].first-1].status==1 && temp->adj[i].second < nodes[temp->adj[i].first-1].key)
                 nodes[temp->adj[i].first-1].key = temp->adj[i].second;

        pop_heap(y.begin(),y.end());
        y.pop_back();
        make_heap(y.begin(),y.end(),myobject);
    }
    cout<<ans;
}
