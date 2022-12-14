import java.util.*;

class Pro_level3_67259 {
    int answer = Integer.MAX_VALUE;
    int[][][] visited;
    int[] dr = {0, 0, 1, -1}; //동 서 남 북
    int[] dc = {1, -1, 0, 0};
    public int solution(int[][] board) {
        //경주로 건설을 위한 최소 비용. 직선 - 100원, 코너 500원
        //0 - 비어있음 1 - 벽
        
        int len = board.length;
        visited = new int[len][len][4];
        
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                for(int k=0; k<4; k++){
                    visited[i][j][k] = Integer.MAX_VALUE;
                }
            }
        }
        
        bfs(0, 0, len, board);
        
        return answer;
    }
    
    public void bfs(int r, int c, int len, int[][] board){
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(r, c, 0, -1));    
        
        
        while(!q.isEmpty()){
            Point p = q.poll();
            int x = p.x;
            int y = p.y;
            int m = p.money;
            int d = p.dir;

            
            if(x==len-1 && y==len-1){
               answer = Math.min(answer, m); 
            }
            
            for(int i=0; i<4; i++){
                int nr = x + dr[i];
                int nc = y + dc[i];

                if(nr<0 || nc<0 || nr>=len || nc>=len || board[nr][nc]==1 ) continue;
                
                int cost = m;
                //직선 코스
                if(d==i || d==-1){
                    cost += 100;
                }
                else{ //곡선 코스
                   cost += 600; 
                }
                
                //갱신
                if(visited[nr][nc][i] >= cost){
                    visited[nr][nc][i] = cost;
                    q.add(new Point(nr, nc, cost, i));
                }
            }
        }
        
    }
    
    static class Point{
        int x, y, money, dir;
        Point(int x, int y, int money, int dir){
            this.x = x;
            this.y = y;
            this.money = money;
            this.dir = dir;
        }
    }
}