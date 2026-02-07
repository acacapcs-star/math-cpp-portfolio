
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    long long L; // 水量可能很大，用 long long 比較保險
    cin >> n >> m >> L;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> result(n, vector<int>(m, 0));
    
    if(L > 0){
        // 找出地圖中的最低高度
        int min_h = 2000000000;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                min_h = min(min_h, a[i][j]);

        // 水只要大於 0，最低的那層一定會淹水
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(a[i][j] == min_h) result[i][j] = 1;

        // 開始從最低高度往上漲水
        int cur_h = min_h;
        while(L > 0) {
            long long cnt = 0;
            // 1. 數數看現在有多少格子已經淹水了（或是高度 <= current_h）
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    if(a[i][j] <= cur_h) cnt++;

            // 2. 嘗試把這些淹水的格子「往上填高 1 公分」
            if(L > cnt) {
                L -= cnt; // 夠填滿這一公分
                cur_h++; // 水位升高）
                for(int i=0; i<n; i++)
                    for(int j=0; j<m; j++)
                        if(a[i][j] <= cur_h) result[i][j] = 1;
            } else {
                L = 0; 
            }
            if(cnt == n * m && L > 0) break; 
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}