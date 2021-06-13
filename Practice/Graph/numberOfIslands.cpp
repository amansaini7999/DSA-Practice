#include<bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

bool isSafe(int M[][COL], int visited[][COL], int i, int j){
    return (i>=0 && j>=0 && i<ROW && j<COL && M[i][j] && !visited[i][j]);
}

void DFS(int M[][COL], int visited[][COL], int i, int j){

    visited[i][j]=1;

    int rowNumber[]={-1, -1, -1, 0, 0, 1, 1, 1};
    int colNumber[]={-1, 0, 1, -1, 1, -1, 0, 1};

    for(int k=0; k<8; k++){
        if(isSafe(M, visited, i+rowNumber[k], j+colNumber[k]))
            DFS(M, visited, i+rowNumber[k], j+colNumber[k]);
    }
}

int main(){
    
    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };

    int visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
    int count=0;

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(M[i][j] && !visited[i][j]){
                DFS(M, visited, i, j);
                count++;
            }
        }
    }

    cout<<count<<"\n";

    return 0;
}