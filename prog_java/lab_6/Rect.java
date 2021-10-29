package com.company;

public class Rect extends Point{
    private double w;
    private double h;

    public double GetW() { return w; }
    public double GetH() { return h; }

    Rect()
    {
        super();
        this.w = 0;
        this.h = 0;
    }
    Rect(double x, double y, double w, double h)
    {
        super(x, y);
        this.w = w;
        this.h = h;
    }
    @Override
    public void setPoint(Point p)
    {

    }
    @Override
    public String toString()
    {
        return "SoldierMission:\n" + "Состояние миссии: " + ((GetState()) ? "Выполнено" : "Провалено");
    }
}
