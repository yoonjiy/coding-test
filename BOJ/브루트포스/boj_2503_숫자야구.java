package 브루트포스;

import java.io.*;
import java.util.*;

public class boj_2503_숫자야구 {
    static int n;
    static List<String[]> list;
    static int answer;
    public static void main(String[] args) throws Exception{
        //영수가 생각하고 있을 가능성이 있는 답의 총 개수
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        list = new ArrayList<>();
        for(int i=0; i<n; i++){
            String[] str = br.readLine().split(" ");
            list.add(str);
        }

        for(int i=123; i<=987; i++){
            //숫자 중복 안됨, 0 안됨
            String num = String.valueOf(i);
            if(num.contains("0")) continue;
            if(isDuplicate(num)) continue;

            boolean flag = true;
            for(int j=0; j<n; j++){
                String target = list.get(j)[0];
                int strike = Integer.parseInt(list.get(j)[1]);
                int ball = Integer.parseInt(list.get(j)[2]);

                //num과 비교. strike 개수와 ball 개수가 n개의 타겟들과 모두 일치해야 가능성이 있는 수임.
                int sn = 0;
                for(int s=0; s<3; s++){
                    if(num.charAt(s)==target.charAt(s)) sn++;
                }

                if(sn!=strike) {
                    flag = false;
                    break;
                }

                int bn = 0;
                for(int bi=0; bi<3; bi++){
                    for(int bj=0; bj<3; bj++){
                        //위치는 다르지만 숫자가 같음
                        if(bi==bj) continue;
                        if(num.charAt(bi)==target.charAt(bj)) bn++;
                    }
                }

                if(bn!=ball) {
                    flag = false;
                    break;
                }
            }

            if(flag) answer++;
        }

        System.out.println(answer);

    }

    public static boolean isDuplicate(String num){
        for(int i=0; i<2; i++){
            if(num.charAt(i)==num.charAt(i+1)) {
                return true;
            }
        }
        if(num.charAt(0)==num.charAt(2)) return true;
        return false;
    }
}
