package ch24_09;

import java.util.LinkedList;

public class ch24_09 {
	public static void main(String[] args) {
		LinkedList<Integer> stack = new LinkedList<Integer>(); 
		//�s�W
		for (int i=10; i<=50; i+=10) {					// ����push
			stack.addLast(i);							// �إ�stack		
			System.out.println("stack : " + stack);
		}
		//���X
		int loop = stack.size();						// �����Ӽ�
		for (int i=1; i<=loop; i++ ) {					// pop�j��
			System.out.printf("pop��%d������ %d : \n",i ,stack.removeLast());
			System.out.println("stack : " + stack);
		}
	}
}

