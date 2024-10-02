class Solution {
    data class Stage(val stage : Int, val fail : Double)

    fun solution(N: Int, stages: IntArray): IntArray {
        var list : MutableList<Stage> = mutableListOf<Stage>()
        var stagesSize : Int = stages.size
        var idx : Int = 0

        stages.sort()


        for(i in 1 .. N){
            var fail : Int = 0
            var sameSize : Int = 0
            while(idx < stages.size && stages[idx] == i){
                sameSize++
                idx++
            }
            list.add(Stage(i,if(stagesSize > 0) sameSize.toDouble() / stagesSize else 0.0))
            stagesSize -= sameSize
        }


        return list.sortedWith(compareByDescending<Stage> { it.fail }.thenBy { it.stage })
            .map { it.stage }
            .toIntArray()
    }
}