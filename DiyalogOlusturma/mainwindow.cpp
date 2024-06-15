#include "mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // QLabel ve QLineEdit oluşturulması
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    // QCheckBox oluşturulması
    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    // QPushButton oluşturulması
    findButton = new QPushButton(tr("&Find"));
    closeButton = new QPushButton(tr("Close"));

    // Find butonunun başlangıçta devre dışı bırakılması
    findButton->setDefault(true);
    findButton->setEnabled(false);

    // Sinyaller ve slotlar arasında bağlantı kurulması
    connect(lineEdit, &QLineEdit::textChanged, this, &MainWindow::enableFindButton);
    connect(findButton, &QPushButton::clicked, this, &MainWindow::findClicked);
    connect(closeButton, &QPushButton::clicked, this, &MainWindow::close);

    // Layout ayarları
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(label);
    topLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    // Merkezi bir widget oluşturun ve layout'u buna set edin
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    setWindowTitle(tr("Find"));
}

// Yıkıcı tanımlaması
MainWindow::~MainWindow()
{
    // Bu kısımda kaynakları temizleyebilirsiniz
}

void MainWindow::findClicked()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void MainWindow::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
