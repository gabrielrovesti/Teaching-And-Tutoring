
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class AscoltaMouseAdapter extends MouseAdapter {

    @Override
    public void mouseClicked(MouseEvent e) {
        if(e.getButton() == 3){
            CasellaSlot casella = (CasellaSlot) e.getComponent();
            casella.bloccaSblocca();
        }
    }
    
}
