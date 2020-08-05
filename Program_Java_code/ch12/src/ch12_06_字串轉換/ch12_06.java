package ch12_06_¦r¦êÂà´«;

public class ch12_06 {

	public static void main(String[] args) {
		char c = 'b';
		String str1 = String.valueOf(c);
		System.out.println(str1);
		
		int i  = 55;
		String str2 = String.valueOf(i);
		System.out.println(str2);
		
		long l = 55L;
		String str3 = String.valueOf(l);
		System.out.println(str3);
		
		float f = 5.5f;
		String str4 = String.valueOf(f);
		System.out.println(str4);
		
		double d = 5.4;
		String str5 = String.valueOf(d);
		System.out.println(str5);
		
		
		System.out.printf("%s	%s	%s	%s	%s\n",str1,str2,str3,str4,str5);
		
		String str6 = str1+str2+str3+str4+str5;
		System.out.print(str6);
		
		//¦r¦êÂàdouble,integer
		System.out.println(".....2.....");
		Integer t1 = Integer.valueOf("3300");
		System.out.println(t1+100);
		
		
		Double t2 = Double.valueOf("3.300");
		System.out.println(t2+100);


	}

}
