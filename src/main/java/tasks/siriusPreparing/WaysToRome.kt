package tasks.siriusPreparing

import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    val m = sc.nextInt()

    val canBeRome = MutableList(n) { true }
    val roadsCounter = MutableList(n) { HashSet<Int>() }
    var res = -1

    repeat(m) {
        val a = sc.nextInt() - 1
        val b = sc.nextInt() - 1

        if (a != b) {
            canBeRome[a] = false
            roadsCounter[b].add(a)
        }
    }

    for (i in 0 until n) {
        if (canBeRome[i] && roadsCounter[i].size == n - 1) {
            res = i + 1
            break
        }
    }

    println(res)
}
