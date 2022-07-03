package Java_StringBuffer;

public class RunoobTest {
	
	public static void main(String[] args) {
		StringBuilder sb = new StringBuilder(10);
		sb.append("Runoob...");
		System.out.println(sb);
		sb.append("!");
		System.out.println(sb);
		sb.insert(8,"Java");
		System.out.println(sb);
		sb.delete(5, 8);//区间左开右闭区间  [a,b)
		System.out.println(sb);
		
		StringBuffer sBuffer = new StringBuffer();
		
		sBuffer.append("www");
		sBuffer.append(".runoob");
		sBuffer.append(".com");
		System.out.println(sBuffer);
	}


}
