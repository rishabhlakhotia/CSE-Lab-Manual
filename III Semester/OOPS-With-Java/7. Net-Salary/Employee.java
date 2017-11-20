import java.io.*;

class EmployeeDetails
{
	int emp_id;
	String emp_name;
	float basic_salary;
	EmployeeDetails(int id, String name, float sal)
	{
		emp_id=id;
		emp_name=name;
		basic_salary=sal;
	}
	void calculateSalary()
	{
		float da=basic_salary*40/100;
		float hra=basic_salary*20/100;
		float pf = basic_salary*10/100;
		float cca =  250;
		float pt = 100;
		float gross_sal=basic_salary+da+hra+cca;
		float it = gross_sal*10/100;
		float deductions = pt+it+pf;
		float netsal = gross_sal - deductions;
		System.out.println ("Employee Id= "+emp_id);
		System.out.println ("Emplyee Name= "+emp_name);
		System.out.println ("Gross Salary= "+gross_sal);
		System.out.println("Net Salary = "+netsal);
	}
}
public class Employee {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println ("Enter Employee id");
		int id = Integer.parseInt(br.readLine());
		System.out.println ("Enter Employee Name");
		String name = br.readLine();
		System.out.println ("Enter Basic Salary");
		Float sal = Float.parseFloat(br.readLine());
		EmployeeDetails e = new EmployeeDetails(id, name, sal);
		e.calculateSalary();
	}

}
