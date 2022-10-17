#include <iostream>
#include <queue>

using namespace std;

template <class T>
class Node<T> {
    T data;
    bool visited;
};

class BFS {

};

// Print the queue
void showq(queue<int> g)
{
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main() {
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    showq(queue);
    showq(queue);
}