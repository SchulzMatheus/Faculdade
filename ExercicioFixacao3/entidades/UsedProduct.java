package entidades;

import java.text.SimpleDateFormat;
import java.util.Date;
//extends serve para herda os metodos de uma classe
public class UsedProduct extends Product{

    private Date manufactureDate ;

    private static final SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

    public UsedProduct(String name, Double price, Date manufactureDate) {
        super(name, price); //função super chama o construtor da classe mãe
        this.manufactureDate = manufactureDate;
    }

    public Date getManufactureDate() {
        return manufactureDate;
    }

    public void setManufactureDate(Date manufactureDate) {
        this.manufactureDate = manufactureDate;
    }

    @Override
    public String priceTag() {
        return getName()
                + " (usado) R$ "
                + String.format("%.2f", getPrice())
                + " (Manufacture date: "
                + sdf.format(manufactureDate)
                + ")";
    }

}
