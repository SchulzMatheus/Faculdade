package ProgramaPrincipal;

import entidades.ImportedProduct;
import entidades.Product;
import entidades.UsedProduct;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class ProgramaPrincipal {
    public static void main(String[] args) throws ParseException {
        
        Scanner sc = new Scanner(System.in);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

        List<Product> list = new ArrayList<>(); //criando um array apenas pra facilitar a chamada.

        System.out.print("Quantos produtos foram solicitados: ");
        int x = sc.nextInt();

        for (int i=1; i<=x; i++) {
            System.out.println(" Dados do Produto #" + i);
            System.out.print("Comum, usado ou importado: (c/u/i)? ");
            char h = sc.next().charAt(0);
            System.out.print("Nome: ");
            sc.nextLine();
            String name = sc.nextLine();
            System.out.print("Preço: ");
            double price = sc.nextDouble();
            if (h == 'c') {
                list.add(new Product(name, price));
            }
            else if (h == 'u') {
                System.out.print("Data de produção (DD/MM/YYYY): ");
                Date date = sdf.parse(sc.next());
                list.add(new UsedProduct(name, price, date));
            }
            else {
                System.out.print("Imposto: ");
                double customsFee = sc.nextDouble();
                list.add(new ImportedProduct(name, price, customsFee));
            }
        }

        System.out.println();
        System.out.println("etiqueta de preço:");
        for (Product prod : list) {
            System.out.println(prod.priceTag());
        }

        sc.close();
    }
}