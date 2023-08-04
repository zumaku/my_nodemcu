void start_scrolling(const char *text, int scrollSpeed) {
    int textWidth = u8g2.getStrWidth(text); // Hitung lebar teks

    if (xPos <= -textWidth) {
        xPos = SCREEN_WIDTH;
    }

    u8g2.clearBuffer();
    u8g2.setCursor(xPos, SCREEN_HEIGHT / 2); // Atur posisi teks di tengah layar
    u8g2.print(text);
    u8g2.sendBuffer();

    xPos -= scrollSpeed;
}

void display_text(){
    if(textFromClient != "" && speedFromClient != 0){   // Jika ada pesan dari server dan kecepatannya
        u8g2.setFont(u8g2_font_ncenB12_tr); // Pilih font dan ukuran
        u8g2.firstPage();
        do {
            unsigned long currentMillis = millis();
            if (currentMillis - prevMillis >= 50) { // Ubah nilai delay di sini
                prevMillis = currentMillis;
                start_scrolling(textFromClient.c_str(), speedFromClient);
            }
        } while ( u8g2.nextPage() );
    } else{     // Tapi jika tidak ada
        do {
            String localIP = "http://";
            localIP += WiFi.localIP().toString();
            const char* localIPChar = localIP.c_str();

            u8g2.setFont(u8g2_font_ncenB12_tr); // Pilih font dan ukuran
            u8g2.firstPage();
            u8g2.drawStr(5, 30, "Server run!");
            u8g2.setFont(u8g2_font_ncenB08_tr); // Ganti ukuran font
            u8g2.drawStr(7, 45, localIPChar);
        } while ( u8g2.nextPage() );
    }
    
}
