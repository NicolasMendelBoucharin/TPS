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

  def eval(e: Expression, m: Map[String, Int]): Int = {
    e match {
      case IntegerValue(i) => i
      case VariableRef(v)  => m.getOrElse(v, -1)
      case BinExpression(o, e1, e2) =>
        o match {
          case Plus => eval(e1, m) + eval(e2, m)

          case Minus => eval(e1, m) - eval(e2, m)
          case Times => eval(e1, m) * eval(e2, m)
          case Inf   => 
            if (eval(e1,m) < eval(e2, m)){
              1
            }
            else 0
          case Infeq => 
            if (eval(e1,m) <= eval(e2, m)){
              1
            }
            else 0
          case Equal => 
            if (eval(e1,m) == eval(e2, m)){
              1
            }
            else 0
        }
    }
  }

  def eval(p: Statement, inList: List[Int], outList: List[Int], m:Map[String, Int]): (List[Int], List[Int], Map[String, Int]) = {
    p match {
      case Seq(s1: Statement, s2: Statement)                => 
        val prout = eval(s1, inList, outList, m)
        eval(s2, prout._1, prout._2, prout._3)//évaluer s1 puis utiliser eval de s1 dans s2
      case If(c: Expression, s1: Statement, s2: Statement)  =>
         if (c==1){
          eval(s1, inList, outList, m)
         }
         else{
          eval(s2, inList, outList, m)
         }
      case While(c: Expression, s: Statement)               => 
        if (eval(c,m)==1){
          val prout = eval(s, inList, outList, m)
          eval(While(c,s), prout._1, prout._2, prout._3)
        }
        else (inList, outList, m)
        
      case Assignement(v: String, e: Expression) => (inList, outList, m +(v -> (eval(e, m))))
         //ajouter un truc à la map
      case Print(e: Expression)                             => (inList, eval(e, m)::outList, m) //ajouter un élément à la liste de sortie
      case Read(s: String) =>//enlever un élement de la liste de base                                
         inList match{
          case Nil =>  (Nil, outList, (m + (s-> (-1)))) // associer s à -1
          case i::inList =>  (inList, outList, (m + (s-> i))) //associer s à i
        } //enlever un élement de la liste de base
      case Skip                                             => (inList, outList, m)
    }
  } 

  def eval(p: Statement, inList: List[Int]): List[Int] = {
    eval(p, inList, Nil, Map[String, Int]())._2

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
    println(Interpret.eval(prog, List(5)))
  }
}
