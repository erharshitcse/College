#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Process {
int id;
int arrivalTime;
int burstTime;
int priority;
int remainingTime;
int turnaroundTime;
int waitingTime;
int completionTime;
};
bool compareArrivalTime(const Process& p1, const Process& p2) {
return p1.arrivalTime < p2.arrivalTime;
}
bool comparePriority(const Process& p1, const Process& p2) {
return p1.priority < p2.priority;
}
void preemptivePriorityScheduling(vector<Process>& processes) {
int n = processes.size();
int currentTime = 0;
int completedProcesses = 0;
while (completedProcesses < n) {
sort(processes.begin(), processes.end(), comparePriority);
int shortestProcess = -1;
int shortestPriority = INT_MAX;
for (int i = 0; i < n; i++) {
if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 &&
processes[i].priority < shortestPriority) {
shortestProcess = i;
shortestPriority = processes[i].priority;
}
}
if (shortestProcess == -1) {
currentTime++;
continue;
}
processes[shortestProcess].remainingTime--;
currentTime++;
if (processes[shortestProcess].remainingTime == 0) {
completedProcesses++;
processes[shortestProcess].completionTime = currentTime;
processes[shortestProcess].turnaroundTime = processes[shortestProcess].completionTime -
processes[shortestProcess].arrivalTime;
processes[shortestProcess].waitingTime = processes[shortestProcess].turnaroundTime -
processes[shortestProcess].burstTime;
}
}
}
int main() {
int n;
cout << "Enter the number of processes: ";
cin >> n;
vector<Process> processes(n);
cout << "Enter the arrival time, burst time, and priority for each process:\n";
for (int i = 0; i < n; i++) {
processes[i].id = i + 1;
cout << "Process " << processes[i].id << ": ";
cin >> processes[i].arrivalTime >> processes[i].burstTime >> processes[i].priority;
processes[i].remainingTime = processes[i].burstTime;
}
preemptivePriorityScheduling(processes);
cout << "\nPreemptive Priority Scheduling:\n";
cout << "Process\tPriority\tArrival Time\tBurst Time\tCompletion Time\tTurnaround 
Time\tWaiting
Time\n";
double totalTurnaroundTime = 0.0;
double totalWaitingTime = 0.0;
for (const Process& process : processes) {
cout << "P" << process.id << "\t" << process.priority << "\t\t" << process.arrivalTime << "\t\t"
<< process.burstTime << "\t\t" << process.completionTime << "\t\t" << process.turnaroundTime 
<<
"\t\t" << process.waitingTime << endl;
totalTurnaroundTime += process.turnaroundTime;
totalWaitingTime += process.waitingTime;
}
double averageTurnaroundTime = totalTurnaroundTime / n;
double averageWaitingTime = totalWaitingTime / n;
cout << "\nAverage Turnaround Time = " << averageTurnaroundTime << endl;
cout << "Average Waiting Time = " << averageWaitingTime << endl;
return 0;
}