
import java.awt.Font;
import javax.swing.JLabel;

public class MyLabel extends JLabel {
    
    private String etichetta;
    private int valore;
    
    public MyLabel(String etichetta,int valore){
        super();
        this.etichetta = etichetta+" ";
        this.valore = valore;
        this.setHorizontalAlignment(JLabel.CENTER);
        setFont(new Font("sans-serif", Font.PLAIN, 20));
        setText(this.etichetta + valore);
               
    }
    public void setValore(int valore){
        this.valore = valore;
        setText(etichetta + valore);
    }
    
    public int getValore(){
        return valore;
    }
    
    public void incrementa(){
        setValore(++valore);
    }
    public void decrementa(){
        setValore(--valore);
    }
    
    public void aggiungi(int valore){
        this.valore +=valore;
        setText(etichetta + this.valore);
    }
    
}
