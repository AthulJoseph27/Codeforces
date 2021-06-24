fun main(){

    var n = readLine()!!.toInt()

    var a = readLine()!!.split(" ").map { it.toLong() }.toList().toTypedArray()

    var b = LongArray(n)

    for(i in 1 ..n)
        b[i-1] = a[i-1]
    
    b.sort()

    var bi = -1
    var sbi = -1

    var count = 0

    for(i in a)
        if(i == b[n-1])
            count+=1
        
    for(i in 1..n)
        if(a[i-1] == b[n-1])
            bi = i
        else if(a[i-1] == b[n-2])
            sbi = i

    if(count > 1)
        sbi = bi
    
    var ans = ArrayList<Int>()

    var sm = 0.toLong()

    for (i in 0..(n-1))
        sm+=a[i]
    
    for (i in 1..n){
       if(i == bi){
            if((sm - a[i-1] - a[sbi-1]) == a[sbi-1]){
                ans.add(i)
            }
        }else{
            if((sm - a[i-1] - a[bi-1]) == a[bi-1]){
                ans.add(i)
            }
        }
    }

    println(ans.size)

    for(i in ans)
        print(i.toString()+" ")
       
    println()
}