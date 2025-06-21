// In MainPage.cpp - Replace updateButtonsPosition() method
void MainPage::updateButtonsPosition() {
    if (currentSelectedRow < 0 || currentSelectedRow >= mediaList->count()) {
        hideActionButtons();
        return;
    }
    
    QListWidgetItem* item = mediaList->item(currentSelectedRow);
    if (!item) {
        hideActionButtons();
        return;
    }
    
    QRect rect = mediaList->visualItemRect(item);
    
    // Check if item is visible in the viewport
    QRect viewportRect = mediaList->viewport()->rect();
    if (!viewportRect.intersects(rect)) {
        hideActionButtons();
        return;
    }
    
    // Calculate button dimensions
    int buttonWidth = buttonsContainer->sizeHint().width();
    int buttonHeight = buttonsContainer->sizeHint().height();
    
    // Get item text and calculate its approximate width more accurately
    QString itemText = item->text();
    QFontMetrics fontMetrics(mediaList->font());
    
    // Account for icon width (27px + spacing) and margins
    int iconWidth = 35; // Icon size + spacing
    int margins = 20;   // Left/right margins
    int textWidth = fontMetrics.horizontalAdvance(itemText) + iconWidth + margins;
    
    // Ensure text doesn't exceed 75% of item width to leave space for buttons
    int maxTextWidth = rect.width() * 0.75;
    if (textWidth > maxTextWidth) {
        textWidth = maxTextWidth;
    }
    
    // Position buttons to the right of text with safe margin
    int xPosition = rect.left() + textWidth + 10; // 10px safety margin
    
    // Ensure buttons don't go outside the visible area
    int maxXPosition = rect.right() - buttonWidth - 5; // 5px margin from right edge
    if (xPosition > maxXPosition) {
        xPosition = maxXPosition;
    }
    
    // Center buttons vertically in the item
    int yPosition = rect.top() + (rect.height() - buttonHeight) / 2;
    
    // Ensure Y position is within bounds
    if (yPosition < rect.top()) {
        yPosition = rect.top() + 2;
    }
    if (yPosition + buttonHeight > rect.bottom()) {
        yPosition = rect.bottom() - buttonHeight - 2;
    }
    
    // Apply position with proper parent coordinate mapping
    QPoint globalPos = mediaList->mapToParent(QPoint(xPosition, yPosition));
    buttonsContainer->setGeometry(globalPos.x(), globalPos.y(), buttonWidth, buttonHeight);
    buttonsContainer->show();
    buttonsContainer->raise(); // Ensure buttons are on top
}

// In MainPage.cpp - Improve showActionButtons method
void MainPage::showActionButtons(int row) {
    // Hide any previously shown buttons
    hideActionButtons();
    
    if (row < 0 || row >= mediaList->count()) return;
    
    // Store current row
    currentSelectedRow = row;
    
    // Update button position
    updateButtonsPosition();
    
    // Ensure buttons are visible and properly styled
    buttonsContainer->show();
    buttonsContainer->raise();
    
    // Make sure buttons are enabled
    listEditButton->setEnabled(true);
    listDeleteButton->setEnabled(true);
}

// In MainPage.cpp - Add method to handle scroll events better
void MainPage::onScrollChanged() {
    // Only update if there are visible buttons and a selected row
    if (buttonsContainer->isVisible() && currentSelectedRow >= 0) {
        // Small delay to avoid excessive updates during rapid scrolling
        QTimer::singleShot(50, this, &MainPage::updateButtonsPosition);
    }
}

// In MainPage.cpp - Update setupUI() to improve button container setup
// Add this to the button container setup section:
void MainPage::setupUI() {
    // ... existing code ...
    
    // Improved button container setup
    buttonsContainer = new QWidget(mediaList);
    buttonsContainer->hide();
    buttonsContainer->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    buttonsContainer->setAutoFillBackground(true);
    
    QHBoxLayout* buttonsLayout = new QHBoxLayout(buttonsContainer);
    buttonsLayout->setContentsMargins(2, 2, 2, 2); // Reduced margins
    buttonsLayout->setSpacing(4); // Reduced spacing
    
    // Create buttons with improved styling
    listEditButton = new QPushButton();
    listEditButton->setToolTip("Modifica");
    listEditButton->setFixedSize(24, 24); // Slightly smaller
    QPixmap editIcon(":/Immagini/BottoneMatita.png");
    listEditButton->setIcon(QIcon(editIcon));
    listEditButton->setIconSize(QSize(14, 14));
    listEditButton->setStyleSheet(
        "QPushButton {"
        "   background-color: rgba(131, 187, 222, 0.9);" // Semi-transparent
        "   color: black;"
        "   border: 1px solid rgb(92, 92, 93);"
        "   border-radius: 12px;"
        "   font-size: 12px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: rgb(87, 163, 210);"
        "   border: 2px solid rgb(92, 92, 93);"
        "}"
    );
    
    listDeleteButton = new QPushButton();
    listDeleteButton->setToolTip("Rimuovi");
    listDeleteButton->setFixedSize(24, 24);
    QPixmap deleteIcon(":/Immagini/BottoneCestino.png");
    listDeleteButton->setIcon(QIcon(deleteIcon));
    listDeleteButton->setIconSize(QSize(16, 16));
    listDeleteButton->setStyleSheet(
        "QPushButton {"
        "   background-color: rgba(240, 107, 70, 0.9);" // Semi-transparent
        "   color: black;"
        "   border: 1px solid rgb(92, 92, 93);"
        "   border-radius: 12px;"
        "   font-size: 12px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: rgb(250, 81, 34);"
        "   border: 2px solid rgb(92, 92, 93);"
        "}"
    );
    
    buttonsLayout->addWidget(listEditButton);
    buttonsLayout->addWidget(listDeleteButton);
    
    // Connect signals
    connect(listEditButton, &QPushButton::clicked, this, &MainPage::onEditButtonClicked);
    connect(listDeleteButton, &QPushButton::clicked, this, &MainPage::onDeleteButtonClicked);
    
    // Connect selection change to hide buttons
    connect(mediaList, &QListWidget::currentRowChanged, this, &MainPage::hideActionButtons);
    
    // ... rest of existing code ...
}