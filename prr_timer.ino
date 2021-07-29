void getStpwtTime(unsigned char deg[7]) {
  unsigned long tenmillisec = currentMsec / 10;
  if(showStpwt) {
    tenmillisec = stpwtMeasuredMsec / 10;
    if(stpwtMode == 2) tenmillisec = (currentMsec - stpwtStartMsec + stpwtMeasuredMsec) / 10;
  }
  unsigned char tt = tenmillisec % 100;
  deg[6] = tt % 10;
  deg[5] = tt / 10;
  unsigned long sec = tenmillisec / 100;
  unsigned char ss = sec % 60;
  unsigned long mmm = (sec / 60) % 1000;
  deg[4] = ss % 10;
  deg[3] = ss / 10;
  deg[2] = mmm % 10;
  mmm /= 10;
  deg[1] = mmm % 10;
  deg[0] = mmm / 10;
}

void getStpwtTime10msec(unsigned char deg[7]) {
  unsigned long tenmillisec = currentMsec / 10;
  tenmillisec = stpwtMeasuredMsec / 10;
  if(stpwtMode == 2) tenmillisec = (currentMsec - stpwtStartMsec + stpwtMeasuredMsec) / 10;
  for(char i = 0; i < 7; i++) {
    deg[6 - i] = tenmillisec % 10;
    tenmillisec /= 10;
  }
}

void print_timer() {
  bool rewrite_dsp = false;
  if(showStpwt) {
    if(currentMsec - stpwtUpdateMsec > 10) rewrite_dsp = true;
  }
  else if(currentMsec - tmrUpdateMsec > 100) rewrite_dsp = true;
  
  if(rewrite_dsp) {
    unsigned char num[7];
    getStpwtTime(num);
    
    char i_end = 5;
    unsigned short col = timerColor;
    unsigned short bgcol = timerbgColor;
    if(showStpwt) {
      i_end = 7;
      col = stpwtColor;
      bgcol = stpwtbgColor;
    }

    M5.Lcd.setTextFont(7);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(col);
    for(char i = 0; i < i_end; i++){
      unsigned char pn = tmrPrintedNums[i];
      if(showStpwt) pn = stpwtPrintedNums[i];
      if(num[i] - pn) {
        M5.Lcd.fillRect(timerNumPos[i] + 1, timerTop, 30, 48, bgcol);
        M5.Lcd.setCursor(timerNumPos[i], timerTop);
        M5.Lcd.print(num[i]);
        if(showStpwt) stpwtPrintedNums[i] = num[i];
        else tmrPrintedNums[i] = num[i];
      }
    }
    if(showStpwt) stpwtUpdateMsec = currentMsec;
    else tmrUpdateMsec = currentMsec;
  }
}

void print_timer_0() {
    M5.Lcd.fillRect(0, timerTop, 320, 48, TFT_BLACK);
    char i_end = 5;
    String str_zero = "0:00";
    unsigned short col = timerColor;
    unsigned short bgcol = timerbgColor;
    if(showStpwt) {
      i_end = 7;
      str_zero = "0:00.00";
      col = stpwtColor;
      bgcol = stpwtbgColor;
    }
    for(char i = 0; i < i_end; i++) {
      M5.Lcd.fillRect(timerNumPos[i] + 1, timerTop, 30, 48, bgcol);
    }
    M5.Lcd.fillRect(timerColonPos[0] + 1, timerTop, 10, 48, bgcol);
    if(showStpwt) M5.Lcd.fillRect(timerColonPos[1] + 1, timerTop, 10, 48, bgcol);

    M5.Lcd.setTextFont(7);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(col);
    M5.Lcd.setCursor(timerNumPos[2], timerTop);
    M5.Lcd.print(str_zero);
}
