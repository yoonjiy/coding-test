package 이분탐색;

import java.util.*;
import java.io.*;

public class boj_1654_java {
    //k개의 랜선을 잘라서 n개의 랜선을 만들고자 할 때, 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성
    static int n, k;
    static int[] lines;
    static long answer;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        lines = new int[k];
        for(int i=0; i<k; i++){
            lines[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(lines);

        long low = 1;
        long high = lines[k-1];
        while(low<=high){
            long mid = (low+high)/2;

            int cnt = divideLine(lines, mid);
            
            if(cnt >= n){ //n개 이상의 랜선을 만들 수 있다면 랜선 길이를 늘림
                answer = mid; 
                low = mid+1;
            }
            else{ //만들 수 없다면 랜선 길이를 줄임
                high = mid-1;
            }
        }

        System.out.println(answer);
    }

    public static int divideLine(int[] lines, long mid){
        int cnt = 0;
        for(int l:lines){
            cnt += l/mid;
        }
        
        return cnt;
    }
}
