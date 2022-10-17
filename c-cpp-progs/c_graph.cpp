#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int v,count1=0,count2=0,e;
	cout<<"Enter number of vertices"<<endl;
	cin>>v;
	char vertex[v];
	int matrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            matrix[i][j]=0;
        }
    }
	cout<<"Enter vertex"<<endl;
	for(int i =0;i<v;i++)
	{
		cin>>vertex[i];
	}
	cout<<"Enter number of edges"<<endl;
	cin>>e;
	char edge1[e],edge2[e];
	for(int i=0;i<e;i++)
	{
		cout<<"Enter "<<i+1<<" edge"<<endl;
		cin>>edge1[i];
		cin>>edge2[i];
	}
		for(int i=0;i<e;i++){
		int pos_i,pos_j;
		for(int j=0;j<v;j++){
			if(vertex[j]==edge1[i])
				pos_i=j;
			if(vertex[j]==edge2[i])
				pos_j=j;
		}
		matrix[pos_i][pos_j]=matrix[pos_i][pos_j]+1;
		matrix[pos_j][pos_i]=matrix[pos_j][pos_i]+1;
	}
	cout<<endl<<endl<<"Matrix is "<<endl<<endl;
	for(int i=0;i<v;i++)
	cout<<setw(3)<<vertex[i]<<"\t";
	cout<<endl;
	for(int i=0;i<v;i++){
		cout<<vertex[i];
		for(int j=0;j<v;j++)
			cout<<setw(3)<<matrix[i][j]<<"\t";
		cout<<endl;
	}
		for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i==j&&matrix[i][j]==0)
			count1++;
			if(i!=j&&matrix[i][j]==1)
			count2++;
		}
	}
	if(count1==v&&count2==(v*v-v))
	cout<<"The graph is a complete graph"<<endl;
	else
	cout<<"The graph is not a complete graph"<<endl;
	
}
