package Exercise3;

class Programmer extends Employee{

     double basicPay, DA, HRA, PF, staffClubFund, grossSalary, netSalary;

    Programmer(int EmployeeID, String EmployeeName, String EmployeeAddress, String EmployeeMailId, long EmployeeMobileNo, double basicPay) {
        super(EmployeeID, EmployeeName, EmployeeAddress, EmployeeMailId, EmployeeMobileNo);
        this.basicPay = basicPay;

        this.DA = 0.97 * basicPay;
        this.HRA = 0.10 * basicPay;
        this.PF = 0.12 * basicPay;
        this.staffClubFund = 0.01 * basicPay;
        this.grossSalary = basicPay + this.DA + this.HRA;
        this.netSalary = basicPay - this.PF - this.staffClubFund;
    }

    public void generatePaySlip(){

        System.out.println("Pay Slip for: " + EmployeeName);
        System.out.println("Employee ID: " + EmployeeID);
        System.out.println("Address: " + EmployeeAddress);
        System.out.println("Email: " + EmployeeMailId);
        System.out.println("Mobile No: " + EmployeeMobileNo);
        System.out.println("Basic Pay: $" + basicPay);
        System.out.println("DA (97% of BP): $" + DA);
        System.out.println("HRA (10% of BP): $" + HRA);
        System.out.println("PF (12% of BP): $" + PF);
        System.out.println("Staff Club Fund (1% of BP): $" + staffClubFund);
        System.out.println("Gross Salary: $" + grossSalary);
        System.out.println("Net Salary: $" + netSalary);
        System.out.println("----------------------------");
    }
}

class Assistant_Professor extends Employee{

    double basicPay, DA, HRA, PF, staffClubFund, grossSalary, netSalary;

    Assistant_Professor(int EmployeeID, String EmployeeName, String EmployeeAddress, String EmployeeMailId, long EmployeeMobileNo, double basicPay) {
        super(EmployeeID, EmployeeName, EmployeeAddress, EmployeeMailId, EmployeeMobileNo);
        this.basicPay = basicPay;

        this.DA = 0.97 * basicPay;
        this.HRA = 0.10 * basicPay;
        this.PF = 0.12 * basicPay;
        this.staffClubFund = 0.01 * basicPay;
        this.grossSalary = basicPay + this.DA + this.HRA;
        this.netSalary = basicPay - this.PF - this.staffClubFund;
    }

    public void generatePaySlip(){

        System.out.println("Pay Slip for: " + EmployeeName);
        System.out.println("Employee ID: " + EmployeeID);
        System.out.println("Address: " + EmployeeAddress);
        System.out.println("Email: " + EmployeeMailId);
        System.out.println("Mobile No: " + EmployeeMobileNo);
        System.out.println("Basic Pay: $" + basicPay);
        System.out.println("DA (97% of BP): $" + DA);
        System.out.println("HRA (10% of BP): $" + HRA);
        System.out.println("PF (12% of BP): $" + PF);
        System.out.println("Staff Club Fund (1% of BP): $" + staffClubFund);
        System.out.println("Gross Salary: $" + grossSalary);
        System.out.println("Net Salary: $" + netSalary);
        System.out.println("----------------------------");
    }
}

class Associate_Professor extends Employee{

    double basicPay, DA, HRA, PF, staffClubFund, grossSalary, netSalary;

    Associate_Professor(int EmployeeID, String EmployeeName, String EmployeeAddress, String EmployeeMailId, long EmployeeMobileNo, double basicPay) {
        super(EmployeeID, EmployeeName, EmployeeAddress, EmployeeMailId, EmployeeMobileNo);
        this.basicPay = basicPay;

        this.DA = 0.97 * basicPay;
        this.HRA = 0.10 * basicPay;
        this.PF = 0.12 * basicPay;
        this.staffClubFund = 0.01 * basicPay;
        this.grossSalary = basicPay + this.DA + this.HRA;
        this.netSalary = basicPay - this.PF - this.staffClubFund;
    }

    public void generatePaySlip(){

        System.out.println("Pay Slip for: " + EmployeeName);
        System.out.println("Employee ID: " + EmployeeID);
        System.out.println("Address: " + EmployeeAddress);
        System.out.println("Email: " + EmployeeMailId);
        System.out.println("Mobile No: " + EmployeeMobileNo);
        System.out.println("Basic Pay: $" + basicPay);
        System.out.println("DA (97% of BP): $" + DA);
        System.out.println("HRA (10% of BP): $" + HRA);
        System.out.println("PF (12% of BP): $" + PF);
        System.out.println("Staff Club Fund (1% of BP): $" + staffClubFund);
        System.out.println("Gross Salary: $" + grossSalary);
        System.out.println("Net Salary: $" + netSalary);
        System.out.println("----------------------------");
    }
}

class Professor extends Employee{

    double basicPay, DA, HRA, PF, staffClubFund, grossSalary, netSalary;

    Professor(int EmployeeID, String EmployeeName, String EmployeeAddress, String EmployeeMailId, long EmployeeMobileNo, double basicPay) {
        super(EmployeeID, EmployeeName, EmployeeAddress, EmployeeMailId, EmployeeMobileNo);
        this.basicPay = basicPay;

        this.DA = 0.97 * basicPay;
        this.HRA = 0.10 * basicPay;
        this.PF = 0.12 * basicPay;
        this.staffClubFund = 0.01 * basicPay;
        this.grossSalary = basicPay + this.DA + this.HRA;
        this.netSalary = basicPay - this.PF - this.staffClubFund;
    }

    public void generatePaySlip(){

        System.out.println("Pay Slip for: " + EmployeeName);
        System.out.println("Employee ID: " + EmployeeID);
        System.out.println("Address: " + EmployeeAddress);
        System.out.println("Email: " + EmployeeMailId);
        System.out.println("Mobile No: " + EmployeeMobileNo);
        System.out.println("Basic Pay: $" + basicPay);
        System.out.println("DA (97% of BP): $" + DA);
        System.out.println("HRA (10% of BP): $" + HRA);
        System.out.println("PF (12% of BP): $" + PF);
        System.out.println("Staff Club Fund (1% of BP): $" + staffClubFund);
        System.out.println("Gross Salary: $" + grossSalary);
        System.out.println("Net Salary: $" + netSalary);
        System.out.println("----------------------------");
    }
}