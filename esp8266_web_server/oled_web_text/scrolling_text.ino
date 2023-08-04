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
    u8g2.setFont(u8g2_font_ncenB12_tr); // Pilih font dan ukuran
    u8g2.firstPage();
    do {
    unsigned long currentMillis = millis();
        if (currentMillis - prevMillis >= 50) { // Ubah nilai delay di sini
            prevMillis = currentMillis;
            start_scrolling(textFromClient.c_str(), 1);
        }
    } while ( u8g2.nextPage() );
}
