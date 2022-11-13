from crawler import Crawler
from args import get_args
import csv

if __name__ == '__main__':
    args = get_args()
    crawler = Crawler()
    contents = crawler.crawl(args.start_date, args.end_date)
    # TODO: write content to file according to spec
    with open(args.output,'w',encoding="utf-8",newline='') as csvf:
        writer = csv.writer(csvf)
        for text in contents:
            writer.writerow(text)
