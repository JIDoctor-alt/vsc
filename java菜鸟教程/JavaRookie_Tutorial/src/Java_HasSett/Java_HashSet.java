package Java_HasSett;

import java.util.HashSet;

public class Java_HashSet {
	public static void main(String[] args) {
		HashSet<String> sites = new HashSet<String>();
		sites.add("Google");
		sites.add("Runoob");
		sites.add("Taobao");
		sites.add("Zhihu");
		sites.add("Runoob");//�ظ���Ԫ�ز��ᱻ���
		
		//ɾ���ɹ�����true�����򷵻�false
		sites.remove("Taobao");
		System.out.println(sites);
		
		System.out.println(sites.contains("Taobao"));
		
		//����HashSet
		for (String string : sites) {
			System.out.println(string);
		}
		
		
		//�����С
		System.out.println(sites.size());
		///ɾ������Ԫ��
		sites.clear();
		System.out.println(sites);
	}
}
