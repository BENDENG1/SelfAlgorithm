/*
두 큐 합 같게 만들기 / 코틀린

두 큐의 원소 합이 같도록 작업에 필요한 최소 횟수

 */
class Solution {
    fun solution(queue1: IntArray, queue2: IntArray): Int {
        var answer: Int = 0
        var size : Int = queue1.size + queue2.size
        var oneSum : Long = queue1.sumOf { it.toLong() }
        var twoSum : Long = queue2.sumOf { it.toLong() }
        var q1 : ArrayDeque<Int> = ArrayDeque(queue1.map { it.toInt() }.toList())
        var q2 : ArrayDeque<Int> = ArrayDeque(queue2.map { it.toInt() }.toList())

        while(answer <= size * 2){
            var tmp : Int = 0
            if(oneSum == twoSum) return answer
            if(oneSum > twoSum) {
                tmp = q1.first()
                q1.removeFirst()
                oneSum -= tmp
                twoSum += tmp
                q2.addLast(tmp)
                answer++
            }else{
                tmp = q2.first()
                q2.removeFirst()
                oneSum += tmp
                twoSum -= tmp
                q1.addLast(tmp)
                answer++
            }
        }
        return -1
    }
}