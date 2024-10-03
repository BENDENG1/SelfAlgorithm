/*
메뉴 리뉴얼 / 코틀린


*/
class Solution {
    val m = hashMapOf<String, Int>()

    fun dfs(order : String, len : Int, str : String, idx : Int){
        if(str.length == len){
            m[str] = m.getOrDefault(str,0) + 1
            return
        }

        for(i in idx until order.length){
            dfs(order,len, str + order[i], i + 1)
        }
    }

    fun solution(orders: Array<String>, course: IntArray): Array<String> {
        val answer = mutableListOf<String>()
        val sortedOrders = orders.map { it.toList().sorted().joinToString("") }

        for(i in course.indices){
            for(j in sortedOrders.indices){
                dfs(sortedOrders[j],course[i],"",0)
            }

            var turn : Int = 0
            m.onEachIndexed { _, entry ->
                turn = if(turn < entry.value){
                    entry.value
                }else{
                    turn
                }
            }

            m.onEachIndexed { index, entry ->
                if(entry.value == turn && entry.value > 1)
                    answer.add(entry.key)
            }

            m.clear()
        }
        return answer.sorted().toTypedArray()
    }
}