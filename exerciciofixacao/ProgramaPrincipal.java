
package exerciciofixacao;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;



public class ProgramaPrincipal {

	public static void main(String[] args) throws ParseException  {

		Scanner entrada = new Scanner(System.in);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy"); 
        		
        		
		System.out.println("Enter department's name :");
		String departmentName = entrada.nextLine();
		
		System.out.println("Enter worker data :");
		System.out.println("Name :");
		String workerName = entrada.nextLine();

		System.out.println("Level :");
		String level = entrada.nextLine();

		System.out.println("Base salary :");
		double baseSalary = entrada.nextDouble();
		
		Worker worker = new Worker(workerName, WorkerLevel.valueOf(level), 
				baseSalary, new Department(departmentName));
		
		System.out.println("How many contracts to this worker??");
		int n = entrada.nextInt();
		
		for (int i = 1; i <= n; i++) {// ler a qtde de contratos
		    System.out.println("Enter contract #" + i + " data :");
		    
		    System.out.println("Data (DD/MM/YYYY) :");
		    Date contractData = sdf.parse(entrada.next()); 
		    
		    System.out.println("Value per hour :");
		    double valueHour = entrada.nextDouble();
		    
		    System.out.println("Duration (hours) :");
		    int hours = entrada.nextInt();
		    
		    HourContract contract =  new HourContract(contractData, valueHour, hours);
		    worker.addContract(contract);
		}
		
		
		System.out.println("");
		System.out.println("Enter month and year to calculate income (MM/YYYY) :");
		String monthYaer = entrada.next();  
		
		int month = Integer.parseInt(monthYaer.substring(0,2));
		int year  = Integer.parseInt(monthYaer.substring(3));
		System.out.println("Name :" + worker.getName());
		System.out.println("Department : " + worker.getDepartment().getName());
		
		System.out.println("Income for " + monthYaer + " : " 
		                   + String.format("%.2f", worker.income(year, month)));
		
		
		
		
		

		entrada.close();
	}



}
