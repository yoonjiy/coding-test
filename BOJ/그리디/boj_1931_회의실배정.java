package 그리디;

import java.io.*;
import java.util.*;

public class boj_1931_회의실배정 {
    static int n;
    static int[][] times;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        StringTokenizer st;
        times = new int[n][2];
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            times[i][0] = Integer.parseInt(st.nextToken());
            times[i][1] = Integer.parseInt(st.nextToken());
        }

        //종료시간 오름차순 정렬
        Arrays.sort(times, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2){
                if(o1[1]==o2[1]){
                    //종료시간이 같으면 시작 시간이 빠른 순으로
                    return Integer.compare(o1[0], o2[0]);
                }
                else return Integer.compare(o1[1], o2[1]);
            }
        });

        int end = times[0][1];
        int answer = 1;
        for(int i=1; i<n; i++){
            if(times[i][0] >= end){
                end = times[i][1];
                answer++;
            }
        }

        System.out.println(answer);
    }
    
}
