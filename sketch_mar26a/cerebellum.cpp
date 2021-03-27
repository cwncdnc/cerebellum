#include <pRNG.h>

#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>

#include "cerebellum.h"

pRNG prng;

void cerebellum(){
  int vcode = prng.getRndInt();
  switch(vcode){
    
    default:break;
  }
  //Serial.write(27);
}
