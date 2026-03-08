/*
    we have a {sr,sc} and a color 
        we have to change the color of  this index and then
            its adjacent neigbours 
        
    [i-1][j]  [i+1][j]  [i][j-1]  [i][j+1] will became rotten........

        then also perfrom the same thing for this index too.......

    Step 1: Initialize
        Queue → store sr,sc
        change the color of {sr,sc}

    Step 2: BFS
        While queue not empty:
            
            check neigbours :  {1,0}, {-1,0}, {0,1}, {0,-1}
        
        if(inBoundry && checkcolor == original color){
            push it into queue
            change color 
        }

    at the end just return grid 
    
    one more important thing we only change that cells whose color is same as {sr,sc} 
        in starting.......

        means before changing sr,sc 
            we store it and then change pixel who are match with this......
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        int original = image[sr][sc];
        if(original == color) return image;   // important edge case
        
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx>=0 && ny>=0 && nx<n && ny<m 
                   && image[nx][ny] == original){
                       
                    image[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }
        
        return image;
    }
};
