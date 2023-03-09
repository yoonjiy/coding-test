package 시뮬레이션;
import java.util.*;
import java.io.*;

class boj_17779_java{
    static int n;
    static int[][] map;
    static boolean[][] border;
    static int answer = Integer.MAX_VALUE;
    static Point[] p; 
    static int total;
    public static void main(String[] args) throws Exception{
        //인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        p = new Point[4];
        for(int i=0; i<4; i++){
            p[i] = new Point(0, 0);
        }
        
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];

        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                total += map[i][j];
            } 
        }

        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                for(int d1=1; d1<n; d1++){
                    for(int d2=1; d2<n; d2++){
                        if(c+d1+d2>=n || r-d1<0 || r+d2>=n) continue;
                        //r,c 를 기준으로 반시계 방향 꼭짓점 저장
                        p[0].r = r; p[0].c = c; 
                        p[1].r = r+d2; p[1].c = c+d2;
                        p[2].r = r-d1+d2; p[2].c = c+d1+d2;
                        p[3].r = r-d1; p[3].c = c+d1; 
                        answer = Math.min(answer, simulation(r, c, d1 ,d2));
                    }
                }
            }
        }

        System.out.println(answer);
    } 

    static class Point{
        int r, c;
        Point(int r, int c){
            this.r = r;
            this.c = c;
        }
    }

    static int simulation(int r, int c, int d1, int d2){
        int[] sum = new int[5];
        border = new boolean[n][n];

        //경계선 그리기
        for(int i=0; i<=d1; i++){
            border[r-i][c+i] = true;
            border[r+d2-i][c+d2+i] = true;
        }
        for(int i=0; i<=d2; i++){
            border[r+i][c+i] = true;
            border[r-d1+i][c+d1+i] = true;
        }

        //1번 선거구
        for(int i=0; i<p[0].r; i++){
            for(int j=0; j<=p[3].c; j++){
                if(border[i][j]) break;
                sum[0] += map[i][j];
            }
        } 

        //2번 선거구
        for(int i=0; i<=p[2].r; i++){
            for(int j=n-1; j>p[3].c; j--){
                if(border[i][j]) break;
                sum[1] += map[i][j];
            }
        }

        //3번 선거구
        for(int i=p[0].r; i<n; i++){
            for(int j=0; j<p[1].c; j++){
                if(border[i][j]) break;
                sum[2] += map[i][j];
            }
        }

        //4번 선거구
        for(int i=p[2].r+1; i<n; i++){
            for(int j=n-1; j>=p[1].c; j--){
                if(border[i][j]) break;
                sum[3] += map[i][j];
            }
        }

        //5번 선거구
        sum[4] = total-sum[0]-sum[1]-sum[2]-sum[3];

        Arrays.sort(sum);

        return sum[4]-sum[0];
    }
}