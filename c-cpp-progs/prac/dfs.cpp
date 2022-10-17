#include <iostream>
#include <queue> 
#include <vector>
using namespace std;
vector<int> vec[20]; 
bool visited[20];

void dfs (int startNode) {
    //preorder
    visited[startNode] = true;    
    cout << startNode;

    //inorder
    vector<int> :: iterator it;
    for (it = vec[startNode].begin() ; it != vec[startNode].end() ; it++)
    {
        if (!visited[*it]) {
            dfs(*it);
        }
    }

}

int main() {
    int n = 0, m = 0;
    cout << "Enter the number of nodes and no of links you want to enter : ";
    cin >> n >> m;
    

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    
    cout << "Enter the node links-> \n";
    for (int i = 0; i < m ;i ++) {  
        int x = 0, y= 0;
        cin >> x >> y ;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    int start = 0;
    cout << "Enter the start node : ";
    cin >> start;

    dfs(start);
}