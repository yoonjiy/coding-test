package 시뮬레이션;

import java.io.*;
import java.util.*;

public class boj_22858_원상복구 {
    static int n, k;
    static int[] origin;
    static int[] fin;
    static int[] d;
    public static void main(String[] args) throws Exception{
        //K번 섞은 카드의 정보와 D의 정보를 알고 있다고 할 때, 원래 카드는 어떤 배치를 이루고 있었는지 구해보자.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        origin = new int[n+1]; //원래 카드 배치
        fin = new int[n+1]; //k번 섞은 이후 카드 배치
        d = new int[n+1];

        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++){
            fin[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++){
            d[i] = Integer.parseInt(st.nextToken());
        }

        int[] temp = new int[n+1];
        temp = fin.clone();

        while(k-- > 0){
            for(int i=1; i<=n; i++){
                //d[i]번째로 보낸다
                origin[d[i]] = temp[i];
            }
            
            temp = origin.clone();            
        }

        for(int i=1; i<=n; i++){
            System.out.print(origin[i] + " ");
        }
    }
    
}
