package University_Database_Program.Main_Program;

import University_Database_Program.University_Database.Details.Address;
import University_Database_Program.University_Database.Details.Official;
import University_Database_Program.University_Database.Details.Person;
import University_Database_Program.University_Database.Entity.Faculty;
import University_Database_Program.University_Database.Entity.Student;

import java.util.Scanner;

public class mainProgram {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        Faculty[] faculties = new Faculty[100];
        int currentFacultyIndex = -1;

        Student[] students = new Student[100];
        int currentStudentIndex = -1;

        int choice;
        int choice2;

        while (true){

            printMenu();
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice){

                case 1:

                    Person person = getPerson();
                    Official official = getOfficial();

                    System.out.println("1. Add Faculty");
                    System.out.println("2. Add Student");
                    System.out.print("Enter: ");
                    choice2 = scanner.nextInt();
                    scanner.nextLine();

                    if (choice2 == 1){

                        Faculty faculty = getFaculty(person, official);
                        faculties[++currentFacultyIndex] = faculty;

                        System.out.println("Faculty added successfully !");
                    }

                    else if (choice2 == 2){

                        Student student = getStudent(person, official);
                        students[++currentStudentIndex] = student;

                        System.out.println("Student added successfully !");
                    }

                    else
                        System.out.println("Invalid Choice");

                    break;

                case 2:
                    System.out.println("1. Faculty");
                    System.out.println("2. Student");
                    System.out.print("Enter: ");
                    choice2 = scanner.nextInt();
                    scanner.nextLine();

                    if (choice2 == 1){

                        System.out.println("1. Based on Phone number");
                        System.out.println("2. ALL");
                        System.out.print("Enter: ");
                        int choice3 = scanner.nextInt();
                        scanner.nextLine();

                        if (choice3 == 1){

                            System.out.print("Enter: ");
                            String phone = scanner.nextLine();

                            for (Faculty faculty : faculties) {

                                if(faculty != null) {
                                    if (faculty.getPerson().getPhone().equals(phone)) {

                                        faculty.printFaculty();
                                    }
                                }
                            }
                        }

                        else if (choice3 == 2){

                            for (Faculty faculty: faculties) {

                                if(faculty != null) {
                                    faculty.printFaculty();
                                    System.out.println("---------------------------------------------");
                                }
                            }
                        }

                        else
                            System.out.println("Invalid Choice");
                    }

                    else if(choice2 == 2){

                        System.out.println("1. Based on Registration number");
                        System.out.println("2. ALL");
                        System.out.print("Enter: ");
                        choice2 = scanner.nextInt();
                        scanner.nextLine();

                        if (choice2 == 1){
                            System.out.print("Enter: ");
                            String registrationNumber = scanner.nextLine();

                            for (Student student : students) {

                                if(student != null) {

                                    if (student.getRegistrationNumber().equals(registrationNumber)) {

                                        student.printStudentInfo();
                                    }
                                }
                            }
                        }

                        else if (choice2 == 2){

                            for (Student student : students) {

                                if(student != null) {

                                    student.printStudentInfo();
                                    System.out.println("----------------------------------------------");
                                }
                            }
                        }

                        else
                            System.out.println("Invalid Choice");
                    }

                    else
                        System.out.println("Invalid Choice");

                    break;

                case 3:
                    scanner.close();
                    System.out.println("Exited Program");
                    return;

                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }
    }

    public static Address getAddress(){

        Address address = new Address();

        System.out.print("Enter Street name: ");
        address.setStreetName(scanner.nextLine());

        System.out.print("Enter Street number: ");
        address.setStreetNumber(scanner.nextLine());

        System.out.print("Enter City: ");
        address.setCity(scanner.nextLine());

        System.out.print("Enter State: ");
        address.setState(scanner.nextLine());

        System.out.print("Enter Zip code: ");
        address.setZip(scanner.nextLine());

        System.out.print("Enter Country: ");
        address.setCountry(scanner.nextLine());

        return address;
    }

    public static Official getOfficial(){

        Official official = new Official();

        System.out.print("Enter official mail: ");
        official.setMail(scanner.nextLine());


        System.out.print("Enter official working hours: ");
        official.setWorkingHours(scanner.nextLine());

        System.out.print("Enter department name: ");
        official.setDepartmentName(scanner.nextLine());

        return official;
    }

    public static Person getPerson(){

        Person person = new Person();

        System.out.print("Enter name: ");
        person.setName(scanner.nextLine());

        System.out.print("Enter age: ");
        person.setAge(scanner.nextInt());
        scanner.nextLine();

        System.out.print("Enter gender: ");
        person.setGender(scanner.nextLine());

        System.out.print("Enter date of birth: ");
        person.setDateOfBirth(scanner.nextLine());

        System.out.print("Enter blood group: ");
        person.setBloodGroup(scanner.nextLine());

        System.out.print("Enter phone number: ");
        person.setPhone(scanner.nextLine());

        person.setAddress(getAddress());

        return person;
    }

    public static Faculty getFaculty(Person person, Official official){

        Faculty faculty = new Faculty();

        System.out.print("Teaching: ");
        faculty.setTeaching(scanner.nextBoolean());

        System.out.print("Experience: ");
        faculty.setExperience(scanner.nextInt());
        scanner.nextLine();

        System.out.print("Role: ");
        faculty.setRole(scanner.nextLine());

        faculty.setOfficial(official);
        faculty.setPerson(person);

        return faculty;
    }

    public static Student getStudent(Person person, Official official){

        Student student = new Student();

        System.out.print("Enter registration number: ");
        student.setRegistrationNumber(scanner.nextLine());

        System.out.print("Enter course: ");
        student.setCourse(scanner.nextLine());

        System.out.print("Enter Branch: ");
        student.setBranch(scanner.nextLine());

        System.out.print("Enter Batch: ");
        student.setBatch(scanner.nextLine());

        student.setPerson(person);
        student.setOfficial(official);

        return student;
    }

    public static void printMenu(){

        System.out.println("1. Add Details");
        System.out.println("2. Print Details");
        System.out.println("3. Exit Program");
        System.out.print("Enter your choice: ");
    }
}
