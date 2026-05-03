# SoftITO Akademi — Gömülü Yazılım Geliştirici Eğitimi

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![STM32](https://img.shields.io/badge/STM32-03234B?style=for-the-badge&logo=stmicroelectronics&logoColor=white)
![CLion](https://img.shields.io/badge/CLion-000000?style=for-the-badge&logo=clion&logoColor=white)

**320 saatlik yoğun eğitim sonunda başarıyla tamamlandı.**

*İstanbul Ticaret Odası — SoftITO Yazılım-Bilişim Akademisi*

</div>

---

## 📌 İçindekiler

- [Eğitim Hakkında](#-eğitim-hakkında)
- [Eğitim Müfredatı](#-eğitim-müfredatı)
  - [1. Mikrodenetleyiciler](#1-mikrodenetleyiciler)
  - [2. Gömülü Sistemler](#2-gömülü-sistemler)
  - [3. Devre Elemanları](#3-devre-elemanları)
  - [4. İleri C / C++](#4-i̇leri-c--c)
  - [5. STM32](#5-stm32)
  - [6. Proje Geliştirme Süreci](#6-proje-geliştirme-süreci)
- [Depo Yapısı](#-depo-yapısı)
- [Klasör Detayları](#klasör-detayları)
- [Kullanılan Teknolojiler ve Araçlar](#-kullanılan-teknolojiler-ve-araçlar)
- [Geliştirme Ortamı Kurulumu](#-geliştirme-ortamı-kurulumu)
- [SoftITO Akademi Hakkında](#softito-akademi-hakkında)

---

## 🏆 Eğitim Hakkında

| Bilgi | Detay |
|---|---|
| **Kurum** | SoftITO Yazılım-Bilişim Akademisi |
| **Kurucu** | İstanbul Ticaret Odası |
| **Program** | Gömülü Sistemler ve Yazılımlar |
| **Toplam Süre** | 320 Saat |
| **Durum** |  Başarıyla Tamamlandı |

Bu repository, **İstanbul Ticaret Odası** tarafından kurulan **SoftITO Yazılım-Bilişim Akademisi**'nin *Gömülü Sistemler ve Yazılımlar* programı kapsamında gerçekleştirilen tüm uygulamalı çalışmaları, ders notlarını, sınav projelerini ve bitirme makalesini barındırmaktadır.

320 saatlik yoğun eğitim boyunca teorik bilgi ve sahada uygulamalı deneyim bir arada kazanılmıştır.

---

## 📚 Eğitim Müfredatı

### 1. Mikrodenetleyiciler

Gömülü sistemlerin kalbi olan mikrodenetleyiciler; mimarisi, çevre birimleri ve programlanması açısından derinlemesine ele alınmıştır.

**Kapsanan Konular:**

- **Mikrodenetleyici Mimarisi:** Harvard ve Von Neumann mimarileri, CPU yapısı, ALU, register dosyaları
- **Bellek Türleri:** Flash (program belleği), SRAM (veri belleği), EEPROM ve bunların adresleme yöntemleri
- **Çevre Birimleri (Peripherals):**
  - **GPIO (General Purpose Input/Output):** Pin yapılandırması, push-pull / open-drain modları, pull-up ve pull-down dirençleri
  - **Timer/Counter:** Temel sayıcı işlemleri, PWM üretimi, Input Capture, Output Compare modları
  - **ADC (Analog-Dijital Çevirici):** Örnekleme hızı, çözünürlük, referans gerilimi, çok kanallı okuma
  - **UART / USART:** Seri haberleşme protokolü, baud rate hesaplama, senkron/asenkron modlar
  - **SPI (Serial Peripheral Interface):** Master-slave yapısı, CPOL/CPHA ayarları, tam çift yönlü haberleşme
  - **I²C (Inter-Integrated Circuit):** Adres çerçeveleme, ACK/NACK mekanizması, çoklu slave yönetimi
  - **DMA (Direct Memory Access):** CPU'yu devre dışı bırakarak bellek-bellek / çevre birim-bellek transferi
  - **Watchdog Timer:** Sistem donmalarına karşı yazılım güvenilirliği
  - **RTC (Real-Time Clock):** Gerçek zamanlı saat/takvim uygulamaları
- **Kesme Mimarisi (Interrupt):** NVIC yapısı, öncelik seviyeleri, IRQ handler yazımı, vektör tablosu
- **Güç Yönetimi:** Uyku modları (Sleep, Stop, Standby), düşük güç tasarım teknikleri

---

### 2. Gömülü Sistemler

Gömülü sistem tasarımının teorik ve pratik boyutlarını kapsayan bu modül; donanım-yazılım entegrasyonunu, gerçek zamanlı kısıtları ve endüstriyel uygulama gereksinimlerini ele almaktadır.

**Kapsanan Konular:**

- **Gömülü Sistem Temelleri:**
  - Genel amaçlı bilgisayarlar ile gömülü sistemler arasındaki temel farklar
  - Gerçek zamanlı (real-time) kavramı: Sert (hard) ve yumuşak (soft) gerçek zamanlı sistemler
  - Deterministik davranış ve zamanlama kısıtları
- **Donanım-Yazılım Arayüzü:**
  - Register seviyesinde programlama (HAL'siz doğrudan erişim)
  - Memory-mapped I/O kavramı
  - Bit manipülasyonu: `|=`, `&=`, `^=`, `~` operatörleri ile donanım kontrol
- **Haberleşme Protokolleri (Uygulama Düzeyi):**
  - Sensör ve aktüatörlerle seri / paralel iletişim
  - CAN (Controller Area Network) temel kavramları — otomotiv ve endüstriyel uygulamalar
  - RS-232, RS-485 fiziksel katmanlar
- **RTOS (Gerçek Zamanlı İşletim Sistemi) Temelleri:**
  - Görev (task) kavramı, zamanlayıcı (scheduler) türleri: preemptive / cooperative
  - Semafor, mutex, kuyruk (queue) ile görevler arası iletişim ve senkronizasyon
  - FreeRTOS üzerinde temel uygulama örnekleri
- **Bootloader ve Firmware:**
  - Firmware yükleme süreçleri (ST-Link, UART bootloader)
  - OTA (Over-the-Air) güncelleme kavramı
- **Gömülü Sistemlerde Güvenlik:**
  - Stack overflow koruması, watchdog mekanizmaları, güvenli bellek yönetimi

---

### 3. Devre Elemanları

Elektronik donanımı anlayabilmek ve devre şemalarını okuyabilmek için gereken temel ve ileri elektronik bilgisi bu modülde aktarılmıştır.

**Kapsanan Konular:**

- **Pasif Devre Elemanları:**
  - **Direnç (Resistor):** Renk kodu okuma, güç hesabı (P = I²R), seri/paralel bağlantı, pull-up/pull-down uygulamaları
- **Sensör ve Aktüatörler:**
  - Sıcaklık sensörleri: NTC termistör, LM35, DS18B20 (1-Wire protokolü)
  - Nem sensörü: DHT11 / DHT22 veri protokolü
  - Mesafe sensörü: HC-SR04 ultrasonik — zaman aralığı ölçümü ile mesafe hesabı
  - Basınç sensörü: BMP280 — I²C / SPI ile barometrik ölçüm
  - Servo motor: PWM sinyali ile açı kontrolü
  - Adım motoru (Stepper): Step/Direction kontrolü, mikro-adım sürme
- **Devre Okuma ve Tasarım:**
  - Şematik semboller ve standartlar
  - Breadboard prototipleme teknikleri

---

### 4. İleri C / C++

Gömülü sistemlerde kullanılan C ve C++ dilinin derinlemesine incelendiği bu modül, düşük seviyeli donanım kontrolünden nesne yönelimli gömülü yazılıma kadar geniş bir yelpazede konuları kapsamaktadır.

**C Dili İleri Konuları:**

- **Pointer ve Bellek Yönetimi:**
  - Pointer aritmetiği, çok kademeli pointer (`**ptr`), fonksiyon pointer'ları
  - `malloc`, `calloc`, `realloc`, `free` — dinamik bellek yönetimi
  - Bellek sızıntısı (memory leak) tespiti ve önlenmesi
  - Stack vs Heap ayrımı ve gömülü sistemlerdeki önemi
- **Donanım Erişimi için C Teknikleri:**
  - `volatile` — derleyici optimizasyonunu engelleme, donanım register okuma
  - `const` ile salt okunur sabitler ve flash'ta saklama
  - `static` ile kapsam kontrolü ve kalıcı yerel değişkenler
  - Bit alanları (`bit fields`) ile register modelleme
  - `union` ile aynı bellek bölgesine farklı tipte erişim
- **Önişlemci (Preprocessor) İleri Kullanım:**
  - Fonksiyon benzeri makrolar: `#define MAX(a,b) ((a)>(b)?(a):(b))`
  - Koşullu derleme: `#ifdef`, `#ifndef`, `#if defined`
  - `#pragma` direktifleri (pack, optimize)
---

### 5. STM32

STMicroelectronics'in ARM Cortex-M tabanlı STM32 serisi mikrodenetleyiciler, endüstriyel gömülü geliştirmenin standartlarından biri olup bu modülde hem teorik hem de kapsamlı uygulama çalışmaları gerçekleştirilmiştir.

**Kapsanan Konular:**

- **STM32 Ailesi ve Mimarisi:**
  - STM32F0/F1/F4 serilerinin karşılaştırması ve özellik matrisi
  - ARM Cortex-M0 / M3 / M4 çekirdek mimarisi
  - CMSIS (Cortex Microcontroller Software Interface Standard)
- **Geliştirme Ortamı:**
  - **STM32CubeIDE:** Proje oluşturma, pin konfigürasyonu, clock tree yapılandırması
  - **STM32CubeMX:** Grafiksel pin/clock/middleware yapılandırması ve otomatik kod üretimi
  - **STM32CubeProgrammer:** Firmware flash yükleme, bellek okuma/yazma
  - **ST-Link/V2:** JTAG/SWD üzerinden debug ve programlama
- **HAL (Hardware Abstraction Layer) Kütüphanesi:**
  - `HAL_GPIO_WritePin / ReadPin / TogglePin`
  - `HAL_UART_Transmit / Receive` (polling, interrupt, DMA modları)
  - `HAL_I2C_Master_Transmit / Receive`
  - `HAL_SPI_TransmitReceive`
  - `HAL_TIM_PWM_Start`, `HAL_TIM_Base_Start_IT`
  - `HAL_ADC_Start`, `HAL_ADC_PollForConversion`
- **Uygulamalı Projeler:**
  - GPIO ile LED kontrolü, buton interrupt'ı ile olay güdümlü programlama
  - TIM ile PWM üretimi — servo motor ve LED parlaklık kontrolü
  - UART ile PC terminal üzerinden çift yönlü haberleşme
  - I²C ile DHT/BMP sensöründen sıcaklık-nem okuma ve OLED ekranda gösterme
  - SPI ile harici EEPROM / Flash bellek okuma-yazma
  - ADC ile potansiyometre ve analog sensör okuma
  - DMA ile yüksek hızlı, kesme gerektirmeyen veri transferi
  - FreeRTOS görev yönetimi — çoklu görevle eşzamanlı sensör okuma ve motor kontrolü
- **Debug ve Test Tekniği:**
  - Breakpoint, watch window, live expressions kullanımı
  - SWV (Serial Wire Viewer) ile gerçek zamanlı log izleme
  - Logic analyzer ile dijital protokol analizi

---

### 6. Proje Geliştirme Süreci

Bireysel teknik becerilerin ötesine geçerek endüstriyel yazılım geliştirme süreçlerini ve proje yönetimi pratiğini kazandırmayı hedefleyen bu modül, akademi eğitiminin olgunlaşma aşamasını temsil etmektedir.

**Kapsanan Konular:**

- **Yazılım Geliştirme Yaşam Döngüsü (SDLC):**
  - Gereksinim analizi ve teknik şartname hazırlama
  - Sistem tasarımı: blok diyagramlar, akış şemaları, FSM diyagramları
  - Kodlama → Birim test → Entegrasyon testi → Sistem testi adımları
  - Doxygen stili yorum blokları ile dokümantasyon standartları
- **Versiyon Kontrol (Git & GitHub):**
  - `git init`, `add`, `commit`, `push`, `pull`, `clone` temel iş akışı
  - Branch stratejisi: `main` / `develop` / `feature/*` yapısı
  - Merge ve rebase farkları, conflict çözümü
  - `.gitignore` ile derleme çıktıları ve IDE dosyalarını hariç tutma
- **Modüler Yazılım Mimarisi:**
  - Header (.h) ve kaynak (.c) dosya ayrımı
  - Sürücü (driver) katmanı — uygulama katmanı ayrımı
  - CMakeLists.txt ile çok dosyalı proje yapılandırması
- **Hata Ayıklama ve Test:**
  - Birim testi prensiplerinin gömülü sistemlere uygulanması
  - Assert ve hata kodları ile sağlam (robust) yazılım tasarımı
  - Donanımsal test ekipmanları: osiloskop, multimetre, logic analyzer
- **Bitirme Projesi:**
  - Proje fikri geliştirme ve fizibilite değerlendirmesi
  - Donanım tasarımı ve komponent seçimi
  - Yazılım mimarisi ve modül dağılımı
  - Akademik makale formatında teknik dokümantasyon
  - Proje sunumu ve değerlendirme

---

## 🗂 Depo Yapısı

```
SoftITO_Akademi/
│
├── 📁 Notlar/                      # Ders notları ve teorik materyaller
├── 📁 clion/                       # CLion IDE ile yazılan C/C++ uygulamaları
├── 📁 sinav/                       # Sınav projeleri ve değerlendirme çalışmaları
├── 📄 Bitirme_Proje_Makalesi.pdf   # Akademi bitirme projesi makalesi (456 KB)
└── 📄 README.md                    # Bu dosya
```

---

## Klasör Detayları

### Notlar

Eğitim boyunca tutulan kapsamlı **ders notlarını** barındırır. Teorik konuların özetleri, formüller, diyagramlar ve referans bilgileri bu klasörde derlenmiştir.

Notların kapsadığı başlıca alanlar:

- Mikrodenetleyici register haritaları ve datasheet özetleri
- C dilinde donanım programlama teknikleri ve örnek kod parçaları
- STM32 HAL fonksiyon referansları ve kullanım notları
- Devre elemanları hesap formülleri (PWM duty cycle, gerilim bölücü vb.)
- Haberleşme protokolleri zaman diyagramları (I²C, SPI, UART frame yapısı)
- RTOS kavramları: görev yönetimi, semafor ve kuyruk kullanım örnekleri

---

### clion

**JetBrains CLion IDE** üzerinde geliştirilen C/C++ uygulama projelerini içerir. Her proje CMake tabanlı yapılandırmayla organize edilmiştir. Bu klasör, eğitim sürecinin pratik programlama boyutunu yansıtır.

Yer alan uygulama kategorileri:

- **Temel C Alıştırmaları:** Pointer, dinamik bellek, string işlemleri, dosya I/O
- **Veri Yapısı Uygulamaları:** Bağlı liste, dairesel tampon, yığın (stack), kuyruk (queue)
- **Algoritma Çalışmaları:** Sıralama (Bubble, Selection, Quick Sort), ikili arama, özyineleme
- **Durum Makinesi Tasarımı:** FSM tabanlı kontrol mantığı örnekleri
- **Donanım Simülasyonu:** Mikrodenetleyici register yapısını `struct` ve `union` ile modelleme
- **C++ Sınıf Tasarımları:** Sensör ve aktüatör soyutlama sınıfları, kalıtım örnekleri

---

### sinav

Eğitim süreci boyunca gerçekleştirilen **sınav ve değerlendirme projelerini** içerir. Birden fazla modülden edinilen bilgilerin bir arada kullanılmasını gerektiren bütünleşik uygulamalardır.

Bu klasördeki çalışmaların özellikleri:

- Zaman kısıtlı problem çözme becerisini yansıtır
- Birden fazla konuyu aynı anda kullanır (örn. pointer + struct + dosya I/O)
- Algoritmik düşünce yeteneğini ölçmeye yönelik tasarlanmıştır
- Gömülü sistem senaryolarını simüle eden konsol tabanlı uygulamalar içerir
- Kod kalitesi, okunabilirlik ve yorum satırları açısından değerlendirilmiştir

---

### Bitirme Proje Makalesi

| Özellik | Bilgi |
|---|---|
| **Dosya Adı** | `Bitirme_Proje_Makalesi.pdf` |
| **Boyut** | 456 KB |
| **Format** | PDF (Akademik Makale) |

320 saatlik eğitimin bitiş noktasını temsil eden bu makale, kazanılan tüm teknik bilgi ve becerilerin sistematik biçimde derlendiği akademik bir çalışmadır.

Makalenin genel yapısı:

1. **Özet / Abstract** — Projenin kısa tanıtımı
2. **Giriş** — Problem tanımı, motivasyon ve projenin kapsamı
3. **Sistem Tasarımı** — Donanım ve yazılım mimarisinin anlatımı
4. **Donanım Bileşenleri** — Kullanılan mikrodenetleyici, sensörler ve devre elemanları
5. **Yazılım Geliştirme** — Kodlama yaklaşımı, kütüphaneler, akış diyagramları
6. **Test ve Sonuçlar** — Deneysel ölçümler ve karşılaştırmalı sonuçlar
7. **Tartışma ve Gelecek Çalışmalar** — İyileştirme önerileri
8. **Kaynakça** — Atıfta bulunulan datasheet'ler, makaleler ve kitaplar

---

## 🛠 Kullanılan Teknolojiler ve Araçlar

### Yazılım Dilleri

| Dil | Kullanım Oranı | Amaç |
|---|---|---|
| **C** | %98.6 | Ana gömülü sistem programlama dili |
| **C++** | İleri modül | Nesne yönelimli donanım soyutlama |
| **CMake** | Yapılandırma | Çok dosyalı derleme yönetimi |

### IDE ve Geliştirme Ortamları

| Araç | Amaç |
|---|---|
| **JetBrains CLion** | C/C++ geliştirme ve hata ayıklama |
| **STM32CubeIDE** | STM32 mikrodenetleyici geliştirme |
| **STM32CubeMX** | Grafik pin/clock yapılandırması ve kod üretimi |
| **STM32CubeProgrammer** | Firmware yükleme ve bellek yönetimi |

### Donanım Platformu

| Donanım | Amaç |
|---|---|
| **STM32 Geliştirme Kartı** | Ana mikrodenetleyici platformu |
| **ST-Link/V2** | SWD/JTAG debug ve programlama |
| **Breadboard & Devre Kiti** | Prototipleme |
| **Logic Analyzer** | Dijital protokol analizi |
| **Multimetre / Osiloskop** | Elektriksel ölçüm ve doğrulama |

### Versiyon Kontrol

| Araç | Amaç |
|---|---|
| **Git** | Yerel versiyon kontrolü |
| **GitHub** | Uzak depo ve proje yönetimi |

---

## 💻 Geliştirme Ortamı Kurulumu

### Repoyu Klonlama

```bash
git clone https://github.com/Feyat/SoftITO_Akademi.git
cd SoftITO_Akademi
```

### CLion Projeleri için

1. JetBrains CLion'u açın
2. `File > Open` menüsünden `clion/` klasörü içindeki ilgili projeyi seçin
3. CMake yapılandırması otomatik yüklenecektir
4. `Build > Build Project` ile derleyin

### Tek Dosya Manuel Derleme

```bash
# C dosyası derleme
gcc -std=c99 -Wall -Wextra -o program dosya.c

# C++ dosyası derleme
g++ -std=c++17 -Wall -Wextra -o program dosya.cpp

# Çalıştırma (Linux/macOS)
./program

# Çalıştırma (Windows)
program.exe
```

### Gereksinimler

```
GCC 9.0+        C derleyicisi
G++ 9.0+        C++ desteği
CMake 3.15+     Proje yapılandırması
CLion           Önerilen IDE
```

---

## SoftITO Akademi Hakkında

**SoftITO Yazılım-Bilişim Akademisi**, İstanbul Ticaret Odası tarafından kurulan bir marka projesidir. Yazılım ve bilişim alanında endüstri odaklı, uygulamalı eğitimler sunan akademi; öğrencileri gerçek iş dünyasına hazırlamayı hedeflemektedir.

- **Web:** [akademi.softito.com.tr](https://akademi.softito.com.tr)
- **Instagram:** [@softitoakademi](https://www.instagram.com/softitoakademi/)
- **LinkedIn:** [SoftITo Yazılım-Bilişim Akademisi](https://tr.linkedin.com/company/softitoakademi)

---

<div align="center">

*320 saatlik Gömülü Sistemler ve Yazılımlar eğitimi — SoftITO Akademi, İstanbul*

**Mikrodenetleyiciler · Gömülü Sistemler · Devre Elemanları · İleri C/C++ · STM32 · Proje Geliştirme**

</div>    
