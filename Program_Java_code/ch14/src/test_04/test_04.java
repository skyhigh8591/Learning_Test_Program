package test_04;

class school{
	protected String title;
	protected String name;
	public void demo(){
		System.out.println("�ǮզW��" + title);
		System.out.println("�ǥͦW��" + name);
	}		
}

class EE extends school{
	protected String Department;	
	public void DemoEE(){
		System.out.println("�ǮզW��" + title);
		System.out.println("�ǥͦW��" + name);
		System.out.println("�ǥͬ�t" + Department);
	}
	
}

class ME extends school{
	protected String Department;	
	public void DemoME(){
		System.out.println("�ǮզW��" + title);
		System.out.println("�ǥͦW��" + name);
		System.out.println("�ǥͬ�t" + Department);
	}	
}
public class test_04 {

	public static void main(String[] args) {
		

	}

}
