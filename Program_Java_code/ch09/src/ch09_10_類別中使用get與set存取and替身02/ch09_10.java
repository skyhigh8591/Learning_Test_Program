package ch09_10_���O���ϥ�get�Pset�s��and����02;

import java.util.Scanner;



class Student {
	private String Sno;
	private String Sname;
	private int Score;

	public String getSno() {
		return "�ڪ��Ǹ��O " + Sno;
	}

	public void setSno(String sno) {
		Sno = sno;
	}

	public String getSname() {
		return Sname + "���͡A�Цh�h����";
	}

	public void setSname(String sname) {
		Sname = sname;
	}

	public int getScore() {
		return Score;
	}

	public void setScore(int score) {
		if(score<0)
		{
			score=0;
		}
		else if(score<100)
		{
			score=100;
			this.Score = score;
		}
		
	}

	public String Iam() {
		return ("I am " + Sno + ":" + Sname + " score=" + Integer.toString(Score));
	}

}

public class ch09_10 {

	public static void main(String[] args) {
		Student S1 = new Student();
		Scanner scanner = new Scanner(System.in);
		System.out.println("�п�J�A���Ǹ�");
		String Son = scanner.nextLine();
		S1.setSno(Son);
		
		System.out.println("�п�J�A���m�W");
		String Sname = scanner.nextLine();
		S1.setSname(Sname);
		
		System.out.println("�п�J�A�����Z");
		int Score = scanner.nextInt();
		S1.setScore(Score);
		
		
		System.out.println(S1.Iam());
		System.out.println(S1.getSname());
		System.out.println(S1.getSno());
		System.out.println(S1.getScore());
		
		

	}

}
