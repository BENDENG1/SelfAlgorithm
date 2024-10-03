/*
괄호 변환 / 코틀린

(,)갯수 같 -> 균현잡힌 괄호 문자열
(,) 짝이 맞 -> 올바른 괄호 문자열
*/
class Solution {
    fun makeString(s : String) : String {
        if(s.isEmpty()) return ""

        var cnt : Int = 0
        var left : Int = 0
        var u : String = ""
        var v : String = ""
        var flag : Boolean = true

        for(i in s){
            if(i == '(') left++ else left --
            cnt++
            if(left == 0){
                u = s.substring(0,cnt)
                v = s.substring(cnt, s.length)
                break
            }
        }

        cnt = 0
        for(i in u){
            if(i == '(') cnt++ else cnt--
            if(cnt < 0) flag = false
        }
        if(flag){
            return u + makeString(v)
        }else{
            var first = "(" +makeString(v) + ")"
            var second = ""
            u.substring(1, u.length - 1).forEach {
                if(it == '(') second = "$second)"
                else second = "$second("
            }
            return first + second
        }
    }

    fun solution(p: String): String {
        var answer = ""
        answer = makeString(p)
        return answer
    }
}