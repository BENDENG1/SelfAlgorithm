/*
k진수에서 소수 개수 구하기

k진수로 바꿨을 때 소수 갯수 ->

0P0 / P0 / 0P / P 단 P는 0을 가질 수 없음

*/
class Solution {
    fun solution(n: Int, k: Int): Int {
        var answer: Int = 0
        var str : String = ""
        var list : List<String> = emptyList()
        var num = n

        while(num > 0){
            str += (num % k).toString()
            num /= k
        }
        list = str.reversed().split(Regex("0+"))
        list.forEach { s->
            if(s.isNotEmpty() && isPrime(s.toLong()))
                answer++
        }
        return answer
    }

    fun isPrime(n : Long) : Boolean{
        if(n < 2)
            return false
        if(n == 2L || n == 3L)
            return true
        for(i in 2..Math.sqrt(n.toDouble()).toInt()){
            if(n % i == 0L)
                return false
        }
        return true
    }
}