package 브루트포스;

import java.util.*;
import java.io.*;

public class boj_2615_오목 {
    static int[][] board;
    static int[] dr = {0, 1, -1, 1}; //오, 아, 위대각선, 아래대각선
    static int[] dc = {1, 0, 1, 1};
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        board = new int[19][19];
        for(int i=0; i<19; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<19; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        
        //검 1, 흰 2	
		for (int j = 0; j < 19; j++) {
			for (int i = 0; i < 19; i++) {
				if(board[i][j]==0) continue;

					for (int d = 0; d < 4; d++) {
						int nr = i;
						int nc = j; 
						int cnt = 1; 
						
						//오른쪽 방향 탐색
						while(true) {
							nr += dr[d];
							nc += dc[d];
                            if(nr<0 || nc<0 || nr>=19 || nc>=19) break;

							if(board[i][j]==board[nr][nc]) cnt++;
                            else break;
						}

						nr = i;
						nc = j;
						
						//반대 방향 탐색
						while( true) {
							nr -= dr[d];
							nc -= dc[d];
							if(nr<0 || nc<0 || nr>=19 || nc>=19) break;
								
                            if(board[i][j]==board[nr][nc]) cnt++;
                            else break;			
						}
						
						//오목이라면
						if (cnt==5) {
							System.out.println(board[i][j]);
							System.out.println((i+1) + " " + (j+1));
							return;
						}
						
					}
				}
			}
		
		
		//아무도 이기지 않았을 경우
		System.out.println(0); 	
    }

}
