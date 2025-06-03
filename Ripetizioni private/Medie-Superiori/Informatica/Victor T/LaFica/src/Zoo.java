public class Zoo {
    private Animale[] listaAnimali;

    public Zoo(Animale[] listaAnimali){
        for(int i = 0; i < listaAnimali.length; i++){
            System.out.println(listaAnimali[i]);
        }
    }
}
