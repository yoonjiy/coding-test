import java.util.*;
class Pro_level1_81301 {
    public int solution(String s) {
        int answer = 0;
        String[] words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        // s가 의미하는 원래 숫자를 return 
        Map<String, Integer> map = new HashMap<>();
        for(int i=0; i<10; i++){
            map.put(words[i], i);
        }
        
        String ans = "";
        String word = "";
        for(int i=0; i<s.length(); i++){
            if(map.containsKey(word)){
                ans += Integer.toString(map.get(word));
                word = "";
            }
            
            if(s.charAt(i)<='9' && s.charAt(i)>='0'){
                ans += s.charAt(i);
            }
            else{
                word += s.charAt(i);
            }
        }
        
        if(map.containsKey(word)){
            ans += Integer.toString(map.get(word));
        }
        
        
        answer = Integer.valueOf(ans);
        return answer;
    }
}