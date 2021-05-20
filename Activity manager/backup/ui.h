#pragma once
#include "service.h"
#include <iostream>

class Ui {

public:
	Ui(ServActiv& servo2) noexcept: servo{servo2} {}
	void start() noexcept;

private:
	ServActiv& servo;
};