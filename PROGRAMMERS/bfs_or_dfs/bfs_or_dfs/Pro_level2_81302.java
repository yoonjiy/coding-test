package bfs_or_dfs;

import java.util.*;

class Pro_level2_81302 {
    int[] dr = {0, 0, 1, -1, 0, 0, 2, -2, 1, 1, -1, -1};
    int[] dc = {1, -1, 0, 0, 2, -2, 0, 0, 1, -1, -1, 1};
    public int[] solution(String[][] places) {    
        int[] answer = new int[5];
        char[][] seat = new char[5][5];
        //각 대기실별로 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 배열에 담아 return 
        //P 응시자 자리, 0 빈 테이블, X 파티션
        for(int i=0; i<5; i++){
            int p = 0;
            for(int j=0; j<5; j++){
                String s = places[i][j];
                for(int k=0; k<5; k++){
                    seat[j][k] = s.charAt(k);
                }
            }
            
            if(bfs(seat)){
                answer[i] = 1;
            }
            else answer[i] = 0;
        }
        
        return answer;
    }
    
    public boolean bfs(char[][] seat){
        Queue<Point> q = new LinkedList<>();
        
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(seat[i][j]=='P'){
                    q.add(new Point(i, j));   
                }
            }
        }
        
        while(!q.isEmpty()){
            Point n = q.poll();
            
            //맨해튼 거리 1 이하 탐색
            for(int i=0; i<4; i++){
                int nr = n.r + dr[i];
                int nc = n.c + dc[i];
                
                if(nr < 0 || nc < 0 || nr>=5 || nc>=5) continue;
                
                //P가 있다면
                if(seat[nr][nc]=='P') return false;
            }
            
            //맨해튼 거리 2, 직선 위치 탐색
            for(int i=4; i<8; i++){
                int nr = n.r + dr[i];
                int nc = n.c + dc[i];
                
                if(nr < 0 || nc < 0 || nr>=5 || nc>=5) continue;
                
                if(seat[nr][nc]=='P'){
                    //r, c와 nr, nc 사이가 X가 아니라면
                    if(seat[(Math.abs(nr+n.r)/2)][Math.abs(nc+n.c)/2]!='X'){
                         return false;
                    }
                }
            }
            
            //맨해튼 거리 2, 대각선 위치 탐색
            for(int i=8; i<12; i++){
                int nr = n.r + dr[i];
                int nc = n.c + dc[i];
                
                if(nr < 0 || nc < 0 || nr>=5 || nc>=5) continue;
                
                if(seat[nr][nc]=='P'){
                    if(seat[n.r][nc]!='X' || seat[nr][n.c]!='X'){
                         return false;
                    }
                }
            }  
        }
        
        return true;
    }

    static class Point{
        int r, c;
        Point(int r, int c){
            this.r = r;
            this.c = c;
        }
    }

}