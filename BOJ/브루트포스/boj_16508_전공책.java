package 브루트포스;

import java.util.*;
import java.io.*;

public class boj_16508_전공책 {
    static String t;
    static int n;
    static int answer = Integer.MAX_VALUE;
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
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            price[i] = Integer.parseInt(st.nextToken());
            book[i] = st.nextToken();
        }


        for(int i=1; i<=n; i++){
            //i권의 전공책 선택 
            visited = new boolean[n];

            int[] comb = new int[i];
            dfs(0, i, 0, comb, 0);

            if(answer!=Integer.MAX_VALUE) break;
        }

        if(answer==Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(answer);
        
    }

    public static void dfs(int depth, int end, int idx, int[] comb, int sum){
        if(depth==end){
            //i권의 전공책 조합을 선택, 원하는 글자 t를 만들 수 있다면
            if(check(comb)){
                if(sum < answer){
                    answer = sum;
                }
            }
            return;
        }

        for(int i=idx; i<n; i++){
            if(visited[i]) continue;

            visited[i] = true;
            comb[depth] = i;
            dfs(depth+1, end, i+1, comb, sum+price[i]);

            visited[i] = false;
        }
    }
    
    public static boolean check(int[] comb){
        char[] chars = t.toCharArray();
        boolean[] included = new boolean[t.length()];
        for(int c:comb){
            //해당 전공책들로 원하는 글자를 만들 수 있는지 확인
            String b = book[c];
            for(int i=0; i<b.length(); i++){
                char bc = b.charAt(i);
                for(int j=0; j<chars.length; j++){
                    if(included[j]) continue;
                    if(bc==chars[j]){
                        included[j] = true;
                        break;
                    }
                }
            }
        }

        for(int i=0; i<chars.length; i++){
            if(!included[i]) return false;
        }

        return true;
    }
}


