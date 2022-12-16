package etc;

import java.util.*;

class Pro_level1_118666 {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        String[][] indicators = {
            {"R", "T"},
            {"C", "F"},
            {"J", "M"},
            {"A", "N"}
        };
        
        int[] score = {3, 2, 1, 0, 1, 2, 3};
        Map<String, Integer> map = new HashMap<>();
        //검사자의 성격 유형 검사 결과를 지표 번호 순서대로 return 
        
        //점수 계산
        for(int i=0; i<survey.length; i++){
            String s = survey[i];
            if(choices[i] < 4){
                String temp = String.valueOf(s.charAt(0));
                map.put(temp, map.getOrDefault(temp, 0)+score[choices[i]-1]);
            }
            else if(choices[i] > 4){ //동의
                String temp = String.valueOf(s.charAt(1));
                map.put(temp, map.getOrDefault(temp, 0)+score[choices[i]-1]);
            }
        }
    
        //성격유형 검사
        for(int i=0; i<4; i++){
            if(map.getOrDefault(indicators[i][0], 0) >= map.getOrDefault(indicators[i][1], 0)){
                answer += indicators[i][0];
            }
            else answer += indicators[i][1];
        }
        
        return answer;
    }
}