package Exercise2.converter.currency;

public class currency_converter {

    public static double dollar_to_inr(double value){

        return value * 83.73;
    }

    public static double inr_to_dollar(double value){

        return value * 0.012;
    }

    public static double euro_to_inr(double value){

        return value * 90.86;
    }

    public static double inr_to_euro(double value){

        return value * 0.011;
    }

    public static double yen_to_inr(double value){

        return value * 0.54;
    }

    public static double inr_to_yen(double value){

        return value * 1.84;
    }
}
