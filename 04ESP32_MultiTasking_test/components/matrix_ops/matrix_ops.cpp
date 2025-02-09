#include "matrix_ops.h"

// Constructor
imageRead::imageRead(const char* taskName, uint8_t image[IMAGE_HEIGHT][IMAGE_WIDTH])
    : taskName(taskName), image(image), taskHandle(NULL) {
    // Create the FreeRTOS task
    xTaskCreate(
        taskFunction,    // Task function (must be static)
        taskName,        // Task name (for debugging)
        2048,            // Stack size (in words)
        this,            // Pass 'this' pointer as task parameter
        1,               // Task priority
        &taskHandle      // Task handle
    );
}

// Destructor
imageRead::~imageRead() {
    if (taskHandle != NULL) {
        vTaskDelete(taskHandle); // Delete the task
    }
}

// Static task function (required by FreeRTOS)
void imageRead::taskFunction(void* pvParameters) {
    // Cast the parameter back to the class instance
    imageRead* taskInstance = static_cast<imageRead*>(pvParameters);

    // Call the member function to read and print the image
    taskInstance->readImage();
}

// Member function to read and print the image
void imageRead::readImage() {
    printf("Task '%s' reading 10x10 image:\n", taskName);
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            printf("%d ", image[y][x]); // Print each pixel value
        }
        printf("\n"); // New line after each row
    }
    printf("Image read complete.\n");

    // Delete the task after completion
    vTaskDelete(NULL);
}