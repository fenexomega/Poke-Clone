/*
 * GELoadingAnimation.h
 *
 *  Created on: 19/02/2014
 *      Author: jordy
 */

#ifndef GEANIMATION_H_
#define GEANIMATION_H_
#include <vector>
#include "Square.h"

class GELoadingAnimation {
private:
	bool active;
	std::vector<Square *> squares;
	 int i;
	int status;
public:
	GELoadingAnimation();
	virtual ~GELoadingAnimation();

	void Begin();
	void Left2Right();
    void UpAndDown();
	void Spiral();

	bool isActive() const {
		return active;
	}

	void setActive(bool active) {
		this->active = active;
	}

	int getStatus() const {
		return status;
	}

	void setStatus(int status) {
		this->status = status;
	}
};

#endif /* GEANIMATION_H_ */
