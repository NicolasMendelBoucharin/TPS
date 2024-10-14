package tp4

object PrettyPrinter {
  def stringOf(o: Operator): String = {
    o match {
      case Plus =>
        "+"

      case Minus => "-"
      case Times => "*"
      case Inf   => "<"
      case Infeq => "<="
      case Equal => "="
    }
  }
  def stringOf(e: Expression): String = {
    e match {
      case IntegerValue(i)        => i.toString()
      case VariableRef(v)         => v
      case BinExpression(o, x, y) => stringOf(x) + stringOf(o) + stringOf(y)
    }
  }

  def stringOf(p: Statement): String = {
    p match {
      case Seq(s1: Statement, s2: Statement) =>
        stringOf(s1) + "\n" + stringOf(s2)
      case If(c: Expression, s1: Statement, s2: Statement) =>
        "if (" + stringOf(c) + ") then {\n" + stringOf(
          s1
        ) + "\n} else{\n" + stringOf(s2) + "\n}"
      case While(c: Expression, s: Statement) =>
        "while (" + stringOf(c) + ") do { \n" + stringOf(s) + "\n}"
      case Assignement(v: String, e: Expression) => v + ":= " + stringOf(e)
      case Print(e: Expression)                  => "print(" + stringOf(e) + ")"
      case Read(s: String)                       => "read(" + s + ")"
      case Skip                                  => "skip"
    }
  }
}

object Interpret {
  def eval(p: Statement, inList: List[Int]): List[int] {
    
  }
}

object Main {
  def main(args: Array[String]): Unit = {
    val exp = BinExpression(
      Plus,
      VariableRef("y"),
      BinExpression(Minus, IntegerValue(1), IntegerValue(2))
    )
    val prog = Seq(
      Assignement("x", IntegerValue(0)),
      Seq(
        Assignement("y", IntegerValue(1)),
        Seq(
          Read("z"),
          Seq(
            While(
              BinExpression(Inf, VariableRef("x"), VariableRef("z")),
              Seq(
                Assignement(
                  "x",
                  BinExpression(Plus, VariableRef("x"), IntegerValue(1))
                ),
                Seq(
                  Assignement(
                    "y",
                    BinExpression(Times, VariableRef("y"), VariableRef("x"))
                  ),
                  Print(VariableRef("x"))
                )
              )
            ),
            Print(VariableRef("y"))
          )
        )
      )
    )

    // A compléter
    println(BinExpression(Plus, VariableRef("x"), IntegerValue(1)))
    println(
      PrettyPrinter.stringOf(
        BinExpression(Plus, VariableRef("x"), IntegerValue(1))
      )
    )
    println(PrettyPrinter.stringOf(prog))
    println("Le résultat est à afficher ici!")
  }
}
