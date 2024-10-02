package Exercise2.converter.distance;

public class distance_converter {

    public static double meter_to_km(double value){

        return value * 0.001;
    }

    public static double km_to_meter(double value){

        return value * 1000;
    }

    public static double mile_to_km(double value){

        return value * 1.60934;
    }

    public static double km_to_mile(double value){

        return value * 0.621371;
    }
}