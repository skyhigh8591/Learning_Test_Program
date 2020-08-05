package test08_02;

public class test08_02 {

	public static void main(String[] args) {
		// orignial
		int[] matrix = new int[] { 75, 29, 38, 45, 16 };
		System.out.println(add(matrix));
	}

	public static int add(int[] nums) {
		int sum = 0;
		for (int z = 0; z < 5; z++) {
			for (int i = 0; i < nums.length - 1; i++) {
				if (nums[i] > nums[i + 1]) {
					sum = nums[i];
					nums[i] = nums[i + 1];
					nums[i + 1] = sum;
				}
			}
		}

		sum = nums[0];
		return sum;
	}

}
