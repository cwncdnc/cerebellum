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
  
  cerebellum_thread.onRun(cerebellum);
  leftbrain_thread.onRun(leftbrain);
  rightbrain_thread.onRun(rightbrain);
 
  cerebellum_thread.setInterval(81);
  leftbrain_thread.setInterval(31);
  rightbrain_thread.setInterval(31);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
    if(cerebellum_thread.shouldRun())
    cerebellum_thread.run();
    if(leftbrain_thread.shouldRun())
    leftbrain_thread.run();
    if(rightbrain_thread.shouldRun())
    rightbrain_thread.run();

}
