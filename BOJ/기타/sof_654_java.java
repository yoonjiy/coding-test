package 기타;

import java.util.*;
import java.io.*;


public class sof_654_java
{
    static int[] bus;
    static int[][] arr;
    static long answer;
    static int n;
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        bus = new int[n+1];
        arr = new int[n+1][n+1]; //arr[x][j] -> j보다 오른쪽에 있는 수들에 대해서 x보다 작은 수들의 개수
        for(int i=0; i<n; i++){
            bus[i] = Integer.parseInt(st.nextToken());
        }

        //arr[x][j] 채우기
        for(int j=n-2; j>=0; j--){
            for(int x=1; x<=n; x++){
                if(bus[j+1] < x){
                    arr[x][j] = arr[x][j+1] + 1;
                }
                else{
                    arr[x][j] = arr[x][j+1];
                }
            }
        }

        //i<j<k에 대해서 ai<aj, ai>ak 인 경우의 수 구하기
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                if(bus[i]<bus[j]){
                    answer += arr[bus[i]][j]; //j보다 오른쪽에 있는 수(ak)들 중 ai보다 작은 경우의 개수
                }
            }
        }

        System.out.println(answer);

    }

}