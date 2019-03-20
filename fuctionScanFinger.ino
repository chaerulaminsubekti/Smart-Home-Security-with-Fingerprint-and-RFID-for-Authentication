void scanning() {
  for (int i = 0; i < 3; i++)
  {
    lcd.clear();
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    lcd.print("Tap Your Fingger");
    delay(2000);
    int result = getFingerprintIDez();
    if (result >= 0)
    {
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(centralock, LOW);
      digitalWrite(alarm, LOW);
      digitalWrite(centralalarm, HIGH);
      digitalWrite(buzzer, LOW);
      lcd.clear();
      lcd.print(" Access Granted ");
      lcd.setCursor(0, 1);
      lcd.print("    Door Open   ");
      delay(5000);
      return;
    }
  }

}
