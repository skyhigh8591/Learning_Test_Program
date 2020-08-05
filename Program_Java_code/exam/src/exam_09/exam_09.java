package exam_09;
interface Math {
	public void show();
	public void max(int a, int b, int c, int d);
	public void min(int a, int b, int c, int d);
	public void sum(int a, int b, int c, int d);
	public void avg(int a, int b, int c, int d);
}
class Compute implements Math {
	int max = 0;
	int min = 0;
	int sum = 0;
	double agv = 0;
	@Override
	public void show() {
		System.out.println("max= " + max);
		System.out.println("min= " + min);
		System.out.println("sum= " + sum);
		System.out.println("agv= " + agv);
	}
	@Override
	public void max(int a, int b, int c, int d) {
		int z = 0;
		z = a;
		if (z < b) {
			z = b;
		}
		if (z < c) {
			z = c;
		}
		if (z < d) {
			z = d;
		}
		max = z;
	}

	@Override
	public void min(int a, int b, int c, int d) {
		int z = 0;
		z = a;
		if (z > b) {
			z = b;
		}
		if (z > c) {
			z = c;
		}
		if (z > d) {
			z = d;
		}
		min = z;
	}
	@Override
	public void sum(int a, int b, int c, int d) {
		int z = 0;
		z = a + b + c + d;
		sum = z;
	}
	@Override
	public void avg(int a, int b, int c, int d) {
		double z = 0;
		z = a + b + c + d;
		z = z / 4;
		agv = z;
	}
}
public class exam_09 {
	public static void main(String[] args) {
		Compute cmp = new Compute();
		cmp.max(4, 5, 6, 7);
		cmp.min(4, 5, 6, 7);
		cmp.sum(4, 5, 6, 7);
		cmp.avg(4, 5, 6, 7);
		cmp.show();
	}

}
