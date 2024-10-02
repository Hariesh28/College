package Exercise2.converter.time;

public class time_converter {

    public static double hour_to_minutes(double value){

        return value * 60;
    }

    public static double minute_to_hour(double value){

        return value / 60;
    }

    public static double hour_to_second(double value){

        return value * 3600;
    }

    public static double second_to_hour(double value){

        return value / 3600;
    }

    public static double minute_to_second(double value){

        return value * 60;
    }

    public static double second_to_minute(double value){

        return value / 60;
    }
}
