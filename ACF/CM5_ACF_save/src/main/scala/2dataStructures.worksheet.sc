println("----------- data structures -------")


/** (Immutable) lists */
print("")
var lz = List(1, 2, 3, 4, 5)
lz = List()
val l1 = 0 :: lz
val l2 = l1 :+ 6

val l3 = List(7, 8, 9, 10)
val l4 = l2 ++ l3
l4.reverse // parameterless method can be called without ()
l4 // lists are immutable
val l5 = l4.reverse
l5

l5 match {
  case Nil => 0
  case e :: _ => e
}


// Exercise 3
val lb = List(1, 2, 3, 5)


// Exercise 4


// Arrays
val t: Array[String] = new Array[String](3)

// Using the type inference it is less verbose
val t1 = new Array[String](5)
t1(0) = "zero"
t1(1) = "un"
t1(2) = "deux"
t1(3) = "trois"
t1(4) = "quatre"
t1

// Using type inference and simplified constructor it is far less verbose!
val t2 = Array("zero", "un", "deux", "trois", "quatre")

// Arrays can be modified
t2(4) = "quatro"
t2


// (Immutable) sets
val s1 = Set(1, 2, 3, 4, 5)
s1.contains(4)
s1 contains 10 // with the '.' free notation


// (Immutable) Tuples

val tu = (1, "toto", 18.3)
tu._1
tu._2

tu match {
  case (2, "toto", _) => "found!"
  case (_, x, _) => x
}

// Maps

val m = Map('C' -> "Carbon", 'H' -> "Hydrogen")
val m1 = m + ('O' -> "Oxygen")
m1('C')
//m1('K')

m1.getOrElse('K',"Unknown")

try m1('K') catch {
  case _: NoSuchElementException => "Unknown"
}

// Exercise 5

m1
