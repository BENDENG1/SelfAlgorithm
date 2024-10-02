/*
오픈 채팅방 / 코틀린
 */
class Solution {
    fun solution(record: Array<String>): Array<String> {
        var answer = mutableListOf<String>()
        val m = mutableMapOf<String,String>()

        record.forEachIndexed { index, s ->
            val list = s.split(' ')
            if(list.size == 3){
                m[list[1]] = list[2]
            }
        }

        record.forEachIndexed { index, s ->
            val list = s.split(' ')
            when(list[0]){
                "Enter" -> {
                    answer.add("${m[list[1]]}님이 들어왔습니다.")
                }
                "Leave" -> {
                    answer.add("${m[list[1]]}님이 나갔습니다.")
                }
            }
        }

        return answer.toTypedArray()
    }
}