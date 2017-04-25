//
//  ApptentiveSerialRequest.h
//  Apptentive
//
//  Created by Frank Schmitt on 12/16/16.
//  Copyright © 2016 Apptentive, Inc. All rights reserved.
//

#import "ApptentiveRequestProtocol.h"
#import <CoreData/CoreData.h>

@class ApptentiveConversation, ApptentivePayload;


/**
 An `ApptentiveSerialRequest` instance encapsulates the data used to make a
 network request in an `ApptentiveSerialNetworkQueue`. Instance are created
 using the
 `+enqueueRequestWithPath:method:payload:attachments:identifier:inContext:`
 method.

 The API version is included because the payload encoding may change, so any
 migrated requests (encoded to the previous version's specifications) should
 be sent with the matching API version.
 */
@interface ApptentiveSerialRequest : NSManagedObject <ApptentiveRequest>

/**
 The API version for which the payload was encoded.
 */
@property (strong, nonatomic) NSString *apiVersion;

/**
 The attachments (used for some messages) that should be included with the
 request.
 */
@property (strong, nonatomic) NSOrderedSet *attachments;

/**
 The conversation identifier (used to associate with a conversation for authentication).
 */
@property (strong, nonatomic) NSString *conversationIdentifier;

/**
 Authorization token that should be used to send a payload
 */
@property (strong, nonatomic) NSString *authToken;

/**
 The date on which the request was created.
 */
@property (strong, nonatomic) NSDate *date;

/**
 An idenfier used to associate a request with a message.
 */
@property (strong, nonatomic) NSString *identifier;

/**
 The HTTP request method that shoud be used to make the request.
 */
@property (strong, nonatomic) NSString *method;

/**
 The path used to build the HTTP request URL.
 */
@property (strong, nonatomic) NSString *path;

/**
 The data that should be transmitted in the body of the HTTP request.
 */
@property (strong, nonatomic) NSData *payload;

/**
 Enqueues a payload with the given conversation information and
 authorization token using the context.

 @param payload An subclass of ApptentivePayload
 @param conversation The conversation that is making the request.
 @param authToken The authorization token to use for the request.
 @param context The managed object context to use to create the request.
 @return Whether the payload was successfull enqueued.
 */
+ (BOOL)enqueuePayload:(ApptentivePayload *)payload forConversation:(ApptentiveConversation *)conversation usingAuthToken:(NSString *)authToken inContext:(NSManagedObjectContext *)context;

@end
