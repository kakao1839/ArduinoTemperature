#include "DHT.h"        //ライブラリ読み込み
#define DHTTYPE DHT11   // DHTの種類をDHT 11に設定

const int DHTPIN=7;    //7番pinをDHTpinに設定

DHT dht(DHTPIN, DHTTYPE);//DHT11に関する情報を入力

void setup() {
  Serial.begin(9600);   //9600bpsでシリアルポートを開く

  dht.begin();           //DHT11による計測開始
}

void loop() {
  
  delay(5000);     //5秒ごとに計測
 
  float h = dht.readHumidity();     // 湿度を測定
  float t = dht.readTemperature();  // 温度を摂氏で測定

  // 読み込み失敗かどうか判断
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.println(t);  //改行しながら温度を出力
  Serial.println(h);  //改行しながら湿度を出力
}
