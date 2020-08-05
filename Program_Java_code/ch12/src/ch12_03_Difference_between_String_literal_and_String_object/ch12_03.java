package ch12_03_Difference_between_String_literal_and_String_object;

public class ch12_03 {

	public static void main(String[] args) {
		String s1  = new String("java");
		String s2  = new String("java");
		System.out.println(s1==s2);

		String s3 = "java";
		String s4 = "java";
		System.out.println(s3==s4);
		
		String s5 = "JDK";
		String s6 = new String("JDK");
		System.out.println(s5==s6);
		
		System.out.println(s1.equals(s2));
		System.out.println(s5.equals(s6));
		System.out.println(s6.equals(s5));
		

	}

}
