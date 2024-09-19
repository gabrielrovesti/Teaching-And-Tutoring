class Lista{
    // Lista
    // [info] [link] --> [info] [link]
    private:
        // informazioni e link (array di interi)
        int[] info;
        int[] next;
    public:
        // costruttore = assegna alle variabili una serie di valori
        Lista(int[] i, int[] n){
            for(int j = 0; j < n; j++)
                info[j] = i[j];
                next[j] = n[j];
        }

        // attraversamento lista
        public void attraversamentoLista(int[] i, int[] n){
            for(int it = 0; it < i.length; it++){
                System.out.println("Lista nell'elemento: ", i, 
                "con informazione", i[it], "verso il nodo", n[it]);
            }
        }
        // Lista
        // [info] [link] --> [info] [link]
}