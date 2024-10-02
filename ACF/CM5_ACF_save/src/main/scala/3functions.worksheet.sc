//2) Functions -----------------------------------------------------------------------

// Basic functions

def plus(x: Int, y: Int) = {
  println("Sum of " + x + " and " + y + " is equal to  " + (x + y))
  x + y // No return keyword
}

plus(18, 24)


// Recursive functions


def fact(n: Int): Int = // result type annotation is compulsory for recursive functions
  if (n <= 1) 1 else n * fact(n - 1)

fact(10)


def gcd(a: Int, b: Int): Int = // result type annotation is compulsory for recursive functions
  if (b == 0) a else gcd(b, a % b)

gcd(15, 9)


// Exercise 6


// Higher order, anonymous functions

// Anonymous functions

((x: Int) => x + 1) // would be written (lambda x. x+1) in Isabelle/HOL
((x: Int) => x + 1) (1) // anonymous functions application

val la = List(1, 2, 3)
la.map((x: Int) => x + 1) 

// Exercise 7
val s = "robert"
s.capitalize

// Partial application the '_' permits to speak about the function associated to any name/object.
plus(_, _)
plus(1, _: Int)
la.map(plus(_: Int, 1))


(_: String).size // the function associated to the size operation of the String class

(_: Int) + (_: Int) // the addition function for integer, etc.

(_: String) == "toto" //the function testing if a string is equal to "toto"


// Exercise 8

// Exercise 9
