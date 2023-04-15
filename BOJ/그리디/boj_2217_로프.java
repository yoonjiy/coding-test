package 그리디;

import java.io.*;
import java.util.*;

public class boj_2217_로프 {
    static int n;
    static int[] weights;
    public static void main(String[] args) throws Exception{
        //로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는 프로그램을 작성
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        weights = new int[n];
        for(int i=0; i<n; i++){
            weights[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(weights); 

        int sum = weights[0]*n;
        for(int i=1; i<n; i++){
            if(sum < weights[i]*(n-i)){
                sum = weights[i]*(n-i);
            }
        }

        System.out.println(sum);
    
    }    
}
