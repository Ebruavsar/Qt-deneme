# Qt ile Bağlantılar Kurma 
Uygulama	 kullanıcının	 tıklayıp	 programdan	çıkabileceği	 bir	 butondan	 oluşuyor

## Kod Yazma

   `main.cpp` dosyasını açın ve aşağıdaki kodu ekleyin:
    ```cpp
    
       #include <QApplication>
       #include <QPushButton>
       
       int main(int argc, char *argv[])
       {
       
           QApplication app(argc, argv);
           QPushButton *button = new QPushButton("Quit");
           QObject::connect(button, SIGNAL(clicked()),
                              &app, SLOT(quit()));
           button->show();
           return app.exec();
       }


![image](https://github.com/Ebruavsar/Qt-deneme/assets/73585933/43af4de9-50cd-4928-9245-db5fb3c48648)

Qt	 parçacıkları	 bir	 kullanıcı	 eylemini	 ya	 da	 ortaya	 çıkan	 bir	 durum	 değişikliğini	 işaret	 etmek	 için	
sinyaller(signal)	 yayar. Örneğin,	 QPushButton kullanıcı	 butona	 tıkladığında	 bir	 clicked() sinyali	
yayar.	Bir	sinyal	bir	yuvaya bağlanmış	olabilir,	böylece	bir	sinyal	yayıldığında,	yuva	otomatik	olarak	yürütülür.	
Bizim	örneğimizde,	butonun	clicked() sinyalini	QApplication nesnesinin	quit() yuvasına	bağladık.	

## Projeyi Derleyip Çalıştırma
1. `Build` menüsünden `Build Project`'i seçin veya `Ctrl+B` tuşlarına basın.
2. `Run` menüsünden `Run`'ı seçin veya `Ctrl+R` tuşlarına basın.


