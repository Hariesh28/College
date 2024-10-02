package University_Database_Program.University_Database.Entity;

import University_Database_Program.University_Database.Details.Official;
import University_Database_Program.University_Database.Details.Person;

public class Faculty {

    private boolean teaching;
    private int experience;
    private String role;
    Official official;
    Person person;

    public Faculty(boolean teaching, int experience, String role, Official official, Person person) {
        this.teaching = teaching;
        this.experience = experience;
        this.role = role;
        this.official = official;
        this.person = person;
    }

    public Faculty(){

        this.teaching = false;
        this.experience = 0;
        this.role = "";
        this.official = null;
        this.person = null;
    }

    public void printFaculty() {
        System.out.println("Is teaching: " + teaching);
        System.out.println("Experience: " + experience);
        System.out.println("Role: " + role);
        person.printPerson();
        official.printOfficial();
    }

    public boolean isTeaching() {
        return teaching;
    }

    public void setTeaching(boolean teaching) {
        this.teaching = teaching;
    }

    public int getExperience() {
        return experience;
    }

    public void setExperience(int experience) {
        this.experience = experience;
    }

    public String getRole() {
        return role;
    }

    public void setRole(String role) {
        this.role = role;
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
}
