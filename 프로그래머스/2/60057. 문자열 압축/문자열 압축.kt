/*
문자열 압축

몇개 단위로 자를지에 대해서 고민하김
*/
class Solution {
    private val MAX = 1000

    fun solution(s: String): Int {
        var answer = MAX

        if(s.length == 1) return 1

        for(i in 1 ..  s.length / 2){
            var str = s.substring(0,i)
            var tmp = ""
            var cnt = 1

            for(j in i .. s.length step i){
                if(i + j <= s.length && s.substring(j,i + j) == str){
                    cnt++
                }else{
                    if(cnt > 1){
                        tmp += cnt.toString() + str
                    }else{
                        tmp += str
                    }

                    if(i + j <= s.length){
                        str = s.substring(j, j + i)
                    }else{
                        str = s.substring(j)
                    }
                    cnt = 1
                }
            }
            tmp += str
            if(answer > tmp.length) answer = tmp.length
        }
        return answer
    }
}