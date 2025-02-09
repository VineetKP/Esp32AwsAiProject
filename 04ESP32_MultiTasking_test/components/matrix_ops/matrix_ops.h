#include <stdio.h>
#include <stdlib.h>
#include "enums.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

// Define image dimensions
#define IMAGE_WIDTH  10
#define IMAGE_HEIGHT 10

// Class to encapsulate a FreeRTOS task
class imageRead {
public:
    // Constructor
    imageRead(const char* taskName, uint8_t image[IMAGE_HEIGHT][IMAGE_WIDTH]);

    // Destructor
    ~imageRead();

private:
    const char* taskName;               // Task name
    uint8_t (*image)[IMAGE_WIDTH];      // Pointer to the image
    TaskHandle_t taskHandle;            // Task handle

    // Static task function (required by FreeRTOS)
    static void taskFunction(void* pvParameters);

    // Member function to read and print the image
    void readImage();
};
