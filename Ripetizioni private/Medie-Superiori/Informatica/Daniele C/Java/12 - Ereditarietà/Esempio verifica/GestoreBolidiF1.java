

import java.util.ArrayList;
import org.xml.sax.Attributes;
import org.xml.sax.helpers.DefaultHandler;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.parsers.SAXParser;
import java.io.File;

public class GestoreBolidiF1 extends DefaultHandler {

    private ArrayList<Pilota> piloti;
    private Pilota p;
	private String strCharacters;
	private String nomeScuderia;
	private String nomePilota;
	private int puntiPilota;

	public GestoreBolidiF1(String nomeFileXML){
		try {
			SAXParserFactory saxFactory = SAXParserFactory.newInstance();
			SAXParser saxParser = saxFactory.newSAXParser();
			saxParser.parse(new File(nomeFileXML),this);
		} catch (Exception e) {
			e.printStackTrace();
		}		
	}


	public void startDocument(){
	}

    public void startElement(String uri, String localName, String qName, Attributes attributi)  {
    }

    public void endElement(String uri, String localName, String qName) {
    }

    public void characters(char ch[], int start, int length)  {
    }
    
    public void endDocument(){
    }
}
