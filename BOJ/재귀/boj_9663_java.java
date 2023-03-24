package 재귀;

import java.io.*;
import java.util.*;

public class boj_9663_java {
    static int n;
    static int[] col;
    static int answer;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        //퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
        //퀸을 기준으로 가로, 세로, 대각선 상에 아무것도 놓을 수 없다.
        col = new int[n];
        nqueen(0);

        System.out.println(answer);

    }

    public static boolean check(int row){
        //같은 열, 대각선에 퀸이 놓여있으면 안됨
        for(int i=0; i<row; i++){
            if(col[i]==col[row]) return false; //같은 열에 퀸이 있는 경우
            if(Math.abs(row-i)==Math.abs(col[row]-col[i])) return false; //대각선에 퀸이 있는 경우
        }
        return true;
    }

    public static void nqueen(int row){
        if(row==n){
            answer++;
        }
        else {
            for(int i=0; i<n; i++){
                col[row] = i; //row행, i열에 퀸을 둠
                if(check(row)){ //가능하다면
                    nqueen(row+1);
                }
            }
        }
    }
}
