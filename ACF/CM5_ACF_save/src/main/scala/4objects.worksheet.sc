// 3) Object model --------------------------------------------------------------------------------

// Class definition and constructors

class Rational(n: Int, d: Int) { // This also defines the primary constructor
  val num = n
  val den = d

  def isNull: Boolean = (num == 0)
}

val r = new Rational(5, 2)
val r1 = new Rational(7, 4)

println(r)
println(r.num)
//r.den = 10 //forbidden reassignement to val

// Exercice 10,11,12,13,14... in the code of Rational

implicit def bool2int(b: Boolean): Int = if (b) 1 else 0
1 + true






