String handle_respont(String text, short speed, bool err = false){
    String send_html = "<!DOCTYPE html>";
    send_html += "<html lang='en'>";
    send_html += "<head>";
        send_html += "<meta charset='UTF-8'>";
        send_html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
        send_html += "<title>Berhasil Dikirim</title>";
        send_html += "<link href='https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css' rel='stylesheet' integrity='sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9' crossorigin='anonymous'>";
    send_html += "</head>";
    send_html += "<body>";
        send_html += "<div class='container text-center mt-5'>";
            send_html += "<div class='row align-items-start'>";
                send_html += "<div class='card'>";
                    send_html += "<div class='card-header'>Status</div>";
                    send_html += "<div class='card-body'>";
                        if(!err){
                            send_html += "<h5 class='card-title'>Pengiriman Berhasil!</h5>";
                            send_html += "<p class='card-text'>Anda mengirim:</p>";
                            send_html += "<p class='card-text'>\"" + text + "\"</p>";
                            send_html += "<p class='card-text'> Kecepatan Text: " + String(speed) + "</p>";
                            send_html += "<a href='/' class='btn btn-success'>Kembali</a>";
                        } else{
                            send_html += "<h5 class='card-title'>Pengiriman Gagal!</h5>";
                            send_html += "<h4>" + text + "</h4>";
                            send_html += "<a href='/' class='btn btn-danger'>Kembali</a>";
                        }
                    send_html += "</div>";
                send_html += "</div>";
            send_html += "</div>";
        send_html += "</div>";
    send_html += "</body>";
    send_html += "</html>";

    return send_html;
}

void bad_request_respont(){
    textFromClient = "Error Code: 400";
    server.send(200, "text/html", handle_respont(textFromClient, speedFromClient, true));
}

void handle_send(){
    String mySpeed;
    char *endPtr;

    if ( server.hasArg("textYgDikirim") && server.hasArg("speedYgDikirim") ) {
        textFromClient = server.arg("textYgDikirim");           // Mengambil value string pada input yang memiliki property name="textYgDikirim"
        mySpeed = server.arg("speedYgDikirim");          // Mengambil value string pada input yang memiliki property name="speedYgDikirim"
        speedFromClient = strtol(mySpeed.c_str(), &endPtr, 10); //Konfersi string ke short

        if( speedFromClient > 0 && speedFromClient < 5 ){       // Mengecek jika nilainya antara 1 - 4
            Serial.print("Received Text: ");
            Serial.println(textFromClient);
            Serial.print("Speed: ");
            Serial.println(String(speedFromClient));

            server.send(200, "text/html", handle_respont(textFromClient, speedFromClient));
        } else{     // Jikai diluar 1 - 4
            bad_request_respont();
            textFromClient = "";
            speedFromClient = 0;
        }
    }
    else {
        bad_request_respont();
    }
}
