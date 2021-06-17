
package exerciciofixacao2;


public class OrdemDeItem {
    
    private int quantidade;
    private double price;
    private Produto produto;
    
    public OrdemDeItem(int quantidade, double price, Produto produto)
    {
        this.quantidade = quantidade;
        this.price = price;
        this.produto = produto;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public Produto getProduto() {
        return produto;
    }

    public void setProduto(Produto produto) {
        this.produto = produto;
    }
    	public double subTotal() {
		return price * quantidade;
	}
       	@Override
	public String toString() {
		return produto.getNomeP()
				+ ", R$" 
				+ String.format("%.2f", price) 
				+ ", Quantidade: " 
				+ quantidade + 
				", Subtotal: R$" 
				+ String.format("%.2f", subTotal());
	}

    }
    
    
    

