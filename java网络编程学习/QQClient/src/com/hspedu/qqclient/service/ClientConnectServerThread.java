package com.hspedu.qqclient.service;

import com.hspedu.qqcommon.Message;
import java.io.ObjectInputStream;
import java.net.*;

public class ClientConnectServerThread extends Thread{
    //该线程需持有Socket
    private Socket socket;

    //构造器可以接收一个Socket对象
    public ClientConnectServerThread(Socket socket){

        this.socket = socket;
    }

    @Override
    public void run() {
        //因为Thread需求在后台和服务器通信，因此我们while循环
        while(true){
            try {
                 System.out.println("客户端线程，等待从读取从服务器端发送的消息");
                 ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
                 //如果服务器没有发送Message对象，线程会阻塞在这里
                 Message message = (Message)ois.readObject();

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    //为了更方便的得到Socket
    public Socket getSocket() {
        return socket;
    }
}
