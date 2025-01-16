package RandomProjects.practice3.q3;

class Programmer extends Employee {

     double basicPay, DA, HRA, PF, staffClubFund, grossSalary, netSalary;

    Programmer( String EmployeeName, String EmployeeAddress, double basicPay) {
        super( EmployeeName, EmployeeAddress);
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
        System.out.println("Address: " + EmployeeAddress);
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

class Developer extends Employee {

    double basicPay, DA, HRA, PF, staffClubFund, grossSalary, netSalary;

    Developer( String EmployeeName, String EmployeeAddress,  double basicPay) {
        super( EmployeeName, EmployeeAddress);
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
        System.out.println("Address: " + EmployeeAddress);
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

class Manager extends Employee {

    double basicPay, DA, HRA, PF, staffClubFund, grossSalary, netSalary;

    Manager( String EmployeeName, String EmployeeAddress, double basicPay) {
        super(EmployeeName, EmployeeAddress);
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
        System.out.println("Address: " + EmployeeAddress);
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

