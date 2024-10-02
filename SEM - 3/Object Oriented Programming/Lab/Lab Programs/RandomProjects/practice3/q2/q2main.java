package RandomProjects.practice3.q2;

abstract class vehicle {
    private int speed;

    abstract void speedup();

    abstract void getSpeed();

}

class car extends vehicle {
    private int speed;

    car(int speed) {
        this.speed = speed;
    }

    void speedup() {
        speed++;
    }

    void getSpeed() {
        System.out.println("current speed: " + speed);
    }

}

class bicycle extends vehicle {
    private int speed;

    bicycle(int speed) {
        this.speed = speed;
    }

    void speedup() {
        speed++;
    }

    void getSpeed() {
        System.out.println("Current speed: " + speed);
    }
}

public class q2main {
    public static void main(String[] args) {
        car car1 = new car(5);
        car1.getSpeed();
        car1.speedup();
        car1.speedup();
        car1.getSpeed();

        bicycle bicycle1 = new bicycle(10);
        bicycle1.speedup();
        bicycle1.getSpeed();
    }
}
