package 그리디;

import java.io.*;
import java.util.*;

public class boj_11000_강의실배정 {
    static int n;
    static int[][] times;
    static PriorityQueue<Integer> pq;

    public static void main(String[] args) throws Exception{
        //최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다. -> 한 강의실에 최대한 많이 배정

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        times = new int[n][2];

        pq = new PriorityQueue<>();
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            times[i][0] = Integer.parseInt(st.nextToken());
            times[i][1] = Integer.parseInt(st.nextToken()); 
        }

        Arrays.sort(times, (o1, o2) -> (o1[0]-o2[0])); //시작 시간 오름차순 정렬

        int end = times[0][1];
        pq.offer(end);

        for(int i=1; i<n; i++){
            if(pq.peek() <= times[i][0]){ //종료시간 보다 시작 시간이 더 늦으면 배정 가능
                pq.poll();
                pq.offer(times[i][1]);
            }
            else{
                //새로운 회의실에 배정
                pq.offer(times[i][1]);
            }
        }
        
        System.out.println(pq.size());

    }
    
}
