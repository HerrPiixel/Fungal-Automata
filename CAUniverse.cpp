#include "CAUniverse.h"

CAUniverse::CAUniverse(int8_t ruleNr)
{
	present = std::vector<int8_t>(_DEFAULT_UNIVERSE_SIZE, _DEFAULT_STATE);
	future = std::vector<int8_t>(_DEFAULT_UNIVERSE_SIZE, _DEFAULT_STATE);
	rules = std::vector<int8_t>(_DEFAULT_RULE_SIZE, _DEFAULT_RULE_STATE);
	//rules[0] is for Neighbourhood 111 and rules[7] for 000
	for (int i = _DEFAULT_RULE_SIZE; i > 0; i--) {
		rules[i - 1] = ruleNr % 2;
		ruleNr = ruleNr / 2;
	}
}

CAUniverse::CAUniverse(int8_t ruleNr, std::vector<int8_t> configuration)
{
	present = configuration;
	future = std::vector<int8_t>(configuration.size(), _DEFAULT_STATE);
	rules = std::vector<int8_t>(_DEFAULT_RULE_SIZE, _DEFAULT_RULE_STATE);
	//rules[0] is for Neighbourhood 111 and rules[7] for 000
	for (int i = _DEFAULT_RULE_SIZE; i > 0; i--) {
		rules[i - 1] = ruleNr % 2;
		ruleNr = ruleNr / 2;
	}
}

CAUniverse::CAUniverse(std::vector<int8_t> rules)
{
	present = std::vector<int8_t>(_DEFAULT_UNIVERSE_SIZE, _DEFAULT_STATE);
	future = std::vector<int8_t>(_DEFAULT_UNIVERSE_SIZE, _DEFAULT_STATE);
	this->rules = rules;
}

CAUniverse::CAUniverse(std::vector<int8_t> rules, std::vector<int8_t> configuration)
{
	present = configuration;
	future = std::vector<int8_t>(configuration.size(), _DEFAULT_STATE);
	this->rules = rules;
}

void CAUniverse::nextStep()
{
	int rulecase = 0;
	for (int k = 0; k < present.size(); k++) {
		if (k == 0) {
			rulecase = present[k] * 2 + present[k + 1];
			future[k] = rules[7 - rulecase];
		}
		else if (k == present.size() - 1) {
			rulecase = present[k - 1] * 4 + present[k] * 2;
			future[k] = rules[7 - rulecase];
		}
		else {
			rulecase = present[k - 1] * 4 + present[k] * 2 + present[k + 1];
			future[k] = rules[7 - rulecase];
		}
	}
	present = future;
}

//Add Boundary checks
void CAUniverse::set(int32_t cell, int8_t value)
{
	present[cell] = value;
}

int8_t CAUniverse::get(int32_t cell)
{
	return present[cell];
}
