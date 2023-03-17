package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_19236_java{
    // 1부터 순서대로 ↑, ↖, ←, ↙, ↓, ↘, →, ↗
    static int[] dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dc = {0, -1, -1, -1, 0, 1, 1, 1};
    static int answer;

    public static class Fish {
        int idx;
        Point p;
        int dir;
        boolean isAlive;

        Fish(int idx, Point p, int dir, boolean isAlive) {
            this.idx = idx;
            this.p = p;
            this.dir = dir;
            this.isAlive = isAlive;
        }
    }

    public static class Point{
        int r, c;
        Point(int r, int c){
            this.r = r;
            this.c = c;
        }
    }

    public static void main(String[] args) throws Exception{
        //상어가 먹을 수 있는 물고기 번호의 합의 최댓값을 구해보자.
        int[][] map;
        Fish[] fishes;
        map = new int[4][4];
        fishes = new Fish[17];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i=0; i<4; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<4; j++){
                int idx = Integer.parseInt(st.nextToken());
                int dir = Integer.parseInt(st.nextToken());
                fishes[idx] = new Fish(idx, new Point(i, j), dir-1, true);
                map[i][j] = idx;
            }
        }

    
        //0,0으로 이동
        dfs(new Point(0, 0), fishes[map[0][0]].dir, 0, map, fishes);

    }

    public static void dfs(Point p, int sd, int sum, int[][] map, Fish[] fishes){

        sum += map[p.r][p.c];
        fishes[map[p.r][p.c]].isAlive = false;
        sd = fishes[map[p.r][p.c]].dir;

        answer = Math.max(answer, sum);

        //물고기 한마리씩 이동
        for(Fish f:fishes){
            move_fish(map, f, fishes, p);
        }

        //상어 이동
        for(int i=1; i<=3; i++){
            int nr = p.r + dr[sd]*i;
            int nc = p.c + dc[sd]*i;

            //종료조건: 상어가 이동할 공간이 없으면(물고기가 없거나 범위 초과)
            if(nr<0 || nc<0 || nr>=4 || nc>=4 || fishes[map[nr][nc]].isAlive==false) {
                break;
            }


            //맵 정보, 상어 정보, 물고기 정보 복사
            //map 배열 복사
            int[][] tempMap = new int[map.length][map.length];
            for(int k = 0; k < map.length; k++) {
                System.arraycopy(map[k], 0, tempMap[k], 0, map.length);
            }

            //fish 배열 복사 
            Fish[] tempFishes = new Fish[fishes.length];
            for(int k = 1; k <= 16; k++) 
                tempFishes[k] = new Fish(fishes[k].idx, new Point(fishes[k].p.r, fishes[k].p.c), fishes[k].dir, fishes[k].isAlive);
            

            dfs(new Point(nr, nc), sd, sum, tempMap, tempFishes);
        }
    }

    public static void move_fish(int[][] map, Fish now, Fish[] fishes, Point p){

        if(now.isAlive==false) return;

        for(int i=0; i<8; i++){
            int nr = now.p.r + dr[now.dir];
            int nc = now.p.c + dc[now.dir];

            //범위를 초과하거나 상어가 있는 경우 이동 불가
            if(nr<0 || nc<0 || nr>=4 || nc>=4 || (nr==p.r && nc==p.c)) {
                now.dir = (now.dir+1)%8; //반시계 방향 45도 회전
                continue;
            }

            int temp = map[nr][nc];
            map[nr][nc] = now.idx;
            map[now.p.c][now.p.c] = temp;

            fishes[temp].p.r = now.p.r;
            fishes[temp].p.c = now.p.c;
            now.p.r = nr;
            now.p.c = nc;

        }
    }
}