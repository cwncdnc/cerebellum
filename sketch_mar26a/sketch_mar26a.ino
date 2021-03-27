#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>

#include "cerebellum.h"
#include "leftbrain.h"
#include "rightbrain.h"

/* BN: Unknown board
VID: 1A86
PID: 7523
SN: Upload any sketch to obtain it
avrdude: Device signature = 0x1e950f (probably m328p)
 */

Thread cerebellum_thread = Thread();
Thread leftbrain_thread = Thread();
Thread rightbrain_thread = Thread();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

}
