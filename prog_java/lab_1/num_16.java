package com.company;

public class Main {

    public static void main(String[] args) {
	    String str = "рыба кулак яблоня анафора раствор рыба";
        String[] strParts = str.split(" ");
        String newStr = "";
        for (int i = 0, count = 0; i < strParts.length; i++, count = 0)
        {
            for (int j = 0; j < strParts.length; j++)
            {
                if (strParts[i].equals(strParts[j])) count++;
            }
            if (count == 1) newStr += strParts[i] + " ";
        }
        newStr.trim();
        System.out.println(newStr);
    }
}
