
import java.awt.Color;
import java.awt.Font;
import java.util.Random;
import javax.swing.BorderFactory;
import javax.swing.JTextField;


public class CasellaSlot extends JTextField{
        
    private boolean bloccata;

    // Casellaslot = Costruita con un font normale
    public CasellaSlot(){
        super();
        bloccata = false;
        setFont(new Font("SANS-SERIF", Font.PLAIN, 40));
        setHorizontalAlignment(JTextField.CENTER);
        setEditable(false);
        setBackground(Color.YELLOW);
        //addMouseListener(new AscoltaMouseAdapter());
    }

    public void setValore(int valore){
        String val = String.valueOf(valore);
        this.setText(val);
    }

    public void setValoreCasuale(){
        int val = (int) (Math.random()*10);
        String valore = String.valueOf(val);
        this.setText(valore);
    }

    public int getValore(){
        int valore = Integer.parseInt(this.getText());
        return valore;
    }

    public void resetCasella(){
        this.setText("");
        if(bloccata){
            this.setBackground(Color.yellow);
            this.setForeground(Color.black);
            bloccata = false;
        }
    }

    public boolean isBloccata(){
        return bloccata;
    }

    // Associa con il listener mouse l'evento del colore
    public void bloccaSblocca(){
        if(bloccata){
            this.setBackground(Color.yellow);
            this.setForeground(Color.black);
        }
        else{
            this.setBackground(Color.blue);
            this.setForeground(Color.white);
        }
        bloccata = !bloccata;
    }

}
