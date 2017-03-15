#pragma once

#include <iostream>

#include "def.impl.h"

struct GooBoo : Boo {
	void foo(int) override {
		std::cerr << "GooMoo::foo(int)";
	}

	void foo(double) override;
};

