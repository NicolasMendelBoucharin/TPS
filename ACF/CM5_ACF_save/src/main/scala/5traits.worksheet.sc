trait IntQueue {
  def get: Int
  def put(x: Int):Unit
}

// implementation of a Trait
class MyIntQueue extends IntQueue {
  protected var b = List[Int]()

  def get = {
    val h = b(0)
    b = b.drop(1)
    h
  }

  def put(x: Int) = {
    b = b :+ x
  }
}


val iq: IntQueue = new MyIntQueue
iq.put(1)
iq.put(2)
iq.put(3)
iq.get
iq.get
iq.get

// singleton object
object InfiniteQueueOfOne extends IntQueue {
  def get = 1
  def put(x: Int) = {}
}


InfiniteQueueOfOne.get
InfiniteQueueOfOne.get
InfiniteQueueOfOne.get
InfiniteQueueOfOne.put(18)
InfiniteQueueOfOne.get
InfiniteQueueOfOne.get
InfiniteQueueOfOne.get
