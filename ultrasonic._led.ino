#define trigPin 9
#define echoPin 10
#define ledHijau 5
#define ledKuning 6
#define ledMerah 7

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledHijau, OUTPUT);
    pinMode(ledKuning, OUTPUT);
    pinMode(ledMerah, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    long duration;
    int distance;

    // Kirim pulsa ultrasonik
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Baca waktu pantulan kembali
    duration = pulseIn(echoPin, HIGH);
    
    // Hitung jarak dalam cm
    distance = duration * 0.034 / 2;

    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Logika LED berdasarkan jarak
    if (distance > 30) { // Jarak jauh (LED hijau menyala)
        digitalWrite(ledHijau, HIGH);
        digitalWrite(ledKuning, LOW);
        digitalWrite(ledMerah, LOW);
    } else if (distance > 15 && distance <= 30) { // Jarak sedang (LED kuning menyala)
        digitalWrite(ledHijau, LOW);
        digitalWrite(ledKuning, HIGH);
        digitalWrite(ledMerah, LOW);
    } else { // Jarak dekat (LED merah menyala)
        digitalWrite(ledHijau, LOW);
        digitalWrite(ledKuning, LOW);
        digitalWrite(ledMerah, HIGH);
    }

    delay(500); // Delay untuk stabilitas sensor
}
