package com.company;

public class Point {
    private double x;
    private double y;
    private boolean state;

    public double GetX() { return x; }
    public double GetY() { return y; }
    public boolean GetState() { return state; }
    public void SetState(boolean state) { this.state = state; }

    Point()
    {
        this.x = 0;
        this.y = 0;
        this.state = false;
    }
    Point(double x, double y)
    {
        this.x = x;
        this.y = y;
        this.state = false;
    }
    public void Move(Point p) {
        this.x += p.x;
        this.y += p.y;
    }
    public void setPoint(Point p)
    {
        this.x = p.x;
        this.y = p.y;
    }
    @Override
    public String toString()
    {
        return "Soldier:\n" + "x: " + this.x + " y: " + this.y;
    }
}
