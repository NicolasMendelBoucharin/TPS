// 1) Basics -----------------------------------------------------------------------
// Base types and type inference
1: Int
1 // here, the type is automatically inferred

'a'
"toto"
(): Unit

// All types (including) base types are objects (contrary to Java)
1 + 2 // For instance, this is equivalent to the usual method call:
(1).+(2)

// Exercise 1



// val and var
val x: Int = 1
//x=1            // reassignement to a val is forbidden!

var y = 2 // reassignement to a var is possible
y = 3
y

// If expressions

// Exercise 2

if (1 == 2) 1 else 2
if (1 == 2) 1 else "toto"
if (1 == 1) 1
if (1 == 1) println(1)

// match-case expressions

val rep = "au revoir"

rep match {
  case "bonjour" => "hello"
  case "au revoir" => "goodbye"
  case _ => "Don't know"
}

// for

(1).to(10)
(1).to(10, 2)

