#include<iostream>
#include<string>
#include<limits>
#include"Stack.h"
#include "SLL.h"
using namespace std;

class DFS{
	private:
	int nov;
	int noe;
	SLL<int>* arr;
	public:
	DFS(int v,int e){
		nov=v;
		noe=e;
		arr=new SLL<int>[nov];
	}
	void input(){
		string t;
		int v1,v2;
		for(int i=0;i<noe;i++){
			cout<<"Enter the vertices of the "<<i+1<<"edge."<<endl;
			cin>>v1;
			cin>>v2;
			arr[v1].addFront(v2);
			arr[v2].addFront(v1);
		}
	}

	void dfs(int start){
		bool visited[nov];
		for(int i=0;i<nov;i++){
			visited[i]=false;
		}
		Stack<int> s(nov);
		s.push(start);
		visited[start]=true;
		while(!s.empty()){
			int curr=s.top();
			Node<int>* t=arr[curr].frontNode();
			s.pop();
			while(t!=NULL){
				if(!visited[t->data]){
					visited[t->data]=true;
					s.push(t->data);
				}
				t=t->next;
			}
			cout<<curr<<endl;
		}
	}
};

int main(){
	int v,e;
	cout<<"Enter the number of vertices."<<endl;
	cin>>v;
	cout<<"Enter the number of edges."<<endl;
	cin>>e;
	DFS b(v,e);
	b.input();
	int s;
	cout<<"Enter the source vertice."<<endl;
	cin>>s;
	b.dfs(s);
}