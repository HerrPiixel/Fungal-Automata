#pragma once

#include <cstdint>
#include <vector>
#include <stdexcept>

/// @brief Simulates a Cellular Automata and allows to change the configuration during simulation.
class CellularAutomata
{
private:
	std::vector<uint8_t> rules;
	std::vector<uint8_t> _configuration;


public:
	/// @brief Standard constructor
	/// @param universeSize Size of the universe, cells over the edges are set to 0.
	/// @param ruleNr Rule number after the normaly used convention.
	CellularAutomata(uint16_t universeSize, uint8_t ruleNr);

	/// @brief Standard constructor with start configuration
	/// @param universeSize Size of the universe, cells over the edges are set to 0.
	/// @param ruleNr Rule number after the normaly used convention. 
	/// @param configuration The start configuration. Has to have the same size as universeSize.
	CellularAutomata(uint16_t universeSize, uint8_t ruleNr, std::vector<uint8_t> configuration);

	/// @brief Sets a specific cell to a specific value.
	/// @param coordinate Coordinate of the cell.
	/// @param value The value the cell should be set to.
	void setCell(uint16_t coordinate, uint8_t value);

	/// @brief sets the whole universe to a specific configuration.
	/// @param configuration The configuration the universe should be set to. Must have the same size as the universe.
	void setConfiguration(std::vector<uint8_t> configuration);

	/// @brief get the value of a specific cell.
	/// @param coordinate coordinate of the cell.
	/// @return the value as a integer.
	uint8_t getCell_int(uint16_t coordinate);

	/// @brief get the entire configuration.
	/// @return A vector as the configuration.
	std::vector<uint8_t> getConfiguration();

	/// @brief Sets the configuration to the next generation based on the given rule.
	void nextStep();
};

