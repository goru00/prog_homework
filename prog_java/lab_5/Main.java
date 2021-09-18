package com.company;

import java.util.*;

class Disciplines
{
    private int idDisc;
    private String nameDisc;
    private int num_sem;
    private int hLection;
    private int hSeminar;
    private String LC;
    Disciplines()
    {
        this.idDisc = 0;
        this.nameDisc = "NULL";
        this.num_sem = 0;
        this.hLection = 0;
        this.hSeminar = 0;
        this.LC = "NULL";
    }
    Disciplines(int idDisc, String nameDisc, int num_sem, int hLection, int hSeminar, String LC)
    {
        this.idDisc = idDisc;
        this.nameDisc = nameDisc;
        this.num_sem = num_sem;
        this.hLection = hLection;
        this.hSeminar = hSeminar;
        this.LC = LC;
    }
    @Override
    public String toString()
    {
        return idDisc + " " + nameDisc + " " + num_sem + " " + hLection + " " + hSeminar + " " + LC;
    }
}

class Personal
{
    private int idPers;
    private String namePers;
    private String post;
    Personal()
    {
        this.idPers = 0;
        this.namePers = "NULL";
        this.post = "NULL";
    }
    Personal(int idPers, String namePers, String post)
    {
        this.idPers = idPers;
        this.namePers = namePers;
        this.post = post;
    }
    @Override
    public String toString()
    {
        return idPers + " " + namePers + " " + post;
    }
}

class TableTime
{
    private String num_group;
    private String date;
    private Personal idPers;
    private Disciplines idDisc;

}

public class Main {

    public static void main(String[] args) {
	    Disciplines TabDisc[] = {
                new Disciplines(100, "Информатика", 1, 12, 12, "Экзамен"),
                new Disciplines(101, "Математика", 1, 16, 8, "Зачет"),
                new Disciplines(102, "Иностранный язык", 2, 0, 32, "Экзамен"),
                new Disciplines(103, "Экономика предприятий", 3, 16, 12, "Зачет")
        };
        ArrayList<Disciplines> arrDisc = new ArrayList<Disciplines>();
        for (int i = 0; i < 4; i++)
        {
            arrDisc.add(TabDisc[i]);
        }
        System.out.println(arrDisc.toString() + "\n");
        Personal TabPers[] = {
                new Personal(1001, "Иванов Сергей Степанович", "доцент"),
                new Personal(1002, "Степанов Василий Ильич", "доцент"),
                new Personal(1003, "Петрова Ирина Олеговна", "профессор")
        };
    }
}
