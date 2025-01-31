
import javax.swing.*; // libreria per Swing = roba grafica (UI)
import java.container.*; // pane (lastra) - label / container (finestra)
public class Swing {
	
	public static void main (String[] args) {
		JFrame win = new JFrame("Prima finestra");
		// new JFrame(String) -> costruttore
		
		// private: String s;
		// public:
		// JFrame(String s){
		// this.s = s;
		// }
		
		// Container = oggetto che è la finestra stessa
		Container c = win.getContentPane();
		
		// aggiungiamo un'etichetta alla finestra
		JLabel etichetta = new JLabel("Buona Lezione")
		c.add(etichetta);
		
		// metodi fissi di tipo JFRame
		// setSize
		// setDefaultCloseOperation
		// setVisible
		
		// Elementi grafici
		// Checkbox in Java = JCheckBox
		JCheckBox box = new JCheckBox("Nome", 200);
		// Radio button in Java = JCheckBox
		// Combo box in Java = Insieme di oggetti
		
		

	}
}

