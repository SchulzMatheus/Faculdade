
package exerciciofixacao2;
import java.text.ParseException;
import java.text.SimpleDateFormat;

import java.util.Date;
import java.util.Scanner;


public class ProgramaPrincipal {

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        
        
                System.out.println("Informe os dados do cliente :");
		System.out.println("Nome :");
		String name = entrada.nextLine();
                System.out.println("email :");
                String email = entrada.nextLine();
                System.out.println("Data de nascimento: ");
                
                String birthday = entrada.nextLine();
                
                Cliente cliente = new Cliente(birthday, name, email);
                System.out.println("Informe os dados da ordem:");
		System.out.print("Status: ");
                StatusOrdem status = StatusOrdem.valueOf(entrada.next());
                
                Ordem ordem = new Ordem(new Date(), status, cliente);
                System.out.print("Quantos produtos foram solicitados? ");
                int n = entrada.nextInt();
                for (int i = 1; i <= n; i++)
                {
                    System.out.println("Informe os dados do #" + i + " item:");
                    System.out.print("Nome do produto: ");
                    entrada.nextLine();
                    String NomeP = entrada.nextLine();
                    System.out.print("Preço do produto: ");
                    double PrecoP = entrada.nextDouble();
                    
                    Produto produto = new Produto(NomeP, PrecoP);
                    
                    System.out.print("Quantidade: ");
                    int quantidade = entrada.nextInt();
                    	OrdemDeItem ordemdeitem = new OrdemDeItem(quantidade, PrecoP, produto);
			ordem.addItem(ordemdeitem);
                }
                System.out.println();
		System.out.println("ORDER SUMMARY:");
		System.out.println(ordem);
		
		entrada.close();
                
    
    }
}
