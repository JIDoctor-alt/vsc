package com.hspedu.qqserver.service;

import com.hspedu.qqcommon.Message;


import java.io.ObjectInputStream;
import java.net.Socket;

/*
* 该类的一个对象和某个客户端保持通信
* */
public class ServerConnectClientThread extends Thread{

    private Socket socket;
    private String userId;//连接到服务器端的用户id

    public ServerConnectClientThread(Socket socket,String userId){
        this.socket = socket;
        this.userId = userId;
    }

    @Override
    public void run() {//这里线程处于run的状态，可以发送/接收消息

        while(true){
            try {
                System.out.println("服务器和客户端" +userId+" 保持通信，读取数据...");
                ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
                Message message = (Message) ois.readObject();
//                后面会使用message
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public Socket getSocket() {
        return socket;
    }

    public void setSocket(Socket socket) {
        this.socket = socket;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }
}
