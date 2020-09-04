#include "ImageCreator.h"


ImageCreator::ImageCreator(uint16_t width, uint16_t height, std::string filename)
{
	//test if file already exists
	file.open(filename);
	if (file.is_open()) {
		file.close();
		throw std::invalid_argument("File already exists");
	}
	file.close();
	
	//create file
	file.open(filename,std::ios::out);
	if (!file.is_open()) {
		file.close();
		throw std::logic_error("File could not be created");
	}
	file.close();

	//write header for PortablePixMap format
	file.open(filename, std::ios::binary | std::ios::in | std::ios::out);
	if (!file.is_open()) {
		file.close();
		throw std::logic_error("File could not be properly opened");
	}
	closed = false;
	file << "P3\n" << width << " " << height << "\n" << "255\n";

	_width = width;
	_height = height;

	//create image array
	std::vector<uint8_t> temp1(3, 0);
	std::vector<std::vector<uint8_t>> temp2(height, temp1);
	img = std::vector<std::vector<std::vector<uint8_t>>>(width, temp2);
}

ImageCreator::ImageCreator(uint16_t width, uint16_t height, std::string filename, bool overwriteable)
{
	//mostly the same as standard constructor
	//differences:
	//- no error when file already exists but overwriting is allowed
	//- file is truncated when properly opened

	//test if file already exists
	file.open(filename);
	if (file.is_open() && !overwriteable) {
		file.close();
		throw std::invalid_argument("File already exists");
	}
	file.close();

	//create file
	file.open(filename, std::ios::out);
	if (!file.is_open()) {
		file.close();
		throw std::logic_error("File could not be created");
	}
	file.close();

	//write header for PortablePixMap format
	file.open(filename, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
	if (!file.is_open()) {
		file.close();
		throw std::logic_error("File could not be properly opened");
	}
	closed = false;
	file << "P3\n" << width << " " << height << "\n" << "255\n";

	_width = width;
	_height = height;

	//create image array
	std::vector<uint8_t> temp1(3, 0);
	std::vector<std::vector<uint8_t>> temp2(height, temp1);
	img = std::vector<std::vector<std::vector<uint8_t>>>(width, temp2);
}

void ImageCreator::set(uint16_t x, uint16_t y, uint8_t red, uint8_t blue, uint8_t green)
{
	if (x >= _width || y >= _height) {
		throw std::invalid_argument("Coordinate out of image");
	}
	img[x][y][0] = red;
	img[x][y][1] = blue;
	img[x][y][2] = green;
}

uint8_t ImageCreator::getRed(uint16_t x, uint16_t y)
{
	if (x >= _width || y >= _height) {
		throw std::invalid_argument("Coordinate out of image");
	}
	return img[x][y][0];
}

uint8_t ImageCreator::getBlue(uint16_t x, uint16_t y)
{
	if (x >= _width || y >= _height) {
		throw std::invalid_argument("Coordinate out of image");
	}
	return img[x][y][1];
}

uint8_t ImageCreator::getGreen(uint16_t x, uint16_t y)
{
	if (x >= _width || y >= _height) {
		throw std::invalid_argument("Coordinate out of image");
	}
	return img[x][y][2];
}

void ImageCreator::close()
{
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			file << std::to_string(img[j][i][0]) << " " << std::to_string(img[j][i][1]) << " " << std::to_string(img[j][i][2]) << "\n";
		}
	}
	file.close();
	closed = true;
}
