//
//  GuideDetailViewController.h
//  iNaturalist
//
//  Created by Ken-ichi Ueda on 9/4/13.
//  Copyright (c) 2013 iNaturalist. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GuideXML.h"
#import "DejalActivityView.h"
#import "RXMLElement.h"
#import "GuideMenuViewController.h"

@interface GuideCollectionViewController : UICollectionViewController <UISearchBarDelegate, GuideMenuControllerDelegate>
{
    DejalActivityView *modalActivityView;
    NSTimer *searchTimer;
}
@property (nonatomic, strong) GuideXML *guide;
@property (nonatomic, strong) NSString *guideXMLPath;
@property (nonatomic, strong) NSString *guideXMLURL;
@property (nonatomic) CGFloat scale;
@property (nonatomic, strong) NSString *sort;
@property (nonatomic, strong) UISearchBar *searchBar;
@property (nonatomic, strong) NSString *search;
@property (nonatomic, strong) NSMutableArray *tags;

- (void)loadXML:(NSString *)path;
- (void)downloadXML:(NSString *)url;
- (void)downloadXML:(NSString *)url quietly:(BOOL)quietly;
- (NSInteger)guideTaxonPositionAtIndexPath:(NSIndexPath *)indexPath;
@end

@interface XMLDownloadDelegate : NSObject <NSURLConnectionDelegate>
@property (nonatomic, strong) UIProgressView *progress;
@property (nonatomic, strong) NSMutableData *receivedData;
@property (nonatomic) long expectedBytes;
@property (nonatomic, strong) DejalActivityView *dejalActivityView;
@property (nonatomic) NSInteger lastStatusCode;
@property (nonatomic, strong) NSString *filePath;
@property (nonatomic, strong) GuideCollectionViewController *controller;
@property (nonatomic) BOOL quiet;

- (id)initWithController:(GuideCollectionViewController *)controller;

@end