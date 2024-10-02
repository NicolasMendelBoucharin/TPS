//polymorphism
trait Queue[T] {
  def get: T
  def push(x: T):Unit
}

class MyQueue[T] extends Queue[T] {
  protected var b = List[T]()

  def get = {
    val h = b(0)
    b = b.drop(1)
    h
  }

  def push(x: T):Unit = {
    b = b :+ x
  }
}
