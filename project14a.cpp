#include<stdio.h>
#include<Math.h>
int P[4]={4,3,1};
int B[4]={8,6,4};
int BB[4]={8,6,4};
int A[4]={0,2,5};


int ct = 0,rp=0;
static int n = 3;
int arrived [3] = {INFINITY,INFINITY,INFINITY};
int current_executing = -1;
int finishTime[3]={-1,-1,-1};
int calculateBurst()
{
	int burst =0;
	for(int i=0;i<n;i++)
	{
		burst+=B[i];
	}
	return burst;
}

void checkArrived()
{
	for(int i=0;i<n;i++)
	{
		if(ct>=A[i])
		{
			arrived[i]=P[i];
		}
	}
}

/*void age()
{
	if(ct<2)return;
	if(ct%2==0)
	{
		for(int i=0;i<n;i++)
		{
			if(i==rp)continue;
			
			arrived[i]--;
		}
	}
}
*/
int getrp()
{
	
	int rrp = 0;
	for(int i=0;i<n;i++)
	{
		//if(B[i]==0)P[i]=INFINITY;
		if(B[i]>0 && arrived[rrp]>arrived[i] )
		{
			rrp = i;
		}
	}
	return rrp;
}

void show()
{
		printf("\n current time = %d",ct);
			for(int i=0;i<n;i++)
		{
			printf("\n burst of %d = %d --- priority of %d = %d",i,B[i],i,arrived[i]);
		}

}
int main()
{
	int calculated_burst = calculateBurst();
	while(calculated_burst>0)
	{
		if(ct>0 && ct%2==0)
		{
			for(int i=0;i<n;i++)
			{
				if(i != rp &&P[i] ==arrived[i]) P[i]--;
			}
		}
		
		checkArrived();
		rp = getrp();
		if(current_executing != -1 && rp!=current_executing && B[current_executing]>0)
		{
			show();ct++;
			printf("\n\nswitching process\n");
			
			checkArrived();
			show();ct++;
			printf("\n\nswitching process\n");
			
			checkArrived();
		}
		if(B[rp]>0 )
		{
			B[rp]--;
		}
		current_executing = rp;		
		
		calculated_burst = calculateBurst();
		show();
		for(int i=0;i<n;i++)
		{
			if(B[i]==0 && finishTime[i]==-1)
			{
				finishTime[i]=ct;
			}
		}
		ct++;
	}
	
	int totalta = 0;
	int totalwt = 0;
	for(int i=0;i<n;i++)
	{
		printf("\nprocess %d finished at %d",i,finishTime[i]);
		int tat =finishTime[i]-A[i];
		int wt = tat - BB[i];
		printf("\nTurn Around Time for process P%d is %d",i,tat);
		printf("\nWaiting time for process P%d is %d",i,wt);
		totalta+=tat;
		totalwt+=wt;
	}
	printf("\n average Turn Around time = %d",totalta/n);
	printf("\n average Waiting time = %d",totalwt/n);
}
