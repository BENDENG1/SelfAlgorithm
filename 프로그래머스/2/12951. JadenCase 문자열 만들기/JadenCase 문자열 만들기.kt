class Solution {
    fun solution(s: String): String {
        var answer = StringBuilder(s.lowercase())

        for(i in answer.indices){
            if(answer[i].isLetter()){
                if(i == 0) 
                    answer[i] = answer[i].uppercaseChar()
                else if(i - 1 > 0 && answer[i - 1] == ' ') 
                    answer[i] = answer[i].uppercaseChar()
            }
        }
        return answer.toString()
    }
}