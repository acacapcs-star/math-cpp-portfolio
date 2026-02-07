#include<bits/stdc++.h>
using namespace std;
int posR[15][65537]; 
int posC[15][65537];
int main(){
    int n, m;
    cin >> n >> m;

    int N = n; 
    string p[15]; 
    int B[15][256][256]; 
    
    for(int k = 0; k < N; k++){
        cin >> p[k];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                cin >> B[k][i][j];
                posR[k][B[k][i][j]] = i;
                posC[k][B[k][i][j]] = j;
            }
        }
    }
    
    int b[65536]; 
    for(int i = 0; i < m * m; i++){
        cin >> b[i];
    }

    for(int t = 0; t < m * m; t++){
        int cur = b[t]; 
        bool sb_win = false;
        bool win_flag[15] = {false}; 

        for(int k = 0; k < N; k++){
            int r_pos = posR[k][cur];
            int c_pos = posC[k][cur];
            // 標記為 0
            B[k][r_pos][c_pos] = 0;
            // 只檢查被影響的那一行和那一列
            int r_cnt = 0, c_cnt = 0;
            for(int j = 0; j < m; j++){
                if(B[k][r_pos][j] == 0){
                    r_cnt++;
                }
                if(B[k][j][c_pos] == 0){
                    c_cnt++;
                }
            }

            if(r_cnt == m || c_cnt == m){
                win_flag[k] = true;
            }
            // 只在需要時檢查對角線
            if(r_pos == c_pos || r_pos + c_pos == m - 1){
                int d1 = 0, d2 = 0;
                for(int i = 0; i < m; i++){
                    if(B[k][i][i] == 0){
                        d1++;
                    }
                    if(B[k][i][m - 1 - i] == 0){
                        d2++;
                    }
                }
                if(d1 == m || d2 == m){
                    win_flag[k] = true;
                }
            }

            if(win_flag[k]){
                sb_win = true;
            }
        }

        if(sb_win){
            cout << cur;
            for(int k = 0; k < N; k++){
                if(win_flag[k]){
                    cout << " " << p[k];
                }
            }
            cout << endl;
            return 0; 
        }
    }
    return 0;
}