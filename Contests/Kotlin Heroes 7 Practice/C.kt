fun main(){

    var t = readLine()!!.toInt()

    for(i in 1..t){
        val(n,k) = readLine()!!.split(" ").map { it.toInt() }
        
        var s = ""

        for(j in 1..n){
            s+=(j%k+97).toChar()
        }

        println(s)

    }
}