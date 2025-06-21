// In Rivista.cpp - Ensure editore is properly serialized in JSON
void Rivista::toJson(QJsonObject& jsonObj) const {
    Media::toJson(jsonObj);
    jsonObj["tipo"] = "rivista";
    
    // Ensure editore is properly set - if empty, use autore as fallback
    QString editoreValue = QString::fromStdString(editore);
    if (editoreValue.isEmpty()) {
        editoreValue = QString::fromStdString(getAutore()); // Use autore as editore
    }
    jsonObj["editore"] = editoreValue;
    
    jsonObj["numero_pagine"] = n_pagine;
    jsonObj["data_pubblicazione"] = QString::fromStdString(data_pubb);
    jsonObj["periodicita"] = QString::fromStdString(periodicita);
}

// In Rivista.cpp - Constructor should ensure editore is set
Rivista::Rivista(string titolo, string autore, string genere, int anno, string lingua, string immagine, 
    bool disponibilita, int numero_copie, string editore, int n_pagine, string data_pubb, 
    string periodicita, int in_prestito, string collocazione, double rating) : 
    Media(titolo, autore, genere, anno, lingua, immagine, disponibilita, numero_copie, in_prestito, collocazione, rating), 
    editore(editore.empty() ? autore : editore), // Use autore if editore is empty
    n_pagine(n_pagine), 
    data_pubb(data_pubb), 
    periodicita(periodicita) {}

// In JsonIO.cpp - Fix JSON loading for riviste
Media* JsonIO::jsonToMedia(const QJsonObject& json) const{
    // ... existing code for common attributes ...
    
    // Add this case for rivista handling:
    else if (tipo == "rivista") {
        string editore = json["editore"].toString().toStdString();
        
        // If editore is empty in JSON, use autore
        if (editore.empty()) {
            editore = autore;
        }
        
        int numeroPagine = json["numero_pagine"].toInt();
        string dataPubblicazione = json["data_pubblicazione"].toString().toStdString();
        string periodicita = json["periodicita"].toString().toStdString();

        return new Rivista(titolo, autore, genere, anno, lingua, immagine, disponibilita, numero_copie, 
                          editore, numeroPagine, dataPubblicazione, periodicita, in_prestito, collocazione, rating);
    }
    
    // ... rest of existing code ...
}