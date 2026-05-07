#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>
#include <driver/ledc.h>  // 添加包含ledc相关类型定义的头文件

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// 如果使用 Duplex I2S 模式，请注释下面一行
#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX

#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_4
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_7
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_15
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_16

#else

#define AUDIO_I2S_GPIO_WS GPIO_NUM_4
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_7

#endif


#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_47
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_40
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39

#define DISPLAY_SDA_PIN GPIO_NUM_41
#define DISPLAY_SCL_PIN GPIO_NUM_42
#define DISPLAY_WIDTH   128
#define DISPLAY_HEIGHT  64

#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y true

// 手势识别模块配置 - PAJ7620U2
#define GESTURE_I2C_SDA_PIN GPIO_NUM_41  // 手势识别传感器SDA引脚，与显示屏共用I2C总线
#define GESTURE_I2C_SCL_PIN GPIO_NUM_42  // 手势识别传感器SCL引脚，与显示屏共用I2C总线
#define GESTURE_I2C_ADDR 0x73           // PAJ7620U2传感器I2C地址
#define GESTURE_I2C_FREQ_HZ 100000      // I2C通信频率，设置为100kHz以确保稳定性
#define GESTURE_I2C_PORT I2C_NUM_0      // 使用I2C端口0（与显示屏共用）

// 舵机引脚配置
#define SERVO_HORIZONTAL_PIN GPIO_NUM_11  // 水平舵机连接到GPIO11
#define SERVO_VERTICAL_PIN GPIO_NUM_12    // 垂直舵机连接到GPIO12

// 舵机角度范围配置 - 根据boardemoji.ino的设置，但限制运动范围以保护舵机
#define SERVO_CENTER_X 90    // 水平舵机中心位置(90度)
#define SERVO_CENTER_Y 90     // 垂直舵机中心位置(90度)
#define SERVO_MIN_X (SERVO_CENTER_X - 40)  // 水平舵机最小角度(左边界) - 中心位置左侧40度
#define SERVO_MAX_X (SERVO_CENTER_X + 40)  // 水平舵机最大角度(右边界) - 中心位置右侧40度
#define SERVO_MIN_Y (SERVO_CENTER_Y - 20)  // 垂直舵机最小角度(上边界) - 中心位置上方20度
#define SERVO_MAX_Y (SERVO_CENTER_Y + 20)  // 垂直舵机最大角度(下边界) - 中心位置下方20度

// 原始boardemoji.ino中的步进和延迟值
#define SERVO_STEP 1           // Arduino中的STEP值
#define SERVO_DELAY 10         // Arduino中的SERVO_DELAY值

// 舵机PWM配置，参考Arduino原始代码设置
#define SERVO_MIN_PULSEWIDTH 500        // 最小脉宽(微秒)
#define SERVO_MAX_PULSEWIDTH 2500       // 最大脉宽(微秒)
#define LEDC_TIMER_BIT_WIDTH LEDC_TIMER_14_BIT  // 14位分辨率
#define LEDC_TIMER LEDC_TIMER_0         // 使用定时器0
#define LEDC_MODE LEDC_LOW_SPEED_MODE   // 使用低速模式
#define LEDC_FREQUENCY 50               // PWM频率50Hz

// 舵机通道配置
#define SERVO_CHANNEL_COUNT 2                      // 舵机通道数量
const ledc_channel_t servo_channels[SERVO_CHANNEL_COUNT] = {
    LEDC_CHANNEL_0,  // 水平舵机使用通道0
    LEDC_CHANNEL_1   // 垂直舵机使用通道1
};

// 舵机引脚数组配置
const uint8_t servo_pins[SERVO_CHANNEL_COUNT] = {
    SERVO_HORIZONTAL_PIN,  // 水平舵机
    SERVO_VERTICAL_PIN,    // 垂直舵机
};

// A MCP Test: Control a lamp
#define LAMP_GPIO GPIO_NUM_18

#endif // _BOARD_CONFIG_H_
