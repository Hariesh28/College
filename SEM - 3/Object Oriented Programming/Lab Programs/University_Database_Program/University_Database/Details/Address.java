package University_Database_Program.University_Database.Details;

public class Address {

    // Members
    private String streetName;
    private String streetNumber;
    private String city;
    private String state;
    private String zip;
    private String country;


    //Constructor
    public Address(String streetName, String streetNumber, String city, String state, String zip, String country) {
        this.streetName = streetName;
        this.streetNumber = streetNumber;
        this.city = city;
        this.state = state;
        this.zip = zip;
        this.country = country;
    }

    public Address(){
        this.streetName = "";
        this.streetNumber = "";
        this.city = "";
        this.state = "";
        this.zip = "";
        this.country = "";
    }

    //Getters
    public String getStreetName() {
        return streetName;
    }

    public String getStreetNumber() {
        return streetNumber;
    }

    public String getCity() {
        return city;
    }

    public String getState() {
        return state;
    }

    public String getZip() {
        return zip;
    }

    public String getCountry() {
        return country;
    }

    //Setters
    public void setStreetName(String streetName) {
        this.streetName = streetName;
    }

    public void setStreetNumber(String streetNumber) {
        this.streetNumber = streetNumber;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public void setState(String state) {
        this.state = state;
    }

    public void setZip(String zip) {
        this.zip = zip;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public void printAddress(){
        System.out.println("Street Name: " + streetName);
        System.out.println("Street Number: " + streetNumber);
        System.out.println("City: " + city);
        System.out.println("State: " + state);
        System.out.println("Zip: " + zip);
        System.out.println("Country: " + country);
    }
}