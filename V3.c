#include<stdio.h>

void main()
{
    /*	at = Arrival Time		bt = Burst Time		p = Process		
		wt = Waiting Time		tat = Turnaround Time
		avg_wt = Average Waiting Time
		avg_tat = Avrage Turnaround Time  	*/
	
	int at[20],bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process: ");
    scanf("%d",&n);
 
    printf("\nEnter Arrival Time: \n");
    for(i=0;i<n;i++)
    {
        printf("p%d: ",i+1);
        scanf("%d",&at[i]);
        p[i]=i+1;           //contains process number
        bt[i] = 2 * at[i];		// Calculate burst time from arrival time.
    }
    
 
    //sorting burst time in decending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
        	if(bt[i]<bt[j] && p[i]<p[j] && at[i]<at[j])
        	{
        		temp=at[i];
        		at[i]=at[j];
        		at[j]=temp; 

        		temp=bt[i];
        		bt[i]=bt[j];
        		bt[j]=temp;
 
        		temp=p[i];
        		p[i]=p[j];
        		p[j]=temp;
			}
        }

    }
 
    wt[0]=0;	//waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
 
    printf("\nProcess \t Arrival time  \t Burst Time \tWaiting Time \t Turnaround Time");
    
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\n p%d \t\t %d \t\t %d \t\t %d \t\t %d",p[i],at[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    
    printf("\n\nAverage Waiting Time = %f",avg_wt);
    printf("\nAverage Turnaround Time = %f\n",avg_tat);
}
