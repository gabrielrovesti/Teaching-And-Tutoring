// MainPage.h - Updated header with new methods and const correctness
#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QGroupbox>
#include <QResizeEvent>
#include <QPixmap>
#include <QSizePolicy>
#include <QCheckBox>
#include <QListWidgetItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QFile>
#include "AddPage.h"
#include "../../Modello logico/Headers/Media.h"
#include "../../Modello logico/Headers/Biblioteca.h"

class MainPage : public QWidget {
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr, Biblioteca* biblioteca = nullptr);
    void onMediaSelected(QListWidgetItem *item);
    void setCurrentFile(const QString& filePath);
    void setLibraryInfo(bool isNew, bool hasChanges); 
    void resetUnsavedChanges();
    void setHasUnsavedChanges(bool hasChanges);

public slots:
    void onBackButtonClicked();  
    void onMediaTypeChanged(); 
    void onApplyFiltersClicked(); 
    void onClearFiltersClicked(); 
    void onAddMediaButtonClicked(); 
    void onBorrowButtonClicked(); 
    void onEditButtonClicked(); 
    void onDeleteButtonClicked(); 
    void onNewMediaCreated(Media* newMedia); 
    void onMediaEdited(); 
    void onSearchTextChanged(const QString& searchText);
    void onScrollChanged();
    void onSaveButtonClicked(); 
    void onSaveAsButtonClicked(); 
    
    // New performance-optimized slots
    void performMediaSelection(QListWidgetItem *item);
    void performResize();

signals:
    void goToChoicePage(); 
    void goToLoginPage(); 
    void goToAddPage(); 
    void goToModifyPage(Media* media); 
    void goToDetailsPage(Media* media); 
    void borrowMedia(Media* media); 
    void libraryModified(); 
    void unsavedChangesUpdated(bool hasChanges);

private:
    // UI Components
    QPushButton *backButton;
    QPushButton *addMediaButton;

    // Filter components
    QComboBox *mediaTypeComboBox;
    QComboBox *genreComboBox;
    QLineEdit *minYearLineEdit;
    QLineEdit *maxYearLineEdit;
    QLineEdit *ratingMinLineEdit;
    QLineEdit *ratingMaxLineEdit;
    QLineEdit *languageLineEdit;
    QPushButton *applyFiltersButton;
    QPushButton *clearFiltersButton;
    QCheckBox *availableCheckBox;

    // Media list components
    QLineEdit *searchBar;
    QListWidget *mediaList;
    int currentSelectedRow = -1;

    // Preview components
    QPixmap originalPixmap;
    QLabel *mediaImageLabel;
    QLabel *mediaInfoLabel;
    QPushButton *borrowButton;
    QPushButton *detailsButton;
    QLabel *mediaTitleLabel;
    QLabel *mediaAuthorLabel;
    QLabel *mediaYearLabel;
    QLabel *mediaRatingLabel;
    QPushButton *editMediaButton; 

    // Action buttons in list
    QPushButton* listEditButton;
    QPushButton* listDeleteButton;
    QWidget* buttonsContainer;

    // Layouts
    QVBoxLayout *mainLayout;
    QHBoxLayout *topBarLayout;
    QVBoxLayout *filtersLayout;
    QVBoxLayout *centerLayout;
    QVBoxLayout *previewLayout;
    QHBoxLayout *contentLayout;
    QGroupBox *filtersGroupBox;
    QGroupBox *previewGroupBox;

    // Data and state
    Biblioteca *biblioteca;
    QString currentFilePath;
    bool hasCurrentFile;
    bool isNewLibrary;
    bool hasUnsavedChanges;

    // Helper methods - performance optimized
    void setupUI();
    void updateGenreComboBox();
    void updateMediaList(const vector<Media*>& listaFiltrata); // Made const-correct
    void updateMediaPreview(Media* const media); // New method for preview update
    void loadImageAsync(const string& imagePath); // New async image loading
    void setDefaultImage(); // New method for default image handling
    
    // Button management methods
    void showActionButtons(int row);
    void hideActionButtons();
    void updateButtonsPosition();
    
    // File operations
    void onDetailsButtonClicked();
    void saveToFile(const QString& filePath); 
    void updateSaveButtonsState();

protected:
    void resizeEvent(QResizeEvent* event) override;
    void updateImageSize();
};

#endif // MAINPAGE_H