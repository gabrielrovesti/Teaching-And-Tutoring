public class Cliente{
    private String nome;
    private String tel;

    public Cliente(String nome, String tel){
        this.nome = nome;
        this.tel = tel;
    }

    public String getNome() {
        return nome;
    }

    public String getTelefono() {
        return tel;
    }

    public String toString(){
        return "Cliente con nome " + nome + "con telefono" + tel + "\n";
    }

};