package Exercise3;

public class Employee {

    String EmployeeName;
    int EmployeeID;
    String EmployeeAddress;
    String EmployeeMailId;
    long EmployeeMobileNo;

    public Employee(int EmployeeID, String EmployeeName, String EmployeeAddress, String EmployeeMailId, long EmployeeMobileNo) {
        this.EmployeeID = EmployeeID;
        this.EmployeeName = EmployeeName;
        this.EmployeeAddress = EmployeeAddress;
        this.EmployeeMailId = EmployeeMailId;
        this.EmployeeMobileNo = EmployeeMobileNo;
    }
}
