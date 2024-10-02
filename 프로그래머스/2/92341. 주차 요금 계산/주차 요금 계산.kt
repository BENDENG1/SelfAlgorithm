/*
주차 요금 계산 / 코틀린

출차 기록x 23:59간주
기본 시가 이하 -> 기본요금
기본 시간 초과 -> 기본요금 + 단위시간마다 단위요금

*/
class Solution {
    data class Park(
        var hour: Int,
        var minute: Int,
        var carNumber: String,
        var isIn: Boolean,
        var time : Int = 0,
        var fee : Int = 0,
    )

    fun splitRecord(record: String): Park {
        val list = record.split(' ')
        val hour = list[0].split(':')[0].toInt()
        val minute = list[0].split(':')[1].toInt()
        val car: String = list[1]
        val isIn: Boolean = list[2] == "IN"

        return Park(hour, minute, car, isIn)
    }

    private fun calculateFee(time : Int, fees : IntArray) : Int{
        if(time <= fees[0])
            return fees[1]
        else{
            val remain : Int = if((time - fees[0]) % fees[2] > 0) 1 else 0
            return fees[1] + ((time - fees[0]) / fees[2] + remain) * fees[3]
        }
    }

    fun solution(fees: IntArray, records: Array<String>): IntArray {
        var answer: IntArray = intArrayOf()
        val list = mutableListOf<Park>()


        records.forEachIndexed { index, s ->
            val record = splitRecord(s)
            val findCar = list.find {it.carNumber == record.carNumber}

            if(findCar == null){
                list.add(Park(record.hour, record.minute, record.carNumber, true, 0))
            }else {
                list.remove(findCar)
                if(record.isIn){
                    list.add(findCar.copy(record.hour, record.minute, record.carNumber, true, findCar.time))
                }else{
                    val diffTime = (record.hour - findCar.hour) * 60 + (record.minute - findCar.minute)
                    list.add(findCar.copy(record.hour, record.minute, record.carNumber, false, findCar.time + diffTime))
                }
            }
        }

        list.forEachIndexed { index, park ->
            if(list[index].isIn){
                val diffTime = (23 * 60 + 59) - (park.hour * 60 + park.minute)
                list[index].time += diffTime
                list[index].fee = calculateFee(list[index].time,fees)
            }else{
                list[index].fee = calculateFee(list[index].time, fees)
            }
        }

        return list.sortedBy { it.carNumber }.map { it.fee }.toIntArray()
    }
}