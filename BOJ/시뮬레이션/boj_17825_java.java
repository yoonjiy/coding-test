package 시뮬레이션;
import java.util.*;
import java.io.*;

public class boj_17825_java {
    static int[] dice = new int[10];
    static int[] board = new int[33];
    static int[] score = new int[33];
    static int[] turn = new int[33];
    static int[] position = new int[4]; //말의 위치 표시
    static boolean[] check = new boolean[33]; //말이 놓여져있는지 아닌지
    static int answer;

    public static void main(String[] args ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for(int i=0; i<10; i++){
            dice[i] = Integer.parseInt(st.nextToken());
        }

        init();

        dfs(0, 0);

        System.out.println(answer);
    }

    static void init(){
        for(int i=0; i<21; i++){
            board[i] = i+1;
        }
        board[21] = 21; //끝
        for(int i=22; i<27; i++){
            board[i] = i+1;
        }
        board[27] = 20;
        board[28] = 29; board[29] = 30; board[30] = 25;
        board[31] = 32; board[32] = 25;

        //점수
        for(int i=0; i<21; i++){
            score[i] = i*2;
        }
        score[22] = 13; score[23] = 16; score[24] = 19;
        score[28] = 28; score[29] = 27; score[30] = 26;
        score[31] = 22; score[32] = 24;
        score[25] = 25; score[26] = 30; score[27] = 35;

        turn[5] = 22;
        turn[10] = 31;
        turn[15] = 28;
    }

    static void dfs(int depth, int sum){
        if(depth==10){
            answer = Math.max(sum, answer);
            return;
        }

        for(int i=0; i<4; i++){
            int prev = position[i];
            int curr = prev;
            int moveCnt = dice[depth];

            //말이 파란색 칸에서 이동을 시작하면 파란색 화살표를 타야함.
            if(turn[curr]>0){
                curr = turn[curr];
                moveCnt--;
            }

            while(true){
                if(moveCnt==0) break;
                curr = board[curr];
                moveCnt--;
            }

            //이동을 마친 말이 도착지점이 아닌데 다른 말이 이미 있으면 이동 불가능
            if(curr!=21 && check[curr]){
                continue;
            }

            check[prev] = false;
            check[curr] = true;
            position[i] = curr;

            dfs(depth+1, sum+score[curr]);

            //말 제자리로 이동
            check[prev] = true;
            check[curr] = false;
            position[i] = prev;

        }

    }
}
