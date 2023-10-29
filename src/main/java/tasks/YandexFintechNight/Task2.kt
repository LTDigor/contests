package tasks.YandexFintechNight

import java.util.*

const val MY_ID = -1
fun main() {
    val sc = Scanner(System.`in`)
    val peopleNumber = sc.nextInt()
    val meetingNumber = sc.nextInt()
    sc.nextLine()

    val myPeriod = getSegment(sc.nextLine(), MY_ID)
    val meetings = mutableListOf<Segment>()

    // read data
    repeat(meetingNumber) {
        val personId = sc.nextInt()
        meetings.add(getSegment(sc.nextLine().trim(), personId))
    }

    val res = findMaxIntersectionLength(meetings, myPeriod, peopleNumber)
    println(res)
}

data class Segment(val start: Int, val end: Int, val personId: Int)
data class Point(val time: Int, val direction: Int, val personId: Int)

fun getSegment(time: String, personId: Int): Segment {
    val times = time.split("-")
    val startTime = times[0].split(":")
    val endTime = times[1].split(":")

    val from = startTime[0].toInt() * 60 + startTime[1].toInt()
    val to = endTime[0].toInt() * 60 + endTime[1].toInt()

    return Segment(from, to, personId)
}

fun findMaxIntersectionLength(segments: List<Segment>, mySegment: Segment, peopleNumber: Int): Int {
    val points = mutableListOf<Point>()
    for (segment in segments) {
        points.add(Point(segment.start, 1, segment.personId))
        points.add(Point(segment.end, -1, segment.personId))
    }
    points.add(Point(mySegment.start, 0, personId = MY_ID))
    points.add(Point(mySegment.end, 0, personId = MY_ID))

    points.sortWith(compareBy({ it.time }, { it.direction }))

    var maxIntersectionLength = 0
    var intersectionCount = 0
    var lastPoint = 0
    var freePeopleInPoint = peopleNumber
    val mapPeopleInPoint = mutableMapOf<Int, Int>()

    for ((point, direction, personId) in points) {
        if (personId != MY_ID) {
            mapPeopleInPoint[personId] = mapPeopleInPoint.getOrDefault(personId, 0) + direction
        }

        if (direction == 1 && mapPeopleInPoint[personId] == 1) {
            freePeopleInPoint -= 1
        }
        else if (direction == -1 && mapPeopleInPoint[personId] == 0) {
            freePeopleInPoint += 1
        }

        if (personId != MY_ID && intersectionCount == 0 && point - lastPoint > maxIntersectionLength && freePeopleInPoint == peopleNumber &&
            point >= mySegment.start && point <= mySegment.end
        ) {
            maxIntersectionLength = point - lastPoint
        }
        intersectionCount += direction
        lastPoint = point
    }
    return maxIntersectionLength
}
