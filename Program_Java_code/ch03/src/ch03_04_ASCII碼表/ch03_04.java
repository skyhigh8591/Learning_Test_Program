package ch03_04_ASCII�X��;

public class ch03_04 {

	public static void main(String[] args) {
		char ch1;
		ch1 = 'a';						
		System.out.println("�ܼ�ch�����e = " + ch1);
		ch1 = '�x';						
		System.out.println("�ܼ�ch�����e = " + ch1);
		
		char ch2;
		ch2 = 65;						
		System.out.println("�ܼ�ch�����e = " + ch2);
		
		char ch3;
		ch3 = '\u0041'; //Unicode�r���C��						
		System.out.println("�ܼ�ch�����e = " + ch3);
		ch3 = '\u9B41';	//Unicode�r���C��					
		System.out.println("�ܼ�ch�����e = " + ch3);
	}
}
