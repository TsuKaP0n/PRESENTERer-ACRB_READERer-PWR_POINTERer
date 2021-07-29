void key_stroke(int k1, int k2, int k3, int k4) {
  if(!(k1 + k2 + k3 + k4)) return;
  bleKeybd.press(k1);
  if(k2) bleKeybd.press(k2);
  if(k3) bleKeybd.press(k3);
  if(k4) bleKeybd.press(k4);
  bleKeybd.releaseAll();
}

int btnAction_SearchIdx(int md) {
  int idx = -1;
  for(int i = 0; i < 200; i++) {
    if(md == btnStrokeNextmode[i][0]) {
      idx = i;
      break;
    }
  }
  return idx;
}

void newBtnMode(int next_md) {
  if(!bleKeybd.isConnected()) {
    if(!((next_md == _FIRST_MENU) + (next_md >= 240) + (next_md == 95) + (next_md == 97))) return;
  }

  //// mode changing
  lastBtnMode = btnMode;
  btnMode = next_md;
  appMode = btnStrokeNextmode[btnAction_SearchIdx(next_md)][1];
  if(btnMode == 200) appMode = 1;
  print_key();

  //// after changing
  switch(btnMode) {
  case 1:   // Acrobat Reader
    if(lastPrsnApp != 1) {
      switch(lastBtnMode) {
        case 20: case 24:
          break;
        default:
          key_stroke(KEY_ESC, 0, 0, 0);
          key_stroke(KEY_LEFT_CTRL, 'l', 0, 0);  // fullscreen
      }
    }
    break;
  case 10:  // PowerPoint
/*
      switch(lastBtnMode) {
        case 10: case 11: case 12:
          break;
        default:
          if(!(lastRefApp == 20) + (lastBtnMode == 202)) {
            key_stroke(KEY_LEFT_GUI, KEY_TAB, 0, 0);    // to focus the powerpoint file
            delay(400);
            key_stroke(KEY_RETURN, 0, 0, 0);
          }
      }
*/
    break;
  case 15:  // File Explorer
    key_stroke(KEY_PAGE_UP, false, false, false);
    break;
  case 20:  // MPC-BE
    switch(lastBtnMode) {
      case 20: case 21: case 22: case 23: case 24: case 98:
        break;
      default:
        key_stroke(KEY_LEFT_GUI, KEY_UP_ARROW, 0, 0);  // maximize
    }
    break;
  case 90:  // close window
    key_stroke(KEY_LEFT_ALT, KEY_F4, false, false);
    newBtnMode(lastBtnMode);
    break;
  case 200: // alt + tab
    bleKeybd.press(KEY_LEFT_ALT);
    bleKeybd.press(KEY_TAB);
    bleKeybd.release(KEY_TAB);
    break;
  case 202: // win + tab
    key_stroke(KEY_LEFT_GUI, KEY_TAB, 0, 0);
    break;
  }

  switch(btnMode) {
  case 1: case 10: case 11: case 12:
    lastPrsnApp = btnMode; break;
  case 5: case 20: case 30:
    lastRefApp = btnMode; break;
  case 205: case 98: case 200:
    lastFilrApp = btnMode; break;
  }
}

void btnAction(bool a_prs, bool b_prs, bool c_prs, bool a_prs_lng, bool c_prs_lng) {
  uint8_t md = btnMode;
  char pressedBtn = 0;
  if(a_prs + b_prs + c_prs) {
    if(b_prs) {
      pressedBtn = a_prs ? 'B' : 'b';
    }else if(c_prs) {
      pressedBtn = a_prs ? 'C' : 'c';
    }else if(a_prs) {
      pressedBtn = a_prs_lng ? 'A' : 'a';
    }
  }
  
  if(a_prs_lng) {        // select application
    newBtnMode(240);
    
  }else if(c_prs_lng) {
    if(appMode != 1) {    // open Orchis Launcher
      if(appMode == 2) key_stroke(KEY_LEFT_ALT, KEY_F4, 0, 0);
      key_stroke(KEY_LEFT_CTRL, KEY_LEFT_ALT, 0x20, 0);
      newBtnMode(205);
    }else {              // close launcher
      key_stroke(KEY_ESC, 0, 0, 0);
      newBtnMode(lastPrsnApp ? lastPrsnApp : lastBtnMode);
    }

  }else if(pressedBtn) {

    const int idx = btnAction_SearchIdx(md);
    if(md < 240) {
      if(idx >=  0) {
        short int j = 0;
        switch(pressedBtn) {
        case 'a': break;
        case 'b': j = 1; break;
        case 'c': j = 2; break;
        case 'B': j = 3; break;
        case 'C': j = 4; break;
        }
        const short int ix = 2 + j * 5;
        if(btnStrokeNextmode[idx][ix]) {
          key_stroke(btnStrokeNextmode[idx][ix], btnStrokeNextmode[idx][ix + 1],
              btnStrokeNextmode[idx][ix + 2], btnStrokeNextmode[idx][ix + 3]);
        }
        const int nxt = btnStrokeNextmode[idx][ix + 4];
        if(nxt) newBtnMode(nxt);
      }
    }

    // additional acttions

    switch(md) {
    case 1:     // Acrobat Reader: TOP
      if(pressedBtn == 'a') {
        key_stroke(KEY_ESC, 0, 0, 0);
        key_stroke(KEY_LEFT_CTRL, KEY_TAB, 0, 0);
        delay(200);
        key_stroke(KEY_LEFT_CTRL, 'l', 0, 0);
      }
      break;
    case 9:     // movie & TV (close)
      if(pressedBtn == 'c') newBtnMode(lastPrsnApp ? lastPrsnApp : 240);
      break;
    case 20:    // MPC-BE (top)
      if(pressedBtn == 'C') {
        key_stroke(KEY_LEFT_ALT, 'x', 0, 0);
        newBtnMode(lastPrsnApp ? lastPrsnApp : 240);
      }
      break;
    case 24:    // MPC-BE (display)
      if(pressedBtn == 'c') newBtnMode(lastPrsnApp ? lastPrsnApp : 240);
      break;
    case 27:    // photo (display)
      if(pressedBtn == 'c') newBtnMode(lastPrsnApp ? lastPrsnApp : 240);
      break;
    case 34:    // Google Chrome (minimize)
      if(pressedBtn == 'b') {
        key_stroke(KEY_LEFT_ALT, 0x20, 0, 0);
        delay(500);
        key_stroke('n', 0, 0, 0);
        newBtnMode(lastPrsnApp ? lastPrsnApp : 240);
      }
      break;
    case 40:
      switch(pressedBtn) {
      case 'a':
        key_stroke(KEY_ESC, 0, 0, 0);
        key_stroke(KEY_LEFT_CTRL, 'l', 0, 0);  // fullscreen
        lastPrsnApp = 1;
        break;
      case 'c':
        lastPrsnApp = 11;
        break;
      }
      break;
    case 41: case 44:
      if(pressedBtn == 'c') repeatingPages = 0;
      break;
    case 42: case 45:
      switch(pressedBtn) {
      case 'a': repeatingPages--; break;
      case 'b': repeatingPages++; break;
      }
      break;
    case 48:
      switch(pressedBtn) {
      case 'a':
        repeatingItvIndex--;
        if(repeatingItvIndex < 0) repeatingItvIndex = 0;
        newBtnMode(48);
        break;
      case 'b':
        repeatingItvIndex++;
        if(repeatingItvIndex > 19) repeatingItvIndex = 19;
        newBtnMode(48);
        break;
      case 'c':
        repeatingPgCount = repeatingPages;
        if(repeatingPgCount > 0) {
          repeatingDirection = 1;
          while(repeatingPgCount > 0) {
            key_stroke(KEY_PAGE_UP, 0, 0, 0);
            repeatingPgCount--;
          } 
        }else if(repeatingPgCount < 0) {
          repeatingDirection = -1;
          while (repeatingPgCount < 0) {
            key_stroke(KEY_PAGE_DOWN, 0, 0, 0);
            repeatingPgCount++;
          }
        }else {
          repeatingDirection = 0;
        }
        intervalRptDspMsec = repeatingItvSec[repeatingItvIndex] * 1000;
        nextRptDspMsec = intervalRptDspMsec + currentMsec;
        newBtnMode(49);
        break;
      }
      break;
    case 49:
      newBtnMode(lastPrsnApp);
      break;
    case 90:    // ALT + F4
      break;
    case 95:    // stopwatch
      switch(pressedBtn) {
      case 'a':
        if(stpwtMode == 0) {
          for(int i = 0; i < 7; i++) stpwtPrintedNums[i] = 0;
        }
        if((stpwtMode == 0) || (stpwtMode == 1)) {
          stpwtStartMsec = currentMsec;
          stpwtMode = 2;
        }
        break;
      case 'b':
        switch(stpwtMode) {
          case 2:
          stpwtMeasuredMsec += currentMsec - stpwtStartMsec;
          stpwtMode = 1;
          break;
        case 1:
          stpwtMeasuredMsec = 0;
          stpwtMode = 0;
          break;
        }
        break;
      case 'c':
        unsigned char num[7];
        getStpwtTime10msec(num);
        for(char i = 0; i < 7; i++){
          key_stroke(48 + num[i], 0, 0, 0);
          if(i == 4) key_stroke('.', 0, 0, 0);
        }
        key_stroke(KEY_RETURN, 0, 0, 0);
        stpwtRowDown++;
        break;
      case 'B':
        showStpwt = false;
        print_timer_0();
        newBtnMode(240);
        break;
      case 'C':
        while(stpwtRowDown > 0){
          stpwtRowDown--;
          key_stroke(KEY_UP_ARROW, 0, 0, 0);
        }
        key_stroke(KEY_RIGHT_ARROW, 0, 0, 0);
        break;
      }
      break;
    case 200:    // window selection (Alt + Tab)
      switch(pressedBtn) {
      case 'a':
        bleKeybd.press(KEY_LEFT_ARROW); bleKeybd.release(KEY_LEFT_ARROW);
        break;
      case 'b':
        bleKeybd.press(KEY_RIGHT_ARROW); bleKeybd.release(KEY_RIGHT_ARROW);
        break;
      case 'c':
        bleKeybd.releaseAll();
        newBtnMode(240);
        break;
      case 'C':
        key_stroke(KEY_ESC, 0, 0, 0);
        newBtnMode(lastBtnMode);
        break;
      }
      break;
    case 202:    // window selection (Win + Tab)
      if(pressedBtn == 'c'){
        delay(400);
        newBtnMode(lastBtnMode);
      }
      break;
    case 239:    // the first question
      if(pressedBtn == 'c') {
        newBtnMode(!_APP_NAME_NUM ?
          (!switchBtnMode100C ? 1 : 10)
          : (!switchBtnMode100C ? 10 : 1));
      }
      break;
    case 240:   // main menu
      switch(pressedBtn) {
      case 'a': newBtnMode((appMenu_str[1][1] != "") ? 241 : 240); break;
      case 'b': newBtnMode(!switchBtnMode100B ? appMenu_btnMode[0][0] : appMenu_btnMode[1][0]); break;
      case 'c': newBtnMode(!switchBtnMode100C ? appMenu_btnMode[0][1] : appMenu_btnMode[0][3]); break;
      case 'B': newBtnMode(appMenu_btnMode[0][2]); break;
      case 'C': newBtnMode(!switchBtnMode100C ? appMenu_btnMode[0][3] : appMenu_btnMode[0][1]); break;
      }
      break;
    case 241:
      switch(pressedBtn) {
      case 'a': newBtnMode((appMenu_str[2][1] != "") ? 242 : 240); break;
      case 'b': newBtnMode(appMenu_btnMode[1][0]); break;
      case 'c': newBtnMode(appMenu_btnMode[1][1]); break;
      case 'B': newBtnMode(appMenu_btnMode[1][2]); break;
      case 'C': newBtnMode(appMenu_btnMode[1][3]); break;
      }
      break;
    case 242:
      switch(pressedBtn) {
      case 'a': newBtnMode((appMenu_str[3][1] != "") ? 243 : 240); break;
      case 'b': newBtnMode(appMenu_btnMode[2][0]); break;
      case 'c': newBtnMode(appMenu_btnMode[2][1]); break;
      case 'B': newBtnMode(appMenu_btnMode[2][2]); break;
      case 'C': newBtnMode(appMenu_btnMode[2][3]); break;
      }
      break;
    case 243:
      switch(pressedBtn) {
      case 'a': newBtnMode(240); break;
      case 'b': newBtnMode(appMenu_btnMode[3][0]); break;
      case 'c': newBtnMode(appMenu_btnMode[3][1]); break;
      case 'B': newBtnMode(appMenu_btnMode[3][2]); break;
      case 'C': newBtnMode(appMenu_btnMode[3][3]); break;
      }
      break;
    }
  }
}  
  
void keystroke_notToSleep(){
  if(sleepTimerOfPC > 0) {
    key_stroke(KEY_LEFT_SHIFT, KEY_RIGHT_SHIFT, false, false);
    nextNtSleepMsec = ntSleepIntervalMsec + currentMsec;
  }
}

void repeatingDisplay() {
  if(btnMode != 49) return;
  else if(!repeatingDirection) return;

  if(nextRptDspMsec < currentMsec) {
    switch(repeatingDirection) {
    case 1:
      if(repeatingPgCount < repeatingPages) {
        key_stroke(KEY_PAGE_DOWN, 0, 0, 0);
        repeatingPgCount++;
      }else {
        while(repeatingPgCount > 0) {
          key_stroke(KEY_PAGE_UP, 0, 0, 0);
          repeatingPgCount--;
        }
      }
      nextRptDspMsec = intervalRptDspMsec + currentMsec;
      break;
    case -1:
      if(repeatingPgCount > repeatingPages) {
        key_stroke(KEY_PAGE_UP, 0, 0, 0);
        repeatingPgCount--;
      }else {
        while(repeatingPgCount < 0) {
          key_stroke(KEY_PAGE_DOWN, 0, 0, 0);
          repeatingPgCount++;
        }
      }
      nextRptDspMsec = intervalRptDspMsec + currentMsec;
      break;
    }
  }
  if(repeatingDirection) {
    uint16_t ii = (nextRptDspMsec - currentMsec) / (int)1000 + 1;
    if(restRptDspSec != ii){
      restRptDspSec = ii;
      print_repeatDispRestTime(restRptDspSec);
    }
  }
}
