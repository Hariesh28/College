package University_Database_Program.University_Database.Entity;

import University_Database_Program.University_Database.Details.Official;
import University_Database_Program.University_Database.Details.Person;

public class Student {

    private String registrationNumber;
    private String course;
    private String branch;
    private String batch;
    Official official;
    Person person;

    public Student(String registrationNumber, String course, String branch, String batch, Official official, Person person) {
        this.registrationNumber = registrationNumber;
        this.course = course;
        this.branch = branch;
        this.batch = batch;
        this.official = official;
        this.person = person;
    }

    public Student(){

        this.registrationNumber = "";
        this.course = "";
        this.branch = "";
        this.batch = "";
        this.official = new Official();
        this.person = new Person();
    }

    public String getRegistrationNumber() {
        return registrationNumber;
    }

    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }

    public String getCourse() {
        return course;
    }

    public void setCourse(String course) {
        this.course = course;
    }

    public String getBranch() {
        return branch;
    }

    public void setBranch(String branch) {
        this.branch = branch;
    }

    public String getBatch() {
        return batch;
    }

    public void setBatch(String batch) {
        this.batch = batch;
    }

    public Official getOfficial() {
        return official;
    }

    public void setOfficial(Official official) {
        this.official = official;
    }

    public Person getPerson() {
        return person;
    }

    public void setPerson(Person person) {
        this.person = person;
    }

    public void printStudentInfo() {
        System.out.println("Registration Number: " + registrationNumber);
        System.out.println("Course: " + course);
        System.out.println("Branch: " + branch);
        System.out.println("Batch: " + batch);
        person.printPerson();
        official.printOfficial();
    }
}
