#include <SDL.h>

// *********************  These are the levels:   **********************
//   1=normal 2=lightning 3=stopper 4=finish 5=teleporter 6=time bonus  
//   7=vertical laser  8=cannon

       Uint8 origMap2[28][15][20] =
        { { {6,0,6,2,6,6,6,2,6,0,0,0,0,0,0,0,0,0,0,8},      
            {0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0},      
            {0,6,0,2,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0},      
            {0,0,0,2,0,0,0,7,0,0,0,2,2,0,0,2,2,2,2,2},      
            {0,0,0,2,0,0,0,7,0,0,0,2,2,0,0,0,2,2,0,0},      
            {0,0,0,2,0,0,0,2,0,0,0,2,2,0,0,0,0,2,2,0},      
            {0,0,0,2,0,0,0,2,0,0,0,2,2,2,0,0,0,0,2,2},      
            {0,0,0,7,0,0,0,2,0,0,0,2,0,2,2,0,0,0,0,0},      
            {0,0,0,7,0,0,0,2,0,0,0,2,0,0,2,2,0,0,0,0},      
            {0,0,0,7,0,0,0,2,0,0,0,2,0,0,0,2,2,0,0,0},      
            {0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,2,2,0,0},      
            {0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,2,2,4},      
            {0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0},      
            {0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,11,12,13},   
            {0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,14,15,16} },  
                                                            
          { {0,0,0,0,7,7,7,7,6,0,7,7,7,7,6,0,7,0,0,8},      
            {0,0,0,0,7,0,0,7,0,0,7,0,0,7,0,0,7,0,0,2},      
            {0,0,0,0,7,0,0,7,7,7,7,0,0,7,0,0,7,0,0,2},      
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},      
            {2,0,0,0,2,0,0,7,0,0,2,0,0,7,0,0,2,0,0,2},      
            {3,0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,2},      
            {2,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},      
            {3,0,1,5,5,5,5,5,5,5,1,0,0,0,0,2,0,0,6,2},      
            {2,0,1,1,1,1,1,1,1,1,1,0,2,2,0,0,0,2,6,2},      
            {0,0,0,0,6,7,7,7,7,7,7,0,2,2,2,2,2,2,7,7},      
            {0,0,0,0,0,7,7,7,7,7,7,0,0,2,2,2,2,2,7,7},      
            {0,0,0,0,0,7,7,7,7,7,7,0,0,0,0,0,2,2,7,7},      
            {0,2,2,2,2,2,2,0,2,1,1,1,1,1,2,0,2,2,2,4},      
            {0,0,2,0,7,0,2,0,7,0,2,0,7,0,2,0,2,11,12,13},   
            {2,0,0,6,2,0,0,6,2,0,0,0,2,0,0,0,2,14,15,16} },  

          { {0,0,1,7,7,7,1,1,7,1,7,7,7,0,0,5,0,0,0,2},      
            {0,0,1,7,7,7,1,1,7,1,7,7,7,0,0,0,0,0,5,2},      
            {0,0,0,0,1,0,0,0,7,7,7,7,1,6,2,0,5,0,0,2},      
            {0,0,0,0,1,0,0,0,1,7,7,7,1,6,2,6,0,0,5,2},      
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0,0,2},      
            {0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,5,0,5},      
            {6,1,0,1,0,0,0,1,0,0,0,1,0,0,0,5,0,0,0,0},      
            {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,5,5,0,5},      
            {0,2,0,2,0,0,0,2,0,0,0,0,1,1,6,1,1,1,1,1},      
            {0,2,0,2,0,2,0,2,1,0,2,0,0,1,0,0,0,3,6,2},      
            {2,2,0,2,0,2,7,2,0,0,8,1,0,0,0,3,3,3,6,2},      
            {2,0,0,2,0,2,7,2,0,1,1,1,1,3,0,0,0,3,7,2},      
            {2,0,2,2,0,2,7,2,0,0,0,0,0,1,0,3,3,3,7,4},      
            {2,0,0,0,0,2,0,2,1,1,1,1,0,1,0,0,0,11,12,13},   
            {2,2,2,2,2,2,0,0,6,0,0,0,0,1,0,3,3,14,15,16} },  

          { {2,6,6,2,0,0,0,0,0,2,2,0,0,0,0,2,0,0,2,2},      
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      
            {0,0,0,0,0,2,2,0,0,0,0,0,2,2,0,0,0,0,0,0},      
            {0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0},      
            {7,7,2,1,6,0,0,0,1,0,0,0,1,6,0,0,0,2,0,0},      
            {7,7,2,1,0,0,1,0,0,0,1,0,0,1,0,1,0,2,0,0},      
            {7,7,2,1,1,0,0,1,1,1,0,0,1,0,0,2,0,2,0,0},      
            {0,0,2,1,0,1,0,1,0,0,0,1,0,0,0,2,0,2,0,0},      
            {0,0,0,1,0,0,0,1,0,8,1,1,0,1,0,2,0,2,0,0},      
            {0,0,0,0,0,1,1,1,0,0,0,0,0,2,0,2,0,2,0,0},      
            {2,2,2,1,1,1,0,1,1,1,1,1,1,1,1,1,0,2,0,0},      
            {4,4,2,0,2,0,0,7,0,0,7,0,0,0,0,0,0,2,0,0},      
            {4,4,6,0,0,0,0,7,0,0,7,0,0,0,0,0,0,2,0,0},      
            {4,4,0,0,0,0,0,7,0,6,7,0,0,2,2,2,2,11,12,13},   
            {2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,5,5,14,15,16} },  
                                                            
          { {0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},      
            {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,2},      
            {1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,7,1},      
            {0,1,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1},      
            {0,0,1,0,0,0,2,3,3,0,3,3,1,0,1,0,0,1,0,1},      
            {0,2,0,1,0,1,1,3,0,0,0,3,1,0,1,0,0,1,0,1},      
            {1,0,1,1,0,1,0,3,0,3,0,3,1,0,1,0,0,1,0,1},      
            {0,0,0,1,0,0,1,3,0,3,0,0,1,0,1,0,0,1,0,1},      
            {0,1,0,0,1,0,1,3,0,3,3,0,0,0,1,0,0,1,0,1},      
            {0,1,0,1,0,0,1,3,6,0,3,3,0,0,1,0,0,1,0,1},      
            {0,1,0,0,0,1,3,3,3,0,3,2,1,1,1,0,0,1,0,1},      
            {0,0,1,1,1,3,0,0,0,0,1,0,0,0,0,0,0,0,0,1},      
            {1,0,0,1,0,0,0,3,3,3,1,0,1,1,1,1,1,1,2,1},      
            {0,1,0,0,0,0,3,1,0,0,1,0,0,0,0,6,4,11,12,13},   
            {0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,14,15,16} },  

          { {0,0,2,5,5,5,6,3,1,6,0,0,0,3,0,0,0,0,6,6},      
            {0,0,2,0,0,5,6,3,1,0,3,3,3,3,0,0,0,0,0,0},      
            {0,0,2,0,0,5,0,3,1,0,1,1,0,0,0,0,0,2,0,2},      
            {2,0,2,0,2,2,0,3,1,0,1,0,0,1,2,0,0,0,0,0},      
            {2,0,2,0,2,2,0,3,1,0,1,0,0,1,2,0,2,0,2,0},      
            {0,0,2,0,0,2,0,3,1,0,1,0,1,1,0,0,0,0,0,0},      
            {0,0,2,0,0,2,0,3,1,0,1,0,0,1,0,2,0,2,0,0},      
            {0,2,2,2,0,2,0,3,1,0,1,1,0,1,1,1,0,0,0,0},      
            {0,2,2,2,0,2,0,3,1,0,1,0,0,1,2,0,2,0,2,0},      
            {0,0,2,0,0,2,0,3,1,0,1,0,1,2,0,0,0,0,0,0},      
            {0,0,2,0,0,2,0,3,1,0,0,0,1,0,0,2,0,2,0,2},      
            {2,0,0,0,0,2,0,3,1,1,0,1,3,0,0,0,0,0,0,0},      
            {2,0,0,0,2,2,0,3,1,0,0,1,3,0,2,0,2,0,0,6},      
            {6,0,0,0,0,2,0,0,0,0,1,4,3,0,0,0,0,11,12,13},   
            {2,2,2,2,2,2,1,1,1,1,4,4,3,0,0,2,6,14,15,16} },  

          { {0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},      
            {0,0,0,0,2,6,6,2,6,6,2,6,6,2,0,0,2,0,0,0},      
            {1,1,0,0,7,0,0,2,0,0,2,0,0,2,0,0,7,0,0,0},      
            {0,2,0,0,7,0,0,2,0,0,2,0,0,2,0,0,7,0,0,2},      
            {0,2,0,0,7,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2},      
            {0,2,0,0,2,0,0,7,0,0,2,0,0,7,0,0,2,0,0,0},      
            {0,2,0,0,2,0,0,7,0,0,2,0,0,7,0,0,2,0,0,0},      
            {0,2,0,0,2,0,0,7,0,0,2,0,0,7,0,0,7,0,0,0},      
            {0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,7,0,0,0},      
            {0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,0},      
            {0,2,0,0,2,0,0,2,0,0,7,0,0,2,0,0,2,0,0,0},      
            {0,2,0,0,2,0,0,2,0,0,7,0,0,2,0,0,2,0,2,0},      
            {0,2,0,0,2,0,0,2,0,0,7,0,0,2,0,0,2,0,2,4},      
            {0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,11,12,13},   
            {0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,14,15,16} },
	    
	  { {5,8,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,4},      
            {5,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},      
            {6,1,0,0,1,1,1,1,5,5,1,1,5,5,1,1,5,1,1,5},      
            {6,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,6,6},      
            {0,2,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0},      
            {0,1,5,5,5,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0},      
            {0,1,5,5,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0},      
            {0,1,6,6,0,0,0,0,6,1,1,1,0,1,1,0,0,0,0,1},      
            {7,1,0,0,0,1,0,0,0,0,0,5,5,5,1,1,1,1,0,0},      
            {0,1,0,1,0,0,0,0,0,0,0,1,6,0,0,0,0,0,0,0},      
            {0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,1,1,1},      
            {0,1,1,0,0,1,1,0,1,1,0,0,1,0,0,1,1,0,0,0},      
            {0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0},      
            {0,0,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,11,12,13},   
            {0,0,1,1,0,0,0,0,0,0,5,1,1,1,0,0,0,14,15,16} },
	    
	  { {8,7,7,7,7,0,0,7,7,7,7,7,7,7,7,7,7,7,7,7},      
            {6,0,7,7,7,0,0,7,7,7,0,0,6,7,7,7,0,0,0,7},      
            {0,0,7,7,7,7,7,7,7,7,0,0,0,7,7,7,0,0,0,7},      
            {0,0,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,7},      
            {7,7,2,2,7,7,7,7,7,7,7,7,7,7,7,7,2,7,7,7},      
            {7,7,7,2,7,7,7,7,0,0,7,7,7,7,7,7,2,7,7,7},      
            {7,7,7,2,7,7,7,7,0,0,7,7,7,7,7,7,2,7,7,7},      
            {7,7,7,2,7,0,6,7,7,2,7,7,7,7,7,7,2,0,0,7},      
            {0,6,7,2,7,0,0,7,2,7,7,4,7,7,7,7,2,0,6,7},      
            {0,0,7,2,7,0,0,7,2,7,7,7,7,7,7,7,2,7,7,7},      
            {7,7,7,2,7,7,7,7,2,7,7,7,7,7,7,7,2,7,7,7},      
            {7,7,7,2,7,7,7,7,7,2,2,2,2,2,2,2,2,7,0,0},      
            {0,0,7,7,2,7,0,0,0,0,7,7,7,6,0,7,7,7,6,0},      
            {0,0,7,7,2,2,7,2,0,0,7,7,7,0,0,7,7,11,12,13},   
            {0,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,14,15,16} },
        };                                                  
