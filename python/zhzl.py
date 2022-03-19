import requests

curl = """curl 'https://www.zhihu.com/api/v4/columns/qiehemao/items?limit=10&offset=10' \
  -H 'authority: www.zhihu.com' \
  -H 'accept: */*' \
  -H 'accept-language: en,zh-CN;q=0.9,zh-TW;q=0.8,zh;q=0.7' \
  -H 'cache-control: no-cache' \
  -H 'dnt: 1' \
  -H 'origin: https://zhuanlan.zhihu.com' \
  -H 'pragma: no-cache' \
  -H 'referer: https://zhuanlan.zhihu.com/qiehemao' \
  -H 'sec-ch-ua: " Not A;Brand";v="99", "Chromium";v="100", "Google Chrome";v="100"' \
  -H 'sec-ch-ua-mobile: ?0' \
  -H 'sec-ch-ua-platform: "macOS"' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-site' \
  -H 'user-agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36' \
  -H 'x-requested-with: fetch' \
  --compressed
"""

header = """
  -H 'authority: www.zhihu.com' \
  -H 'accept: */*' \
  -H 'accept-language: en,zh-CN;q=0.9,zh-TW;q=0.8,zh;q=0.7' \
  -H 'cache-control: no-cache' \
  -H 'dnt: 1' \
  -H 'origin: https://zhuanlan.zhihu.com' \
  -H 'pragma: no-cache' \
  -H 'referer: https://zhuanlan.zhihu.com/qiehemao' \
  -H 'sec-ch-ua: " Not A;Brand";v="99", "Chromium";v="100", "Google Chrome";v="100"' \
  -H 'sec-ch-ua-mobile: ?0' \
  -H 'sec-ch-ua-platform: "macOS"' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-site' \
  -H 'user-agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36' \
  -H 'x-requested-with: fetch' \
"""

def header_to_dict(header):
    els = [el.strip() for el in header.strip().split('-H')]
    els = [el[1:-1] for el in els if el != '']
    els = [[item.strip() for item in el.split(':', 1)] for el in els]
    return dict(els)

def fetch(slug, limit, offset, header):
    api = f"https://www.zhihu.com/api/v4/columns/{slug}/items"
    # ?limit=10&offset=10
    params = dict(limit=limit, offset=offset)
    header['referer'] = f"https://zhuanlan.zhihu.com/{slug}"
    response = requests.get(
        api,
        params=params,
        headers=header
    )
    print(response.text)

if __name__ == '__main__':
    fetch("qiehemao", 10, 10, header_to_dict(header))
