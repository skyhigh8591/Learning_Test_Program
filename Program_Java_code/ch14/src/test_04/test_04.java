package test_04;

class school{
	protected String title;
	protected String name;
	public void demo(){
		System.out.println("學校名稱" + title);
		System.out.println("學生名稱" + name);
	}		
}

class EE extends school{
	protected String Department;	
	public void DemoEE(){
		System.out.println("學校名稱" + title);
		System.out.println("學生名稱" + name);
		System.out.println("學生科系" + Department);
	}
	
}

class ME extends school{
	protected String Department;	
	public void DemoME(){
		System.out.println("學校名稱" + title);
		System.out.println("學生名稱" + name);
		System.out.println("學生科系" + Department);
	}	
}
public class test_04 {

	public static void main(String[] args) {
		

	}

}
