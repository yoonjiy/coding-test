package bfs_dfs;
import java.io.*;
import java.util.*;

public class boj_18430_무기공학 {
    static int n, m;
    static int[][] board;
    static boolean[][] visited;
    static int answer = Integer.MIN_VALUE;
    public static void main(String[] args) throws Exception{
        //길동이가 만들 수 있는 부메랑들의 강도 합의 최댓값을 출력하는 프로그램을 작성하시오. 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        board = new int[n][m];
        for(int i=0; i<n; i++){
            st  = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        //부메랑을 만들 수 없는 경우는 0 반환
        if(n*m <= 3) {
            System.out.println(0);
            return;
        }
 
        visited = new boolean[n][m];
        dfs(0, 0);

        System.out.println(answer);
    }

    public static void dfs(int index, int sum){
        int r = index/m;
        int c = index%m;

        //종료 조건. 끝에 도달한 경우
        if(index==n*m){
            answer = Math.max(answer, sum);
            return;
        }

        if(!visited[r][c]) {
            //ㄱ 모양
            if((r+1)<n && (c-1)>=0 && !visited[r+1][c] && !visited[r][c-1]){
                visited[r][c] = true;
                visited[r+1][c] = true;
                visited[r][c-1] = true;
                dfs(index+1, sum+2*board[r][c]+board[r+1][c]+board[r][c-1]);
                visited[r+1][c] = false;
                visited[r][c-1] = false;
                visited[r][c] = false;
            }

            //ㄴ모양
            if((r-1)>=0 && (c+1)<m && !visited[r-1][c] && !visited[r][c+1]){
                visited[r][c] = true;
                visited[r-1][c] = true;
                visited[r][c+1] = true;
                dfs(index+1, sum+2*board[r][c]+board[r-1][c]+board[r][c+1]);
                visited[r-1][c] = false;
                visited[r][c+1] = false;
                visited[r][c] = false;
            }

            //ㄱ 뒤집어진 모양
            if((c+1)<m && (r+1)<n && !visited[r][c+1] && !visited[r+1][c]){
                visited[r][c] = true;
                visited[r][c+1] = true;
                visited[r+1][c] = true;
                dfs(index+1, sum+2*board[r][c]+board[r][c+1]+board[r+1][c]);
                visited[r][c] = false;
                visited[r][c+1] = false;
                visited[r+1][c] = false;
            }

            //ㄴ 뒤집어진 모양
            if((r-1)>=0 && (c-1)>=0 && !visited[r-1][c] && !visited[r][c-1]){
                visited[r][c] = true;
                visited[r-1][c] = true;
                visited[r][c-1] = true;
                dfs(index+1, sum+2*board[r][c]+board[r-1][c]+board[r][c-1]);
                visited[r-1][c] = false;
                visited[r][c-1] = false;
                visited[r][c] = false;
            }
        }

        dfs(index+1, sum);
        

    }
    
}
