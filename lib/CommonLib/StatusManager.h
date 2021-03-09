#ifndef CommonLib_StatusManager_H
#define CommonLib_StatusManager_H

#include "oled.h"

#define LINE_BUFFER_SIZE 64

class StatusManager {
	uint64_t scrollTimer;
	uint16_t messagePos[OLED_ROWS];
	uint16_t messageLen[OLED_ROWS];
	char *messages[OLED_ROWS];
	OledDisplay *oled;

	void formatLine(uint8_t line, const char *message);
	void scroll();
	void write(uint8_t line);
	void printOffset(char *message, int16_t offset);

   public:
	StatusManager(OledDisplay *lcd);
	~StatusManager();

	void update();
	void clear();
	void put(uint8_t line, const char* message);
};

#endif