fun main(){

    var n = readLine()!!.toInt()

    var N = 2*n - 2

    var l = ArrayList<String>()
    var ms = ""
    var index = -1

    for(i in 1..N){
        var s = readLine()!!
        if(s.length > ms.length){
            ms = s
            index = i
        }
        l.add(s)
    }

    var prefix = ""
    var suffix = ""
    
    for(i in l){
        if(i.length == n-1){
            if(prefix == ""){
                prefix = i
            }else{
                suffix = i
            }
        }
    }

    var option1 = prefix+suffix[suffix.length-1]
    var option2 = suffix+prefix[prefix.length-1]

    var ans1 = ArrayList<String>()

    var ans2 = ArrayList<String>()

    var ans3 = ArrayList<String>()

    var ans4 = ArrayList<String>()

    var isOption1 = true

    var taken = ArrayList<Boolean>()

    for(i in 1..(n-1))
        taken.add(true)

    for(i in l){
        if(taken.get(i.length-1) && option1.substring(0,i.length) == i){
            ans1.add("P")
            taken[i.length-1] = false;
        }else if(option1.substring(n-i.length,n) == i){
            ans1.add("S")
        }else{
            isOption1 = false
            break
        }
    }

    var sCount = 0
    var pCount = 0

    for(i in ans1){
        if(i == "S")
            sCount++
        else
            pCount++
    }

    if(isOption1){
        isOption1 = (pCount == sCount)
    }

    if(isOption1){
        for(i in ans1)
            print(i)
        println()
        return
    }



    var taken2 = ArrayList<Boolean>()

    for(i in 1..(n-1))
        taken2.add(true)

    for(i in l){
        if(taken2.get(i.length-1) && option2.substring(0,i.length) == i){
            ans2.add("P")
            taken2[i.length-1] = false
        }else{
            ans2.add("S")
        }
    }

    
    for(i in ans2)
        print(i)
    println()

}

    // 4 , 5, 3