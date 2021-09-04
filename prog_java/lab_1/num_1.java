package com.company;

public class Main {

    public static void main(String[] args) {
	    String str = "шалаш кулак яблоня анафора раствор рыба";
	    String[] strParts = str.split(" ");
	    int count = 0;
	    for (int i = 0; i < strParts.length; i++)
        {
            if (strParts[i].toLowerCase().charAt(0) == strParts[i].toLowerCase().charAt(strParts[i].length() - 1)) count++;
        }
	    System.out.println(count);
    }
}
