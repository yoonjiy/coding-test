package 시뮬레이션;

import java.util.*;
import java.util.stream.Collectors;
import java.io.*;


public class boj_23290_java {
    static int m, s;
    static int dr[] = {0, -1, -1, -1, 0, 1, 1, 1}; //←, ↖, ↑, ↗, →, ↘, ↓, ↙ 
    static int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    static List<Fish> fishes;
    static int sr, sc; //상어의 위치
    static int[][] smell; 
    static int[][] board; //물고기 수 저장
    static int[] sharkdir = {2, 1, 4, 3};
    static int[] reverseR = {-1, 0, 1, 0}; //상좌하우
    static int[] reverseC = {0, -1, 0, 1};
    static class Fish{
        int r, c, d;
        
        Fish(int r, int c, int d){
            this.r = r;
            this.c = c;
            this.d = d;
        }
    }
    static class Info{
        int sum;
        String way;
        
        Info(int sum, String way){
            this.sum = sum;
            this.way = way;
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new  InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());

        smell = new int[5][5]; //물고기 냄새
        board = new int[5][5]; //물고기 수

        fishes = new ArrayList<>();
        for(int i=0; i<m; i++){
            //물고기 정보
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            board[r][c]++;
            fishes.add(new Fish(r, c, d-1));
        }

        st = new StringTokenizer(br.readLine());
        sr = Integer.parseInt(st.nextToken());
        sc = Integer.parseInt(st.nextToken());

        while(s-- > 0){
            //1. 복제마법
            List<Fish> temp = new ArrayList<>();
            for(Fish f:fishes) {
                temp.add(new Fish(f.r, f.c, f.d)); //f를 그대로 추가하면 얕은 복사가 됨
            }

            System.out.println("물고기 이동 전");
            for(Fish f:fishes){
                System.out.println(f.r + " " + f.c + " " + f.d);
            }
            System.out.println();

            //냄새 증가
            for(int i=1; i<=4; i++){
                for(int j=1; j<=4; j++){
                    if(smell[i][j]>0) smell[i][j]++;
                }
            }

            //2. 모든 물고기 이동
            moveFish(fishes);

            System.out.println("물고기 이동 후");
            for(Fish f:fishes){
                System.out.println(f.r + " " +f.c + " " + f.d);
            }
            System.out.println();

            //3. 상어 연속 3칸 이동 (제외된 물고기 수가 가장 많은 순, 사전 순)
            boolean[][] visited = new boolean[5][5];
            
            List<Info> list = new ArrayList<>();
            visited[sr][sc] = true;
            dfs(sr, sc, "", visited, board[sr][sc], list);

            list.sort(new Comparator<Info>(){
                @Override
                public int compare(Info o1, Info o2) {
                    // TODO Auto-generated method stub
                    if(o1.sum==o2.sum) return Integer.compare(Integer.parseInt(o1.way), Integer.parseInt(o2.way)); //dirsum 오름차순 반환
                    else return Integer.compare(o2.sum, o1.sum); //sum 내림차순 반환
                }
            });

            
            //상어 이동시키기 - fishes, board, smell이 변함
            moveShark(list.get(0).way);

            System.out.println("상어 이동" + list.get(0).way);
            System.out.println("sr="+sr + " sc=" + sc);

            //두번 전 연습에서 생긴 물고기 냄새 사라짐
            for(int i=1; i<=4; i++){
                for(int j=1; j<=4; j++){
                    if(smell[i][j]>2){
                        smell[i][j] = 0;
                    }
                }
            }

            //4. 복제 마법 완료
            //fishes, board 변경
            for(Fish f:temp){
                fishes.add(f);
                board[f.r][f.c]++;
            }

        }

        //격자에 있는 물고기의 수 구하기
        int answer= 0;
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                answer += board[i][j];
            }
        }

        System.out.println(answer);

    }

    static void moveShark(String way){
        for(int i=0; i<way.length();i++){
            int w = way.charAt(i)-'0'; //상좌하우 1234
            sr += reverseR[w-1];
            sc += reverseC[w-1];

            Iterator iter = fishes.iterator();
            while(iter.hasNext()){
                Fish f = (Fish)iter.next();
                if(f.r==sr && f.c==sc){
                    iter.remove();
                    board[sr][sc] = 0;
                    smell[sr][sc] = 1;
                }
            }

        }
    }

    static void dfs(int r, int c, String w, boolean[][] visited, int sum, List<Info> list){
        if(w.length()==3){
            list.add(new Info(sum, w));
            return;
        }

        for(int i=0; i<8; i+=2){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr<1 || nc<1 || nr>4 || nc>4 || visited[nr][nc]) continue;

            visited[nr][nc] = true;
            //nr, nc에 해당하는 물고기 추가
            sum += board[nr][nc];

            //사전순 이동 방향. 좌상우하 0, 2, 4, 6 -> 2, 1, 4, 3 
            dfs(nr, nc, w+String.valueOf(sharkdir[i/2]) , visited, sum, list);

            visited[nr][nc] = false;
            sum -= board[nr][nc];
        
        }

    }

    static void moveFish(List<Fish> fishes){
        for(Fish f:fishes){
            int i=0;

            while(i < 8){
                int nr = f.r+dr[f.d];
                int nc = f.c+dc[f.d];

                if(nr<1 || nc<1 || nr>4 || nc>4 || smell[nr][nc]>0 || (nr==sr && nc==sc)) {
                    if(f.d==0) f.d = 7;
                    else f.d = (f.d-1)%8; //45도 반시계 회전
                    i++;

                    continue;
                }

                //물고기 이동
                board[f.r][f.c]--;
                f.r = nr;
                f.c = nc;
                board[f.r][f.c]++;
                break;
            }
        }
    }
    
    
}
