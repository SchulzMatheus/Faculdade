package entities;
//extends mesmo sentido usado no codigo passado
public class Individual extends TaxPayer {

    private Double healthExpenditures;


    public Individual(String name, Double anualIncome, Double healthExpenditures) {
        super(name, anualIncome);
        this.healthExpenditures = healthExpenditures;
    }

    public Individual(String name, Double anualIncome) {
        super(name, anualIncome);
    }

    public Double getHealthExpenditures() {
        return healthExpenditures;
    }

    public void setHealthExpenditures(Double healthExpenditures) {
        this.healthExpenditures = healthExpenditures;
    }

    @Override //override ensinado pelo professor em aula, pra poder da um override na função
    public Double tax() {
        if (getAnualIncome() < 20000.0) {
            return getAnualIncome() * 0.15 - healthExpenditures * 0.5;
        }
        else {
            return getAnualIncome() * 0.25 - healthExpenditures * 0.5;
        }
    }
}