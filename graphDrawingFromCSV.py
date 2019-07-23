import csv
import matplotlib.pyplot as plt

rank_list = []
price_list = []

with open("book_rank.csv", "r", encoding="utf-8") as f:
    reader = csv.reader(f)
    header = next(reader)
    for row in reader:
        rank = int(row[0])
        price = int(row[3].replace(",", ""))
        rank_list.append(rank)
        price_list.append(price)

#グラフ描画
plt.plot(rank_list, price_list)
plt.xlabel("rank[th]")
plt.ylabel("price[yen]")
plt.show()