package com.company;

import java.util.concurrent.Phaser;

class Personal
{
    private String name;
    private String[] desc; // состояние сотрудника

    public String getValueDesc(int index) {
        if (desc.length <= index) return getValueDesc(index - 1);
        return desc[index];
    }
    public String getName() { return name; }

    public void setName(String name) { this.name = name; }

    Personal()
    {
        this.name = "";
        this.desc = null;
    }
    Personal(String name, String[] desc)
    {
        this.name = name;
        this.desc = new String[desc.length];
        for (int i = 0; i < desc.length; i++) {
            this.desc[i] = desc[i];
        }
    }

}

class Restoraunt implements Runnable
{
    Phaser phaser;
    Personal pers;
    Restoraunt(Phaser phaser, Personal pers)
    {
        this.phaser = phaser;
        this.pers = pers;
        phaser.register();
    }

    @Override
    public void run() {
        System.out.println(pers.getName() + ": " + pers.getValueDesc(0));


        phaser.arriveAndAwaitAdvance();


        try{
            Thread.sleep(200);
        }
        catch(InterruptedException ex){
            System.out.println(ex.getMessage());
        }
        if (pers.getName() == "Уборщики") System.out.println(pers.getName() + ": " + pers.getValueDesc(0));
        else System.out.println(pers.getName() + ": " + pers.getValueDesc(1));


        phaser.arriveAndAwaitAdvance();


        try{
            Thread.sleep(200);
        }
        catch(InterruptedException ex){
            System.out.println(ex.getMessage());
        }
        if (pers.getName() == "Повара" || pers.getName() == "Официанты") {
            System.out.println(pers.getName() + " " + pers.getValueDesc(2));
            phaser.arriveAndDeregister();
            return; // не лучший способ завершить поток
        } else if (pers.getName() == "Уборщики") {
            System.out.println(pers.getName() + ": " + pers.getValueDesc(0));
            phaser.arriveAndAwaitAdvance();
        } else {
            System.out.println(pers.getName() + ": " + pers.getValueDesc(2));
            phaser.arriveAndAwaitAdvance();
        }


        try{
            Thread.sleep(200);
        }
        catch(InterruptedException ex){
            System.out.println(ex.getMessage());
        }
        if (pers.getName() == "Уборщики") {
            System.out.println(pers.getName() + ": " + pers.getValueDesc(1));
        }
        else {
            System.out.println(pers.getName() + ": " + pers.getValueDesc(3));
        }
        phaser.arriveAndDeregister();


    }
}

public class Main {

    public static void main(String[] args) {

        Personal pers[] = {
                new Personal("Бармен", new String[]
                        {
                                "ревизия на баре",
                                "готовка",
                                "закрытие кассы",
                                "заканчивает работу"
                        }),
                new Personal("Официанты", new String[]
                        {
                                "сервировка столов",
                                "обслуживание гостей",
                                "заканчивают работу"
                        }
                        ),
                new Personal("Повара", new String[]
                        {
                                "ревизия на кухне",
                                "готовка",
                                "заканчивают работу"
                        }),
                new Personal("Уборщики", new String[]
                        {
                                "уборка столов, стульев и мытье полов",
                                "заканчивают работу"
                        })
        };

        Phaser phase = new Phaser(1);


        new Thread(new Restoraunt(phase, pers[0])).start();
        new Thread(new Restoraunt(phase, pers[1])).start();
        new Thread(new Restoraunt(phase, pers[2])).start();
        new Thread(new Restoraunt(phase, pers[3])).start();

        System.out.println("Фаза: " + phase.getPhase());

        phase.arriveAndAwaitAdvance();
        System.out.println("Фаза: " + phase.getPhase());

        phase.arriveAndAwaitAdvance();
        System.out.println("Фаза: " + phase.getPhase());

        phase.arriveAndAwaitAdvance();
        System.out.println("Фаза: " + phase.getPhase());

        phase.arriveAndDeregister();
    }
}