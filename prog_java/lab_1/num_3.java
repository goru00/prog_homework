package com.company;

public class Main {

    public static void main(String[] args) {
	    String str = "рыба кулак яблоня анафора раствор";
        String[] strParts = str.split(" ");
        int flag = 0;
        for (int i = 0; i < strParts.length; i++)
        {
            if (strParts[flag].length() > strParts[i].length()) flag = i;
        }
        System.out.println(strParts[flag]);
    }
}
