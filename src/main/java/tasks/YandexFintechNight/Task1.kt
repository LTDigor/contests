package tasks.YandexFintechNight

import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val firstInt = sc.nextLine().trim('[', ']').split(", ").joinToString("").toLong()
    val secondInt = sc.nextLine().trim('[', ']').split(", ").joinToString("").toLong()

    val res = (firstInt + secondInt).toString().toCharArray().map { it.toString().toLong() }
    println(res)
}
