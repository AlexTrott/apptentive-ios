//
//  ApptentiveConversationBaseRequest.h
//  Apptentive
//
//  Created by Alex Lementuev on 4/28/17.
//  Copyright © 2017 Apptentive, Inc. All rights reserved.
//

#import "ApptentiveRequest.h"


@interface ApptentiveConversationBaseRequest : ApptentiveRequest

- (nullable instancetype)initWithConversationIdentifier:(NSString *_Nonnull)conversationIdentifier;

@end
