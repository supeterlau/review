import java.io._
import scala.io.Source

object Main {
  def main(args: Array[String]) : Unit= {
    // val writer = new PrintWriter(new File("file.txt"))
    // writer.write("Scala Language.")
    // writer.close()
    Source.fromFile("file.scala").foreach {
      print
    }
  }
}
