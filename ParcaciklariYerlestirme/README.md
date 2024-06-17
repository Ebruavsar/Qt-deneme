# Qt ile Bağlantılar Kurma

Bu proje, kullanıcının bir `QSpinBox` ve `QSlider` kullanarak bir yaş değeri girebileceği bir Qt uygulamasını içermektedir. Bu widget'lar birbirine bağlıdır, bu yüzden birinde yapılan değişiklik diğerine yansır.

## Kod Yazma

`main.cpp` dosyasını açın ve aşağıdaki kodu ekleyin:

  ```cpp
    #include <QApplication>
    #include <QHBoxLayout>
    #include <QSlider>
    #include <QSpinBox>
    
    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
    
        QWidget *window = new QWidget;
        window->setWindowTitle("Enter Your Age");
    
        QSpinBox *spinBox = new QSpinBox;
        QSlider *slider = new QSlider(Qt::Horizontal);
        spinBox->setRange(0, 130);
        slider->setRange(0, 130);
    
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
        QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        spinBox->setValue(35);
    
        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(spinBox);
        layout->addWidget(slider);
        window->setLayout(layout);
    
        window->show();
    
        return a.exec();
    }

```
## Kodun Açıklaması
### Başlık Dosyaları Ekleme:
```cpp
    #include <QApplication>
    #include <QHBoxLayout>
    #include <QSlider>
    #include <QSpinBox>
```
Bu başlık dosyaları, Qt uygulamaları geliştirmek için gerekli sınıfları içerir:

- **`QApplication`: Qt uygulamasını oluşturmak ve çalıştırmak için gerekli.
- **`QHBoxLayout`: Widget'ları yatay olarak düzenlemek için kullanılan layout sınıfı.
- **`QSlider`: Kayan çubuk widget'ı.
- **`QSpinBox`: SpinBox widget'ı.

### main Fonksiyonu ve QApplication Nesnesi:
 ```cpp
    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
```
`main` fonksiyonu, programın giriş noktasıdır. `QApplication a(argc, argv);` ifadesi, Qt uygulaması için gerekli olan QApplication nesnesini oluşturur.

### Pencere Oluşturma ve Başlık Ayarlama:
  ```cpp
        QWidget *window = new QWidget;
        window->setWindowTitle("Enter Your Age");
```
Bir QWidget nesnesi oluşturuluyor ve bu pencerenin başlığı "Enter Your Age" olarak ayarlanıyor.

### QSpinBox ve QSlider Oluşturma ve Ayarlama:
 ```cpp
        QSpinBox *spinBox = new QSpinBox;
        QSlider *slider = new QSlider(Qt::Horizontal);
        spinBox->setRange(0, 130);
        slider->setRange(0, 130);
```
Bir `QSpinBox` ve yatay bir `QSlider` oluşturuluyor. Her iki widget'ın da değer aralığı 0 ile 130 arasında ayarlanıyor.

### Sinyal ve Yuva Bağlantıları Kurma:

  ```cpp
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
        QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        spinBox->setValue(35);
```
`spinBox` ve `slider` arasında iki yönlü bir bağlantı kurulur:

- **`spinBox` değeri değiştiğinde, bu değer `slider`'a ayarlanır.
- **`slider` değeri değiştiğinde, bu değer `spinBox`'a ayarlanır.
Başlangıç değeri `spinBox` için 35 olarak ayarlanır ve bu değer `slider`'a da yansıtılır.

### Layout Oluşturma ve Widget'ları Ekleyip Pencereye Atama:

  ```cpp
        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(spinBox);
        layout->addWidget(slider);
        window->setLayout(layout);
```
Yatay bir `QHBoxLayout` oluşturuluyor ve `spinBox` ile `slider` bu layout'a ekleniyor. Ardından layout, pencereye (window) atanıyor.
### Pencereyi Gösterme:

  ```cpp
        window->show();
```
### Uygulama Döngüsüne Girme:

  ```cpp
        return a.exec();
```
Qt uygulaması çalıştırılıyor ve olay döngüsüne giriliyor. Bu, uygulamanın kullanıcı etkileşimlerine yanıt vermesini sağlar.

---
Bu adımları izlediğinizde, kullanıcı "Enter Your Age" başlıklı bir pencere görecek ve `QSpinBox` ile `QSlider` kullanarak yaşını ayarlayabilecektir.
