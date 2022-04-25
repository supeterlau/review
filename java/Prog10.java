import java.io.*;
import java.util.*;
import java.text.*;

public class Prog10 {
	public static void main(String args[]) {
		System.out.println(Math.random());
		System.out.println(Math.random());
		Integer x = 100;
		x = x + 50;
  	System.out.println(x);

		// 11. characters
		char ch = 'c';
		char uniChar = '\u039A';
		char[] charArray = {'J','a','v','a','!'};
		// Character cha = new Character('A');
		Character cha = 'A';
		System.out.println("is uppercase? " + Character.isUpperCase(cha));
		System.out.println("to uppercase: " + Character.toUpperCase(cha));

		// 12. Strings
		String str1 = "Java";
		String str2 = "Cpp";
		StringBuffer str3 = new StringBuffer("Cpp");

		boolean res_str1_str3 = str1.contentEquals(str3);
		boolean res_str2_str3 = str2.contentEquals(str3);
		System.out.println("str1-str3: " + res_str1_str3 + " str2-str3: " + res_str2_str3);

		String str4 = new String("Loop Control");
		try {
			String UTF8Str = new String(str4.getBytes("UTF-8"));
			System.out.println("UTF8Str: "+UTF8Str);
			String ISOStr = new String(str4.getBytes("ISO-8859-1.1"));
			System.out.println("ISOStr: " + ISOStr);
		} catch (UnsupportedEncodingException e) {
			System.out.println("Unsupported character set.");
		}
		System.out.println("intern: "+str4.intern());

		// 13. Array
		double[] rands = {Math.random(), Math.random(), Math.random()};
		double total = 0;
		for(int i = 0; i < rands.length; i++) {
			total += rands[i];
		}
		System.out.println("Total of rands: " + total);
		double max=rands[0];
		for(int i = 0; i < rands.length; i++) {
			if(max < rands[i]) max = rands[i];
		}
		System.out.println("Max of rands: " + max);

		// 14. Date Time
		Date dNow = new Date();
		SimpleDateFormat ft = new SimpleDateFormat("E yyyy.MM.dd 'at' HH:mm:ss a zzz");
		System.out.println("CurrentDate: " + ft.format(dNow));

		try {
			long start = System.currentTimeMillis();
			System.out.println(new Date() + "\n");
			Thread.sleep(5 * 60 * 10);
			System.out.println(new Date() + "\n");
			long end = System.currentTimeMillis();
			long diff = end - start;
			System.out.println("Difference is : "+diff);
		} catch (Exception e) {
			System.out.println("Go an exception.");
		}
		// Gregorian Calendar
		GregorianCalendar gcalendar = new GregorianCalendar();
		int year;

		System.out.print("Date: ");
		System.out.println(year = gcalendar.get(Calendar.YEAR));
	}
}

