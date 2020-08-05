package ch12_08_StringBuffer類別;

public class ch12_08 {

	public static void main(String[] args) {
		String str = "Java";
		char[] ch1 = {'淡','江','大','學'};
		char[] ch2 = {'M','I','N','G','-','C','H','I'};
		
		StringBuffer bstr = new StringBuffer(str);
		System.out.println("bstr " + bstr);
		
		bstr.append('9');
		System.out.println("bstr " + bstr);
		
		bstr.append(ch2);
		System.out.println("bstr " + bstr);
		
		bstr.append("12345");
		System.out.println("bstr " + bstr);
		
		//insert()
		bstr.insert(0, ch1);
		System.out.println("bstr "+bstr);
		
		//deletecharat()
		bstr.deleteCharAt(13);
		System.out.println("bstr:" + bstr);
		
		//delete()
		bstr.delete(4, 8);
		System.out.println("bstr " + bstr);
		
		String str2 = bstr.toString();
		System.out.println(str2);
		System.out.println(str2.getClass());
	}

}
