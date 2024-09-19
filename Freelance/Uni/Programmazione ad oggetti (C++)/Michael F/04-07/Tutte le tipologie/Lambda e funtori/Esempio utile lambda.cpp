#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <vector>

using namespace std;

int main(){
	vector<string> titolo;
	vector<string> artista;
	titolo.push_back("blood");
	titolo.push_back("sugar");
	titolo.push_back("sex");
	titolo.push_back("magik");
	for(string s : titolo) cout << s << ' ';
	/* for_each loop: costrutto del c++11 che itera titolo assegnando ad s ogni oggetto-stringa contenuto in titolo: molto utile per iterazioni "al volo" */
	//stampa blood sugar sex magik
	cout << endl;
	artista.push_back("red");
	artista.push_back("hot");
	artista.push_back("chili");
	artista.push_back("peppers");
	for(string s : artista) cout << s << ' ';
	//stampa red hot chili peppers
	cout << endl;
	for_each(artista.begin(), artista.end(), [&titolo](string s){
		titolo.push_back(s);
	}); 
	/*  for_each(container.begin(), container.end(), FunzioneUnaria);
			FunzioneUnaria(T t) viene invocata passando come parametro attuale l'iteratore dereferenziato, da container.begin() (compreso) a container.end() (escluso).
			Se FunzioneUnaria e' una funzione il cui scope e' raggiungibile dal blocco contenente l'istruzione di for_each, allora viene passato come parametro attuale a tale funzione un iteratore dereferenziato di questo intervallo: [container.begin(), container.end()).
			Se FunzioneUnaria e' una lambda espressione, allora il suo parametro formale sara' necessariamente un parametro dello stesso tipo contenuto in container: il parametro attuale cosi' ottenuto assumera' un valore diverso ad ogni iterazione, come succede nel caso precedente.
			artista quindi non compare nella capture list perche' gli oggetti che contiene sono rappresentati coerentemente col parametro formale ad ogni iterazione.
	*/
	for(string s : titolo) cout << s << ' ';
	cout << endl;
	cout << "totale: " << ([&titolo]()throw()->int{
			int a = 0;
			for(auto it=titolo.begin(); it!=titolo.end(); ++it) ++a;
			return a;
		})() << " parole\n";
		/* la lambda espressione precedente non aveva tipo di ritorno (void), questa invece ha come tipo di ritorno un funtore. Un funtore, sostanzialmente, e' un oggetto che puo' essere invocato come se fosse una funzione: e' proprio quello che succede qui.
			Una scrittura equivalente sarebbe potuta essere questa:
				auto a = [&titolo]()throw()->int{
					int e = 0;
					for(auto it=titolo.begin(); it!=titolo.end(); ++it) ++e;
					return e;
				};
				cout << "totale: " << a() << " parole.\n";
				viene catturato titolo per riferimento, viene specificato che non possono essere sollevate eccezioni all'interno del corpo della lambda espressione, la lista parametri e' vuota ed il tipo di ritorno del funtore e' int. La lista parametri deve necessariamente essere scritta se si vuole specificare il tipo di ritorno.
*/
}