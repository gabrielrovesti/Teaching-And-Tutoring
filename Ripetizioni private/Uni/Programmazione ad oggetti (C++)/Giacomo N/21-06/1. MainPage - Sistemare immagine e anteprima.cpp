// In MainPage.cpp - Replace updateImageSize() method
void MainPage::updateImageSize(){
    if (!originalPixmap.isNull()) {
        // Use fixed size constraints instead of dynamic calculation
        int maxWidth = 250;  // Fixed maximum width
        int maxHeight = 250; // Fixed maximum height
        
        // Scale pixmap maintaining aspect ratio
        QPixmap scaledPixmap = originalPixmap.scaled(maxWidth, maxHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        
        // Set directly without background creation
        mediaImageLabel->setPixmap(scaledPixmap);
        mediaImageLabel->setFixedSize(maxWidth, maxHeight);
    }
}

// In MainPage.cpp - Update onMediaSelected() method for better image handling
void MainPage::onMediaSelected(QListWidgetItem *item) {
    if (!item) return;
    
    int row = mediaList->row(item);
    showActionButtons(row);
    
    Media* media = biblioteca->getListaMedia()[row];
    
    if (media) {
        // Update text information
        mediaTitleLabel->setText(QString::fromStdString(media->getTitolo()));
        mediaTitleLabel->setStyleSheet("font-weight: bold; font-size: 20px;");
        mediaAuthorLabel->setText(QString::fromStdString(media->getAutore()));
        mediaAuthorLabel->setStyleSheet("font-size: 16px;");
        mediaYearLabel->setText(QString::number(media->getAnno()));
        mediaYearLabel->setStyleSheet("font-size: 14px;");

        double rating = media->getRating();
        QString stars = QString("Rating: %1 %2").arg(QString("★").repeated(static_cast<int>(rating))).arg(QString::number(rating, 'f', 1));
        mediaRatingLabel->setText(stars);
        mediaRatingLabel->setStyleSheet("font-size: 14px;");

        // Handle image loading with error checking
        QString imagePath = QString::fromStdString(media->getImmagine());
        if (!imagePath.isEmpty() && QFile::exists(imagePath)) {
            QPixmap pixmap(imagePath);
            if (!pixmap.isNull()) {
                originalPixmap = pixmap;
                updateImageSize();
            } else {
                // Handle corrupt image file
                setDefaultImage();
            }
        } else {
            // Handle missing image file
            setDefaultImage();
        }

        // Enable buttons
        borrowButton->setEnabled(true);
        detailsButton->setEnabled(true);
        editMediaButton->setEnabled(true);
    }
}

// Add helper method for default image
void MainPage::setDefaultImage() {
    mediaImageLabel->clear();
    mediaImageLabel->setText("Immagine non disponibile");
    mediaImageLabel->setStyleSheet(
        "border: 1px solid black;"
        "background-color: white;"
        "color: gray;"
        "padding: 5px;"
        "font-size: 14px;"
    );
    originalPixmap = QPixmap(); // Reset original pixmap
}