//
//  Created by Nextpeer development team.
//  Copyright (c) 2014 Nextpeer, Inc. All rights reserved.
//

#ifndef __NextpeerPlayer__
#define __NextpeerPlayer__

#include "cocos2d.h"
USING_NS_CC;

#include <string>
using namespace std;

namespace nextpeer {
    class NextpeerPlayer : public CCObject
    {
    public:
        static NextpeerPlayer* create(string playerName, string playerId, string playerImageUrl, bool isRecording);
        void init(string playerName, string playerId, string playerImageUrl, bool isRecording);
        
    protected:
        CC_SYNTHESIZE(string, mPlayerName, PlayerName);
        CC_SYNTHESIZE(string, mPlayerId, PlayerId);
        CC_SYNTHESIZE(string, mPlayerImageUrl, PlayerImageUrl);
        CC_SYNTHESIZE(bool, mIsRecording, IsRecording);
    };
}

#endif /* defined(__NextpeerPlayer__) */
