/*
성격 유형 검사하기


TR /CF /JM /AN
 */
class Solution {
    fun solution(survey: Array<String>, choices: IntArray): String {
        var answer = StringBuilder()
        val map = hashMapOf<Char, Int>()

        val characters = listOf('T', 'R', 'C', 'F', 'J', 'M', 'A', 'N')
        characters.forEach { map[it] = 0 }

        for (i in survey.indices) {
            val choice = choices[i]
            val first = survey[i][0]
            val second = survey[i][1]

            if (choice > 4) {
                map[second] = map[second]!! + (choice - 4)
            } else if (choice < 4) {
                map[first] = map[first]!! + (4 - choice)
            }
        }
        answer.append(if (map['R']!! >= map['T']!!) 'R' else 'T')
        answer.append(if (map['C']!! >= map['F']!!) 'C' else 'F')
        answer.append(if (map['J']!! >= map['M']!!) 'J' else 'M')
        answer.append(if (map['A']!! >= map['N']!!) 'A' else 'N')

        return answer.toString()
    }
}