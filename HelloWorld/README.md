# Qt "Hello World" Uygulaması

Bu proje, Qt Creator kullanarak basit bir "Hello World" uygulaması oluşturmak için adım adım talimatlar içermektedir.

## Temel Kavramlar

### Qt'nin Yapısı ve Ana Bileşenleri
Qt, çeşitli modüllerden oluşur:

- **QtCore**: Temel sınıflar ve altyapı (örneğin, sinyaller ve yuvalar).
- **QtGui**: 2D grafik ve resim işleme.
- **QtWidgets**: Geleneksel masaüstü widget'ları.
- **QtQuick**: QML ile kullanıcı arayüzü oluşturma.
- **QtMultimedia**: Ses ve video işleme.

### Sinyaller ve Yuvalar (Signals and Slots)
Sinyaller ve yuvalar, Qt'nin olay tabanlı programlama modelinin temelini oluşturur. Bir sinyal, belirli bir olay gerçekleştiğinde yayılan bir mesajdır. Bir yuva, bu sinyali işleyen bir işlevdir.

## "Hello World" Uygulaması

### Adım 1: Yeni Proje Oluşturma
1. Qt Creator'u açın.
2. `File` menüsünden `New File or Project`'i seçin.
3. `Application` altında `Qt Widgets Application`'ı seçin ve `Choose...`'a tıklayın.
4. Projeye bir isim verin ve bir dizin seçin, ardından `Next`'e tıklayın.
5. Kit seçimini yapın (genellikle varsayılan kit seçili olarak gelir) ve `Next`'e tıklayın.
6. Sonraki adımları varsayılan ayarlarla geçerek `Finish`'e tıklayın.

### Adım 2: Arayüz Tasarımı
1. `mainwindow.ui` dosyasını açın.
2. Tasarım alanında bir `QPushButton` ekleyin.
3. Düğmenin metnini "Hello World" olarak ayarlayın.

### Adım 3: Kod Yazma
1. `mainwindow.h` dosyasını açın ve aşağıdaki kodu ekleyin:
    ```cpp
    private slots:
        void on_pushButton_clicked();
    ```
2. `mainwindow.cpp` dosyasını açın ve aşağıdaki kodu ekleyin:
    ```cpp
    void MainWindow::on_pushButton_clicked() {
        QMessageBox::information(this, "Hello", "Hello, World!");
    }
    ```
3. `mainwindow.ui` dosyasına dönün ve `QPushButton`'a tıklayın.
4. Sağ taraftaki `Signals and Slots` düzenleyicisinde, `clicked()` sinyalini `on_pushButton_clicked()` yuvasına bağlayın.

### Adım 4: Projeyi Derleyip Çalıştırma
1. `Build` menüsünden `Build Project`'i seçin veya `Ctrl+B` tuşlarına basın.
2. `Run` menüsünden `Run`'ı seçin veya `Ctrl+R` tuşlarına basın.

Bu adımları izlediğinizde, düğmeye tıkladığınızda bir mesaj kutusunda "Hello, World!" yazısını görmelisiniz.
