package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        List<Point> army = new ArrayList<>();
        List<Circle> areaCircle = new ArrayList<>();
        List<Rect> areaRect = new ArrayList<>();

        army.add(new Point(1, 1)); // первый солдат

        areaCircle.add(new Circle(2, 2, 2)); // первая область высадки солдата
        areaCircle.add(new Circle(3, 3, 2)); // вторая область высадки солдата
        areaCircle.add(new Circle(3, 4, 6)); // третья область высадки солдата

        areaRect.add(new Rect(5, 2, 4, 3)); // первая область захвата
        areaRect.add(new Rect(3, 2, 7, 2)); // вторая область захвата
        areaRect.add(new Rect(2, 2, 4, 1)); // третья область захвата
        areaCircle.get(0).setPoint(army.get(0));
        Info(areaCircle);
        Info(army);
    }
    public static void Info(List<? extends Point> arg)
    {
        for (Point item : arg) {
            System.out.println(item);
        }
    }
}
