/*
개인정보 수집 유효기간 / 코틀린

모든달은 28일까지 있다고 가정
*/
class Solution {

    private fun isFinish(today : String, month : Int, date : String) : Boolean {
        val yearDiff = today.split(".")[0].toInt() - date.split(".")[0].toInt()
        val monthDiff = today.split(".")[1].toInt() - date.split(".")[1].toInt()
        val dayDiff = today.split(".")[2].toInt() - date.split(".")[2].toInt()

        return (yearDiff * 12 + monthDiff) * 28 + dayDiff >= month * 28
    }

    fun solution(today: String, terms: Array<String>, privacies: Array<String>): IntArray {
        var answer = mutableListOf<Int>()
        val termsMap = mutableMapOf<Char,Int>()

        terms.forEach {term ->
            val list = term.split(" ")
            termsMap[list[0][0]] = list[1].toInt()
        }

        privacies.forEachIndexed { index, privacy ->
            if(isFinish(today, termsMap.getOrDefault(privacy.split(" ")[1][0],0),privacy.split(" ")[0])){
                answer.add(index + 1)
            }
        }
        return answer.toList().toIntArray()
    }
}