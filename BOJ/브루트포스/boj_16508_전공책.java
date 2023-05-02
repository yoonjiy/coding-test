package 브루트포스;

import java.util.*;
import java.io.*;

public class boj_16508_전공책 {
    static String t;
    static int n;
    static int answer = Integer.MAX_VALUE;
    static int[] count;
    static int[] select;
    static boolean[] visited;
    static int[] price;
    static String[] book;
    public static void main(String[] args) throws Exception{
        //가장 적은 비용으로 민호가 원하는 단어를 만들기 위해서. 가장 적은 가격의 합 출력

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = br.readLine();
        n = Integer.parseInt(br.readLine());

        StringTokenizer st;
        price = new int[n];
        book = new String[n];
        count = new int[26];
        select = new int[26];

        for(int i=0; i<t.length(); i++){
            count[t.charAt(i)-'A']++;
        }

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            price[i] = Integer.parseInt(st.nextToken());
            book[i] = st.nextToken();
        }

        dfs(0, 0);

        System.out.println((answer==Integer.MAX_VALUE) ? -1 : answer);
    
    }

    public static void dfs(int depth, int sum){
        if(depth==n){
            //n개의 전공책에 대한 선택이 모두 끝나면
            if(check()){
                answer = Math.min(answer, sum);
            }
            return;
        }

        //depth번째 전공책을 선택하는 경우
        for(int i=0; i<book[depth].length(); i++){
            select[book[depth].charAt(i)-'A']++;
        }
        dfs(depth+1, sum+price[depth]);

        //depth번째 전공책을 선택하지 않는 경우
        for(int i=0; i<book[depth].length(); i++){
            select[book[depth].charAt(i)-'A']--; //원상 복구
        }
        dfs(depth+1, sum);
    }
    
    public static boolean check(){
        for(int i=0; i<26; i++){
            if(count[i] > select[i]) return false;
        }

        return true;
    }
}


