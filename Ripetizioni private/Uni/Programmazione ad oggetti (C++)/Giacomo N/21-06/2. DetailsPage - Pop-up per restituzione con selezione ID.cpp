// In DetailsPage.cpp - Replace onReturnButtonClicked() method
void DetailsPage::onReturnButtonClicked() {
    qDebug() << "=== INIZIO DetailsPage::onReturnButtonClicked ===";
    
    if (!currentMedia) return;
    
    // Create return dialog
    QDialog returnDialog(this);
    returnDialog.setWindowTitle("Restituisci Media");
    returnDialog.setModal(true);
    returnDialog.resize(400, 300);
    
    QVBoxLayout* layout = new QVBoxLayout(&returnDialog);
    
    // Title label
    QLabel* titleLabel = new QLabel(QString("Restituire: %1").arg(QString::fromStdString(currentMedia->getTitolo())));
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold; margin-bottom: 10px;");
    layout->addWidget(titleLabel);
    
    // Instructions
    QLabel* instructionLabel = new QLabel("Seleziona l'ID del media da restituire:");
    instructionLabel->setStyleSheet("font-size: 14px; margin-bottom: 5px;");
    layout->addWidget(instructionLabel);
    
    // Get all media with same title from biblioteca (need access to biblioteca)
    // For now, we'll create a simple ID input field
    // In a real implementation, you'd need to pass biblioteca reference to DetailsPage
    
    QListWidget* idList = new QListWidget();
    idList->setStyleSheet("QListWidget { border: 1px solid #ccc; border-radius: 4px; }");
    
    // Simulate showing IDs - in real implementation, query biblioteca for matching titles
    // This is a simplified version for demonstration
    QString currentId = QString::fromStdString(currentMedia->getId());
    QListWidgetItem* item = new QListWidgetItem(currentId);
    idList->addItem(item);
    
    // Add note about ideal library
    QLabel* noteLabel = new QLabel("Nota: In una biblioteca reale, gli ID sarebbero visibili solo sulle etichette fisiche dei media.");
    noteLabel->setStyleSheet("font-size: 12px; color: #666; font-style: italic; margin-top: 5px;");
    noteLabel->setWordWrap(true);
    
    layout->addWidget(idList);
    layout->addWidget(noteLabel);
    
    // Input field for manual ID entry
    QLabel* manualLabel = new QLabel("Oppure inserisci l'ID manualmente:");
    manualLabel->setStyleSheet("font-size: 14px; margin-top: 10px; margin-bottom: 5px;");
    layout->addWidget(manualLabel);
    
    QLineEdit* idInput = new QLineEdit();
    idInput->setPlaceholderText("Inserisci ID (es. VC-123)");
    idInput->setStyleSheet("QLineEdit { border: 1px solid #ccc; border-radius: 4px; padding: 5px; }");
    layout->addWidget(idInput);
    
    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* confirmButton = new QPushButton("Conferma Restituzione");
    QPushButton* cancelButton = new QPushButton("Annulla");
    
    confirmButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #28a745;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 4px;"
        "   padding: 8px 16px;"
        "   font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #218838;"
        "}"
    );
    
    cancelButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #6c757d;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 4px;"
        "   padding: 8px 16px;"
        "   font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #545b62;"
        "}"
    );
    
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(confirmButton);
    layout->addLayout(buttonLayout);
    
    // Connect signals
    connect(cancelButton, &QPushButton::clicked, &returnDialog, &QDialog::reject);
    connect(confirmButton, &QPushButton::clicked, [&]() {
        QString selectedId;
        
        // Check if ID was selected from list
        if (idList->currentItem()) {
            selectedId = idList->currentItem()->text();
        }
        // Check if ID was entered manually
        else if (!idInput->text().isEmpty()) {
            selectedId = idInput->text().trimmed();
        }
        
        if (selectedId.isEmpty()) {
            QMessageBox::warning(&returnDialog, "Errore", "Seleziona o inserisci un ID valido.");
            return;
        }
        
        // Validate ID format (basic check)
        if (!selectedId.contains("-")) {
            QMessageBox::warning(&returnDialog, "Errore", "Formato ID non valido. Utilizzare formato: XX-###");
            return;
        }
        
        // Here you would validate that the ID exists in biblioteca
        // For now, we'll just check if it matches current media ID
        if (selectedId != QString::fromStdString(currentMedia->getId())) {
            QMessageBox::warning(&returnDialog, "Errore", 
                QString("L'ID '%1' non corrisponde a nessun media presente in biblioteca.").arg(selectedId));
            return;
        }
        
        returnDialog.accept();
    });
    
    // Show dialog
    if (returnDialog.exec() == QDialog::Accepted) {
        QString selectedId;
        if (idList->currentItem()) {
            selectedId = idList->currentItem()->text();
        } else {
            selectedId = idInput->text().trimmed();
        }
        
        qDebug() << "Emettendo segnale mediaReturned per ID:" << selectedId;
        emit mediaReturned(currentMedia);
        updateUI();
        
        QMessageBox::information(this, "Restituzione Completata", 
            QString("Media con ID '%1' restituito con successo.").arg(selectedId));
    }
    
    qDebug() << "=== FINE DetailsPage::onReturnButtonClicked ===";
}