#include "CellularAutomata.h"

CellularAutomata::CellularAutomata(uint16_t universeSize, uint8_t ruleNr)
{
	//start configuration
	if(universeSize == 0) {
		throw std::invalid_argument("Size of the universe must be greater than 0");
	}
	_configuration = std::vector<uint8_t>(universeSize, 0);

	//creating rules from rule number
	rules = std::vector<uint8_t>(8, 0);
	//rules[0] is for neighbourhood 000 and rules[7] for 111 
	for (int i = 0; i < 8; i++) {
		rules[i] = ruleNr % 2;
		ruleNr = (ruleNr - rules[i]) / 2;
	}
}

CellularAutomata::CellularAutomata(uint16_t universeSize, uint8_t ruleNr, std::vector<uint8_t> configuration)
{
	//start configuration
	if (universeSize == 0) {
		throw std::invalid_argument("Size of the universe must be greater than 0");
	}
	if (configuration.size() != universeSize) {
		throw std::invalid_argument("Size of the start configuration must be the same as the universe");
	}
	_configuration = configuration;

	//creating rules from rule number
	rules = std::vector<uint8_t>(8, 0);
	//rules[0] is for neighbourhood 000 and rules[7] for 111 
	for (int i = 0; i < 8; i++) {
		rules[i] = ruleNr % 2;
		ruleNr = (ruleNr - rules[i]) / 2;
	}
}

void CellularAutomata::setCell(uint16_t coordinate, uint8_t value)
{
	if (coordinate >= _configuration.size()) {
		throw std::invalid_argument("Coordinate is out of universe");
	}

	//We treat cell == 0 as "off" and anything else as "on".
	if (value == 0) {
		_configuration[coordinate] = 0;
	}
	else
	{
		_configuration[coordinate] = 1;
	}
}

void CellularAutomata::setConfiguration(std::vector<uint8_t> configuration)
{
	if (configuration.size() != _configuration.size()) {
		throw std::invalid_argument("New configuration must be the same size as universe");
	}
	//SUGGESTION: maybe set every non-zero value to 1 for uniformity
	_configuration = configuration;
}

uint8_t CellularAutomata::getCell_int(uint16_t coordinate)
{
	if (coordinate >= _configuration.size())
	{
		throw std::invalid_argument("Coordinate is out of universe");
	}
	//if a configuration is set with values that are not zero or one, we output sign(value)
	if (_configuration[coordinate]) {
		return 1;
	}
	else
	{
		return 0;
	}
}

std::vector<uint8_t> CellularAutomata::getConfiguration()
{
	//could be that a configuration is returned that has not been run through sign(x), in that case a non-zero value should be treated as "on" (or 1)
	return _configuration;
}

void CellularAutomata::nextStep()
{	
	//We treat coordinates "outside of the bounds" as constant 0
	
	std::vector<uint8_t> nextConf(_configuration.size(), 0);
	if (_configuration.size() == 1) {
		nextConf[0] = _configuration[0] ? rules[2] : rules[0];
	}
	else
	{	
		//special case for the outer cells, the left side can only be {000, 001, 010, 011} and the right side {000, 010, 100, 110}
		uint8_t _case = (_configuration[0] ? 1 : 0) * 2 + (_configuration[1] ? 1 : 0);
		nextConf[0] = rules[_case];
		_case = (_configuration[_configuration.size() - 1] ? 1 : 0) * 2 + (_configuration[_configuration.size() - 2] ? 1 : 0) * 4;
		nextConf[_configuration.size() - 1] = rules[_case];


		for (int i = 1; i < _configuration.size() - 1; i++) {
			_case = (_configuration[i - 1] ? 1 : 0) * 4 + (_configuration[i] ? 1 : 0) * 2 + (_configuration[i + 1] ? 1 : 0);
			nextConf[i] = rules[_case];
		}
	}
	_configuration = nextConf;
}
