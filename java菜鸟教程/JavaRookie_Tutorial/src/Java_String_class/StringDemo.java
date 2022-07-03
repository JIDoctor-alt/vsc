package Java_String_class;

public class StringDemo {

	public static void main(String[] args) {
		char[] helloArray = {'r','u','n','o','o','b'};
		String helloString = new String(helloArray);
		System.out.println(helloArray);
		
		String site = "www.runoob.com";
		int len  = site.length();
		System.out.println("菜鸟教程网址长度："+len);
		
		String string1 = "菜鸟教程网址：";
		System.out.println("1、 "+string1+"www.runoob.com");
		String string2 = "菜鸟教程址：";
		string1.concat("ssssssssssssss");
		
		System.out.println("--------");
		System.out.println(string2);
		System.out.println(string1.concat("ssssssssssssss"));
	}
}
