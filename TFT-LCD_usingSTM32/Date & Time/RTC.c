void RTCinit(void)
{ //init sequence
	PWR -> CR |= PWR_CR_DBP;
	RCC -> CFGR |= 25 << 16;
	RCC -> BDCR |= RCC_BDCR_RTCSEL;
	RCC -> BDCR |= RCC_BDCR_RTCEN;
	RTC -> WPR = 0xCA;
	RTC -> WPR = 0x53; //DISABLE RTC WRITE PROTECT
	RTC -> ISR |= RTC_ISR_INIT | 1<<11; //INITIALIZE RTC
	while(!(RTC -> ISR & RTC_ISR_INITF)); //WAIT
	RTC -> PRER = 0x00000000;
	RTC -> PRER = (127 << 16) | 2399;
  //init sequence ends
	RTC -> CR |= RTC_CR_FMT | RTC_CR_TSE; //Configure the time format
	RTC->TR = (0x13 << 16) | (0x58 << 8) | 0x00; //Configure hour,min,sec
	RTC->DR = (1<<0) |        // Date (DD = 01)
          (8<<8) |        // Month (MM = 08)
          (4<<16) |       // Year Units (YY = 20)
          (2<<20) | (Sunday<<13);        // Year Tens (YY = 24)
	RTC -> ISR &= ~RTC_ISR_INIT; //Exit initialization mode.
	RTC -> WPR = 0xFF;
	PWR -> CR &= ~PWR_CR_DBP;
}
int main(){
RTCinit();
displayGpioInit();			//Init LCD I/O and SPI
Init_Dispaly();					//Send Init Commands and Data
LCDInit();	
Text(VIS1, LT_ALN, 40, 40, "Time Now", B4LIB20, 0,0,31, 0,0,0);
	Text(VIS1, LT_ALN, 15, 160, "Date Today", B4LIB20, 0,0,31, 0,0,0);
	uint32_t dr = RTC->DR;
	const uint8_t weekday = (dr >> 13) & 0x07;
	switch (weekday){
		case 0:
		Text(VIS1, LT_ALN, 65, 160, "Invalid Day", B4LIB14, 0,0,31, 0,0,0);
		break;
		case Monday:
		Text(VIS1, LT_ALN, 65, 120, "Monday", B4LIB14, 0,0,31, 0,0,0);
		break;
		case Tuesday:
		Text(VIS1, LT_ALN, 65, 120, "Tuesday", B4LIB14, 0,0,31, 0,0,0);
		break;
		case Wednesday:
		Text(VIS1, LT_ALN, 65, 120, "Wednesday", B4LIB14, 0,0,31, 0,0,0);
		break;
		case Thursday:
		Text(VIS1, LT_ALN, 65, 120, "Thursday", B4LIB14, 0,0,31, 0,0,0);
		break;
		case Friday:
		Text(VIS1, LT_ALN, 65, 120, "Friday", B4LIB14, 0,0,31, 0,0,0);
		break;
		case Saturday:
		Text(VIS1, LT_ALN, 65, 120, "Saturday", B4LIB14, 0,0,31, 0,0,0);
		break;
		case Sunday:
		Text(VIS1, LT_ALN, 65, 120, "Sunday", B4LIB14, 0,0,31, 0,0,0);
		break;
	}
	while(1){

	uint32_t tr = RTC->TR; // Read the TR register
	// Extract BCD values
	uint8_t hours_tens = (tr >> 20) & 0x03;
	uint8_t hours_units = (tr >> 16) & 0x0F;
	uint8_t minutes_tens = (tr >> 12) & 0x07;
	uint8_t minutes_units = (tr >> 8) & 0x0F;
	uint8_t seconds_tens = (tr >> 4) & 0x07;
	uint8_t seconds_units = tr & 0x0F;
	uint8_t year_tens = (dr >> 20) & 0x0F;
	uint8_t year_units = (dr >> 16) & 0x0F;
	uint8_t month_tens = (dr >> 12) & 0x01;
	uint8_t month_units = (dr >> 8) & 0x0F;
	uint8_t day_tens = (dr >> 4) & 0x0F;
	uint8_t day_units = dr & 0x0F;
	// Convert BCD to decimal
	uint8_t hours = (hours_tens * 10) + hours_units;
	uint8_t minutes = (minutes_tens * 10) + minutes_units;
	uint8_t seconds = (seconds_tens * 10) + seconds_units;
	uint8_t year =  (year_tens * 10) + year_units;
	uint8_t month = (month_tens * 10) + month_units;
	uint8_t day = (day_tens * 10) + day_units;
	char date[20];
		sprintf(date, "%02d/%02d/%02d", day,month,year);
		Text(VIS1, LT_ALN, 65, 200, &date, B4LIB14, 0,0,31, 0,0,0);
	char time[20];
		sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);
		Text(VIS1, LT_ALN, 65, 80, &time, B4LIB14, 0,0,31, 0,0,0);}
}
