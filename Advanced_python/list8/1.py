import requests
import pandas as pd
import matplotlib.pyplot as plt

def get_euro(year):
    url = f"https://api.nbp.pl/api/exchangerates/rates/A/EUR/{year}-01-01/{year}-12-31/?format=json"
    r = requests.get(url)
    r.raise_for_status()

    data = r.json()["rates"]
    dates = [item["effectiveDate"] for item in data]
    values = [item["mid"] for item in data]

    df = pd.DataFrame({"date": dates, "value": values})
    df["date"] = pd.to_datetime(df["date"])
    return df


def get_btc(start_date, timespan):
    url = (
        "https://api.blockchain.info/charts/market-price"
        f"?start={start_date}&timespan={timespan}&format=json&sampled=false"
    )
    r = requests.get(url)
    r.raise_for_status()

    data = r.json()["values"]

    dates = [pd.to_datetime(item["x"], unit="s") for item in data]
    values = [item["y"] for item in data]

    df = pd.DataFrame({"date": dates, "value": values})
    return df

def monthly_mean(df):
    df = df.copy()
    df["year"] = df["date"].dt.year
    df["month"] = df["date"].dt.month
    monthly = (
        df.groupby(["year", "month"])["value"]
        .mean()
        .reset_index()
        .sort_values(["year", "month"])
    )
    return monthly

def forecast_by_average(monthly_df, year1, year2):
    forecast = []
    for m in range(1, 13):
        vals = monthly_df[
            (monthly_df["month"] == m)
            & (monthly_df["year"].isin([year1, year2]))
        ]["value"]
        forecast.append(vals.mean() if len(vals) > 0 else None)
    return forecast

def main():
    year1 = 2023
    year2 = 2024
    forecast_year = 2025

    print("Pobieram dane...")

    eur_2023 = get_euro(year1)
    eur_2024 = get_euro(year2)
    eur_all = pd.concat([eur_2023, eur_2024], ignore_index=True)

    btc_all = get_btc("2023-01-01", "2years")
    btc_all = btc_all[(btc_all["date"].dt.year.isin([year1, year2]))].copy()

    eur_monthly = monthly_mean(eur_all)
    btc_monthly = monthly_mean(btc_all)

    print("EUR miesięczne (kilka pierwszych):")
    print(eur_monthly.head())
    print("\nBTC miesięczne (kilka pierwszych):")
    print(btc_monthly.head())

    months = list(range(1, 13))
    eur_forecast = forecast_by_average(eur_monthly, year1, year2)
    btc_forecast = forecast_by_average(btc_monthly, year1, year2)

    fig, axes = plt.subplots(3, 1, figsize=(10, 12), sharex=True)
    month_labels = ["I", "II", "III", "IV", "V", "VI",
                    "VII", "VIII", "IX", "X", "XI", "XII"]

    ax1 = axes[0]

    eur_y1 = eur_monthly[eur_monthly["year"] == year1]
    btc_y1 = btc_monthly[btc_monthly["year"] == year1]

    line_btc23, = ax1.plot(btc_y1["month"], btc_y1["value"], marker="o",
                           label=f"BTC/USD {year1}")
    ax1.set_ylabel("BTC [USD]")
    ax1.set_title(f"Wskaźniki w roku {year1}")
    ax1.grid(True)

    ax1b = ax1.twinx()
    line_eur23, = ax1b.plot(eur_y1["month"], eur_y1["value"], marker="s", linestyle="--",
                            label=f"EUR/PLN {year1}", color="tab:orange")
    ax1b.set_ylabel("EUR/PLN")

    lines1 = [line_btc23, line_eur23]
    labels1 = [l.get_label() for l in lines1]
    ax1.legend(lines1, labels1, loc="upper left")

    ax2 = axes[1]

    eur_y2 = eur_monthly[eur_monthly["year"] == year2]
    btc_y2 = btc_monthly[btc_monthly["year"] == year2]

    line_btc24, = ax2.plot(btc_y2["month"], btc_y2["value"], marker="o",
                           label=f"BTC/USD {year2}")
    ax2.set_ylabel("BTC [USD]")
    ax2.set_title(f"Wskaźniki w roku {year2}")
    ax2.grid(True)

    ax2b = ax2.twinx()
    line_eur24, = ax2b.plot(eur_y2["month"], eur_y2["value"], marker="s", linestyle="--",
                            label=f"EUR/PLN {year2}", color="tab:orange")
    ax2b.set_ylabel("EUR/PLN")

    lines2 = [line_btc24, line_eur24]
    labels2 = [l.get_label() for l in lines2]
    ax2.legend(lines2, labels2, loc="upper left")

    ax3 = axes[2]

    line_btc25, = ax3.plot(months, btc_forecast, marker="o",
                           label=f"Prognoza BTC/USD {forecast_year}")
    ax3.set_ylabel("BTC [USD]")
    ax3.set_title(
        f"Prognoza na rok {forecast_year} (średnia z lat {year1}–{year2})"
    )
    ax3.grid(True)

    ax3b = ax3.twinx()
    line_eur25, = ax3b.plot(months, eur_forecast, marker="s", linestyle="--",
    label=f"Prognoza EUR/PLN {forecast_year}", color="tab:orange")
    ax3b.set_ylabel("EUR/PLN")

    ax3.set_xlabel("Miesiąc")
    ax3.set_xticks(months)
    ax3.set_xticklabels(month_labels)

    lines3 = [line_btc25, line_eur25]
    labels3 = [l.get_label() for l in lines3]
    ax3.legend(lines3, labels3, loc="upper left")

    fig.suptitle("Dwa źródła danych: NBP (EUR/PLN) + Blockchain (BTC/USD)", fontsize=14)
    fig.tight_layout(rect=[0, 0.03, 1, 0.97])

    plt.savefig("inflacja_dwa_zrodla_wspolne_roki.png", dpi=150)
    plt.show()


if __name__ == "__main__":
    main()
