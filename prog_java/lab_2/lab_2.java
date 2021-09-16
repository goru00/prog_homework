package com.company;
class Groups
{
    private char symb;
    private String name_group;
    private static String title;
    Groups(String s)
    {
        String r[] = s.split(", ");
        char[] ch = r[0].toCharArray();
        symb = ch[0];
        name_group = r[1];
    }
    @Override
    public String toString() {
        String out[] = title.split(", ");
        return "| " + out[0] + "|" + out[1] + "| ";
    }
    static void setTitle(String s)
    {
        title = s;
    }
    public static void Show(Groups s[])
    {
        System.out.println(s[0]);
        for (Groups a: s)
        {
            System.out.format("%3c  |  %3s\n", a.symb, a.name_group);
        }
    }
}
class Children
{
    private int id;
    private String name_baby;
    private char symb;
    static String title;
    Children(String s)
    {
        String[] r = s.split(", ");
        id = Integer.parseInt(r[0]);
        name_baby = r[1];
        char[] ch = r[2].toCharArray();
        symb = ch[0];
    }
    @Override
    public String toString() {
        String r[] = title.split(", ");
        return "| " + r[0] + " | " + r[1] + "|     " + r[2] + "|";
    }
    static void setTitle(String s)
    {
        title = s;
    }
    public static void Show(Children s[])
    {
        System.out.println(s[0]);
        for (Children a: s)
        {
            System.out.format("| %3d   |    %3s    |   %2c\n", a.id, a.name_baby, a.symb);
        }
    }
}
public class Main {
    public static void main(String[] args) {
        String[] ObjGroups = {
                "№ группы, Название группы",
                "М, Младшая",
                "С, Средняя",
                "П, Подготовительная",
                "Я, Ясельная"
        };
        Groups.setTitle(ObjGroups[0]);
        Groups arg1[] = new Groups[ObjGroups.length - 1];
        for (int i = 0; i < arg1.length; i++) arg1[i] = new Groups(ObjGroups[i + 1]);

        Groups.Show(arg1);
        String[] ObjChildren = {
                "№ порядковый, ФИО ребенка, № группы",
                "1001, Иванов Алеша, С",
                "1002, Сидорова Наташа, С",
                "1003, Петрова Катя, С",
                "1004, Петров Артем, М",
                "1005, Фролов Антон, М",
                "1006, Федорова Ирина, П"
        };
        Children.setTitle(ObjChildren[0]);
        Children arg2[] = new Children[ObjChildren.length - 1];
        for (int i = 0; i < arg2.length; i++) arg2[i] = new Children(ObjChildren[i + 1]);
        Children.Show(arg2);
    }
}
