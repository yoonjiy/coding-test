package 기타;

import java.io.*;
import java.util.*;

public class boj_11399_java {
    static int n;
    static int[] lines;
    static int answer;
    public static void main(String[] args) throws Exception{
        //각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        lines = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            lines[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(lines);

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += lines[i];
            answer += sum;
        }
        
        System.out.println(answer);

    }
}
