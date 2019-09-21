#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int vi[10001]; //time performance from each cachier
int c;

priority_queue< pair<int, int> > cachier_queue;

int total_time = 0;

int main() {
    int n,m; //n cachiers and m clients
    cin >> n >> m;
    for (int i=0; i<n; i++)//reading cachier time
        cin >> vi[i];

    /* 
    - Adding as negative numbers in order to create a minimum heap.
    - If more than one cashier are free at the same time, client will 
    be attended by the cashier with the lowest identification number.
    */
    for(int i = 0; i < n; i++)
        cachier_queue.push( make_pair(0, -i) );

    while (m--) {
        cin >> c;
        int chachier = -cachier_queue.top().second; //id of the first consumer
        int wait_time = -cachier_queue.top().first; //available cachier
        cachier_queue.pop();
        cachier_queue.push( make_pair( -(wait_time+vi[chachier]*c), -chachier ) );
        total_time = max(total_time, wait_time+vi[chachier]*c);
    }

    cout << total_time << endl;

    return 0;
}