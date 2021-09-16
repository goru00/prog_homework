package com.company;
class Figure
{
    private double x_center, y_center;
    public double GetX() { return x_center; }
    public double GetY() { return y_center; }
    Figure()
    {
        this.x_center = this.y_center = 0;
    }
    Figure(double x, double y)
    {
        this.x_center = x;
        this.y_center = y;
    }
    public void Move(double distance, int angle)
    {
        x_center += distance * Math.cos(angle);
        y_center += distance * Math.sin(angle);
    }
    public void Rotate(double x0, double y0, int angle)
    {
        x_center = x0 + (x_center - x0) * Math.cos(angle) - (y_center - y0) * Math.sin(angle);
        y_center = y0 + (y_center - y0) * Math.cos(angle) + (x_center - x0) * Math.sin(angle);
    }
    public void Print()
    {
        System.out.format("Координаты: (%3f, %3f)\n\n", x_center, y_center);
    }
}
class Ellipse extends Figure
{
    private double radius;
    Ellipse(double x, double y, double r)
    {
        super(x, y);
        this.radius = r;
    }
    @Override
    public void Print()
    {
        System.out.format("Эллипс: \nЦентр(%3f, %3f)\nРадиус: %3f\n\n", super.GetX(), super.GetY(), radius);
    }
}
class Rect extends Figure
{
    private double width, height;
    Rect(double x, double y, double w, double h)
    {
        super(x, y);
        this.width = w;
        this.height = h;
    }
    @Override
    public void Print()
    {
        System.out.format("Прямоугольник:\nКоординаты(%3f,%3f)\nШирина: %3f\nВысота: %3f\n\n", super.GetX(), super.GetY(), width, height);
    }
}
class RightTriangles extends Figure
{
    private double width, height;
    RightTriangles(double x, double y, double w, double h)
    {
        super(x, y);
        width = w;
        height = h;
    }
    public double Diagonal()
    {
        return Math.sqrt(width * width + height * height);
    }
    @Override
    public void Print()
    {
        System.out.format("Прямоугольный треугольник:\nКоординаты: (%3f, %3f)\nШирина: %3f\nВысота: %3f\nДиагональ: %3f\n\n", super.GetX(), super.GetY(), width, height, Diagonal());
    }
}
public class Main {

    public static void main(String[] args) {
        Figure figure = new Figure(3.3, 5.5);
        Figure rect = new Rect(4, 5, 3, 3);
        Figure rt = new RightTriangles(-66.4, -99, 89, 1024);
        Figure ellipse = new Ellipse(-10, -9.5, 10);

        System.out.println("Данные фигур: ");

        figure.Print();
        figure.Move(-43, -23);
        figure.Rotate(0, 9, 45);

        rect.Print();
        rect.Move(-43, -23);
        rect.Rotate(0, 9, 45);

        rt.Print();
        rt.Move(-43, -23);
        rt.Rotate(0, 9, 45);

        ellipse.Print();
        ellipse.Move(-43, -23);
        ellipse.Rotate(0, 9, 45);

        System.out.println("Фигуры после перемещения и поворота: \n");
        figure.Print();
        rect.Print();
        rt.Print();
        ellipse.Print();
    }
}
