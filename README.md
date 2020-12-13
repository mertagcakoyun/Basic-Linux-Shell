# Basic-Linux-Shell
A Basic Linux Shell programmed by C Language
<h3>Proje Konusu:</h3>
Projede temel bir linux shell programı yazıldı. Bu shell programının kendine özgü komutları, yanıtları, hata çıktıları tasarlandı. Proje kapsamında; toplama, çıkarma işlemleri, girilen değeri istediğimiz kadar ekrana yazdıran tekrar islemi, proje dizininde bulunan dosyaların herhangi birinin içindekileri (kod / metin vs.) görüp inceleyebileceğimiz cat komutu, terminali tamamen silen clear komutu ve terminalden çıkılmasını sağlayan bir exit komutu implemente edilmesi hedeflenmiştir.
<h3>Bilinmesi Gerekenler</h3>
<h4>-Shell nedir?</h4>
İşletim sistemimizdeki shell ile; programları, dosya sistemlerini çalıştırabilir, bilgisayar kodunu derleyebilir yani bir sistemi işletebiliriz. Kısacası bilgisayarımızı en etkili şekilde yönetebiliriz. Shell (kabuk) Grafiksel kullanıcı arabiriminden (GUI) daha az sezgiseldir. Ancak doğru komutlar ve ne yaptığını bilenler için GUI den çok daha etkili kullanılabilir. Bu noktadan baktığımızda Kabuk basit şekliyle bir komut dili yorumlayıcısıdır.
<h4>Fork Nedir?</h4>
fork() komutu çalıştırıldığı anda çocuk (child), ve onu oluşturan process ise veli (parent) adını almaktadır. Çocuk yaratıldığı anda velinin hangi değişkeni var ise onun hepsinin kopyasını alır. Böylece çocuk velinin bulunduğu konumdan itibaren çalışır. fork() komutu çalıştırıldığı anda çocuk (child), ve onu oluşturan process ise veli (parent) adını almaktadır. Çocuk yaratıldığı anda velinin hangi değişkeni var ise onun hepsinin kopyasını alır ve bulunduğu konumdan itibaren çalışır.
<h3>Proje Açıklaması</h3>
Proje terminalde proje dizinine gidildikten sonra, “make” komutu ile derlenir ve ./myshell komutu ile çalıştırılabilir.
<h4>İslem</h4>
Projenin işlem komutunun altında iki farklı sınıf çalışmaktadır. Bunlardan biri topla diğeri çıkar argümanıdır. islem argümanından sonra hangi islemin yazıldığına göre çalışacak sınıfın seçimi gerçekleştirilir. Pipe / Uzun çizgi ( “ | ” ) sembolü ile birden çok komut sırasıyla çalıştırılabilir.
 
<h4>Tekrar</h4>
Tekrar komutunda kullanıcıdan alınan değerin kullanıcının istediği kadar ekrana yansıtılması hedeflenmiştir. Alınan ilk argüman tekrar sınıfının çalışmasını ikincisi hangi girdinin basılacağı üçüncüsü içe kaç kez basılacağını belirtir.

![1](https://github.com/mertagcakoyun/Basic-Linux-Shell/blob/main/images/islem-tekrar-komutlari.jpeg)
<h4>Cat</h4>
Cat komutuyla birlikte proje klasörünün dizininde bulunan dosyaların içeriği görülebilmektedir Kullanıcıların görüntülemek istediği dosyanın adını uzantısıyla birlikte verilmesi gerekmektedir. <br>

![2](https://github.com/mertagcakoyun/Basic-Linux-Shell/blob/main/images/cat-komutu.jpeg)
<h4>Exit</h4>
exit komutu ile projeden çıkılmaktadır. Girilen komutun içerisinde aşağıdaki şekilde görüldüğü gibi exit dışında bir girdi varsa bu kabul edilmemektedir. İçerik sadece exit ten oluşmalıdır.<br>

![3](https://github.com/mertagcakoyun/Basic-Linux-Shell/blob/main/images/exit-komutu.jpeg)
<h4>Clear</h4>
Clear komutu ile sonuç alınan bütün komutlar ve bunların çıktıları silinir. Temiz bir shell gösterilir.
