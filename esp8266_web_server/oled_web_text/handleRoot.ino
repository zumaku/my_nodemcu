void handle_root() {
    String root_html = "<!DOCTYPE html>";
    root_html += "<html lang='en'>";
    root_html += "<head>";
        root_html += "<meta charset='UTF-8'>";
        root_html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
        root_html += "<title>Oled Web Text</title>";
        root_html += "<link href='https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css' rel='stylesheet' integrity='sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9' crossorigin='anonymous'>";
    root_html += "</head>";
    root_html += "<body>";
        root_html += "<div class='container text-center mt-5'>";
            root_html += "<div class='row align-items-start'>";
                root_html += "<div class='h-100'>";
                    root_html += "<h1>Oled Web Text</h1>";
                    root_html += "<p class=''>Kirim teks untuk ditampilkan di layar LCD Oled 128x64 secara online</p>";
                    root_html += "<p class='mb-5'><small>Made by <a href='https://www.github.com/zumaku' target='_blank'>Zumaku</a>.</small></p>";
                    root_html += "<form action='/send' method='POST' class='form-floating'>";
                        root_html += "<textarea class='form-control mb-3' placeholder='Leave a comment here' id='floatingTextarea2' style='height: 150px' name='textYgDikirim'></textarea>";
                        root_html += "<label for='floatingTextarea2'>Masukkan teks disini</label>";
                        root_html += "<button type='submit' class='btn btn-primary'>Kirim</button>";
                    root_html += "</form>";
                root_html += "</div>";
            root_html += "</div>";
        root_html += "</div>";
        root_html += "<script src='https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js' integrity='sha384-HwwvtgBNo3bZJJLYd8oVXjrBZt8cqVSpeBNS5n7C8IVInixGAoxmnlMuBnhbgrkm' crossorigin='anonymous'></script>";
    root_html += "</body>";
    root_html += "</html>";

    server.send(200, "text/html", root_html);
}