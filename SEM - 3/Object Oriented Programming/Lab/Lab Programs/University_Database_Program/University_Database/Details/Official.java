package University_Database_Program.University_Database.Details;

public class Official {

    private String mail;
    private String workingHours;
    private String departmentName;

    public Official(String mail, String workingHours, String departmentName) {
        this.mail = mail;
        this.workingHours = workingHours;
        this.departmentName = departmentName;
    }

    public Official(){
        this.mail = "";
        this.workingHours = "";
        this.departmentName = "";
    }


    public String getMail() {
        return mail;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }

    public String getWorkingHours() {
        return workingHours;
    }

    public void setWorkingHours(String workingHours) {
        this.workingHours = workingHours;
    }

    public String getDepartmentName() {
        return departmentName;
    }

    public void setDepartmentName(String departmentName) {
        this.departmentName = departmentName;
    }

    public void printOfficial(){
        System.out.println("Mail: " + mail);
        System.out.println("WorkingHours: " + workingHours);
        System.out.println("Department: " + departmentName);
    }
}
