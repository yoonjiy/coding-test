package 그리디;

import java.io.*;
import java.util.*;

public class boj_20115_에너지드링크 {
    static int n;
    static int[] energy;
    public static void main(String[] args) throws Exception{
        //페인은 합쳐진 에너지 드링크의 양을 최대로 하려 한다. 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        energy = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for(int i=0; i<n; i++){
            energy[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(energy);

        //가장 작은 걸 반 나눠서 가장 큰 쪽에 담아야 한다.
        //2 3 6 9 10
        //3 6 9 11
        //6 9 12.5
        //9 15.5
        //20
  
        double max = (double)energy[n-1];
        for(int i=0; i<n-1; i++){
            max = (double)energy[i]/2 + max;
        }

        System.out.println(max);

    }
}
