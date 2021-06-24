fun main(){

    var t = readLine()!!.toInt()

    for(i in 1..t){
        val(a,b) = readLine()!!.split(" ").map { it.toInt() }
        println(a+b)
    }
}