//Sharma ji ka Ladka Code Karta h !!!

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int testcases;
    cin >> testcases;
    for(int r = 0; r < testcases; r++){
    bool done = false;
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> times;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        times.push_back(make_pair(make_pair(a, 2), i));//adding
        times.push_back(make_pair(make_pair(b, 1), i));//removal
    }
    sort(times.begin(), times.end());
    bool Ctaken = false;
    bool Jtaken = false;
    int Cjob = -1;
    int Jjob = -1;
    string s = "";
    for(int i = 0; i < n; i++){
        s += " ";
    }
    for(int i = 0; i < times.size(); i++){
        if(Ctaken == true && Jtaken == true && times[i].first.second == 2){
            cout << "Case #" << r + 1 << ": " << "IMPOSSIBLE" << endl;
            done = true;
            break;
        }
        else if(times[i].first.second == 2 && Ctaken == false){
            Ctaken = true;
            Cjob = times[i].second;
            s[Cjob] = 'C';
            continue;
        }
        else if(times[i].first.second == 2 && Ctaken == true){
            Jtaken = true;
            Jjob = times[i].second;
            s[Jjob] = 'J';
            continue;
        }
        else if(times[i].first.second == 1){
            int curJob = times[i].second;
            if(Cjob == curJob){
                Cjob = -1;
                Ctaken = false;
            }
            else if(Jjob == curJob){
                Jjob = -1;
                Jtaken = false;
            }
        }
    }
    if(done){
        continue;
    }
    cout << "Case #" << r + 1 << ": " << s << endl;
    }
}