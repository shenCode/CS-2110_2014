/**
 * HW2 Part 1 - Coding with bases
 *
 * @author Shen Yang
 * 
 * *** NOTE: The rules are different for each java file! ***
 *
 * You may NOT use any of the following:
 * - Any functions found in Java libraries (especially the Math library)
 *     - Example Math.pow, Integer.bitCount, String.valueOf, etc.
 *     - Basically, any function that does everything for you. The purpose of this
 *       homework is to learn how to do these operations yourself, and the Java API!
 *     - The only exception to this rule is String.charAt to get a character from a
 *       String, and you may use String.length to get the size of the string.
 *     
 * - You may not implement any Java library functions as helpers to use in other functions.
 *     
 * - You may not write your own pow() method to use. None of the functions require a pow() 
 *		function to complete.
 *
 * - String concatenation with a number for more than one digit.
 *     - For example, "" + 123 is banned. "" + 6 is allowed, though.
 *     
 * - You may use Modulus(%), Multiplication(*), Division(/), Addition(+), Subtraction(-)
 *
 * - You may use the assignment operator (of course).
 *
 * - You may only use 2 if-statements max PER method.
 *     - You may use if statements inside for/while loops if necessary.
 *     - This means you may have 2 separate conditions, making these okay:
 *     
 *     if(cond1) {
 *         code;
 *     } else {
 *         moreCode;
 *     }
 *     if(cond2) {
 *         code;
 *     } else {
 *         modeCode;
 *     }
 *     
 *     OR
 *
 *     if(cond1){
 *	   		if(cond2){
 *				code
 * 			}
 *			code
 *     }
 *
 *	   OR
 * 
 *	   if(cond1){
 *			code
 *	   }else if(cond2){
 *			code
 *	   }else{}
 * 
 * - We also understand that for/while loops can be used like if-statements,
 *		but it is in your best interest to not exploit the loophole.
 *   
 * - You may not use a switch statement.
 *     
 * - Recursion is not allowed.
 * 
 * - You may not reuse any function to implement another function.
 * - You may reuse portions of your code from different methods inside other methods.
 *     You are just not allowed to call methods from within other methods.
 *  
 * - You may not use arrays. You shouldn't have to use an array for those problems.
 *	   
 * - You will only have to worry about the cases we mentioned in the method descriptions.
 *
 */
public class HW2Bases
{
	
	private static final int CONVERT = 48;
	private static final int CONVERT_2 = 55; 
	/**
	 * strdtoi - Decimal String to int
	 *
	 * Convert a string containing ASCII characters (in decimal) to an int.
	 * You do not have to handle negative numbers. The Strings we will pass in will be
	 * valid decimal numbers, and able to fit in a 32-bit signed integer.
	 * 
	 * Example: strdtoi("123"); // => 123
	 */
	public static int strdtoi(String decimal)
	{
		int current = 1;
		int result = 0;

		for (int i = decimal.length()-1; i >= 0; i--) {
			result = result + (decimal.charAt(i)-CONVERT)*current; // Adds every character of the string to the right location.
			current = current * 10;
		}
		return result;
	}

	/**
	 * strbtoi - Binary String to int
	 *
	 * Convert a string containing ASCII characters (in binary) to an int.
	 * You do not have to handle negative numbers. The Strings we will pass in will be
	 * valid binary numbers, and able to fit in a 32-bit signed integer.
	 * 
	 * Example: strbtoi("111"); // => 7
	 */
	public static int strbtoi(String binary)
	{
		int current = 1;
		int result = 0;
		
		for (int i = binary.length()-1; i >= 0; i--) {
			result = result + (binary.charAt(i)-CONVERT)*current; // Adds every character of the string to the right location.
			current = current * 2;
		}
		return result;
	}

	/**
	 * strxtoi - Hexadecimal String to int
	 *
	 * Convert a string containing ASCII characters (in hex) to an int.
	 * You do not have to handle negative numbers. The Strings we will pass in will be
	 * valid hexadecimal numbers, and able to fit in a 32-bit signed integer.
	 * 
	 * You may assume that hex string will be capital (ie. 0xFF2A rather than 0xff2a).
	 *
	 * Example: strxtoi("A6"); // => 166
	 */
	public static int strxtoi(String hex)
	{
		int current = 1;
		int result = 0;
		
		for (int i = hex.length()-1; i >= 0; i--) {
			if (hex.charAt(i) >= 48 && hex.charAt(i) <= 57) { // Check if it is letters or numbers.
				result = result+(hex.charAt(i)-CONVERT)*current; // Adds every character of the string to the right location.
			}
			else {
				result = result+(hex.charAt(i)-CONVERT_2)*current; // Check if it is letters or numbers.
			}
			current = current * 16;
		}
		return result;
	}

	/**
	 * itostrb - int to Binary String
	 *
	 * Convert a int into a String containing ASCII characters (in binary).
	 * You do not have to handle negative numbers.
	 * The String returned should contain the minimum number of characters necessary to
	 * represent the number that was passed in.
	 * 
	 * Example: itostrb(7); // => "111"
	 */
	public static String itostrb(int binary)
	{
		String result = "";
		do {
			result = (char)(binary % 2 + CONVERT) + result;
			binary = binary / 2;
		
		} while (binary != 0);
	return result;
	}

	/**
	 * itostrx - int to Hexadecimal String
	 *
	 * Convert a int into a String containing ASCII characters (in hexadecimal).
	 * You do not have to handle negative numbers.
	 * The String returned should contain the minimum number of characters necessary to
	 * represent the number that was passed in.
	 * 
	 * Example: itostrx(166); // => "A6"
	 */
	public static String itostrx(int hex)
	{
		{
			String result = "";
			do {
				if (hex % 16 >= 10) {
					result = (char)(hex % 16 + CONVERT_2) + result;
				}
				else {
					result = (char)(hex % 16 + CONVERT) + result;
				}
				
				hex = hex / 16;
			} while (hex != 0);
		return result;
		}
	}
}
