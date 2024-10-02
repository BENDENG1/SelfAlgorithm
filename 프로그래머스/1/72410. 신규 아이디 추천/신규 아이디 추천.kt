/*
신규 아이디 추천 / 코틀린

아이디 : 3 .. 15 / 알파벳 소문자 - _ . 사용 가능/ .는 처음 끝 그리고 연속 불가


*/
class Solution {
    fun solution(new_id: String): String {
        var answer: String = ""
        
        answer = new_id.lowercase().replace(Regex("[^a-z0-9._-]"),"").replace(Regex("[.]+"),".").trim('.')
        //5. 빈문자열 -> a를 대입
        if(answer.isEmpty())
            answer = "a"
        //6. 길이가 16이상이면 15개로 자르고 마지막.이면 .제거
        if(answer.length >= 16){
            answer = answer.substring(0,15).removeSuffix(".")
        }
        // 7. 2이하이면 3이 될때까지 마지막 더함
        while (answer.length < 3) {
            answer += answer.last()
        }

        return answer
    }
}

//        // 1. 소문자로 변환
//        answer = new_id.lowercase()
//
//        //2. -,_,.를 제외한 문자 제거
//        answer = answer.replace(Regex("[^a-z0-9._-]"),"")
//
//        //3. . 연속 제거
//        answer = answer.replace(Regex("[.]+"),".")
//
//        //4. .처음 끝이면 제거
//        answer = answer.trim('.')