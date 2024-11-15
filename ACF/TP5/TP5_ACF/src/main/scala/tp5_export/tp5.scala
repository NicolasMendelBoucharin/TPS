package tp5_export

// Here you should paste the Scala code generated from Isabelle/HOL
// and replace all the code below (object tp5 and Nat)


object HOL {

trait equal[A] {
  val `HOL.equal`: (A, A) => Boolean
}
def equal[A](a: A, b: A)(implicit A: equal[A]): Boolean = A.`HOL.equal`(a, b)
object equal {
  implicit def `Product_Type.equal_prod`[A : equal, B : equal]: equal[(A, B)] =
    new equal[(A, B)] {
    val `HOL.equal` = (a: (A, B), b: (A, B)) =>
      Product_Type.equal_proda[A, B](a, b)
  }
  implicit def `Nat.equal_nat`: equal[Nat.nat] = new equal[Nat.nat] {
    val `HOL.equal` = (a: Nat.nat, b: Nat.nat) => Nat.equal_nata(a, b)
  }
}

def eq[A : equal](a: A, b: A): Boolean = equal[A](a, b)

} /* object HOL */

object Code_Numeral {

def integer_of_nat(x0: Nat.nat): BigInt = x0 match {
  case Nat.Nata(x) => x
}

} /* object Code_Numeral */

object Nat {

abstract sealed class nat
final case class Nata(a: BigInt) extends nat

def equal_nata(m: nat, n: nat): Boolean =
  Code_Numeral.integer_of_nat(m) == Code_Numeral.integer_of_nat(n)

} /* object Nat */

object Product_Type {

def equal_proda[A : HOL.equal, B : HOL.equal](x0: (A, B), x1: (A, B)): Boolean =
  (x0, x1) match {
  case ((x1, x2), (y1, y2)) => HOL.eq[A](x1, y1) && HOL.eq[B](x2, y2)
}

} /* object Product_Type */

object Lista {

def member[A : HOL.equal](x0: List[A], y: A): Boolean = (x0, y) match {
  case (Nil, y) => false
  case (x :: xs, y) => HOL.eq[A](x, y) || member[A](xs, y)
}

} /* object Lista */

object ENSEMBLES {

def clean[A : HOL.equal](x0: List[A]): List[A] = x0 match {
  case Nil => Nil
  case x :: xs =>
    (if (Lista.member[A](xs, x)) clean[A](xs) else x :: clean[A](xs))
}

def includee[A : HOL.equal](x0: List[A], xs: List[A]): Boolean = (x0, xs) match
  {
  case (Nil, xs) => true
  case (x :: xs, Nil) => false
  case (x :: xs, v :: va) =>
    Lista.member[A](v :: va, x) && includee[A](xs, v :: va)
}

def equal[A : HOL.equal](xs: List[A], ys: List[A]): Boolean =
  includee[A](xs, ys) && includee[A](ys, xs)

def union[A : HOL.equal](x0: List[A], l: List[A]): List[A] = (x0, l) match {
  case (Nil, l) => l
  case (v :: va, Nil) => v :: va
  case (x :: xs, v :: va) =>
    (if (Lista.member[A](v :: va, x)) union[A](xs, v :: va)
      else x :: union[A](xs, v :: va))
}

def delete[A : HOL.equal](x: A, xa1: List[A]): List[A] = (x, xa1) match {
  case (x, Nil) => Nil
  case (x, y :: ys) =>
    (if (HOL.eq[A](x, y)) delete[A](x, ys) else y :: delete[A](x, ys))
}

def deleteList[A : HOL.equal](x0: List[A], l: List[A]): List[A] = (x0, l) match
  {
  case (Nil, l) => l
  case (x :: xs, ys) => delete[A](x, deleteList[A](xs, ys))
}

} /* object ENSEMBLES */

object tp5 {

abstract sealed class rule
final case class Drop(a: List[(Nat.nat, (Nat.nat, (Nat.nat, Nat.nat)))]) extends
  rule
final case class Accept(a: List[(Nat.nat, (Nat.nat, (Nat.nat, Nat.nat)))])
  extends rule

def acceptation(x0: List[rule]): List[(Nat.nat, (Nat.nat, (Nat.nat, Nat.nat)))]
  =
  x0 match {
  case Nil => Nil
  case Accept(l) :: c1 =>
    ENSEMBLES.union[(Nat.nat,
                      (Nat.nat,
                        (Nat.nat,
                          Nat.nat)))](acceptation(c1),
                                       ENSEMBLES.clean[(Nat.nat,
                 (Nat.nat, (Nat.nat, Nat.nat)))](l))
  case Drop(l) :: c1 =>
    ENSEMBLES.deleteList[(Nat.nat,
                           (Nat.nat,
                             (Nat.nat,
                               Nat.nat)))](ENSEMBLES.clean[(Nat.nat,
                     (Nat.nat, (Nat.nat, Nat.nat)))](l),
    acceptation(c1))
}

def equal(c1: List[rule], c2: List[rule]): Boolean =
  ENSEMBLES.equal[(Nat.nat,
                    (Nat.nat,
                      (Nat.nat, Nat.nat)))](acceptation(c1), acceptation(c2))

} /* object tp5 */
