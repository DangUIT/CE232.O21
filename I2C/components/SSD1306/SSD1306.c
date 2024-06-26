#include <SSD1306.h>
#include <font8x8_basic.h>

static const char *TAG = "SSD1306";

const unsigned char UITlogo [1024]= {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xbf, 
	0xbf, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x0f, 0x07, 0x87, 0x83, 0xc3, 0x41, 0xe1, 
	0xe1, 0xf0, 0x70, 0x50, 0xf8, 0xf8, 0xfc, 0xdc, 0xd4, 0xfe, 0xee, 0xff, 0xff, 0x75, 0x7f, 0x7f, 
	0x3b, 0x3f, 0x1f, 0x1d, 0x9f, 0x9f, 0xcf, 0xcf, 0xcf, 0xc7, 0xe7, 0xe7, 0xe7, 0xf7, 0xf3, 0xf3, 
	0xf3, 0xfb, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xfd, 0xfc, 0xfc, 0xfc, 0xfc, 0x7c, 0xfc, 0xfc, 
	0xfc, 0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf9, 0xf3, 
	0xf3, 0xe7, 0xe7, 0xcf, 0x9f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x7f, 0xf7, 0xf3, 0x51, 0x78, 0xbc, 0xf4, 0xd6, 0xfe, 0xef, 0xf5, 0xf7, 0x7f, 0x7f, 0x3d, 0x1f, 
	0x1f, 0x1f, 0x8f, 0xcf, 0xc7, 0xc7, 0xe3, 0xf3, 0xf1, 0xf1, 0xf9, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfd, 
	0xf7, 0xef, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7b, 
	0x7d, 0x3d, 0x1e, 0x1f, 0x0f, 0x07, 0x07, 0x83, 0xc1, 0xe1, 0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 
	0xff, 0xff, 0xff, 0x3f, 0x1f, 0x07, 0x83, 0xc1, 0xe0, 0x70, 0x70, 0x38, 0x1c, 0x0d, 0x0f, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x0d, 0x1d, 0x18, 0x38, 0x70, 0xe0, 0xe1, 0xc3, 0x87, 0x0f, 0x1f, 0x7f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfc, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 
	0xc0, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xc3, 0x83, 0x83, 0x83, 0x83, 0xff, 
	0xff, 0xff, 0xfb, 0xff, 0x9f, 0x8f, 0x87, 0x87, 0x86, 0xc6, 0xe6, 0xe6, 0xee, 0xfc, 0xfc, 0xfc, 
	0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xee, 0xe6, 0xc6, 0xc6, 0x87, 0x87, 0x87, 0x8f, 0xbf, 0xff, 
	0xff, 0xff, 0xff, 0xbf, 0x83, 0x83, 0x83, 0x83, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xbf, 0xef, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xcf, 0xcf, 0x8f, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x3f, 
	0x3d, 0x79, 0x79, 0x79, 0xf1, 0xe1, 0xe1, 0xc1, 0xc3, 0x87, 0x8f, 0x1f, 0x3f, 0x3f, 0x7f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x8f, 0x87, 0xc3, 0xc3, 0xe1, 0xe1, 0xf1, 0xf1, 0x79, 
	0x79, 0x3d, 0x3d, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x8f, 0x8f, 0xcf, 0xef, 0xef, 0xf7, 0xfb, 0xfd, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 
	0x1f, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 
	0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe0, 0xe0, 0xe0, 
	0xe1, 0xe3, 0x61, 0xe0, 0xe0, 0xe2, 0xa1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 
	0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 
	0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf9, 
	0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
void ssd1306_init()
{
	esp_err_t espRc;

	i2c_cmd_handle_t cmd = i2c_cmd_link_create();

	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, (OLED_I2C_ADDRESS << 1) | I2C_MASTER_WRITE, true);
	i2c_master_write_byte(cmd, OLED_CONTROL_BYTE_CMD_STREAM, true);

	i2c_master_write_byte(cmd, OLED_CMD_SET_CHARGE_PUMP, true);
	i2c_master_write_byte(cmd, 0x14, true);

	i2c_master_write_byte(cmd, OLED_CMD_SET_SEGMENT_REMAP, true); // reverse left-right mapping
	i2c_master_write_byte(cmd, OLED_CMD_SET_COM_SCAN_MODE, true); // reverse up-bottom mapping

	i2c_master_write_byte(cmd, OLED_CMD_DISPLAY_NORMAL, true);
	i2c_master_write_byte(cmd, OLED_CMD_DISPLAY_OFF, true);
	i2c_master_write_byte(cmd, OLED_CMD_DISPLAY_ON, true);
	i2c_master_stop(cmd);

	espRc = i2c_master_cmd_begin(I2C_NUM_0, cmd, 10 / portTICK_PERIOD_MS);
	if (espRc == ESP_OK)
	{
		ESP_LOGI(TAG, "OLED configured successfully");
	}
	else
	{
		ESP_LOGE(TAG, "OLED configuration failed. code: 0x%.2X", espRc);
	}
	i2c_cmd_link_delete(cmd);
}

void task_ssd1306_display_text(const void *arg_text)
{
	char *text = (char *)arg_text;
	uint8_t text_len = strlen(text);

	i2c_cmd_handle_t cmd;

	uint8_t cur_page = 0;

	cmd = i2c_cmd_link_create();
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, (OLED_I2C_ADDRESS << 1) | I2C_MASTER_WRITE, true);
	i2c_master_write_byte(cmd, OLED_CONTROL_BYTE_CMD_STREAM, true);

	i2c_master_write_byte(cmd, 0x00, true);			   // reset column - choose column --> 0
	i2c_master_write_byte(cmd, 0x10, true);			   // reset line - choose line --> 0
	i2c_master_write_byte(cmd, 0xB0 | cur_page, true); // reset page

	i2c_master_stop(cmd);
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 10 / portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	for (uint8_t i = 0; i < text_len; i++)
	{
		if (text[i] == '\n')
		{
			cmd = i2c_cmd_link_create();
			i2c_master_start(cmd);
			i2c_master_write_byte(cmd, (OLED_I2C_ADDRESS << 1) | I2C_MASTER_WRITE, true);

			i2c_master_write_byte(cmd, OLED_CONTROL_BYTE_CMD_STREAM, true);
			i2c_master_write_byte(cmd, 0x00, true); // reset column
			i2c_master_write_byte(cmd, 0x10, true);
			i2c_master_write_byte(cmd, 0xB0 | ++cur_page, true); // increment page

			i2c_master_stop(cmd);
			i2c_master_cmd_begin(I2C_NUM_0, cmd, 10 / portTICK_PERIOD_MS);
			i2c_cmd_link_delete(cmd);
		}
		else
		{
			cmd = i2c_cmd_link_create();
			i2c_master_start(cmd);
			i2c_master_write_byte(cmd, (OLED_I2C_ADDRESS << 1) | I2C_MASTER_WRITE, true);

			i2c_master_write_byte(cmd, OLED_CONTROL_BYTE_DATA_STREAM, true);

			i2c_master_write(cmd, font8x8_basic_tr[(uint8_t)text[i]], 8, true);

			i2c_master_stop(cmd);
			i2c_master_cmd_begin(I2C_NUM_0, cmd, 10 / portTICK_PERIOD_MS);
			i2c_cmd_link_delete(cmd);
		}
	}

	// vTaskDelete(NULL);
}

void task_ssd1306_display_clear()
{
	i2c_cmd_handle_t cmd;

	uint8_t clear[128];
	for (uint8_t i = 0; i < 128; i++)
	{
		clear[i] = 0;
	}
	for (uint8_t i = 0; i < 8; i++)
	{
		cmd = i2c_cmd_link_create();
		i2c_master_start(cmd);
		i2c_master_write_byte(cmd, (OLED_I2C_ADDRESS << 1) | I2C_MASTER_WRITE, true);
		i2c_master_write_byte(cmd, OLED_CONTROL_BYTE_CMD_SINGLE, true);
		i2c_master_write_byte(cmd, 0xB0 | i, true);

		i2c_master_write_byte(cmd, OLED_CONTROL_BYTE_DATA_STREAM, true);
		i2c_master_write(cmd, clear, 128, true);
		i2c_master_stop(cmd);
		i2c_master_cmd_begin(I2C_NUM_0, cmd, 10 / portTICK_PERIOD_MS);
		i2c_cmd_link_delete(cmd);
	}

	// vTaskDelete(NULL);
}

void draw(const void *arg_text)
{
	char *text = (char *)arg_text;
	

	i2c_cmd_handle_t cmd;
	uint8_t cur_page = 0;
	cmd = i2c_cmd_link_create();
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, (OLED_I2C_ADDRESS << 1) | I2C_MASTER_WRITE, true);
	i2c_master_write_byte(cmd, OLED_CONTROL_BYTE_CMD_STREAM, true);

	i2c_master_write_byte(cmd, 0x00, true);			   // reset column - choose column --> 0
	i2c_master_write_byte(cmd, 0x10, true);			   // reset line - choose line --> 0
	i2c_master_write_byte(cmd, 0xB0 | cur_page, true); // reset page

	i2c_master_write_byte(cmd, 0x20, true);			   // set memory
	i2c_master_write_byte(cmd, 0x00, true);			   // Horizontal addressing mode

	i2c_master_stop(cmd);
	i2c_master_cmd_begin(I2C_NUM_0, cmd, 10 / portTICK_PERIOD_MS);
	i2c_cmd_link_delete(cmd);

	for (int i = 0; i <1024; i++)
	{
		cmd = i2c_cmd_link_create();
		i2c_master_start(cmd);
		i2c_master_write_byte(cmd, (OLED_I2C_ADDRESS << 1) | I2C_MASTER_WRITE, true);

		i2c_master_write_byte(cmd, OLED_CONTROL_BYTE_DATA_STREAM, true);

		i2c_master_write_byte(cmd, text[i], true);

		i2c_master_stop(cmd);
		i2c_master_cmd_begin(I2C_NUM_0, cmd, 10 / portTICK_PERIOD_MS);
		i2c_cmd_link_delete(cmd);
	}
	// vTaskDelete(NULL);
}
void drawlogo()
{
	draw(UITlogo);
}
