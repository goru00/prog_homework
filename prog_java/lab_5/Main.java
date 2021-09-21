package com.company;

import java.util.*;

class Disciplines extends ArrayList<Disciplines>
{
    private int idDisc;
    private String nameDisc;
    private int num_sem;
    private int hLection;
    private int hSeminar;
    private String LC;
    public int GetIdDisc() { return idDisc; }
    Disciplines()
    {
        this.idDisc = 0;
        this.nameDisc = "NULL";
        this.num_sem = 0;
        this.hLection = 0;
        this.hSeminar = 0;
        this.LC = "NULL";
    }
    Disciplines(int idDisc)
    {
        this.idDisc = idDisc;
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

class Personal implements Comparable<Personal>
{
    private int idPers;
    private String namePers;
    private String post;
    public int GetidPers() { return idPers; }
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
    public int compareTo(Personal arg1)
    {
        return idPers - arg1.GetidPers();
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
    private int num_par;
    private Personal idPers;
    private Disciplines idDisc;
    TableTime()
    {
        this.num_group = "NULL";
        this.date = "NULL";
        this.num_par = 0;
        this.idDisc = null;
        this.idPers = null;
    }
    TableTime(String num_group, String date, int num_par, Personal idPers, Disciplines idDisc)
    {
        this.num_group = num_group;
        this.date = date;
        this.num_par = num_par;
        this.idPers = idPers;
        this.idDisc = idDisc;
    }

}

public class Main {

    static void Show(ArrayList<Disciplines> arg)
    {
        Object[] arr = arg.toArray();
        Show(arr);
    }
    static void Show(Object[] arg)
    {
        for (Object item : arg)
        {
            System.out.println(item);
        }
    }

    public static void main(String[] args) {
        Disciplines TabDisc[] = {
                new Disciplines(100, "Информатика", 1, 12, 12, "Экзамен"),
                new Disciplines(101, "Математика", 1, 16, 8, "Зачет"),
                new Disciplines(102, "Иностранный язык", 2, 0, 32, "Экзамен"),
                new Disciplines(103, "Экономика предприятий", 3, 16, 12, "Зачет"),
                new Disciplines(103, "Экономика предприятий", 3, 16, 12, "Зачет")
        };
        Personal TabPers[] = {
                new Personal(1001, "Иванов Сергей Степанович", "доцент"),
                new Personal(1002, "Степанов Василий Ильич", "доцент"),
                new Personal(1003, "Петрова Ирина Олеговна", "профессор")
        };
        TableTime TabTableTime[] = {
                new TableTime("ГМУ-101", "23.11.2013", 1, TabPers[2], TabDisc[0]),
                new TableTime("ГМУ-101", "23.11.2013", 2, TabPers[0], TabDisc[3]),
                new TableTime("ИВТ-204", "24.11.2013", 3, TabPers[0], TabDisc[3]),
                new TableTime("ИВТ-204", "23.11.2013", 1, TabPers[0], TabDisc[1]),
                new TableTime("ГМУ-201", "24.11.2013", 2, TabPers[2], TabDisc[1]),
                new TableTime("ГМУ-201", "24.11.2013", 3, TabPers[1], TabDisc[2])
        };

        ArrayList<Disciplines> arrDisc = new ArrayList<Disciplines>();
        System.out.println("«Дисциплины»");
        for (int i = 0; i < 4; i++)
        {
            arrDisc.add(TabDisc[i]);
        }
        Show(arrDisc);
        Disciplines find = new Disciplines(100); // поиск по ключу
        if (arrDisc.contains(find)) System.out.println("Запись найдена");
        else {
            System.out.println("Такой записи не существует");
        }
        if (arrDisc.remove(find)) System.out.println("Запись была успешна удалена");
        else System.out.println("Запись не существует");
        System.out.println("Список после удаления записи: ");
        Show(arrDisc);
        find = TabDisc[2];
        Disciplines up = new Disciplines(102, "Иностранный язык", 5, 0, 40, "Экзамен");
        arrDisc.set(2, up);
        System.out.println("Список после изменения записи: ");
        Show(arrDisc);

        System.out.println();
        SortedSet<Personal> SetPersonal = new TreeSet<Personal>();
        System.out.println("«Преподаватели»");
        for (int i = 0; i < 3; i++)
        {
            SetPersonal.add(TabPers[i]);
            System.out.println(TabPers[i].toString());
        }
        Map<Integer, TableTime> MapTableTime = new HashMap<Integer, TableTime>();
        for (int i = 0; i < 6; i++)
        {
            MapTableTime.put(i, TabTableTime[i]);
        }
        System.out.println("\n«Расписание занятий»");
        for(Map.Entry<Integer, TableTime> item : MapTableTime.entrySet()){

            System.out.printf("Ключ: %s - Значение: %s \n", item.getKey(), item.getValue());
        }
    }
}
