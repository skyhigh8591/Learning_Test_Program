//��x���ǤJ�����
package ch24_14;

import java.util.ArrayList;
import java.util.Arrays;

class Student implements Comparable<Student>{
	private String name;
	private int no;
	private int Score;
	
	public Student(int no,String Sname, int Score) {
		this.no = no;
		this.name = Sname;
		this.Score = Score;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getNo() {
		return no;
	}

	public void setNo(int no) {
		this.no = no;
	}

	public int getScore() {
		return Score;
	}

	public void setScore(int score) {
		Score = score;
	}

	@Override
	public int compareTo(Student o) {
		// TODO Auto-generated method stub
		
		//return this.no-o.no;
		return o.no-this.no;
	}
}
 
public class ch24_14 {

	public static void main(String[] args) {
		Integer[] ID = { 1, 2, 3, 4, 5 };//�ŧi Integer ���O�A���i�ϥΰ����� int 
		// �ŧi arraylist �r�ꪫ�� list 
		ArrayList<Integer> list1 = new ArrayList<Integer>(Arrays.asList(ID));
		System.out.println("------1------");
		System.out.println(list1);
		for (int i = 0; i < 5; i++)
			list1.add(i + 6);

		System.out.println("------2------");
		System.out.println(list1);

		list1.add(0, 0);
		System.out.println("------3------");
		System.out.println(list1);

		System.out.println("------4------");
		for (Integer e : list1) {
			System.out.println(e);
		}
		//////////////////////////////////////////
		String[] question1 = { "Q1", "Q2", "Q3", "Q4" };
		ArrayList<String> list2 = new ArrayList<String>(Arrays.asList(question1));
		System.out.println("------5------");
		System.out.println(list2);
		list2.remove(0); // �Ĥ@�Ӥ���
		System.out.println(list2); // ���X
		for (String e : list2) {
			System.out.println(e);
		}
		///////////////////////////////////////////
		ArrayList<Student> slist = new ArrayList<Student>();
		slist.add(new Student(1,"JOHN",100));
		slist.add(new Student(8,"MARY",80));
		slist.add(new Student(4,"TOM",90));
		
//		//�ק�
//		slist.get(1).setName("AAAAAA");
//		
//		//�R��
//		slist.remove(0);
//		
//		//check
		System.out.println("------6------");
		for (int i=0;i<slist.size();i++) {
			System.out.println(slist.get(i).getNo()+" "+slist.get(i).getName()+" "+slist.get(i).getScore());
		}
		
		//�ק�,���]MARY 50
		for(int i=0;i<slist.size();i++) {
			if(slist.get(i).getName()=="MARY") {
				slist.get(i).setScore(50);
			}
		}
		System.out.println("------7------");
		for (int i=0;i<slist.size();i++) {
			System.out.println(slist.get(i).getNo()+" "+slist.get(i).getName()+" "+slist.get(i).getScore());
		}

	}
}