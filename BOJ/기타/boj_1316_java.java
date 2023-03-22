package 기타;

import java.util.*;
import java.io.*;

public class boj_1316_java{
    static int n;
    static String[] words;
    public static void main(String[] args) throws Exception{
        //단어 N개를 입력으로 받아 그룹 단어의 개수를 출력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        words = new String[n];
        for(int i=0; i<n; i++){
            words[i] = br.readLine();
        }

        int answer = 0;
        for(String w:words){
            if(check(w)){
                answer++;
            }
        }

        System.out.println(answer);
    }

    public static boolean check(String w){
        boolean[] alphabets = new boolean[26];
        
        alphabets[ w.charAt(0)-'a'] = true;
        
        for(int i=1; i<w.length(); i++){
           char c = w.charAt(i);
           if(c!=w.charAt(i-1) && alphabets[c-'a']){
            return false;
           }
           alphabets[c-'a'] = true;
        }

        return true;

    }
}