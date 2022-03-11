import java.io._
import Prog04Run._

class Point(val xc: Int, val yc: Int) {
  var x: Int = xc
  var y: Int = yc

  def move(dx: Int, dy: Int): Unit = {
    x = x + dx
    y = y + dy
    println("Point x location : " + x)
    println("Point y location : " + y)
  }
}

// Extend class
class Location(override val xc: Int, override val yc: Int, val zc :Int) extends Point(xc, yc) {
  var z :Int = zc

  def move(dx: Int, dy: Int, dz: Int) :Unit = {
    x = x + dx
    y = y + dy
    z = z + dz
    println("Point.x location :" + x)
    println("Point.y location :" + y)
    println("Point.z location :" + z)
  }
}

object Main {
  def  main(args: Array[String]) : Unit = {
    val p = new Point(100, 200)
    p.move(45, 55)

    val loc = new Location(300, 400, 500)
    loc.move(100, -200, 200)

    // implicit class
    4 times println("Working...")
  }
}
