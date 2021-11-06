package com.company;

import java.util.HashMap;
import java.util.Map;

class BattleShip
{
    private String shipName;
    private int size;
    private boolean state[];

    BattleShip()
    {
        this.shipName = null;
        this.size = 0;
        this.state = null;
    }
    BattleShip(String Ship, int size)
    {
        this.shipName = Ship;
        this.size = size;
        this.state = new boolean[size];
        for (int i = 0; i < size; i++) {
            this.state[i] = true;
        }
    }
    @Override
    public String toString()
    {
        int count = 0;
        String str = "Название корабля: " + shipName + "\n" + "Размер корабля: " + size + "\n" + "Состояние корабля: ";
        for (int i = 0; i < size; i++) {
            if (state[i] == true) count++;
        }
        str += String.valueOf(count) + "/" + String.valueOf(size) + "\n";
        return str;
    }
}

class Chess
{
    private String nameFigures;
    private String colorFigures;

    public String GetNameFigures() { return nameFigures; }
    public String GetColorFigures() { return colorFigures; }

    Chess()
    {
        this.nameFigures = null;
        this.colorFigures = null;
    }
    Chess(String nameFigures, String colorFigures)
    {
        this.nameFigures = nameFigures;
        this.colorFigures = colorFigures;
    }
    @Override
    public String toString()
    {
        return "Название фигуры: " + nameFigures + "\n" + "Цвет фигуры: " + colorFigures + "\n";
    }
}

class Matrix<T>
{
    private Map<String, T> ptr;
    private int nSize;
    private int mSize;
    private String key;

    public int GetNSize() { return nSize; }
    public int GetMSize() { return mSize; }

    Matrix()
    {
        ptr = null;
        nSize = 0;
        mSize = 0;
    }
    Matrix(int nSize, int mSize)
    {
        this.nSize = nSize;
        this.mSize = mSize;
        ptr = new HashMap<>();
    }
    public void Add(T item) {
        if (nSize * mSize < ptr.size()) {
            System.out.println("Поле уже заполнено!");
            return;
        }
        char keyAF = (char)((ptr.size() / 10 + 65) & 0x00FF);
        ptr.put(String.valueOf(keyAF) + String.valueOf(ptr.size() % 10 + 1), item);
    }
    public T GetIndex(int posI, int posJ)
    {
        try {
            int count = 0;
            if (posI > nSize || posJ > mSize) throw new Exception("Индексы не могут быть больше размеров поля!");
            for (Map.Entry<String, T> item : ptr.entrySet())
            {
                if (count == (posI * 10 + posJ)) return item.getValue();
                count++;
            }
            throw new Exception("Объект с таким индексом не был найден!");
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
        return null;
    }
    public T GetKey(String key)
    {
        try {
            if (ptr.get(key) == null) {
                throw new Exception("Объект с таким ключом не был найден!");
            }
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
        return ptr.get(key);
    }
}

public class Main {

    public static void main(String[] args) {
        Chess figures[] = {
                new Chess("Король", "Белая"),
                new Chess("Ферзь", "Белая"),
                new Chess("Ладья", "Белая"),
                new Chess("Ладья", "Белая")
        };
        Matrix<Chess> tableChess = new Matrix<>(8,8);
        tableChess.Add(figures[0]);
        tableChess.Add(figures[1]);
        System.out.println(tableChess.GetKey("A1"));
        System.out.println(tableChess.GetIndex(0, 1));
        BattleShip ships[] = {
                new BattleShip("Крейсер", 3),
                new BattleShip("Лодка", 1)
        };

        Matrix<BattleShip> tableBattleShip = new Matrix<>(10, 10);
        tableBattleShip.Add(ships[0]);
        tableBattleShip.Add(ships[1]);
        System.out.println(tableBattleShip.GetKey("A1"));
    }

}




