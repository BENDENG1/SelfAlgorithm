class Solution {
    fun solution(s: String): String {
        var answer = StringBuilder(s.lowercase())
        
        for(i in 0 until answer.length){
            if(i == 0){
                answer[i] = answer[i].uppercaseChar()
            }else{
                if(s[i- 1] == ' ') answer[i] = answer[i].uppercaseChar()
            }
        }
        return answer.toString()
    }
}