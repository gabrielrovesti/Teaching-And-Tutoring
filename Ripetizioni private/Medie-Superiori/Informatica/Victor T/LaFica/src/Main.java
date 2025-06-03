//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Cane c1 = new Cane("Gabriel", 24, "Doberman");
        Gatto g1 = new Gatto("Pistorio", 75, "Nigga");
        Uccello u1 = new Uccello("PabloEscobar", 56, 180);
        Animale a1 = new Animale("CiccioGamer", 20);
        Animale[] listaAnimali = {c1,g1,u1,a1};
        Zoo zoo = new Zoo(listaAnimali);
    }
}
