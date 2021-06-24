fun main(){

    var n = readLine()!!.toInt()

    var a = readLine()!!.split(" ").map { it.toInt() }.toList().toTypedArray()

    a.sort()

    var ans = 0

    for(i in 1..n step 2){
        ans+=(a[i] - a[i-1])
    }

    println(ans)
}