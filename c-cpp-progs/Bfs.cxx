#include<iostream>
#include<string>
#include<limits>
#include"queue.h"
#include "SLL.h"
using namespace std;

class BFS{
	private:
	int v;
	int e;
	SLL<int>* arr;
	public:
	BFS(int v,int e){
		v=v;
		e=e;
		arr=new SLL<int>[v];
	}
	void input(){
		string t;
		int v1,v2;
		for(int i=0;i<e;i++){
			cout<<"Enter the vertices of the "<<i+1<<"edge."<<endl;
			cin>>v1;
			cin>>v2;
			v1--;
			v2--;
			arr[v1].addFront(v2);
		}
	}
	void bfs(int start){
		bool visited[v];
		int level[v];
		for(int i=0;i<v;i++){
			visited[i]=false;
			level[i]=std::numeric_limits<int>::min();
		}
		Queue<int> q(v);
		visited[start]=true;
		q.enqueue(start);
		level[start]=0;
		while(!q.empty()){
			int curr=q.front();
			Node<int>* t=arr[curr].frontNode();
			while(t!=NULL){
				if(!visited[t->data]){
					visited[t->data]=true;
					level[t->data]=level[curr]+1;
					q.enqueue(t->data);
				}
				t=t->next;
			}
			q.dequeue();
		}

		cout<<"Layers:"<<endl;
		for(int i=0;i<nov;i++){
			cout<<level[i]<<endl;
		}
	}
};

int main(){
	BFS b(6,7);
	b.input();
	b.bfs(0);
}