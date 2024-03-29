#include <iostream>
using namespace std;

int main()
{
	int n;
	cout<<"\nEnter the number of Processes :\n";
    cin>>n;
    int CPU = 0;     
    int allTime = 0; 
	cout<<"\nEnter the arrival time of the processes :\n";
    int arrivaltime[n];
    for(int j=0; j<n; j++){
    	cout<<"Enter["<<j+1<<"]:";
        cin>>arrivaltime[j];
    }
    cout<<"\nEnter the burst time of the processes :\n";
    int bursttime[n];
    for(int m=0; m<n; m++)
    {
        cout<<"Enter["<<m+1<<"]:";
        cin>>bursttime[m];
    }
    int priority[n];
    cout<<"\nEnter the priority of the processes :\n";
    for(int k=0; k<n; k++)
    {
        cout<<"Enter["<<k+1<<"]:";
        cin>>priority[k];
    }
    int ATt[n];
    int NoP = n; //number of Processes
    int PPt[n];
    int waitingTime[n];
    int turnaroundTime[n];
    int i = 0;

    for (i = 0; i < n; i++)
    {
        PPt[i] = priority[i];
        ATt[i] = arrivaltime[i];
    }

    int LAT = 0; //LastArrivalTime
    for (i = 0; i < n; i++)
        if (arrivaltime[i] > LAT)
            LAT = arrivaltime[i];

    int MAX_P = 0; //Max Priority
    for (i = 0; i < n; i++)
        if (PPt[i] > MAX_P)
            MAX_P = PPt[i];

    int ATi = 0;     //Pointing to Arrival Time indix
    int P1 = PPt[0]; //Pointing to 1st priority Value
    int P2 = PPt[0]; //Pointing to 2nd priority Value

    //finding the First Arrival Time and Highest priority Process
    int j = -1;
    while (NoP > 0 && CPU <= 1000)
    {
        for (i = 0; i < n; i++)
        {
            if ((ATt[i] <= CPU) && (ATt[i] != (LAT + 10)))
            {
                if (PPt[i] != (MAX_P + 1))
                {
                    P2 = PPt[i];
                    j = 1;

                    if (P2 < P1)
                    {
                        j = 1;
                        ATi = i;
                        P1 = PPt[i];
                        P2 = PPt[i];
                    }
                }
            }
        }

        if (j == -1)
        {
            CPU = CPU + 1;
            continue;
        }
        else
        {
            waitingTime[ATi] = CPU - ATt[ATi];
            CPU = CPU + bursttime[ATi];
            turnaroundTime[ATi] = CPU - ATt[ATi];
            ATt[ATi] = LAT + 10;
            j = -1;
            PPt[ATi] = MAX_P + 1;
            ATi = 0;        //Pointing to Arrival Time index
            P1 = MAX_P + 1; //Pointing to 1st priority Value
            P2 = MAX_P + 1; //Pointing to 2nd priority Value
            NoP = NoP - 1;
        }
    }

    cout << "\nProcess_Number\tBurst_Time\tPriority\tArrival_Time\tWaiting_Time\tTurnaround_Time\n\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << bursttime[i] << "\t\t" << priority[i] << "\t\t" << arrivaltime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }

    float AvgWT = 0;  //Average waiting time
    float AVGTaT = 0; // Average Turn around time
    for (i = 0; i < n; i++)
    {
        AvgWT = waitingTime[i] + AvgWT;
        AVGTaT = turnaroundTime[i] + AVGTaT;
    }

    cout << "Average waiting time = " << AvgWT / n << endl;
    cout << "Average turnaround time = " << AVGTaT / n << endl;
}
