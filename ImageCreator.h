#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>

/// @brief Creates images in PortablePixMap (.ppm) format. 
class ImageCreator
{
private:
	std::fstream file;
	std::vector<std::vector<std::vector<uint8_t>>> img;
	uint16_t _width;
	uint16_t _height;
	bool closed;

public:
	/// @brief Standard constructor.
	/// @param width Width of the picture in pixel.
	/// @param height Height of the picture in pixel.
	/// @param filename Path to the image. File should not exists beforehand.
	ImageCreator(uint16_t width, uint16_t height, std::string filename);

	/// @brief Constructor that can overwrite already existing file.
	/// @param width Width of the picture in pixel.
	/// @param height Height of the pixture in pixel.
	/// @param filename path to the image. If the file already exists, set overwriteable = true to overwrite.
	/// @param overwriteable Set to true if file already exists and should be overwritten.
	ImageCreator(uint16_t width, uint16_t height, std::string filename,bool overwriteable);

	/// @brief Set RGB value of specific pixel.
	/// @param x x coordinate of pixel.
	/// @param y y coordinate of pixel.
	/// @param red red value of RGB color.
	/// @param blue blue value of RGB color.
	/// @param green green value of RGB color.
	void set(uint16_t x, uint16_t y, uint8_t red, uint8_t blue, uint8_t green);

	/// @brief Get red value of RGB value of specific pixel.
	/// @param x x coordinate of pixel.
	/// @param y y coordinate of pixel.
	/// @return Red Value of specific pixel.
	uint8_t getRed(uint16_t x, uint16_t y);

	/// @brief Get blue value of RGB value of specific pixel.
	/// @param x x coordinate of pixel.
	/// @param y y coordinate of pixel.
	/// @return Blue Value of specific pixel.
	uint8_t getBlue(uint16_t x, uint16_t y);

	/// @brief Get green value of RGB value of specific pixel.
	/// @param x x coordinate of pixel.
	/// @param y y coordinate of pixel.
	/// @return Green Value of specific pixel.
	uint8_t getGreen(uint16_t x, uint16_t y);

	/// @brief creates the image and closes the ImageCreator, blocking subsequent setting of pixels.
	void close();
};

