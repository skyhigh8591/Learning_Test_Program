package ch24_10;

import java.util.LinkedList;

public class ch24_10 {
	public static void main(String[] args) {
		LinkedList<Integer> queue = new LinkedList<Integer>(); 
		//�s�W
		for (int i=10; i<=50; i+=10) {					// ����enqueue
			queue.addLast(i);							// �إ�queue		
			System.out.println("queue : " + queue);
		}
		//���X
		int loop = queue.size();						// �����Ӽ�
		for (int i=1; i<=loop; i++ ) {					// dequeue�j��
			System.out.printf("dequeue��%d������ %d : \n",i ,queue.removeFirst());
			System.out.println("queue : " + queue);
		}
	}
}

