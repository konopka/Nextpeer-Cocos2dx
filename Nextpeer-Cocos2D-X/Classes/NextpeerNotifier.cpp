//
//  Created by Nextpeer development team.
//  Copyright (c) 2014 Nextpeer, Inc. All rights reserved.
//

#include "NextpeerNotifier.h"
#include "support/CCNotificationCenter.h"
#include "NextpeerEventQueue.h"

namespace nextpeer
{
    
    NextpeerNotifier* NextpeerNotifier::_instance = 0;

    NextpeerNotifier* NextpeerNotifier::getInstance()
    {
        if (!_instance) _instance = new NextpeerNotifier();
        
        return _instance;
    }
    
    NextpeerNotifier::NextpeerNotifier()
    {
#ifdef USE_EVENT_QUEUE
//        CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(NextpeerNotifier::queueScheduler), this, 0,
//                                                                       kCCRepeatForever, 0, false);
        CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(NextpeerNotifier::queueScheduler), this, 0.0f, false, kCCRepeatForever, 0.0f);
#endif
    }
    
    void NextpeerNotifier::queueScheduler()
    {
        NextpeerEventQueue* queue = NextpeerEventQueue::getInstance();
        unsigned int count = queue->queueSize();

        if (!count) return;
        
        for (int i = 0; i < count; i++) {
            pair<string, CCObject*> element = queue->popQueue();
            CCNotificationCenter::sharedNotificationCenter()->postNotification(element.first.c_str(), element.second);
        }
    }
    
    void NextpeerNotifier::broadcastTournamentStarted(TournamentStartData* tournamentStartData)
    {
#ifdef USE_EVENT_QUEUE
        NextpeerEventQueue::getInstance()->addToQueue(string(NEXTPEER_NOTIFICATION_TOURNAMENT_STARTED), tournamentStartData);
#else
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NEXTPEER_NOTIFICATION_TOURNAMENT_STARTED, tournamentStartData);
#endif
        
    }
    
    void NextpeerNotifier::broadcastTournamentEnded()
    {
#ifdef USE_EVENT_QUEUE
        NextpeerEventQueue::getInstance()->addToQueue(string(NEXTPEER_NOTIFICATION_TOURNAMENT_ENDED), NULL);
#else
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NEXTPEER_NOTIFICATION_TOURNAMENT_ENDED, NULL);
#endif
    }
    
    void NextpeerNotifier::broadcastIncomingTournamentDataPacket(TournamentP2PData* data)
    {
#ifdef USE_EVENT_QUEUE
        NextpeerEventQueue::getInstance()->addToQueue(string(NEXTPEER_NOTIFICATION_INCOMING_DATA_PACKET), data);
#else
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NEXTPEER_NOTIFICATION_INCOMING_DATA_PACKET, data);
#endif
    }
    
    void NextpeerNotifier::broadcastDashboardWillAppear()
    {
#ifdef USE_EVENT_QUEUE
        NextpeerEventQueue::getInstance()->addToQueue(string(NEXTPEER_NOTIFICATION_DASHBOARD_WILL_APPEAR), NULL);
#else
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NEXTPEER_NOTIFICATION_DASHBOARD_WILL_APPEAR, NULL);
#endif
    }
    
    void NextpeerNotifier::broadcastDashboardWillDisappear()
    {
#ifdef USE_EVENT_QUEUE
        NextpeerEventQueue::getInstance()->addToQueue(string(NEXTPEER_NOTIFICATION_DASHBOARD_WILL_DISAPPEAR), NULL);
#else
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NEXTPEER_NOTIFICATION_DASHBOARD_WILL_DISAPPEAR, NULL);
#endif
    }
    
    void NextpeerNotifier::broadcastDashboardDidAppear()
    {
#ifdef USE_EVENT_QUEUE
        NextpeerEventQueue::getInstance()->addToQueue(string(NEXTPEER_NOTIFICATION_DASHBOARD_DID_APPEAR), NULL);
#else
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NEXTPEER_NOTIFICATION_DASHBOARD_DID_APPEAR, NULL);
#endif
    }
    
    void NextpeerNotifier::broadcastDashboardDidDisappear()
    {
#ifdef USE_EVENT_QUEUE
        NextpeerEventQueue::getInstance()->addToQueue(string(NEXTPEER_NOTIFICATION_DASHBOARD_DID_DISAPPEAR), NULL);
#else
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NEXTPEER_NOTIFICATION_DASHBOARD_DID_DISAPPEAR, NULL);
#endif
    }
    
    void NextpeerNotifier::broadcastDashboardNextpeerReturnToGame()
    {
#ifdef USE_EVENT_QUEUE
        NextpeerEventQueue::getInstance()->addToQueue(string(NEXTPEER_NOTIFICATION_DASHBOARD_RETURN_TO_GAME), NULL);
#else
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NEXTPEER_NOTIFICATION_DASHBOARD_RETURN_TO_GAME, NULL);
#endif
    }

};

