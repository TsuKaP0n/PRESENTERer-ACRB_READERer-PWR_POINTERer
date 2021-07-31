/*  ADB_READERer / PWR_POINTERer
 *   for Windows10 + M5Stack Basic (16 MB Flush)
 *   w/ Orchis Launcher, Media Player Classic BE
 *   by TsuKaP0n
 *   
 *      Licence
 *        MIT; Copyright (c) 2021 TsuKaP0n ( https://twitter.com/cos_TH )
 * 
 *      Requires
 *      device:
 *        - M5Stack Basic (16 MB Flush)
 *        - microSD card (16 GB or smaller)
 *      pc:
 *        - Microsoft Windows 10
 *        - Bluetooth function
 *      pc application:
 *        - Adobe Acrobat Reader or Microsoft PowerPoint
 *        - Orchis Launcher ( https://www.eonet.ne.jp/~gorota/ )
 *        - Media Player Classic BE ( https://ja.osdn.net/projects/sfnet_mpcbe/ )
 *      Arduino library:
 *        - M5Stack ( https://github.com/m5stack )
 *        - ESP32 BLE Keyboard ( https://github.com/T-vK/ESP32-BLE-Keyboard )
 *        - ArduinoJson ( https://github.com/bblanchon/ArduinoJson )
 *        - M5StackUpdater ( https://github.com/tobozo/M5Stack-SD-Updater )
 *      better to use:
 *        - M5Stack LovyanLauncher ( https://github.com/lovyan03/M5Stack_LovyanLauncher )
 * 
 * 
 *      Arduino IDE settings
 *        tool -> board manager -> esp32 : version 1.0.6
 *        tool -> board: ESP32 Arduino -> M5Stack-Fire
 *        tool -> Partition Scheme: Default
 *   
 *   
 *      Orchis Launcher の設定
 *          右クリック→共通設定→表示方法→全般→
 *                        ☑ 表示中にそれを表示するキーボード操作を...
 *                          ☑「常に表示」状態でも閉じる
 *      
 *      
 *      to display username and input time to sleep PC (minutes),
 *        make "/json/presenterer.json" file on the microSD card.
 *        for example;
            {
              "username": "YOUR NAME",
              "sleep": 5
            }
 *
 *        to enable sleep mode, write
 *            "sleep": 0
 *                    
 *  version
 *  1.4.2  2021/08/01 - eneble to use esp32 virsion 1.0.5 or later
 *  1.4.1  2021/07/30 - bugfixed
 *  1.4.0  2021/07/28 - 
 *  
 */
#include <M5Stack.h>
#include <M5StackUpdater.h>
#include <ArduinoJson.h>
#include <BleKeyboard.h>
#include "prr_btnName.h"

#define _APP_NAME_NUM   1   // 0: ACRB_READERer  1: PWR_POINTERer
#define _APP_VER      "1.4.2"
#define _BLE_NAME     "PRSNTERer 1.4.2"

#define _FIRST_MENU 239

const uint16_t timerColor       = M5.Lcd.color565(255, 127, 0);
const uint16_t timerbgColor     = TFT_BLACK;
const uint16_t stpwtColor       = TFT_WHITE;
const uint16_t stpwtbgColor     = TFT_BLUE;
const uint16_t keyColor0        = M5.Lcd.color565(0, 239, 239);
const uint16_t keyColor1        = TFT_YELLOW;
const uint16_t keyColor2        = TFT_PINK;
const uint16_t usernameColor    = TFT_LIGHTGREY;
const uint16_t shiftColor       = TFT_LIGHTGREY;
const uint16_t connectionColor0 = TFT_RED;
const uint16_t connectionColor1 = TFT_DARKCYAN;
const uint16_t lcdBrightness0   = 15;               // up to 255
const uint16_t lcdBrightness1   = 47;               // up to 255
const uint16_t usernameTop      = 55;
const uint16_t timerTop         = 80;

BleKeyboard bleKeybd(_BLE_NAME);

const String appName[2] = {"ACRB_READERer","PWR_POINTERer"};
const String aboutThisApp = appName[_APP_NAME_NUM] + " for Windows10  version " + _APP_VER;

String userName = "";
uint16_t sleepTimerOfPC = 5;

uint32_t currentMsec = 0;
uint32_t bttUpdateMsec = 0;
uint32_t tmrUpdateMsec = 0;
uint32_t stpwtUpdateMsec = 0;
uint16_t stpwtRowDown = 0;
uint32_t ntSleepIntervalMsec = (sleepTimerOfPC * 60 - 30) * 1000;
uint32_t nextNtSleepMsec = ntSleepIntervalMsec;
bool ble = false;
uint16_t bttUpdateLvl = -1;

uint8_t tmrPrintedNums[5] = {0, 0, 0, 0, 0};
bool showStpwt = false;
int8_t stpwtMode = 0;
uint8_t stpwtPrintedNums[7] = {0, 0, 0, 0, 0, 0, 0};
const uint16_t timerNumPos[7] = {
  70,   // 100min, 70
  102,  // 10min, 70+32
  134,  // 1min, 70+32*2
  178,  // 10sec, 70+32*3+12
  210,  // 1sec, 70+32*3+12+32
  254,  // 100msec, 70+32*3+12+32*2+12
  286   // 10msec, 70+32*3+12+32*2+12+32
};
const uint16_t timerColonPos[2] ={
  166,  // min:sec, 70+32*3
  242   // sec:msec, 70+32*3+12+32*2
};

uint32_t stpwtStartMsec = 0;
uint32_t stpwtStopMsec = 0;
uint32_t stpwtMeasuredMsec = 0;

bool lcdBright = false;

uint16_t btnNameIndex[200];
uint16_t btnMssIndex[50];

uint8_t btnMode = _FIRST_MENU;
uint8_t lastBtnMode = _FIRST_MENU;
uint8_t lastPrsnApp = 0;
uint8_t lastRefApp = 0;
uint8_t lastFilrApp = 0;
int8_t appMode = -1;    // 0: slide  1: launcher  2: reference material
bool switchBtnMode100B = false;
bool switchBtnMode100C = false;
String modeName = "";
bool a_pressed = false;
bool b_pressed = false;
bool c_pressed = false;
bool a_pressed_long = false;
bool b_pressed_long = false;
bool c_pressed_long = false;
uint16_t a_pos, b_pos, c_pos;
String a_tx, b_tx, c_tx;
String B_tx, C_tx;
String mss1, mss2;

int16_t repeatingPages, repeatingPgCount;
int8_t repeatingDirection;
String repeatingItvName[20] = {
  "1 sec.",  "2 sec.",    "3 sec.",  "5 sec.",  "7 sec.",
  "10 sec.", "15 sec.",   "20 sec.", "30 sec.", "45 sec.",
  "1 min.",  "1.5 min.",  "2 min.",  "3 min.",  "5 min.",
  "7 min.",  "10 min.",   "15 min.", "20 min.", "30 min."};
uint16_t repeatingItvSec[20] = {
  1,    2,    3,    5,    7,
  10,   15,   20,   30,   45,
  60,   90,   120,  180,  300,
  420,  600,  900,  1200, 1800};
int16_t repeatingItvIndex = 5;
uint32_t nextRptDspMsec, intervalRptDspMsec;
uint16_t restRptDspSec;

void setup() {
  M5.begin(true, true, false, true);  // LCD, SD, Serial, I2C

  // reload LovyanLauncher
  delay(1);
  if(digitalRead(BUTTON_A_PIN) == 0) {
    updateFromFS(SD);
    ESP.restart();
  }
  
  M5.Power.begin();
  M5.Speaker.begin(); // cancelling noise from the speaker
  M5.Speaker.mute();

  userName = appName[_APP_NAME_NUM];
  readFromSD();
  setBtnNameIndex();
  setBtnMssIndex();

  bleKeybd.begin();

  M5.Lcd.setBrightness(lcdBrightness0);
  if(M5.BtnB.isPressed()) {
    switchBtnMode100B = true;
    lcdBright = !lcdBright;
  }
  if(M5.BtnC.isPressed()) {
    switchBtnMode100C = true;
    if(userName == appName[_APP_NAME_NUM]) userName = appName[1 - _APP_NAME_NUM];
  }
  newBtnMode(btnMode);
  print_ble(false);
  print_username();
  print_timer_0();
}
 
void loop() {
  M5.update();
  currentMsec = millis();
  print_battery();
  print_timer();
  repeatingDisplay();
  
  if(bleKeybd.isConnected()) {
    if(!ble) {
      ble = true;
      print_ble(ble);
    }
  }else {
    if(ble) {
      ble = false;
      print_ble(ble);
    }
  }

  if(M5.BtnA.wasPressed()) a_pressed = true;
  if(M5.BtnB.wasPressed()) b_pressed = true;
  if(M5.BtnC.wasPressed()) c_pressed = true;
  if(M5.BtnA.pressedFor(300)) a_pressed_long = true;
  if(b_pressed + c_pressed) a_pressed_long = false;
  if(M5.BtnB.pressedFor(300)) b_pressed_long = true;
  if(b_pressed_long) if(!M5.BtnB.isPressed()) {
    switchLcdBrightness();
    b_pressed = false;
    b_pressed_long = false;
  }
  if(M5.BtnC.pressedFor(300)) c_pressed_long = true;

  if(!(M5.BtnA.isPressed() + M5.BtnB.isPressed() + M5.BtnC.isPressed())) {
    btnAction(a_pressed, b_pressed, c_pressed, a_pressed_long, c_pressed_long);

    if(a_pressed + b_pressed + c_pressed) nextNtSleepMsec = ntSleepIntervalMsec + currentMsec;
    if(nextNtSleepMsec < currentMsec) keystroke_notToSleep();

    a_pressed = false;
    b_pressed = false;
    c_pressed = false;
    a_pressed_long = false;
    c_pressed_long = false;
  }
  delay(3);
}
