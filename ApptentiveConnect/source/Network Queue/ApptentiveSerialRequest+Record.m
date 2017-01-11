//
//  ApptentiveSerialRequest+Record.m
//  ApptentiveConnect
//
//  Created by Frank Schmitt on 1/6/17.
//  Copyright © 2017 Apptentive, Inc. All rights reserved.
//

#import "ApptentiveSerialRequest+Record.h"

@implementation ApptentiveSerialRequest (Record)

+ (void)enqueueRequestWithPath:(NSString *)path noncePrefix:(NSString *)noncePrefix payload:(NSDictionary *)payload inContext:(NSManagedObjectContext *)context {
	NSMutableDictionary *fullPayload = [payload mutableCopy];

	fullPayload[@"nonce"] = [NSString stringWithFormat:@"%@:%@", noncePrefix, [NSUUID UUID].UUIDString];
	fullPayload[@"client_created_at"] = @([NSDate date].timeIntervalSince1970);
	fullPayload[@"client_created_at_utc_offset"] = @([[NSTimeZone systemTimeZone] secondsFromGMTForDate:[NSDate date]]);

	[self enqueueRequestWithPath:path method:@"POST" payload:fullPayload attachments:nil identifier:nil inContext:context];
}

+ (void)enqueueSurveyResponseWithAnswers:(NSDictionary *)answers identifier:(NSString *)identifier inContext:(NSManagedObjectContext *)context {
	NSMutableDictionary *payload = [NSMutableDictionary dictionary];

	payload[@"id"] = identifier;
	payload[@"answers"] = answers;

	[self enqueueRequestWithPath:[NSString stringWithFormat:@"surveys/%@/respond", identifier] noncePrefix:@"pending-survey-response" payload:payload inContext:context];
}

+ (void)enqueueEventWithLabel:(NSString *)label interactionIdentifier:(NSString *)interactionIdenfier userInfo:(id)userInfo customData:(NSDictionary *)customData extendedData:(NSArray *)extendedData inContext:(NSManagedObjectContext *)context {
	NSMutableDictionary *payload = [NSMutableDictionary dictionary];

	payload[@"label"] = label;

	if (interactionIdenfier != nil) {
		payload[@"interaction_id"] = interactionIdenfier;
	}

	if (userInfo != nil) {
		payload[@"data"] = userInfo;
	}

	if (customData) {
		NSDictionary *customDataDictionary = @{ @"custom_data": customData };
		if ([NSJSONSerialization isValidJSONObject:customDataDictionary]) {
			[payload addEntriesFromDictionary:customDataDictionary];
		} else {
			ApptentiveLogError(@"Event `customData` cannot be transformed into valid JSON and will be ignored.");
			ApptentiveLogError(@"Please see NSJSONSerialization's `+isValidJSONObject:` for allowed types.");
		}
	}

	if (extendedData) {
		for (NSDictionary *data in extendedData) {
			if ([NSJSONSerialization isValidJSONObject:data]) {
				// Extended data items are not added for key "extended_data", but rather for key of extended data type: "time", "location", etc.
				[payload addEntriesFromDictionary:data];
			} else {
				ApptentiveLogError(@"Event `extendedData` cannot be transformed into valid JSON and will be ignored.");
				ApptentiveLogError(@"Please see NSJSONSerialization's `+isValidJSONObject:` for allowed types.");
			}
		}
	}

	[self enqueueRequestWithPath:@"events" noncePrefix:@"event" payload:payload inContext:context];
}

@end
