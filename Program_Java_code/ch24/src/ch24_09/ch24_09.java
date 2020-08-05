package ch24_09;

import java.util.LinkedList;

public class ch24_09 {
	public static void main(String[] args) {
		LinkedList<Integer> stack = new LinkedList<Integer>(); 
		//新增
		for (int i=10; i<=50; i+=10) {					// 模擬push
			stack.addLast(i);							// 建立stack		
			System.out.println("stack : " + stack);
		}
		//取出
		int loop = stack.size();						// 元素個數
		for (int i=1; i<=loop; i++ ) {					// pop迴圈
			System.out.printf("pop第%d筆元素 %d : \n",i ,stack.removeLast());
			System.out.println("stack : " + stack);
		}
	}
}

