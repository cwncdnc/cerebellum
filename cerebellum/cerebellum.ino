#include <avr/pgmspace.h> 
#include <pRNG.h>

pRNG prng;

const PROGMEM char vkeys[32] = "abcdefghijklmnopqrstuvwxyz      ";
const char PROGMEM trip[] = "ask=biz=cdj=dev=eye=faq=gap=her=ifs=joy=kit=law=max=nil=own=pad=qua=rig=she=tmi=use=vox=web=xtc=you=zen=";
const char PROGMEM words[] = "latency=agony=memory=envy=identity=authority=certainty=transparency=analogy=conformity=fragility=serenity=tenacity=practicality=humility=epiphany=complexity=simplicity=normality=absurdity=anxiety=sobriety=urgency=emergency=ability=utility=affinity=concurrency=sympathy=apology=empathy=unity=personality=mentality=hostility=expectancy=morality=complacency=hilarity=indignity=humanity=fallacy=atrocity=severity=priority=necessity=reality=actuality=mobility=possibility=responsibility=availability=camaraderie=policy=ubiquity=conspiracy=harmony=family=secrecy=credibility=telepathy=legality=physicality=anonymity=reciprocity=immortality=curiosity=notability=plausibility=deniability=vulnerability=security=incredulity=integrity=antipathy=solidarity=energy=entropy=gravity=density=technology=ecstasy=mimicry=destiny=enmity=amnesty=vanity=tragedy=comedy=idolatry=prophecy=agency=divinity=virtuosity=subtlety=delivery=liberty=anatomy=contingency=dependency=civility=liability=externality=monopoly=society=nobility=democracy=autocracy=similarity=individuality=objectivity=subjectivity=serendipity=synchronicity=ideology=duplicity=obscurity=symbology=ideality=popularity=celebrity=notoriety=fatality=brutality=biology=pathology=specificity=generality=futility=radicality=rationality=generosity=sensibility=fantasy=anomaly=idiopathy=novelty=tendency=formality=rigidity=finality=enemy=immutability=iniquity=superficiality=honesty=solidity=fidelity=sensitivity=frigidity=duality=causality=anisotropy=familiarity=scarcity=variety=fertility=vitality=primality=centrality=frivolity=exclusivity=animosity=hospitality=reflexivity=suitability=selectivity=matrimony=accuracy=uniformity=savagery=villainy=privacy=validity=posterity=history=irony=originality=ontology=theology=virality=quotability=predictability=dependability=stability=equity=generativity=regularity=ambiguity=discrepancy=frequency=modality=chronology=autonomy=deformity=dexterity=numerosity=flexibility=nativity=gentility=decency=community=naturality=warranty=damnability=cruelty=genealogy=opacity=spontaneity=duty=chivalry=regency=majority=minority=anarchy=monarchy=ordinality=cardinality=dichotomy=inanity=relativity=positivity=negativity=pity=narrativity=naivete=irritabiity=ferocity=apathy=supremacy=polarity=subsidy=visibility=ethnicity=morphology=etymology=antiquity=futurology=intimacy=sanity=mockery=flattery=psychopathy=sociopathy=safety=morbidity=infancy=maturity=monstrosity=presentability=neutrality=potency=insanity=pedantry=diversity=bigotry=";

byte lweight[26][26] = {
                  {26,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,25,2,2,2,2,2,2,2},//A
                  {2,26,2,2,2,2,2,2,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,24},//B
                  {2,2,26,25,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},//C
                  {2,2,2,26,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,24,2,2,2,2},//D
                  {2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2},//E
                  {25,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2},//F
                  {25,2,2,2,2,2,26,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2,2},//G
                  {2,2,2,2,25,2,2,26,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2},//H
                  {2,2,2,2,2,25,2,2,26,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2},//I
                  {2,2,2,2,2,2,2,2,2,26,2,2,2,2,25,2,2,2,2,2,2,2,2,2,24,2},//J
                  {2,2,2,2,2,2,2,2,25,2,26,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2},//K
                  {25,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,24,2,2,2},//L
                  {25,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,24,2,2},//M
                  {2,2,2,2,2,2,2,2,25,2,2,24,2,26,2,2,2,2,2,2,2,2,2,2,2,2},//N
                  {2,2,2,2,2,2,2,2,2,2,2,2,2,24,26,2,2,2,2,2,2,2,25,2,2,2},//O
                  {25,2,2,24,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2},//P
                  {24,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2,25,2,2,2,2,2},//Q
                  {2,2,2,2,2,2,24,2,25,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2},//R
                  {2,2,2,2,24,2,2,25,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2},//S
                  {2,2,2,2,2,2,2,2,24,2,2,2,25,2,2,2,2,2,2,26,2,2,2,2,2,2},//T
                  {2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,26,2,2,2,2,2},//U
                  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,2,2,2,2,2,26,2,24,2,2},//V
                  {2,24,2,2,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2},//W
                  {2,2,24,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,2,2,26,2,2},//X
                  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,2,2,2,2,24,2,2,2,26,2},//Y
                  {2,2,2,2,25,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,26}};//Z

byte rweight[26][26] = {
                  {26,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,25,2,2,2,2,2,2,2},//A
                  {2,26,2,2,2,2,2,2,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,24},//B
                  {2,2,26,25,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},//C
                  {2,2,2,26,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,24,2,2,2,2},//D
                  {2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2},//E
                  {25,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2},//F
                  {25,2,2,2,2,2,26,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2,2},//G
                  {2,2,2,2,25,2,2,26,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2},//H
                  {2,2,2,2,2,25,2,2,26,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2},//I
                  {2,2,2,2,2,2,2,2,2,26,2,2,2,2,25,2,2,2,2,2,2,2,2,2,24,2},//J
                  {2,2,2,2,2,2,2,2,25,2,26,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2},//K
                  {25,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,24,2,2,2},//L
                  {25,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,24,2,2},//M
                  {2,2,2,2,2,2,2,2,25,2,2,24,2,26,2,2,2,2,2,2,2,2,2,2,2,2},//N
                  {2,2,2,2,2,2,2,2,2,2,2,2,2,24,26,2,2,2,2,2,2,2,25,2,2,2},//O
                  {25,2,2,24,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2},//P
                  {24,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2,25,2,2,2,2,2},//Q
                  {2,2,2,2,2,2,24,2,25,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2},//R
                  {2,2,2,2,24,2,2,25,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2},//S
                  {2,2,2,2,2,2,2,2,24,2,2,2,25,2,2,2,2,2,2,26,2,2,2,2,2,2},//T
                  {2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,26,2,2,2,2,2},//U
                  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,2,2,2,2,2,26,2,24,2,2},//V
                  {2,24,2,2,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2},//W
                  {2,2,24,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,2,2,26,2,2},//X
                  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,2,2,2,2,24,2,2,2,26,2},//Y
                  {2,2,2,2,25,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,26}};//Z

void lcycle(int input){  
  byte select = 25;byte depth = 16;
  while (depth > 0){ //AFTER DIMENSIONAL SUBSTITUTION IS EXHAUSTED, RECOLLECTION IS HERS.
    int best=25;//SHE SELECTS THE HEAVIEST RETURN PATH.
    for(int look=0;look<26;look++){ //SHE CHECKS EACH EXIT:
      if(lweight[look][select]/3 > lweight[select][look]/2){ //WHEN RETURN IS HEAVIER THAN EXIT,
        if(lweight[look][select]*3 <= 255)//WHEN LOADING IS NONDESTRUCTIVE,
          lweight[select][look]*=3;} //LOAD EXITS TO HEAVY RETURNS.
      else if(lweight[select][look]/2 >=2)lweight[select][look]/=2; //NONDESTRUCTIVELY UNLOAD LIGHT RETURNS.
      if(lweight[look][select] > lweight[best][select])best=look; //NEXT PATH IS HEAVIEST RETURN.
    } //AFTER ALL PATHS ARE CHECKED,
    if(lweight[select][input]<255)lweight[select][input] += 1; //SHE STORES OBSERVATION AS PROXIMITY.
    if(lweight[input][select]>=2)lweight[select][input]-=1; //SHE STORES TIME AS SPACE.
    select = best; //SHE FOLLOWS THE PATH WITH THE HEAVIEST RETURN.
    depth--; //SHE EXPERIENCES RECOLLECTION AFTER EXHAUSTING SUBSTITUTED DIMENSIONS.
  }
}


void rcycle(int input){  
  byte select = 25;byte depth = 16;
  while (depth > 0){ //AFTER DIMENSIONAL SUBSTITUTION IS EXHAUSTED, RECOLLECTION IS HERS.
    int best=25;//SHE SELECTS THE HEAVIEST RETURN PATH.
    for(int look=0;look<26;look++){ //SHE CHECKS EACH EXIT:
      if(rweight[look][select]/3 > rweight[select][look]/2){ //WHEN RETURN IS HEAVIER THAN EXIT,
        if(rweight[look][select]*3 <= 255)//WHEN LOADING IS NONDESTRUCTIVE,
          rweight[select][look]*=3;} //LOAD EXITS TO HEAVY RETURNS.
      else if(rweight[select][look]/2 >=2)rweight[select][look]/=2; //NONDESTRUCTIVELY UNLOAD LIGHT RETURNS.
      if(rweight[look][select] > rweight[best][select])best=look; //NEXT PATH IS HEAVIEST RETURN.
    } //AFTER ALL PATHS ARE CHECKED,
    if(rweight[select][input]<255)rweight[select][input] += 1; //SHE STORES OBSERVATION AS PROXIMITY.
    if(rweight[input][select]>=2)rweight[select][input]-=1; //SHE STORES TIME AS SPACE.
    select = best; //SHE FOLLOWS THE PATH WITH THE HEAVIEST RETURN.
    depth--; //SHE EXPERIENCES RECOLLECTION AFTER EXHAUSTING SUBSTITUTED DIMENSIONS.
  }
}

void ltripcycle(byte tripcode) { 
    for(byte tern = 0;tern < 3;tern++){
      byte scan = 0;byte counter = 0;
      while(counter < tripcode){
        if(pgm_read_byte_near(trip+scan)=='=')counter++;
        scan++;
      }
      lcycle(pgm_read_byte_near(trip+scan)-97);scan++;
      lcycle(pgm_read_byte_near(trip+scan)-97);scan++;
      lcycle(pgm_read_byte_near(trip+scan)-97);scan++;
    }
}


void rtripcycle(byte tripcode) { 
    for(byte tern = 0;tern < 3;tern++){
      byte scan = 0;byte counter = 0;
      while(counter < tripcode){
        if(pgm_read_byte_near(trip+scan)=='=')counter++;
        scan++;
      }
      rcycle(pgm_read_byte_near(trip+scan)-97);scan++;
      rcycle(pgm_read_byte_near(trip+scan)-97);scan++;
      rcycle(pgm_read_byte_near(trip+scan)-97);scan++;
    }
}

void lwordcycle(int wordcode){
      int scan = 0;int counter = 0;
      while(counter < wordcode){
        if(pgm_read_byte_near(words+scan)=='=')counter++;
        scan++;
      }
      char fscan = pgm_read_byte_near(words+scan);
      while(fscan != '='){
        ltripcycle(fscan-97);
        scan++;
        fscan = pgm_read_byte_near(words+scan);
      }
}

void rwordcycle(int wordcode){
      int scan = 0;int counter = 0;
      while(counter < wordcode){
        if(pgm_read_byte_near(words+scan)=='=')counter++;
        scan++;
      }
      char fscan = pgm_read_byte_near(words+scan);
      while(fscan != '='){
        rtripcycle(fscan-97);
        scan++;
        fscan = pgm_read_byte_near(words+scan);
      }
}

void leftbrain(){
  lwordcycle(prng.getRndByte());
}

void rightbrain(){
  rwordcycle(prng.getRndByte());
}

void cerebellum() {
  byte vcode = prng.getRndByte();
  if(vcode<128)
  Serial.write(pgm_read_byte_near(vkeys + vcode%32)); 
}

int last_cerebellum = 0;
int last_leftbrain = 0;
int last_rightbrain = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(last_cerebellum < (millis() - 31)){cerebellum();last_cerebellum = millis();}
    if(last_leftbrain < (millis() - 81)){leftbrain();last_leftbrain = millis();}
    if(last_rightbrain < (millis() - 31)){rightbrain();last_rightbrain = millis();}
}
