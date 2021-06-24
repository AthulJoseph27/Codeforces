fun main(){

    var t = readLine()!!.toInt()

    for(i in 1..t){
        val(a,b,k) = readLine()!!.split(" ").map { it.toLong() }
        
        var netMove = a-b

        if(k%2 == 0.toLong()){
            println(netMove * (k/2))
        }else{
            println(netMove * ((k-1)/2) + a)
        }
    }
}