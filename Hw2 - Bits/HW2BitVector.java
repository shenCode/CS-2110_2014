/**
 * HW2 Part 3 - Coding a bit vector
 * @author Shen Yang
 * 
 * *** NOTE: The rules are different for each java file! ***
 * 
 * This class represents a bit vector, which is 32 bits which can be manipulated through
 * the use of the methods that this class provides.
 * 
 * The only things you are allowed to use in your code are the following:
 *	   - The bitwise operators |, &, ~, ^, <<, >>
 *     - Increment and Decrement (++ and --).
 *         - You may also add or subtract 1 from a number, but it must be only 1.
 *     - Boolean operators ||, &&, and !, which are only allowed in if-statements.
 *     - Conditional statements (if, if-else, switch-case, ? :).
 *         - However, you may only handle up to two cases.
 *         - You may only use up to 2 if/else-if statements.
 *     - Equality comparisons (==, !=, <=, >=, <, >).
 *     - String concatenation (+) only in the toString method.
 *     - Iteration may be used for the onesCount, zerosCount, size, toString methods.
 *     - The assignment operator (of course).
 *
 * You are not allowed to use anything not mentioned above. This includes the following,
 * but is not an exhaustive list:
 *     - Multiplication or Division
 *     - Addition or Subtraction with numbers other than 1.
 *          - Iteration in functions other than toString.
 *          - The unsigned right shift operator >>> (C does not provide this operator).
 *     - Modulus (%).
 *     - Iteration (such as for/while) may not be used for methods other than onesCount, zerosCount, size, toString methods.
 *     - Any functions found in Java libraries (especially the Math library).
 *         - Example: Math.pow, Integer.bitCount, etc.
 *     - Casting (you should not have cast anywhere!)
 * 	   - Using 0b prefix to represent binary numbers
 * 			Note: Java prior to version 7 did not have a native way of representing 
 *			numbers in binary, though it did have a way of representing hex (0x notation).
 * 			Java 7 allows for binary literals (using the 0b prefix); however, you are 
 * 			not allowed to use it, and you should instead use hex (0x prefix) in order to make the 
 *			masks.
 *
 * You should not call methods from within other methods in this file. Still, some methods may be similar 
 *	to others in their implementations, and it is fine to have similar code for different methods.
 *
 * You will only have to worry about the cases we mentioned in the method descriptions.
 *
 */
public class HW2BitVector
{
	/** 
	 * 32-bit data initialized to all zeros. Here is what you will be using to represent
	 * the Bit Vector. Do not change its scope from private.
	 */
	 
	/** You may not add any more fields to this class other than the given one. */
	private int bits;
	

	/**
	 * Sets the bit (sets to 1) pointed to by index.
	 * @param index index of which bit to set.
	 *        0 for the least significant bit (right most bit).
	 *        31 for the most significant bit.
	 */
	public void set(int index)
	{
		// TODO implement
		bits = bits | (0x1 << index); // Move the 1 to the right location then change it.
	}

	/**
	 * Clears the bit (sets to 0) pointed to by index.
	 * @param index index of which bit to set.
	 * 	      0 for the least significant bit (right most bit).
	 * 	      31 for the most significant bit.
	 */
	public void clear(int index)
	{
		bits = bits & ~(0x1 << index); // Move the 0 to the right location then change it.
	}

	/**
	 * Toggles the bit (sets to the opposite of its current value) pointed to by index.
	 * @param index index of which bit to set.
	 * 	      0 for the least significant bit (right most bit).
	 * 	      31 for the most significant bit.
	 */
	public void toggle(int index)
	{
		bits = bits ^ (0x1 << index); // Move the bit to the location, and use XOR to switch it.
	}
	
	/**
	 * Returns true if the bit pointed to by index is currently set.
	 * @param index index of which bit to check.  
	 * 	      0 for the least significant bit (right-most bit).
	 * 	      31 for the most significant bit.
	 * @return true if the bit is set, false if the bit is clear.
	 *         If the index is out of range (index >= 32), then return false.
	 */
	public boolean isSet(int index)
	{
		if (index >= 32) {return false;} // Out of range
		else {
			return ((bits & (0x1 << index)) == (0x1 << index)); // Move the 1 to the index and check if it is actually 1.
		}
	}
	
	/**
	 * Returns true if the bit pointed to by index is currently clear.
	 * @param index index of which bit to check.  
	 * 	      0 for the least significant bit (right-most bit).
	 * 	      31 for the most significant bit.
	 * @return true if the bit is clear, false if the bit is set.
	 *         If the index is out of range (index >= 32), then return true.
	 */
	public boolean isClear(int index)
	{
		if (index >= 32) {return true;} // Out of range
		else {
			return ((bits & (0x1 << index)) != (0x1 << index)); // Move the 1 to the index and check if it is not 1.
		}
	}
	
	/**
	 * Returns a string representation of this object.
	 * Return a string with the binary representation of the bit vector.
	 * You may use String concatenation (+) here. 
	 * You must return a 32-bit string representation.
	 * i.e if the bits field was 2, then return "00000000000000000000000000000010"
	 */
	public String toString()
	{
		String result = "";
		
		for (int i = 0; i < 32; i++) {
			if (isSet(i)) {
				result = "1" + result; // If it is 1, add 1.
			}
			else {
				result = "0" + result; // Else, add 0.
			}
		}
		return result;
	}

	/**
	 * Returns the number of bits currently set (=1) in this bit vector.
	 * You may obviously use the ++ operator to increment your counter. 
	 */
	public int onesCount()
	{
		int count = 0;
		for (int i = 0; i < 32; i++) {
			if (isSet(i)) {
				count++; // Increase count for every 1.
			}
		}
		return count;
	}
	
	/**
	 * Returns the number of bits currently clear (=0) in this bit vector.
	 * You may obviously use the ++ operator to increment your counter. 
	 */
	public int zerosCount()
	{
		int count = 0;
		for (int i = 0; i < 32; i++) {
			if (isClear(i)) {
				count++; // Increase count for every 0.
			}
		}
		return count;
	}
	
	/**
	 * Returns the "size" of this BitVector. The size of this bit vector is defined
	 * to be the minimum number of bits that will represent all of the ones.
	 * For example, the size of the bit vector 00010000 will be 5.
	 */
	public int size()
	{
		int size = 0;
		for (int i = size; i < 32; i++) {
			if (isSet(i)) {
				size = i; // Check from the right for every 1 and store the furthest location.
			}
		}
		return size+1;
	}
	
	// *** Do not change any code below here! ***
	
	public HW2BitVector() {
		bits = 0;
	}
	
	public int getBits() {
		return bits;
	}
}
