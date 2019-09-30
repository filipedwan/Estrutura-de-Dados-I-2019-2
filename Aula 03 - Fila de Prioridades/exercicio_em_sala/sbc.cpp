#include<iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n, t, c;
    long long int wait;
    long long int run_time;
    priority_queue< pair<int, int>, vector< pair<int, int> > > processes;
    priority_queue< pair<int, int>, vector< pair<int, int> > > execTime;
    pair<int, int> aux;

    while(cin >> n){
        wait = 0;
        run_time = 0;

        for(int i = 0; i < n; i++) {
            cin >> t >> c;
            processes.push(make_pair(-t, -c));
        }

        run_time = -processes.top().first;

        while(!processes.empty()) {
            aux = processes.top();
            if(-aux.first > run_time) {
                if(-execTime.top().second <= run_time){
                    wait += run_time + execTime.top().second;
                }else{
                    run_time = -execTime.top().second;
                }
                run_time += -execTime.top().first;

                execTime.pop();
            }
            execTime.push(make_pair(aux.second, aux.first));
            processes.pop();
        }

        while(!execTime.empty()) {
            if(-execTime.top().second <= run_time){
                wait += run_time + execTime.top().second;
            }else{
                run_time = -execTime.top().second;
            }
            run_time += -execTime.top().first;

            execTime.pop();
        }

        cout << wait << endl;
    }

    return 0;
}