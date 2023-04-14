package dp;
import java.io.*;
import java.util.*;

public class boj_5557_1학년 {
    static int n;
    static int[] num;
    static int count;
    public static void main(String[] args) throws Exception{
        //상근이가 만들 수 있는 올바른 등식의 수를 구하는 프로그램을 작성하시오. 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        num = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            num[i] = Integer.parseInt(st.nextToken());
        }

        int last = num[n-1];

        dfs(0, 0, last);

        System.out.println(count);
    }

    public static void dfs(int idx, int sum, int last){
        if(idx==n-1){
            if(sum==last)
                count++;
            return;
        }

        //0이상 20이하
        if(sum+num[idx] <= 20)
            dfs(idx+1, sum+num[idx], last);
        if(sum-num[idx]>=0)
            dfs(idx+1, sum-num[idx], last);
    }
}
