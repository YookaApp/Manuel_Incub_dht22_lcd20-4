
#ifndef lcd
#define lcd

#include "prototypes.h"
#include <LiquidCrystal_I2C.h>

char tableau[2];
LiquidCrystal_I2C lcd_tempe(0x27, 20, 4);

void affichage(){  
  sprintf(tableau,"%cC ", char(0b11011111));
  lcd_tempe.setCursor(5, 0);
  lcd_tempe.print("INCUBATOR.");
  
  lcd_tempe.print("");
  lcd_tempe.setCursor(4, 1);
  lcd_tempe.print("T");
  lcd_tempe.print(char(0b11011111));
  lcd_tempe.setCursor(15, 1);
  lcd_tempe.print("H");
    
  lcd_tempe.setCursor(2, 2);

  lcd_tempe.print(tempe, 1);
  lcd_tempe.print(tableau);
  
  lcd_tempe.setCursor(13, 2);
  lcd_tempe.print(humidy, 1);
  lcd_tempe.print('%');
  

}
#endif
