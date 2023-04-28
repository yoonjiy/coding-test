package 브루트포스;

import java.io.*;
import java.util.*;

public class boj_9079_동전게임 {
    static int t;
    static int[][] board;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());

        StringTokenizer st;
        while(t-- > 0){
            board = new int[3][3];
            for(int i=0; i<3; i++){
                st = new StringTokenizer(br.readLine());
                for(int j=0; j<3; j++){
                    char c = st.nextToken().charAt(0);
                    if(c=='H'){
                        board[i][j] = 1;
                    }
                    else board[i][j] = 0;
                }
            }

            //모두 같은 면이 보이기 위한 최소 연산 횟수, 불가능면 -1
            int answer = bfs();
            System.out.println(answer);
        }

    }

    public static int bfs(){
        boolean[] visited = new boolean[512]; //2^0~2^8의 합
        int num = boardToNum(); //board 상태 2진수->10진수 변환
        visited[num] = true;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{num, 0});

        while(!q.isEmpty()){
            int[] n = q.poll();

            numToBoard(n[0]);

            //모두 같은 면이면 연산횟수 반환
            if(check()){
                return n[1];
            }

            //모든 행 뒤집기
            for(int i=0; i<3; i++){
                flip_row(i);
                int tn = boardToNum();
                if(visited[tn]) continue;

                visited[tn] = true;
                q.add(new int[]{tn, n[1]+1});
                flip_row(i);
            }

            //모든 열 뒤집기
            for(int i=0; i<3; i++){
                flip_col(i);
                int tn = boardToNum();
                if(visited[tn]) continue;
                
                visited[tn] = true;
                q.add(new int[]{tn, n[1]+1});
                flip_col(i);
            }


            //모든 대각선 뒤집기
            for(int i=0; i<2; i++){
                flip_cross(i);
                int tn = boardToNum();
                if(visited[tn]) continue;
                
                visited[tn] = true;
                q.add(new int[]{tn, n[1]+1});
                flip_cross(i);
            }

        }

        return -1;
    }

    public static void flip_row(int row){
        for(int i=0; i<3; i++){
            board[row][i] = (board[row][i] ==1 ? 0 : 1);
        }

    }

    
    public static void flip_col(int col){
        for(int i=0; i<3; i++){
            board[i][col] = (board[i][col] ==1 ? 0 : 1);
        }
    }

    public static void flip_cross(int cross){    
        for(int i=0; i<3; i++){
            if(cross==0){
                board[i][i] = (board[i][i]==1 ? 0 : 1);
            }
            else{
                board[i][2-i] = (board[i][2-i]==1 ? 0 : 1);
            }
        }
    
        
    }

    public static boolean check(){
        int temp = board[0][0];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (temp != board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static int boardToNum(){
        int temp = 0;
        int pow = 8;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                temp += (int)Math.pow(2, pow)*board[i][j];
                pow--;
            }
        }

        return temp;
    }

    public static void numToBoard(int num){
        for(int i=2; i>=0; i--){
            for(int j=2; j>=0; j--){
                board[i][j] = num%2;
                num /= 2;
            }
        }

    }

}