public class Prog09 {

	public static void main(String args[]) {
		int value = 30;
		if (value > 30) {
			System.out.print("IF statement");
		} else if (value == 30) {
			System.out.print("Value Equal 30");
		} else {
			System.out.print("ELSE statement");
		}

		System.out.println("");

		// Switch
		// char grade = "c";
		char grade = args[0].charAt(0);
		switch(grade) {
			case 'a':
				System.out.println(grade + " " + "Excellent");
				break;
			case 'b':
			case 'c':
				System.out.println(grade + " " + "Well done");
				break;
			case 'd':
				System.out.println(grade + " " + "You passed");
				break;
			case 'f':
				System.out.println(grade + " " + "Not good");
				break;
			default:
				System.out.println("Invalid grade: " + grade);
		}
	}
}
