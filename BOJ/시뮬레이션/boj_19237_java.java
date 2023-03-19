package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_19237_java{
    public static int n, m, k;
    public static int[][] map;
    public static Smell[][] smell;
    public static Shark[] sharks;
    public static int[] dr = {-1, 1, 0, 0}; //상하좌우
    public static int[] dc = {0, 0, -1, 1};
    public static int answer;
    public static class Shark{
        //상하좌우에 대한 우선 방향
        int idx;
        int d;
        int r, c;
        boolean isPresent;
        int[][] dir;
        Shark(int idx, int d, int r, int c, boolean isPresent, int[][] dir){
            this.idx = idx;
            this.d = d;
            this.r = r;
            this.c = c;
            this.isPresent = isPresent;
            this.dir = dir;
        }
    }

    public static class Smell{
        int idx;
        int time;
        Smell(int idx, int time){
            this.idx = idx;
            this.time = time;
        }
    }

    public static void main(String[] args) throws Exception{
        //1번 상어만 격자에 남게 되기까지 몇 초가 걸리는지를 구하는 프로그램을 작성하시오.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new int[n][n];
        smell = new Smell[n][n];
        sharks = new Shark[m+1];

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());

                smell[i][j] = new Smell(map[i][j], 0);
                if(map[i][j]!=0){
                    smell[i][j].time = k;
                    sharks[map[i][j]] = new Shark(map[i][j], 0, i, j, true, new int[4][4]);
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=m; i++){
            sharks[i].d = Integer.parseInt(st.nextToken());
        }

        for(int i=1; i<=m; i++){
            for(int j=0; j<4; j++){
                st = new StringTokenizer(br.readLine());
                for(int k=0; k<4; k++){
                    sharks[i].dir[j][k] = Integer.parseInt(st.nextToken());
                }
            }
        }

        //제한 시간 1000초
        while(answer <= 1000){

            //격자 안 상어가 동시에 이동한다
            for(int i=1; i<=m; i++){
                if(sharks[i].isPresent)
                    move(sharks[i]);
            }

            //냄새 유효시간이 줄어든다
            decreaseTime();

            //새로운 냄새를 뿌린다
            createSmell();

            answer++;
    
            //1번 상어만 남으면
            boolean check = true;
            for(int i=2; i<=m; i++){
                if(sharks[i].isPresent){
                    check = false;
                    break;
                }
            }

            if(check && sharks[1].isPresent){
                System.out.println(answer);
                break;
            }

        }

        if(answer>1000)
            System.out.println(-1);
    }

    public static void move(Shark s){
        
        //냄새가 없는 칸으로 이동
        boolean flag = false;
        for(int i=0; i<4; i++){
            int dir = s.dir[s.d-1][i];
            int nr = s.r + dr[dir-1];
            int nc = s.c + dc[dir-1];

            if(nr<0 || nc<0 || nr>=n || nc>=n) continue;

            //냄새가 없는 칸이면 이동
            if(smell[nr][nc].time==0 && smell[nr][nc].idx==0 ){
                if(map[nr][nc]!=0 && map[nr][nc] < s.idx){ //이미 번호가 작은 상어가 존재하면 쫓겨남
                    s.isPresent = false;
                    break;
                }
                map[s.r][s.c] = 0;
                map[nr][nc] = s.idx; //상어 이동
                s.r = nr; s.c = nc;
                s.d = dir;
                flag = true;
                   
                break;
            }
        }

            
        if(!flag && s.isPresent){
            //자신의 냄새가 있는 칸으로 이동
            for(int i=0; i<4; i++){
                int dir = s.dir[s.d-1][i];
                int nr = s.r + dr[dir-1];
                int nc = s.c + dc[dir-1];
    
                if(nr<0 || nc<0 || nr>=n || nc>=n) continue;
                if(smell[nr][nc].idx==s.idx){
                    map[s.r][s.c] = 0;
                    map[nr][nc] = s.idx; //상어 이동
                    s.r = nr; s.c = nc;
                    s.d = dir;
       
                    break;
                }
            }
        }
    }

    public static void decreaseTime(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){ 
                if(smell[i][j].time > 0){
                    smell[i][j].time--;
                }
                if(smell[i][j].time==0){
                    smell[i][j].idx = 0;
                }
            }
        }
    }

    public static void createSmell(){
        for(int i=1; i<=m; i++){
            Shark s = sharks[i];
            if(s.isPresent){
                smell[s.r][s.c].idx = s.idx;
                smell[s.r][s.c].time = k;
            }
        }
    }
}