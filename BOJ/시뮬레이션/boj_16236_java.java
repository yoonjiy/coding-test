package 시뮬레이션;

import java.util.*;
import java.io.*;

public class boj_16236_java {
    static int n;
    static int[][] map;
    static int[][] dist;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static List<Info> eat_list;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        dist = new int[n][n];
        
        int r = 0, c = 0;
        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==9){
                   //아기 상어가 있는 칸
                    r = i;
                    c = j;
                    map[i][j] = 0; 
                }
            }
        }

        //아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 
        eat_list = new ArrayList<>();
        int answer = 0;
        int count = 0; //아기 상어가 먹은 물고기 수
        int curr_size = 2;
        while(true){
            bfs(r, c, curr_size);

            if(eat_list.isEmpty()) break; //먹을 수 있는 물고기가 없다면 종료

            //가까운 순, r이 작은 순, y가 작은 순으로 먹이를 먹음
            eat_list.sort(new Comparator<Info>(){
                @Override
                public int compare(Info o1, Info o2) {     
                    if(o1.distance==o2.distance){
                        if(o1.p.r==o2.p.r) return Integer.compare(o1.p.c, o2.p.c);
                        else return Integer.compare(o1.p.r, o2.p.r);
                    }
                    else return Integer.compare(o1.distance, o2.distance);
                
                }
            });

            
            count++;
            answer += eat_list.get(0).distance;
            r = eat_list.get(0).p.r;
            c = eat_list.get(0).p.c; //아기 상어 위치 이동
            map[r][c] = 0;
            //아기 상어 크기 갱신
            if(curr_size==count){
                curr_size++;
                count = 0;
            }
        }

        System.out.println(answer);

    }

    public static void bfs(int r, int c, int curr_size){
        //dist, eat_list 초기화
        for(int[] d: dist)
            Arrays.fill(d, -1);
        eat_list.clear();

        Queue<Point> q = new LinkedList<>();
        q.add(new Point(r, c));
        dist[r][c] = 0; //처음 아기상어 위치

        while(!q.isEmpty()){
            Point p = q.poll();

            for(int i=0; i<4; i++){
                int nr = p.r + dr[i];
                int nc = p.c + dc[i];

                if(nr<0 || nc<0 || nr>=n || nc>=n || map[nr][nc] > curr_size || dist[nr][nc]!=-1) continue;

                //아기상어가 지나갈 수 있음
                if(map[nr][nc]==0 || map[nr][nc] == curr_size){
                    dist[nr][nc] = dist[p.r][p.c] + 1;
                    q.add(new Point(nr, nc));
                }

                //아기상어가 잡아 먹고, 지나갈 수 있음
                if(map[nr][nc] < curr_size && map[nr][nc]>=1){
                    dist[nr][nc] = dist[p.r][p.c] + 1;
                    eat_list.add(new Info(new Point(nr, nc), dist[nr][nc])); //아기상어와의 거리와 좌표를 기록
                    q.add(new Point(nr, nc));
                }

            }
        }
    }

    public static class Point{
        int r, c;
        Point(int r, int c){
            this.r = r;
            this.c = c;
        }
    }

    public static class Info{
        Point p; // 좌표
        int distance; //아기상어와의 거리
        Info(Point p, int distance){
            this.p = p;
            this.distance = distance;
        }
    }
}
