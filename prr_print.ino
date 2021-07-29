void switchLcdBrightness() {
  lcdBright = !lcdBright;
  M5.Lcd.setBrightness(lcdBright ? lcdBrightness1 : lcdBrightness0);
  //if(lcdBright) screenServer();
}

void print_ble(bool flg) {
  M5.Lcd.setTextFont(4);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.fillRect(0, 0, 160, 20, TFT_BLACK);
  if(flg) {
    M5.Lcd.setTextColor(connectionColor1);
    M5.Lcd.print("Connected");
  } else {
    M5.Lcd.setTextColor(connectionColor0);
    M5.Lcd.printf("Disconnected");
  }
}

void print_username() {
  M5.Lcd.setTextFont(2);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(usernameColor);
  M5.Lcd.setCursor(100, usernameTop);
  M5.Lcd.print(userName);
}

void print_key() {
  btnName(btnMode);
  
  uint16_t kc = keyColor2;
  switch(appMode) {
    case 1: kc = keyColor1; break;
    case 2: kc = keyColor0; break;
  }
  M5.Lcd.fillRect(0, 152, 320, 88, TFT_BLACK);

  //// line 1-3
  if(mss1 + mss2 != "") {
    M5.Lcd.setTextFont(1);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(shiftColor, TFT_BLACK);
    M5.Lcd.setCursor(2, 154);
    M5.Lcd.print(mss1);
    M5.Lcd.setCursor(2, 180);
    M5.Lcd.print(mss2);
  }else {
    // line 1
    M5.Lcd.setTextFont(2);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(kc, TFT_BLACK);
    M5.Lcd.setCursor(2, 152);
    M5.Lcd.print(modeName);  
    // line 2
    switch(btnMode) {
    case 97:
      break;
    default:
      M5.Lcd.fillRect(0, 178, 24, 4, shiftColor); 
      M5.Lcd.setTextFont(2);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setTextColor(shiftColor);
      M5.Lcd.setCursor(48, 172);
      M5.Lcd.print("MENU");
      M5.Lcd.setCursor(b_pos, 172); //120
      M5.Lcd.print("BRIGHTNESS");
      M5.Lcd.setCursor(c_pos, 172); //222
      M5.Lcd.print((appMode == 1) ? "ESC" : "LAUNCHER");
      break;
    }
    // line 3
    M5.Lcd.fillRect(8, 194, 8, 6, shiftColor); 
    M5.Lcd.fillRect(0, 203, 24, 4, shiftColor); 
    M5.Lcd.setTextColor(TFT_BLACK, shiftColor);
    M5.Lcd.setCursor(40, 192);
    M5.Lcd.print(" SHIFT ");
    M5.Lcd.setTextColor(shiftColor, TFT_BLACK);
    M5.Lcd.setCursor(b_pos + 1, 192);
    M5.Lcd.print(B_tx);
    M5.Lcd.setCursor(c_pos + 1, 192);
    M5.Lcd.print(C_tx);    
  }

  //// line 4
  M5.Lcd.setTextFont(4);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(kc);
  M5.Lcd.fillRect(8, 223, 8, 6, kc); 
  M5.Lcd.setCursor(a_pos, 212);
  M5.Lcd.print(a_tx);
  M5.Lcd.setCursor(b_pos, 212);
  M5.Lcd.print(b_tx);
  M5.Lcd.setCursor(c_pos, 212);
  M5.Lcd.print(c_tx);

  switch(btnMode) {
    case 5:   // draw play/pause button
    case 20:
      M5.Lcd.fillTriangle(235, 212, 235, 232, 250, 222, keyColor0);
      M5.Lcd.fillRect(260, 212, 3, 20, keyColor0);
      M5.Lcd.fillRect(270, 212, 3, 20, keyColor0);
      break;
    case 95:
      if(!showStpwt) {
        showStpwt = true;
        for(char i = 0; i < 5; i++) tmrPrintedNums[i] = 0;
        print_timer_0();
      }
      break;
    case 97:
      M5.Lcd.setTextFont(2);
      M5.Lcd.setTextSize(1);
      M5.Lcd.setTextColor(keyColor0, TFT_BLACK);
      M5.Lcd.setCursor(0, 192);
      M5.Lcd.print(aboutThisApp);

      M5.Lcd.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
      M5.Lcd.setCursor(0, 213);
      M5.Lcd.print("DEVICE NAME - ");
      M5.Lcd.print(_BLE_NAME);
      break;
  }
}

void print_repeatDispRestTime(uint16_t ii) {
  String s = String(ii);
  if(ii < 10) s = " " + s;
  if(ii < 100) s = " " + s;
  if(ii < 1000) s = " " + s;
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(shiftColor, TFT_BLACK);
  M5.Lcd.setCursor(2, 154);
  M5.Lcd.print(s);
}

void print_battery() {
  if(currentMsec - bttUpdateMsec > 1000) {
    int bttLvl =  M5.Power.getBatteryLevel();
    const int left = 270;
    if(bttUpdateLvl != bttLvl){
      M5.Lcd.fillRect(left, 2, 44, 19, shiftColor);
      M5.Lcd.fillRect(left + 44, 6, 4, 10, shiftColor);
      M5.Lcd.fillRect(left + 2, 4, 40, 15, TFT_BLACK);
      M5.Lcd.fillRect(left + 44, 8, 2, 6, TFT_BLACK);
      if(bttLvl <= 25) {
        M5.Lcd.fillRect(left + 3, 5, 9, 13, TFT_ORANGE);
      } else {
        M5.Lcd.fillRect(left + 3, 5, 8, 13, keyColor0);
        if(bttLvl > 25) {
          M5.Lcd.fillRect(left + 13, 5, 8, 13, keyColor0);
          if(bttLvl > 50) {
            M5.Lcd.fillRect(left + 23, 5, 8, 13, keyColor0);
            if(bttLvl > 75) {
              M5.Lcd.fillRect(left + 33, 5, 8, 13, keyColor0);
            }
          }
        }
      }
      bttUpdateLvl = bttLvl;
    }
    bttUpdateMsec = currentMsec;
  }
}
