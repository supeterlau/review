class Vehicle {}

class Car extends Vehicle {}

public class Prog07 {
	public static void main(String args[]) {
		Car car = new Car();
		boolean car_result = car instanceof Vehicle;
		System.out.println(car_result);

		String name = "Apache";
		boolean result = name instanceof String;
		System.out.println(result);
	}
}
