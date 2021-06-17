
package exerciciofixacao2;


public class Produto {
    private String NomeP;
    private double PrecoP;
        	public Produto() {
		// TODO Auto-generated constructor stub
	}
    public Produto(String NomeP, double PrecoP)
    {
        this.NomeP = NomeP;
        this.PrecoP = PrecoP;
    }

    public String getNomeP() {
        return NomeP;
    }

    public void setNomeP(String NomeP) {
        this.NomeP = NomeP;
    }

    public double getPrecoP() {
        return PrecoP;
    }

    public void setPrecoP(double PrecoP) {
        this.PrecoP = PrecoP;
    }
    
}
