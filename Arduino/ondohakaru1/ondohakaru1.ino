//#include "DHT.h" //ライブラリ読み込み 
//
//const int DHTPIN=7; //7番pinをDHTpinに設定 
//#define DHTTYPE DHT11 // DHTの種類をDHT 11に設定 
//
//DHT dht(DHTPIN, DHTTYPE);//DHT11に関する情報を入力 
//
//void setup() { 
//Serial.begin(9600); //9600bpsでシリアルポートを開く 
//
//dht.begin(); //DHT11による計測開始 
//} 
//
//void loop() { 
//
//delay(5000); //5秒ごとに計測 
//
//float h = dht.readHumidity(); // 湿度を測定 
//float t = dht.readTemperature(); // 温度を摂氏で測定 
//
// 読み込み失敗かどうか判断 
// if (isnan(h) || isnan(t)) { 
// Serial.println("Failed to read from DHT sensor!"); 
// return; 
// } 
//
//Serial.println(t); //改行しながら温度を出力 
//Serial.println(h); //改行しながら湿度を出力 
//}
//
// 温度センサーの値をシリアルモニタに表示するプログラム
//
int sensorPin = A0;     //アナログ0番ピンを指定
int sensorValue = 0;
void setup() {
Serial.begin(9600);           //シリアルモニタに表示する為の設定
}
void loop() {
sensorValue = analogRead(sensorPin);    //アナログ0番ピンからの入力値を取得
float temp  = modTemp(sensorValue);     //温度センサーからの入力値を変換
Serial.println(temp);                   //結果をシリアルモニタに表示
delay(500);                             //0.5秒ウェイト
}
//アナログ入力値を摂氏度℃に変換
float modTemp(int analog_val){
float v  = 5;     // 基準電圧値( V )
float tempC = ((v * analog_val) / 1024) * 100 - 320;  // 摂氏に換算
return tempC;
}
