package 브루트포스;

import java.io.*;
import java.util.*;

public class boj_16937_두스티커 {
    static int h, w;
    static int n;
    static int answer;
    static boolean[] visited;
    static List<int[]> stickers;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        h = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());

        n = Integer.parseInt(br.readLine());
        visited = new boolean[n];
        stickers = new ArrayList<>();

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            stickers.add(new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
        }

        //두 스티커가 붙여진 넓이의 최댓값을 구해보자.
        //스티커 2개 고르기. 조합
        dfs(0, 0, new int[2]);

        System.out.println(answer);

    }

    public static void dfs(int cnt, int idx, int[] s){
        if(cnt==2){
            //2개가 선택되었으면
            answer = Math.max(answer, calculate(s));
            return;
        }

        for(int i=idx; i<n; i++){
            if(visited[i]) continue;

            visited[i] = true;
            s[cnt] = i;
            dfs(cnt+1, i+1, s);

            visited[i] = false;
        }
    }

    public static int calculate(int[] s){

        int[] fs = stickers.get(s[0]); //첫번째 스티커
        int[] ss = stickers.get(s[1]); //두번째 스티커
        
        int temp = fs[0]*fs[1] + ss[0]*ss[1];
        int hh, ww;
        //둘 다 그대로 있는 경우
        //가로
        hh = Math.max(fs[0], ss[0]);
        ww = fs[1]+ss[1];
        if(hh <= h && ww<=w) return temp;
        //세로
        hh = fs[0]+ss[0];
        ww = Math.max(fs[1], ss[1]);
        if(hh <= h && ww<=w) return temp;

        //fs만 회전하는 경우
         //가로
         hh = Math.max(fs[1], ss[0]);
         ww = fs[0]+ss[1];
         if(hh <= h && ww<=w) return temp;
         //세로
         hh = fs[1]+ss[0];
         ww = Math.max(fs[0], ss[1]);
         if(hh <= h && ww<=w) return temp;


        //ss만 회전하는 경우
        //가로
        hh = Math.max(fs[0], ss[1]);
        ww = fs[1]+ss[0];
        if(hh <= h && ww<=w) return temp;
        //세로
        hh = fs[0]+ss[1];
        ww = Math.max(fs[1], ss[0]);
        if(hh <= h && ww<=w) return temp;

        //둘다 회전하는 경우
        //가로
        hh = Math.max(fs[1], ss[1]);
        ww = fs[0]+ss[0];
        if(hh <= h && ww<=w) return temp;
        //세로
        hh = fs[1]+ss[1];
        ww = Math.max(fs[0], ss[0]);
        if(hh <= h && ww<=w) return temp;

        return 0;
    }
    
}
