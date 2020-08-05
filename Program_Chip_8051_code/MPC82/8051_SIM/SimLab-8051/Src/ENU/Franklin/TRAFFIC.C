//
//   配合"12個LED實習板"
//   P0.0~P0.5 control 4 couple of traffic light(initial state:all OFF),
///   Change form:
///        The same direction traffic lights have the same operation ,
///      green light ON 3 sec, yellow light flash 3 sec, red light ON 3 sec
///
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "Delay.h"

main()
{
	int i;

	for(;;) {
	    P0 = 0xde;
	    for(i=0;i<1;i++) {
		Delay100ms() ;
	    }

	    for(i=0;i<4;i++){
		if((i&1)==1){
		    P0 = 0xfe;
		}
		else{
		    P0 = 0xee;
		}
		Delay100ms() ;
	    }

	    P0 = 0xf3;
	    for(i=0;i<1;i++) {
		Delay100ms() ;
	    }

	    for(i=0;i<4;i++){
		if((i&1)==1) P0 = 0xf7;
		else 	 P0 = 0xf5;
		Delay100ms() ;
	    }
	}
}
