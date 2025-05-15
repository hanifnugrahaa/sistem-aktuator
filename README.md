# Sistem Aktuator: Simulasi Kendali Mobil dan Pesawat

## Deskripsi
Repository ini berisi kumpulan program yang saya kerjakan untuk keperluan tugas praktikum mata kuliah sistem aktuator.

### 1. Simulasi Kendali Mobil
- Deskripsi: Kontrol servo setir dan BLDC motor menggunakan tombol dan potensiometer.
- Komponen: Servo motor, ESC, tombol, potensiometer.
- Fitur: Toggle motor dengan tombol, kemudi dikendalikan potensiometer.

#### File
- `simulasi_kendali_mobil/kendali_mobil_servo_bldc.ino`: Program Arduino untuk kendali mobil.

#### Cara Menggunakan
1. Buka file `kendali_mobil_servo_bldc.ino` di Arduino IDE.
2. Pilih board dan port yang sesuai dengan mikrokontroler Anda.
3. Upload program ke board Arduino.
4. Uji pergerakan mobil dengan menggunakan input yang telah diprogram.

---

### 2. Simulasi Kendali Pesawat
- Deskripsi: Simulasi pesawat mini dengan kontrol aileron dan rudder secara otomatis, serta kontrol throttle via potensiometer.
- Komponen: 2 Servo, potensiometer, BLDC motor.
- Fitur: Gerakan servo otomatis tiap 2 detik, kecepatan motor dari potensiometer.

#### File
- `simulasi_kontrol_pesawat/kontrol_pesawat.ino`: Program Arduino untuk kendali pesawat.

#### Cara Menggunakan
1. Buka file `kontrol_pesawat.ino` di Arduino IDE.
2. Pilih board dan port yang sesuai dengan mikrokontroler Anda.
3. Upload program ke board Arduino.
4. Uji kendali pesawat dengan memonitor pergerakan instruksi yang diprogram.

---

## Catatan
Setiap folder berisi file `.ino` untuk masing-masing proyek. Kode ditulis dan diuji menggunakan Arduino IDE.

---

Silakan eksplorasi tiap folder untuk detail lebih lanjut dari masing-masing program.
