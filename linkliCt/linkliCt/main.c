//
//  main.c
//  linkliCt
//
//  Created by Joubin Jabbari on 7/25/15.
//  Copyright (c) 2015 Joubin Jabbari. All rights reserved.
//

#include "linklist.h"

int main(int argc, const char * argv[]) {
    AL_setup();
    AL_appened("aaa");
    AL_appened("bbb");
    AL_appened("ccc");
    AL_appened("ddd");
     Iterator it = AL_iterator();
    while (AL_hasNext(it)) {
        AL_next(&it);
        void* xx = it.current.string;
        printf("%s\n", xx);
    }
    AL_remove(2);
    it = AL_iterator();
    while (AL_hasNext(it)) {
        AL_next(&it);
        void* xx = it.current.string;
        printf("%s\n", xx);
    }
    

    return 0;
}
