// MainPage.cpp - Fix lag when selecting media from list
void MainPage::onMediaSelected(QListWidgetItem *item) {
    if (!item) return;
    
    // Use single shot timer to debounce rapid selections
    static QTimer* selectionTimer = nullptr;
    if (!selectionTimer) {
        selectionTimer = new QTimer(this);
        selectionTimer->setSingleShot(true);
        selectionTimer->setInterval(100); // 100ms debounce
        connect(selectionTimer, &QTimer::timeout, [this, item]() {
            performMediaSelection(item);
        });
    }
    
    selectionTimer->stop();
    selectionTimer->start();
}

// MainPage.cpp - Separate actual selection logic
void MainPage::performMediaSelection(QListWidgetItem *item) {
    if (!item) return;
    
    const int row = mediaList->row(item);
    showActionButtons(row);
    
    const vector<Media*>& mediaVector = biblioteca->getListaMedia();
    if (row >= 0 && row < static_cast<int>(mediaVector.size())) {
        Media* const media = mediaVector[row];
        updateMediaPreview(media);
    }
}

// MainPage.cpp - Separate preview update logic for better performance
void MainPage::updateMediaPreview(Media* const media) {
    if (!media) return;
    
    // Update text information first (fast operations)
    mediaTitleLabel->setText(QString::fromStdString(media->getTitolo()));
    mediaTitleLabel->setStyleSheet("font-weight: bold; font-size: 20px;");
    mediaAuthorLabel->setText(QString::fromStdString(media->getAutore()));
    mediaAuthorLabel->setStyleSheet("font-size: 16px;");
    mediaYearLabel->setText(QString::number(media->getAnno()));
    mediaYearLabel->setStyleSheet("font-size: 14px;");

    const double rating = media->getRating();
    const QString stars = QString("Rating: %1 %2")
        .arg(QString("★").repeated(static_cast<int>(rating)))
        .arg(QString::number(rating, 'f', 1));
    mediaRatingLabel->setText(stars);
    mediaRatingLabel->setStyleSheet("font-size: 14px;");

    // Load image asynchronously to avoid UI blocking
    loadImageAsync(media->getImmagine());

    // Enable buttons
    borrowButton->setEnabled(true);
    detailsButton->setEnabled(true);
    editMediaButton->setEnabled(true);
}

// MainPage.cpp - Async image loading to prevent UI lag
void MainPage::loadImageAsync(const string& imagePath) {
    const QString qImagePath = QString::fromStdString(imagePath);
    
    if (qImagePath.isEmpty() || !QFile::exists(qImagePath)) {
        setDefaultImage();
        return;
    }
    
    // Use QTimer to load image in next event loop iteration
    QTimer::singleShot(0, this, [this, qImagePath]() {
        const QPixmap pixmap(qImagePath);
        if (!pixmap.isNull()) {
            originalPixmap = pixmap;
            updateImageSize();
        } else {
            setDefaultImage();
        }
    });
}

// MainPage.cpp - Optimize resize event to prevent lag
void MainPage::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    
    // Use timer to debounce resize events
    static QTimer* resizeTimer = nullptr;
    if (!resizeTimer) {
        resizeTimer = new QTimer(this);
        resizeTimer->setSingleShot(true);
        resizeTimer->setInterval(150); // 150ms debounce for resize
        connect(resizeTimer, &QTimer::timeout, this, &MainPage::performResize);
    }
    
    resizeTimer->stop();
    resizeTimer->start();
}

// MainPage.cpp - Actual resize logic
void MainPage::performResize() {
    constexpr int maxImageWidth = 250;
    constexpr int imageHeight = 250;
    
    mediaImageLabel->setFixedSize(maxImageWidth, imageHeight);
    
    if (!originalPixmap.isNull()) {
        updateImageSize();
    }
    
    // Update button positions if visible
    if (buttonsContainer->isVisible() && currentSelectedRow >= 0) {
        updateButtonsPosition();
    }
}

// MainPage.h - Add new method declarations
class MainPage : public QWidget {
    Q_OBJECT

public:
    // ... existing methods ...

private slots:
    // ... existing slots ...
    void performMediaSelection(QListWidgetItem *item);
    void performResize();

private:
    // ... existing members ...
    void updateMediaPreview(Media* const media);
    void loadImageAsync(const string& imagePath);
    
    // ... rest of class ...
};

// Media.h - Add const correctness improvements
class Media {
    // ... existing code ...
    
public:
    // Make getter methods const-correct
    const string& getId() const { return id; }
    const string& getTitolo() const { return titolo; }
    const string& getAutore() const { return autore; }
    const string& getGenere() const { return genere; }
    int getAnno() const { return anno; }
    const string& getLingua() const { return lingua; }
    const string& getImmagine() const { return immagine; }
    bool getDisponibilita() const { return disponibilita; }
    int getNumeroCopie() const { return numero_copie; }
    int getInPrestito() const { return in_prestito; }
    const string& getCollocazione() const { return collocazione; }
    double getRating() const { return rating; }
    
    // ... rest of class ...
};

// Biblioteca.h - Improve const correctness
class Biblioteca {
    // ... existing code ...
    
public:
    // Make methods const where appropriate
    bool esisteMedia(const string& titolo, int anno, const string& genere) const;
    Media* cercaMediaDaID(const string& id) const;
    Media* cercaMediaDaT_A_G(const string& titolo, int anno, const string& genere) const;
    
    const vector<Media*>& getListaMedia() const { return listaMedia; }
    int getNumeroTotaleMedia() const { return static_cast<int>(listaMedia.size()); }
    
    // ... rest of class ...
};