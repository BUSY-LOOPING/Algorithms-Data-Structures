#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    int n = 0, m = 0;
    cout << "Enter the number of nodes and no of links you want to enter : ";
    cin >> n >> m;
    vector<int> vec[20]; 
    vector<bool> visitedVector(n);

    for (int i = 0; i < n; i++)
    {
        visitedVector[i] = false;
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


    queue<int> queue;
    queue.push(start);
    visitedVector[start] = true;
    
    while (!queue.empty()) {
        int node = queue.front();

        queue.pop();
        cout << node <<endl;

        vector<int> :: iterator it;
    
        for (it = vec[node].begin() ;it != vec[node].end() ; it++) {
            if (!visitedVector[*it]) {
                visitedVector[*it] = true;
                queue.push(*it);
            }
        }
    }
}