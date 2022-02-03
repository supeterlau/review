class Count {
	int init;
	Count(int v) { init = v; }
}

public class Prog03 {
	public static void main(String args[]) {
		Count c1 = new Count(10);
		Count c2 = new Count(200);
		System.out.println(c1.init + " \\ " + c2.init);
	}
}
