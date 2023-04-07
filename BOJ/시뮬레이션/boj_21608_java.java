package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_21608_java {
    static int n;
    static int[][] board;
    static List<Integer>[] like;
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static int[] score = {0, 1, 10, 100, 1000}; //만족도
    static int answer;

    public static class Seat{
        int r, c;
        int likes; //인접 칸에 좋아하는 학생 수
        int empty; //인접 칸에 비어있는 자리 수
        Seat(int r, int c, int likes, int empty){
            this.r = r;
            this.c = c;
            this.likes = likes;
            this.empty = empty;
        } 
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        board = new int[n+1][n+1]; //자리 배치

        like = new ArrayList[n*n+1];
        for(int i=0; i<n*n; i++){
            st = new StringTokenizer(br.readLine());
            int student = Integer.parseInt(st.nextToken());
            like[student] = new ArrayList<>();
            for(int j=0; j<4; j++){
                like[student].add(Integer.parseInt(st.nextToken()));
            }

            //1. 자리 배치
            if(i==0){
                board[2][2] = student;
            }
            else{
                //앉을 수 있는 자리를 모두 넣기
                List<Seat> list = new ArrayList<>();
                collectSeat(student, list);

                //정렬
                list.sort(new Comparator<Seat>(){
                    @Override
                    public int compare(Seat s1, Seat s2){
                        if(s1.likes==s2.likes){
                            if(s1.empty==s2.empty){
                                if(s1.r==s2.r){
                                    return Integer.compare(s1.c, s2.c);
                                }
                                else return Integer.compare(s1.r, s2.r);
                            }
                            else return Integer.compare(s2.empty, s1.empty); //내림차순
                        }
                        else return Integer.compare(s2.likes, s1.likes);
                    }
                });

                Seat s = list.get(0);
                board[s.r][s.c] = student;
            }
        }

        //만족도 구하기
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int stu = board[i][j];
                int cnt = 0;
                for(int d=0; d<4; d++){
                    int nr = i+dr[d];
                    int nc = j+dc[d];

                    if(nr<1 || nc<1 || nr>n || nc>n) continue;

                    if(like[stu].contains(board[nr][nc])){
                        cnt++;
                    }
                }
                answer += score[cnt];
            }
        }

        System.out.println(answer);

        
    }

    public static void collectSeat(int student, List<Seat> list){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(board[i][j]!=0) continue;

                //비어 있으면 그 인접 좌석의 좋아하는 학생 수, 빈 좌석 수 세기
                int emptySeat = 0;
                int likeStu = 0;
                for(int d=0; d<4; d++){
                    int nr = i+dr[d];
                    int nc = j+dc[d];
                    
                    if(nr<1 || nc<1 || nr>n || nc>n) continue;

                    if(like[student].contains(board[nr][nc])){
                        likeStu++;
                    }
                    if(board[nr][nc]==0){
                        emptySeat++;
                    }
                }

                list.add(new Seat(i, j, likeStu, emptySeat));

            }
        }

    }
}
