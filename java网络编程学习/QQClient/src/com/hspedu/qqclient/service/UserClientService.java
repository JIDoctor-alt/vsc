package com.hspedu.qqclient.service;

import com.hspedu.qqcommon.Message;
import com.hspedu.qqcommon.MessageType;
import com.hspedu.qqcommon.User;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.*;

/*
* 该类完成用户登录和注册等功能
* */
public class UserClientService {

    //因为我们可能在其他方面使用user信息
    private User u = new User();
    //因为Socket在其他地方也可能使用，因此做出属性
    private Socket socket;

    //根据userID 和 userpwd 到服务器验证该用户是否合法
    public boolean checkUser(String userId,String pwd){
        boolean b = false;
        //创建一个User对象
        u.setUserId(userId);
        u.setPasswd(pwd);

//        连接到服务器,发送u对象
        try {
            socket = new Socket(InetAddress.getByName("127.0.0.1"),9999);
            //得到ObjectOutputStream对象
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            oos.writeObject(u);//发送User对象

            //读取从服务器回复的Message对象
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
            Message ms = (Message) ois.readObject();

            if(ms.getMesType().equals(MessageType.MESSAGE_LOGIN_SUCCEED)){//登录ok

                //创建一个和服务保持通信的线程-》创建一个类 ClientConnectServerThread
                //等待...
                ClientConnectServerThread ccst = new ClientConnectServerThread(socket);
                //启动客户端的线程
                ccst.start();
                //这里为了后面客户端的扩展，我们将线程放入到集合管理
                ManageClientConnectServerThread.addClientConnectServerThread(userId,ccst);
                b = true;
            }else{
                //如果登录失败，我们就不能启动和服务器通讯的线程，关闭socket
                socket.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return b;
    }

}
