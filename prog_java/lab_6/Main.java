import java.util.Random;

class Program
{
    public static void main(String[] args) {

        Mission<ParatrooperMission> pm = new Mission("ParatrooperMission", new Point(2,4));
        pm.aim = new ParatrooperMission();
        System.out.println(pm);
        System.out.println("===============");
        Mission<SoldieMission> sm = new Mission("SoldieMission", new Point(2,4));
        sm.aim = new SoldieMission();
        System.out.println(sm);

    }
}

class Point
{
    public float x;
    public float y;

    public Point()
    {
        x = new Random().nextFloat() * 10f;
        y = new Random().nextFloat() * 10f;
    }

    public Point(float x, float y)
    {
        this.x = x;
        this.y = y;
    }

    public Point(Point a)
    {
        this.x = a.x;
        this.y = a.y;
    }

    @Override
    public String toString() {
        return "Point: " + x + ", " + y + " ";
    }
}

class Circle
{
    Point center;
    float R;

    public Circle()
    {
        center = new Point();
        R = new Random().nextFloat() * 3f;
    }

    public Circle(float x, float y, float R)
    {
        center = new Point(x, y);
        this.R = R;
    }

    public Circle(Point a, float R)
    {
        center = a;
        this.R = R;
    }

    public Circle(Circle a)
    {
        center = a.center;
        R = a.R;
    }

    @Override
    public String toString() {
        return center + "\nR: " + R;
    }
}

class Rect
{
    Point A;
    Point B;
    Point C;
    Point D;

    public Rect()
    {
        A = new Point();
        B = new Point();
        C = new Point();
        D = new Point();
    }

    public Rect(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy)
    {
        A = new Point(Ax, Ay);
        B = new Point(Bx, By);
        C = new Point(Cx, Cy);
        D = new Point(Dx, Dy);
    }

    public Rect(Point A, Point B, Point C, Point D)
    {
        this.A = A;
        this.B = B;
        this.C = C;
        this.D = D;
    }

    public Rect(Rect a)
    {
        this.A = a.A;
        this.B = a.B;
        this.C = a.C;
        this.D = a.D;
    }

    @Override
    public String toString() {
        return "Rect points\n" + A + B + C + D;
    }
}

class Mission<T>
{
    String missionName;
    boolean successful;
    Point unitPosition;
    T aim;

    public Mission(String name, Point pos)
    {
        missionName = name;
        successful = false;
        unitPosition = pos;
    }

    @Override
    public String toString() {
        return "Mission name: " + missionName + "\nSuccessful: " + successful +
        "\nUnitPosition: " + unitPosition + "\nAim: " + aim;
    }
}

class ParatrooperMission
{
    Circle aim;

    public ParatrooperMission()
    {
        aim = new Circle();
    }

    public ParatrooperMission(Circle aim)
    {
        this.aim = aim;
    }

    public Circle getAim() {
        return aim;
    }

    @Override
    public String toString() {
        return aim.toString();
    }
}

class SoldieMission
{
    Rect aim;

    public SoldieMission()
    {
        aim = new Rect();
    }

    public SoldieMission(Rect aim)
    {
        this.aim = aim;
    }

    public Rect getAim() {
        return aim;
    }

    @Override
    public String toString() {
        return aim.toString();
    }
}
