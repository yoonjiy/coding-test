package 그리디;

import java.util.*;
import java.io.*;

public class boj_20207_달력 {
    static int n;
    static int[] cnt;
    public static void main(String[] args) throws Exception{
        //일정의 개수와 각 일정의 시작날짜, 종료날짜가 주어질 때 수현이가 자르는 코팅지의 면적을 구해보자.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        cnt = new int[366];

        StringTokenizer st; 
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            for(int j=s; j<=e; j++){
                cnt[j]++;
            }
        }

        int sum = 0;
        int width = 0, height = 0;
        for(int i=1; i<=365; i++){
            if (cnt[i] == 0) {
                sum += height*width;
                height = width = 0;
                continue;
            }

            width++;
            height = Math.max(height, cnt[i]);
        }

        sum += height*width;

        System.out.println(sum);
    }
    
}
