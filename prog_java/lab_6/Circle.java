package com.company;

public class Circle extends Point{

    private double radius;
    final String nameMission = "Приземлиться внутрь окружности";

    public double GetRadius() { return radius; }
    public String GetNameMission() { return nameMission; }

    Circle()
    {
        super();
        radius = 0;
    }
    Circle(double x, double y, double radius)
    {
        super(x, y);
        this.radius = radius;
    }
    @Override
    public void setPoint(Point p)
    {
        if (Math.pow(p.GetX() - GetX(), 2) + Math.pow(p.GetY() - GetY(), 2) <= (radius * radius)) {
            SetState(true);
        } else {
            SetState(false);
        }
    }
    @Override
    public String toString()
    {
        return "ParatrooperMission:\n" + "Состояние миссии: " + ((GetState()) ? "Выполнено" : "Провалено");
    }
}
