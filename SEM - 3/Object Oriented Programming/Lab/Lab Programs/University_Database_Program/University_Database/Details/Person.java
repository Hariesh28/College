package University_Database_Program.University_Database.Details;

public class Person{

    private String name;
    private int age;
    private String gender;
    private String dateOfBirth;
    private String bloodGroup;
    private Address address;
    private String phone;

    public Person(String hariesh, String male, String s, String string, Address address, String number){
        this.name = "";
        this.age = 0;
        this.gender = "";
        this.dateOfBirth = "";
        this.bloodGroup = "";
        this.address = new Address();
        this.phone = "";
    }

    public Person(String name, int age, String gender, String dateOfBirth, String bloodGroup, Address address, String phone){
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.dateOfBirth = dateOfBirth;
        this.bloodGroup = bloodGroup;
        this.address = address;
        this.phone = phone;
    }

    public Person(String name, int age, String gender, String dateOfBirth, String bloodGroup,String phone, String streetName, String city, String streetNo, String state, String zip, String country){
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.dateOfBirth = dateOfBirth;
        this.bloodGroup = bloodGroup;
        this.phone = phone;
        this.address = new Address(streetName, streetNo, city, state, zip, country);
    }

    public Person() {

        this.name = "";
        this.age = 0;
        this.gender = "";
        this.dateOfBirth = "";
        this.bloodGroup = "";
        this.address = new Address();
        this.phone = "";
    }


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getDateOfBirth() {
        return dateOfBirth;
    }

    public void setDateOfBirth(String dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public String getBloodGroup() {
        return bloodGroup;
    }

    public void setBloodGroup(String bloodGroup) {
        this.bloodGroup = bloodGroup;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void printPerson(){
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
        System.out.println("DateOfBirth: " + dateOfBirth);
        System.out.println("Blood Group: " + bloodGroup);
        address.printAddress();
        System.out.println("Phone: " + phone);
    }
}
