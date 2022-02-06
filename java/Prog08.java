public class Prog08 {

	public static void main(String args[]) {
		for(int x = 3; x < 30; x+=3) {
			System.out.println("Value of x is: " + x);
		}

		String [] apps = {"Movie", "Music", "Radar", "Tasks"};
		for(String app : apps) {
			System.out.println("Pick: " + app);
		}
	}
}
