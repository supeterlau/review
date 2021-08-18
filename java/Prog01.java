class FreshJuice {
	enum FreshJuiceSize { SMALL, MEDIUM, LARGE }
	FreshJuiceSize size;
}

public class Prog01 {
	// public static void main(String []args) {
	public static void main(String args[]) {
		System.out.println("Helo Java Programming!");
		for (int x = 0; x < args.length; x++) {
			System.out.println("args["+ x + "]: "+ args[x]);
		}

		FreshJuice juice = new FreshJuice();
		juice.size = FreshJuice.FreshJuiceSize.MEDIUM;
		System.out.println("Fresh Juice Size: " + juice.size);
	}
}
