package test_06;

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
	public void demo(){
		System.out.println("�ǮզW��" + title);
		System.out.println("�ǥͦW��" + name);
		System.out.println("�ǥͬ�t" + Department);
	}
	
}

class ME extends school{
	protected String Department;	
	public void demo(){
		System.out.println("�ǮզW��" + title);
		System.out.println("�ǥͦW��" + name);
		System.out.println("�ǥͬ�t" + Department);
	}	
}


public class test_06 {

	public static void main(String[] args) {
		EE E = new EE();
		ME M = new ME();
		E.Department = "�´���j";
		E.name = "�q��";
		E.title = "Sam";
		E.demo();
		System.out.println("....................");
		M.Department = "�x�_��j";
		M.name = "����";
		M.title = "Lish";
		M.demo();

	}

}
