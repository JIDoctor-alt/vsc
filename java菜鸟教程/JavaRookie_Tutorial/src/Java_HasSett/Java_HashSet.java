package Java_HasSett;

import java.util.HashSet;

public class Java_HashSet {
	public static void main(String[] args) {
		HashSet<String> sites = new HashSet<String>();
		sites.add("Google");
		sites.add("Runoob");
		sites.add("Taobao");
		sites.add("Zhihu");
		sites.add("Runoob");//重复的元素不会被添加
		
		//删除成功返回true，否则返回false
		sites.remove("Taobao");
		System.out.println(sites);
		
		System.out.println(sites.contains("Taobao"));
		
		//迭代HashSet
		for (String string : sites) {
			System.out.println(string);
		}
		
		
		//计算大小
		System.out.println(sites.size());
		///删除所有元素
		sites.clear();
		System.out.println(sites);
	}
}
