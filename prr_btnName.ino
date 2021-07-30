void setBtnNameIndex() {
  for(int i = 0; i < 200; i++) {
    if(subMenu[i][0] == "") break;
    btnNameIndex[i] = subMenu[i][0].toInt();
  }
}

void setBtnMssIndex() {
  for(int i = 0; i < 50; i++) {
    if(btnMss[i][0] == "") break;
    btnMssIndex[i] = btnMss[i][0].toInt();
  }
}

void btnName(int md) {
  int idx = -1;
  int idx_m = -1;
  if(md < 240) {
    for(int i = 0; i < 200; i++) {
      if(md == btnNameIndex[i]) {
        idx = i;
        break;
      }
    }
    if(idx >=  0) {
      modeName = subMenu[idx][1];
      a_tx = subMenu[idx][2];   a_pos = subMenu[idx][3].toInt();
      b_tx = subMenu[idx][4];   b_pos = subMenu[idx][5].toInt();
      c_tx = subMenu[idx][6];   c_pos = subMenu[idx][7].toInt();
      B_tx = subMenu[idx][8];
      C_tx = subMenu[idx][9];
    }
    for(int i = 0; i < 50; i++) {
      if(md == btnMssIndex[i]) {
        idx_m = i;
        break;
      }
    }
    if(idx_m >= 0) {
      mss1 = btnMss[idx_m][1];
      mss2 = btnMss[idx_m][2];
    }else {
      mss1 = "";
      mss2 = "";
    }
    switch(btnMssIndex[idx_m]) {
    case _FIRST_MENU:
      if(_APP_NAME_NUM == 0) {
        mss2 = !switchBtnMode100C ? "  PDF FILE(S)?" : "  POWERPOINT FILE?";
      }else {
        mss2 = switchBtnMode100C ? "  PDF FILE(S)?" : "  POWERPOINT FILE?";
      }
      break;
    case 48:
      mss2 += repeatingItvName[repeatingItvIndex];
      break;
    case 49:
      mss1 += repeatingItvName[repeatingItvIndex];
      break;
    }
  }
  else {
    switch(md){
    case 240:
      modeName = "MENU 1/4";
      a_tx = "next";      a_pos = 40;
      b_tx = appMenu_str[0][0];
      b_pos = appMenu_pos[0][0];
      if(!_APP_NAME_NUM) {
        c_tx = !switchBtnMode100C ? appMenu_str[0][1] : appMenu_str[0][3];
      }else {
        c_tx = switchBtnMode100C ? appMenu_str[0][1] : appMenu_str[0][3];
      }
      c_pos = appMenu_pos[0][1];
      B_tx = appMenu_str[0][2];
      C_tx = !switchBtnMode100C ? appMenu_str[0][3] : appMenu_str[0][1];
      break;
    case 241:
      modeName = "MENU 2/4";
      a_tx = "next";              a_pos = 40;
      b_tx = appMenu_str[1][0];   b_pos = appMenu_pos[1][0];
      c_tx = appMenu_str[1][1];   c_pos = appMenu_pos[1][1];
      B_tx = appMenu_str[1][2];
      C_tx = appMenu_str[1][3];
      break;
    case 242:
      modeName = "MENU 3/4";
      a_tx = "next";              a_pos = 40;
      b_tx = appMenu_str[2][0];   b_pos = appMenu_pos[2][0];
      c_tx = appMenu_str[2][1];   c_pos = appMenu_pos[2][1];
      B_tx = appMenu_str[2][2];
      C_tx = appMenu_str[2][3];
      break;
    case 243:
      modeName = "MENU 4/4";
      a_tx = "next";              a_pos = 40;
      b_tx = appMenu_str[3][0];   b_pos = appMenu_pos[3][0];
      c_tx = appMenu_str[3][1];   c_pos = appMenu_pos[3][1];
      B_tx = appMenu_str[3][2];
      C_tx = appMenu_str[3][3];
      break;
    }
    mss1 = "";
    mss2 = "";
  }
}
