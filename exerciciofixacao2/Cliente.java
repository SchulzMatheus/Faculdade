
package exerciciofixacao2;

import java.text.SimpleDateFormat;

public class Cliente {
    
    
    private String name;
    private String email;
    private String birthday;
    
    	public Cliente() {
		// TODO Auto-generated constructor stub
	}

    public Cliente (String birthday, String name, String email)
    {
        this.birthday = birthday;
        this.email = email;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getBirthday() {
        return birthday;
    }

    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }
    @Override
	public String toString() {
		return name + " - Data de nascimento:(" + birthday + ") - email: " + email;
		//return "Client [name=" + name + ", email=" + email + ", birthDate=" + birthDate + "]";
	}
    
    
}
