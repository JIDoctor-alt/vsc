package com.hspedu.qqcommon;

import java.io.Serializable;

public class User implements Serializable {

    private String userId;//用户id 、 用户名
    private String passwd;//用户密码

    public String getUserId() {
        return userId;
    }

    public String getPasswd() {
        return passwd;
    }

    public void setPasswd(String passwd) {
        this.passwd = passwd;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }
}
