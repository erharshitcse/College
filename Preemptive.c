78 #include<stdio.h>
79
80 int main()
81 {
82 int
bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
83 printf("Enter Total Number of Process:");
84 scanf("%d",&n);
85
86 printf("\nEnter Burst Time and Priority\n");
87 for(i=0;i<n;i++)
88 {
89 printf("\nP[%d]\n",i+1);
90 printf("Burst Time:");
91 scanf("%d",&bt[i]);
92 printf("Priority:");
93 scanf("%d",&pr[i]);
94 p[i]=i+1; //contains process number
95 }
96
97 //sorting burst time, priority and process number in ascending order using 
selection sort
98 for(i=0;i<n;i++)
99 {
100 pos=i;
101 for(j=i+1;j<n;j++)
102 {
103 if(pr[j]<pr[pos])
104 pos=j;
105 }
106
107 temp=pr[i];
108 pr[i]=pr[pos];
109 pr[pos]=temp;
110
111 temp=bt[i];
112 bt[i]=bt[pos];
113 bt[pos]=temp;
114
115 temp=p[i];
116 p[i]=p[pos];
117 p[pos]=temp;
118 }
119
120 wt[0]=0; //waiting time for first process is zero
121
122 //calculate waiting time
123 for(i=1;i<n;i++)
124 {
125 wt[i]=0;
126 for(j=0;j<i;j++)
127 wt[i]+=bt[j];
128
129 total+=wt[i];
130 }
131
132 avg_wt=total/n; //average waiting time
133 total=0;
134
135 printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
136 for(i=0;i<n;i++)
137 {
138 tat[i]=bt[i]+wt[i]; //calculate turnaround time
139 total+=tat[i];
140 printf("\nP[%d]\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
141 }
142
143 avg_tat=total/n; //average turnaround time
144 printf("\n\nAverage Waiting Time=%d",avg_wt);
145 printf("\nAverage Turnaround Time=%d\n",avg_tat);
146
147 return 0;
148}
