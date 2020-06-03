#pragma once

#include "Universe.h"
#include <cstdint>
#include <vector>
#include <iostream> //for testing

class CAUniverse :
	protected Universe
{
private:
	const static int16_t _DEFAULT_UNIVERSE_SIZE = 100;
	const static int16_t _DEFAULT_RULE_SIZE = 8;
	const static int8_t _DEFAULT_STATE = 0;
	const static int8_t _DEFAULT_RULE_STATE = 0;

	CAUniverse();

	std::vector<int8_t> present;
	std::vector<int8_t> future;
	std::vector<int8_t> rules;

public:
	CAUniverse(int8_t ruleNr);
	CAUniverse(int8_t ruleNr, std::vector<int8_t> configuration);
	CAUniverse(std::vector<int8_t> rules);
	CAUniverse(std::vector<int8_t> rules, std::vector<int8_t> configuration);

	void nextStep();

	void set(int32_t cell, int8_t value);
	int8_t get(int32_t cell);
};

