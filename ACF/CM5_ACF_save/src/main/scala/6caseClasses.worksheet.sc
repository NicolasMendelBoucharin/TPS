class Rational(n: Int, d: Int) { // This also defines the primary constructor
  val num = n
  val den = d

  def isNull: Boolean = (num == 0)

  def +(r: Rational): Rational =
    new Rational(this.num * r.den + r.num * this.den
      , this.den * r.den)

  override def toString = this.num + "/" + this.den
}

// case classes
sealed trait Expression

case class BinExpr(o: String, l: Expression, r: Expression) extends Expression
case class Constant(r: Rational) extends Expression
case class Inv(e: Expression) extends Expression

// case classes
val e = BinExpr("+", Constant(new Rational(18, 27)), Inv(Constant(new Rational(1, 2)))) // No need for 'new' to build objects from case classes!


// pattern matching
def op(e: Expression): String = {
  e match {
    case BinExpr(o, _, _) => o
    case _ => "No operator"
  }
}

op(e)

// Exercise 15



// interoperability between Java and Scala

import scala.collection.JavaConverters._

val lj: java.util.List[Int] = new java.util.ArrayList[Int]()
lj.add(1)
lj.add(2)
lj.add(3)

val sb1 = lj.asScala.toList
val sl1 = sb1.asJava
