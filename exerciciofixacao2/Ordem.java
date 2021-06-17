
package exerciciofixacao2;

import java.text.SimpleDateFormat;
import java.util.ArrayList;

import java.util.Date;

public class Ordem {
    private static final SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
    
    private Date momento;
    private StatusOrdem status;
    
    private Cliente cliente;
    private ArrayList<OrdemDeItem> Itens = new ArrayList<>();
    
    public Ordem ()
    {
        
    }
    public Ordem(Date momento, StatusOrdem status, Cliente cliente)
    {
        this.momento = momento;
        this.status = status;
        this.cliente = cliente;
    }

    public Date getMomento() {
        return momento;
    }

    public void setMomento(Date momento) {
        this.momento = momento;
    }

    public StatusOrdem getStatus() {
        return status;
    }

    public void setStatus(StatusOrdem status) {
        this.status = status;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }
    public void addItem (OrdemDeItem item)
    {
        Itens.add(item);
    }
    public void removeItem (OrdemDeItem item)
    {
        Itens.remove(item);
    }
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("Momento da ordem: ");
		sb.append(sdf.format(momento) + "\n");
		sb.append("Status da ordem: ");
		sb.append(status + "\n");
		sb.append("Cliente: ");
		sb.append(cliente + "\n");
		sb.append("Itens solicitados:\n");
		for (OrdemDeItem item : Itens) {
			sb.append(item + "\n");
		}
		sb.append("Preço total: R$");
		sb.append(String.format("%.2f", total()));
		return sb.toString();
	}

	// ------------------------- Methods -----------------------------
	public double total() {
		double sum = 0.0;
		for (OrdemDeItem item : Itens) {
			sum += item.subTotal();
		}
		return sum;
	}
    
}
