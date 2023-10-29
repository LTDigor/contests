package tasks.yandexInternMeetup

import java.util.*
import kotlin.math.min

fun check(groups: MutableMap<Int, Int>, rooms: MutableMap<Int, Int>): Boolean {
    var res = true

    val roomSizes = rooms.keys.sorted().toMutableList()

    val groupSizes = groups.keys.sorted().toMutableList()

    while (groupSizes.size > 0) {
        if (rooms.isEmpty() || groupSizes.last() > roomSizes.last()) {
            res = false
            break
        }

        val roomsToRemove = min(rooms[roomSizes.last()]!!, groups[groupSizes.last()]!!)
        rooms[roomSizes.last()] = rooms[roomSizes.last()]!! - roomsToRemove
        groups[groupSizes.last()] = groups[groupSizes.last()]!! - roomsToRemove

        if (rooms[roomSizes.last()] == 0) {
            rooms.remove(roomSizes.last())
            roomSizes.removeLast()
        }

        if (groups[groupSizes.last()] == 0) {
            groups.remove(groupSizes.last())
            groupSizes.removeLast()
        }
    }
    return res
}

fun main() {
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()

    val groups = mutableMapOf<Int, Int>()
    for (i in 0 until n) {
        val value = sc.nextInt()
        groups[value] = groups.getOrDefault(value, 0) + 1
    }

    val k = sc.nextInt()
    val rooms = mutableMapOf<Int, Int>()
    repeat(k) {
        val key = sc.nextInt()
        val value = sc.nextInt()
        rooms[key] = rooms.getOrDefault(key, 0) + value
    }
    println(if (check(groups, rooms)) "Yes" else "No")
}
