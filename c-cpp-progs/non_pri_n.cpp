
#include <bits/stdc++.h>
using namespace std;
int totalprocess;

struct process
{
int at,bt,pr,pno;
};
 
process proc[50];

bool comp(process a,process b)
{
if(a.at == b.at)
{
return a.pr<b.pr;
}
else
{
    return a.at<b.at;
}
}
 

void get_wt_time(int wt[])
{

int service[50];

service[0] = proc[0].at;
wt[0]=0;
 
 
for(int i=1;i<totalprocess;i++)
{
service[i]=proc[i-1].bt+service[i-1];
 
wt[i]=service[i]-proc[i].at;

     
    if(wt[i]<0)
    {
    wt[i]=0;
    }
}
 
}
 
void get_tat_time(int tat[],int wt[])
{

for(int i=0;i<totalprocess;i++)
{
    tat[i]=proc[i].bt+wt[i];
}
     
}
 
void findgc()
{

int wt[50],tat[50];
 
double wavg=0,tavg=0;

get_wt_time(wt);

get_tat_time(tat,wt);
     
int stime[50],ctime[50];
 
stime[0] = proc[0].at;
ctime[0]=stime[0]+tat[0];

for(int i=1;i<totalprocess;i++)
    {
        stime[i]=ctime[i-1];
        ctime[i]=stime[i]+tat[i]-wt[i];
    }
    
     cout<<"\n-------------------------------------------------------------------------------------\n\n";
    cout<<"PROCESS    \tBURST TIME\tARRIVAL TIME\tPRIORITY\tTURN AROUND TIME\tWAITING TIME  \n";

     
     for(int i=0;i<totalprocess;i++)
     {
     	wavg+=wt[i];
     	tavg+=tat[i];
     	
     	cout<<proc[i].pno<<" \t\t  "<<proc[i].bt<<" \t\t     "<<proc[i].at<<" \t\t  "<<proc[i].pr<<" \t\t  "<<tat[i]<<" \t\t          "<<wt[i]<<endl;
	 }
  cout<<"\n-------------------------------------------------------------------------------------\n\n";
     
    cout<<"Average waiting time: ";
    cout<<wavg/(float)totalprocess<<endl;
    cout<<"Average turnaround time: ";
    cout<<tavg/(float)totalprocess<<endl;
 
}
 
int main()
{
	int arrivaltime[20],bursttime[20],priority[20];

cout<<"\nEnter number of processes: ";
cin>>totalprocess;

for(int i=0;i<totalprocess;i++)
{
	cout<<"\nFOR PROCESS "<<i+1<<" : \n";
	cout<<"Enter burst time: ";
	cin>>bursttime[i];
	
	cout<<"Enter arrival time: ";
	cin>>arrivaltime[i];
	
	cout<<"Enter priority: ";
	cin>>priority[i];
}

     
for(int i=0;i<totalprocess;i++)
{
    proc[i].at=arrivaltime[i];
    proc[i].bt=bursttime[i];
    proc[i].pr=priority[i];
    proc[i].pno=i+1;
    }

     
    sort(proc,proc+totalprocess,comp);

    findgc();
 
    return 0;
}

