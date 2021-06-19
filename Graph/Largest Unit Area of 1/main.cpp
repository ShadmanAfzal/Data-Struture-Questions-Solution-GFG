// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Move{
public:
    int x,y;
    Move(){}
    Move(int x,int y){
        this->x = x;
        this->y = y;
    }
};

class Solution
{
    public:
    
    bool isValid(int x,int y,int row,int col,vector<vector<int>> grid){
        return (x>=0 and x<row and y>=0 and y<col and grid[x][y]==1);
    }
    
    int getmaxArea(vector<vector<int>> grid,int i,int j,int row,int col){
        queue<Move> q;
        int distance = 0;
        int dx[] = {1,-1,0,0,1,-1,1,-1};
        int dy[] = {0,0,1,-1,1-1,-1,1};
        Move move;
        q.push(Move(i,j));
        
        while(!q.empty()){
            move = q.front();
            q.pop();
            
            if(isValid(move.x,move.y,row,col,grid)){
                distance++;
                grid[move.x][move.y] = 0;
                for(int a=0;a<row;a++){
                    q.push(Move(move.x+dx[a],move.y+dy[a]));
                }
            }
        }
        return distance;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        queue<Move> q;
        int maxArea = INT_MIN;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1)
                    maxArea = min(maxArea,getmaxArea(grid,i,j,row,col));
            }
        }
        return maxArea;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends