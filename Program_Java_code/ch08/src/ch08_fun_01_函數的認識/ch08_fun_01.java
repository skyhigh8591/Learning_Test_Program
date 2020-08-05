package ch08_fun_01_¨ç¼Æªº»{ÃÑ;

public class ch08_fun_01 {

	
		//input 0 output 0
		public static void star() {
			for(int i=0 ; i<20 ; i++) {
				System.out.print("*");
			}
			System.out.print("\n");	
		}
		
///////////////////////////////////////////////////////////////////////
		
		// input 2 output1
		public static int sumN2N(int begin,int end) {
			
			//1+2+3+4+5
			int sum = 0;
			for(int i=begin;i<=end;i++) {
				sum+=i;
			}
			return sum;
		}

/////////////////////////////////////////////////////////////////////////		
	
		//input2 output4
		public static double[] operation(int num1,int num2) {
			double sum = num1 + num2;
			double cut = num1 + num2;
			double multiply = num1 * num2;
			double divide = (double)num1 / (double)num2;
			double[] feedback = {sum , cut , multiply , divide};//1*4 array;
			return feedback;

		
		}
		
/////////////////////////////////////////////////////////////////////////		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
///////////////////////////////////////////////////////////////////////
		
		public static void main(String[] args) {
			
///////////////////////////////////////////////////////////////////////			
			System.out.print("...........1.............\n");
			for(int i=0 ; i<10 ; i++) {
				System.out.print("*");
			}
			System.out.print("\n");
			
			for(int i=0 ; i<10 ; i++) {
				System.out.print("*");
			}
			System.out.print("\n");
			
			for(int i=0 ; i<10 ; i++) {
				System.out.print("*");
			}
			System.out.print("\n");
			
///////////////////////////////////////////////////////////////////////			
			
			System.out.print("...........2.............\n");	
			star();
			star();
			star();
			System.out.print("\n");
			
///////////////////////////////////////////////////////////////////////			
			
			System.out.print("...........3.............\n");
			int sum1 = sumN2N(1,3);
			System.out.print(sum1);
			System.out.print("\n");

	
/////////////////////////////////////////////////////////////////////////				
			
			System.out.print("...........4.............\n");
			double[] return_array = operation(50,9);
			for (int i=0 ; i<return_array.length ; i++) {
				System.out.println(return_array[i]);
			}
			
			
			
			
			
/////////////////////////////////////////////////////////////////////////			
		}

	}


