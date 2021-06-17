package app;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

import entities.Company;
import entities.Individual;
import entities.TaxPayer;

public class Program {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        List<TaxPayer> list = new ArrayList<>();

        System.out.print("Informe quantos contribuintes existem: ");
        int x = sc.nextInt();

        for (int i = 1; i <= x; i++) {
            System.out.println("Dados do #" + i + " contribuinte:");
            System.out.print("Pessoa física ou jurídica? (f/j)? ");
            char c = sc.next().charAt(0);
            System.out.print("Nome: ");
            sc.nextLine();
            String name = sc.nextLine();
            System.out.print("Renda anual: ");
            double income = sc.nextDouble();
            if (c == 'f') {
                System.out.print("Despesas com saúde: ");
                double healthExpenditures = sc.nextDouble();
                list.add(new Individual(name, income, healthExpenditures));
            } else {
                System.out.print("Número de empregados: ");
                int numberOfEmployees = sc.nextInt();
                list.add(new Company(name, income, numberOfEmployees));
            }
        }

        double sum = 0.0;
        System.out.println();
        System.out.println("Impostos pagos:");
        for (TaxPayer tp : list) {
            double tax = tp.tax();
            System.out.println(tp.getName() + ": R$ " + String.format("%.2f", tax));
            sum += tax;
        }

        System.out.println();
        System.out.println("Total de impostos: R$ " + String.format("%.2f", sum));

        sc.close();
    }
}