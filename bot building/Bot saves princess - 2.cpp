#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
void print(int n,int mx,int my,int px, int py){
    for(int i = 0; i < n;i++){
        stringstream ss("");
        for(int j = 0; j < n;j++){
            if( i == mx && j == my){
                ss << "m";
                continue;
            }
            if( i == px & j == py){
                ss << "p";
                    continue;
            }
            ss << "-";
        }
        cout << ss.str() << endl;
    }
    return;
}

void nextMove(int n, int r, int c, vector <string> grid){
    int mx = r,my = c,px,py;
    for(int i = 0; i < n;i++){
        stringstream ss(grid[i]);
        char ch;
        for(int j = 0; j < n;j++){
            ss >> ch;
            if(ch == 'p'){
                px = i;
                py = j;
                //cout << "px : " << px << " py : " << py << " mx : " << mx << " my : " << my << endl;
                if(mx - px < 0){
                    cout << "DOWN" << endl;
                    //++mx;
                    //print(n,mx,my,px,py);
                    return;
                }
                if(mx - px > 0){
                    cout << "UP" << endl;
                    //--mx;
                    //print(n,mx,my,px,py);
                    return;
                }
                if(my - py < 0){
                    cout << "RIGHT" << endl;
                    //++my;
                    //print(n,mx,my,px,py);
                   return;
                }
                if(my - py > 0){
                    cout << "LEFT" << endl;
                    //--my;
                    //print(n,mx,my,px,py);
                    return;
                }
            }
        }   
    }
}


int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}