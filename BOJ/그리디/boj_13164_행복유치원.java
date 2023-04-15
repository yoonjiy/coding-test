package 그리디;

import java.util.*;
import java.io.*;

public class boj_13164_행복유치원 {
    static int n, k;
    static int[] heights;
    public static void main(String[] args) throws Exception{
        //K개의 조에 대해 티셔츠 만드는 비용의 합을 최소로 하고 싶어한다. 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        heights = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            heights[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(heights);

        //어떻게 그룹을 묶을 것인가? 
        List<Integer> diff = new ArrayList<>();
        for(int i=1; i<n; i++){
            diff.add(heights[i]-heights[i-1]);
        }

        Collections.sort(diff); //차이 오름차순


        //k개의 그룹을 만들기 위해 n-k번의 합치는 과정이 필요
        int answer = 0;
        for(int i=0; i<n-k; i++){
            answer += diff.get(i);
        }

        System.out.println(answer);



    }
    
}
