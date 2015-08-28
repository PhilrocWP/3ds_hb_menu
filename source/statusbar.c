#include <stdio.h>
#include <string.h>

#include "statusbar.h"
#include "gfx.h"

#include "wifi_full_bin.h"
#include "wifi_none_bin.h"
#include "battery_full_bin.h"
#include "battery_mid_high_bin.h"
#include "battery_mid_low_bin.h"
#include "battery_low_bin.h"
#include "battery_lowest_bin.h"
#include "battery_charging_bin.h"

u8* batteryLevels[] = {
	(u8*)battery_lowest_bin,
	(u8*)battery_lowest_bin,
	(u8*)battery_low_bin,
	(u8*)battery_mid_low_bin,
	(u8*)battery_mid_high_bin,
	(u8*)battery_full_bin,
};

#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

void drawStatusBar(bool wifiStatus, bool charging, int batteryLevel)
{
	u64 timeInSeconds = osGetTime() / 1000;
	u64 dayTime = timeInSeconds % SECONDS_IN_DAY;
	u8 24hour = dayTime / SECONDS_IN_HOUR;
	u8 12hour
	if(24hour < 13)
		12hour === 24hour
	if(24hour === 13)
		12hour === 1
	if(24hour === 14)
		12hour === 2
	if(24hour === 15)
		12hour === 3
	if(24hour === 16)
		12hour === 4
	if(24hour === 17)
		12hour === 5
	if(24hour === 18)
		12hour === 6
	if(24hour === 19)
		12hour === 7
	if(24hour === 20)
		12hour === 8
	if(24hour === 21)
		12hour === 9
	if(24hour === 22)
		12hour === 10
	if(24hour === 23)
		12hour === 11
	if(24hour === 24)
		12hour === 12
	u8 min = (dayTime % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
	u8 seconds = dayTime % SECONDS_IN_MINUTE;

	char timeString[17];
	sprintf(timeString, "%02d:%02d:%02d (%02d:%02d:%02d)", 24hour, min, seconds, 12hour, min, seconds);
	gfxDrawText(GFX_TOP, GFX_LEFT, NULL, timeString, 240 - 18, 400 / 2 - 16);

	if(wifiStatus)
	{
		gfxDrawSpriteAlphaBlend(GFX_TOP, GFX_LEFT, (u8*)wifi_full_bin, 18, 20, 240 - 18, 0);
	}
	else
	{
		gfxDrawSpriteAlphaBlend(GFX_TOP, GFX_LEFT, (u8*)wifi_none_bin, 18, 20, 240 - 18, 0);
	}

	if(charging)
	{
		gfxDrawSpriteAlphaBlend(GFX_TOP, GFX_LEFT, (u8*)battery_charging_bin, 18, 27, 240 - 18, 400 - 27);
	}
	else
	{
		gfxDrawSpriteAlphaBlend(GFX_TOP, GFX_LEFT, batteryLevels[batteryLevel], 18, 27, 240 - 18, 400 - 27);
	}
}

