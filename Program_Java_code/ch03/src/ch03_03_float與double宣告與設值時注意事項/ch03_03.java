package ch03_03_float�Pdouble�ŧi�P�]�Ȯɪ`�N�ƶ�;

public class ch03_03 {

	public static void main(String[] args) {
		System.out.println(".......int and long......");
		int x1;
		long y1;
		x1 = 103; // �]�w10�i����
		System.out.println("�C�L103  ���� = " + x1);
		x1 = 0b111; // �]�w2�i����
		System.out.println("�C�L0b111���� = " + x1);
		y1 = 022; // �]�w8�i����
		System.out.println("�C�L022  ���� =  " + y1);
		y1 = 0x2B; // �]�w16�i����
		System.out.println("�C�L0x2B ���� =  " + y1);

		long x2;
		x2 = 10345678L; // �]�w10�i������
		System.out.println("�C�L10345678 ���� = " + x2);
		x2 = 1_000_200; // �]�w�t���u���
		System.out.println("�C�L1_000_200���� = " + x2);
		x2 = 2_0000; // �]�w�t���u���
		System.out.println("�C�L2_0000   ���� = " + x2);

		System.out.println(".......double......");
		double x3;
		x3 = 1.05;
		System.out.println("�ܼ�x���� = " + x3);
		x3 = .789;
		System.out.println("�ܼ�x���� = " + x3);
		x3 = 5;
		System.out.println("�ܼ�x���� = " + x3);
		x3 = 1.29E-2;
		System.out.println("�ܼ�x���� = " + x3);
		x3 = 1.78E3;
		System.out.println("�ܼ�x���� = " + x3);

		System.out.println(".......float......");
		float x4, y4, z4;
		x4 = 1.05F;
		System.out.println("�ܼ�x1���� = " + x4);
		y4 = .789F;
		System.out.println("�ܼ�x2���� = " + y4);
		z4 = x4 + y4;
		System.out.println("�ܼ�x3���� = " + z4);

	}

}