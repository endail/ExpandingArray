#include "../src/ExpandingArray.h"

using namespace endail;

#define ARR_LENGTH 50;

void setup() {

	while(!Serial);
	Serial.begin(115200);

	ExpandingArray<int> arr(ARR_LENGTH);

	for(int i = 0; i < arr.length(); ++i) {
		arr[i] = random();
	}

	for(auto ptr = arr.ptr(); ptr != arr.end(); ++ptr) {
		Serial.println(*ptr);
	}

}

void loop() {
}
