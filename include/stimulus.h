/*
 * stimulus.h
 *
 *  Created on: Jul 28, 2018
 *      Author: b1-166er
 */

#ifndef STIMULUS_H_
#define STIMULUS_H_

namespace EmotionsModel {

	class stimulus {

	public:
		double mArousal;
		double mValence;

		stimulus(double arousal, double valence);
		virtual ~stimulus();
	};
}

#endif /* STIMULUS_H_ */
