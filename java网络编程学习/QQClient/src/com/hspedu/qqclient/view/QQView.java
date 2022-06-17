package com.hspedu.qqclient.view;

import com.hspedu.qqclient.service.UserClientService;
import com.hspedu.qqclient.utils.Utility;

//客户端的菜单界面
public class QQView {

    private boolean loop = true;//控制是否显示菜单
    private String key = "";//接收用户的键盘输入
    private UserClientService userClientService = new UserClientService();//对象是用于登录服务

    public static void main(String[] args) {
        new QQView().mainMenu();
        System.out.println("客户端退出系统..........");
    }

    //显示菜单
    private void mainMenu(){

        while(loop){
            System.out.println("==================欢迎登录网络通讯系统==================");
            System.out.println("\t\t 1 登录系统");
            System.out.println("\t\t 9 退出系统");
            System.out.print("请输入您的选择：");

            key = Utility.readString(1);

            //根据用户的输入，来处理不同的逻辑
            switch (key){
                case "1":
                    System.out.print("请输入用户号： ");
                    String userId = Utility.readString(50);
                    System.out.print("请输入密    码");
                    String pwd = Utility.readString(50);
                    //这里就比较麻烦了，需要到服务器验证是否合法
                    //这里有很多代码
                    if(userClientService.checkUser(userId,pwd)){
                        System.out.println("===========欢迎（用户"+userId + ")===========");
                        //进入到二级菜单
                        while(loop){
                            System.out.println("\n=================网络通信系统二级菜单（用户"+userId+")==============");
                            System.out.println("\t\t 1 显示在线用户列表");
                            System.out.println("\t\t 2 群发消息");
                            System.out.println("\t\t 3 私聊消息");
                            System.out.println("\t\t 4 发送文件");
                            System.out.println("\t\t 9 退出系统");
                            System.out.print("请输入你的选择：  ");
                            key = Utility.readString(1);
                            switch (key){
                                case "1":
                                    System.out.println("显示在线用户列表");
                                    break;
                                case "2":
                                    System.out.println("群发消息");
                                    break;
                                case "3":
                                    System.out.println("私聊消息");
                                    break;
                                case "4":
                                    System.out.println("发送文件");
                                    break;
                                case "9":
                                    loop = false;
                                    break;
                            }
                        }
                    }else{//登录服务器失败
                        System.out.println("==============登录失败================");
                    }
                    break;
                case "9":
                    loop = false;
                    break;
            }
        }
    }
}
