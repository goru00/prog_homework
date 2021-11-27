package com.company;
import java.util.ArrayDeque;

class Parking<T>
{
    private ArrayDeque<T> lots;
    private int sizeLots;

    Parking()
    {
        sizeLots = 0;
    }
    Parking(int sizeLots)
    {
        this.sizeLots = sizeLots;
        this.lots = new ArrayDeque<>();
    }

    public boolean isLots() { return sizeLots > lots.size(); }

    public void checkParking(T arg)
    {
        if (sizeLots > lots.size())
        {
            long restTime = (long) (Math.random() * 2000);
            try
            {
                lots.addLast(arg);
                System.out.println("Машина " + arg + " заняла парковочное место!");
                Thread.sleep(restTime);
            }
            catch (InterruptedException e)
            {

            }
            lots.removeLast();
            System.out.println("Машина " + arg + " покинула стоянку. Машина простояла примерно " + ((double) restTime / (double) 1000) + " секунд.");
        }
    }
}

class Car extends Thread implements Runnable
{
    private int numCar;
    Parking carPark;

    Car()
    {
        this.numCar = 0;
    }
    Car(Parking carPark, int numCar)
    {
        this.carPark = carPark;
        this.numCar = numCar;
    }

    @Override
    public void run() {
        long restTime = (long) (Math.random() * 2000);
        if (carPark.isLots()) {
            carPark.checkParking(this);
        } else {
            try {
                System.out.println("Машина " + numCar + " ожидает свободного места.");
                Thread.sleep(restTime);
                System.out.println("Машина " + numCar + " проверяет наличие свободного парковочного места.");
                carPark.checkParking(this);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public String toString()
    {
        return "" + numCar;
    }
}
public class Main
{
    public static void main(String[] args)
    {
        long startTime = System.currentTimeMillis();
        Parking<Car> parking = new Parking<Car>(10);
        for (int i = 0; i < 25; i++) {
             new Car(parking, i + 1).start();
        }
    }
}