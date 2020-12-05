
# pip install igramscraper

from igramscraper.instagram import Instagram

# keys = [
#         "LXXXIV: HPR",
#         "LVIII: HUQ",
#         "XXXII: YYS",
#         "XLVIII: NXT",
#         "LXXVI: GTM",
#         "XVI: FUP",
#         "XXII: MOG",
#         "LII: WXZ",
#         "LI: KMI",
#         "XXVIII: RGU",
#         "LXVIII: WLD",
#         "LXVI: HQQ",
#         "XXXVI: DZU",
#         "LIX: SFZ",
#         "LXXX: GTD",
#         "LXI: LOA",
#         "XLVII: KUC",
#         "XCV: OOI",
#         "XCII: UWR",
#         "LX: HVR",
#         "XLVI: QPG",
#         "LXVII: CQH",
#         "XLIX: HWE",
#         "XCVII: YOY",
#         "LXII: MPN",
#         "XXXIV: BDJ",
#         "LIV: OKS",
#         "XC: CCQ",
#         "LXIII: HDR",
#         "XCVIII: DKT",
#         "LXXXI: ZBE",
#         "LXIV: VAQ",
#         "XIV: MWT",
#         "XII: ZAE",
#         "XCIX: VRM",
#         "XXIV: CNX",
#         "LXX: SAU",
#         "LXXV: MZP",
#         "LVI: WAT",
#         "L: SFM",
#         "III: TSF",
#         "LXXIX: PRZ",
#         "XI: MXV",
#         "XXXI: NEB",
#         "LXV: POR",
#         "XXIX: TFS",
#         "XIX: PYL",
#         "XVII: CVN",
#         "XCIV: LXP",
#         "XXX: PRI",
#         "X: TED",
#         "VIII: TYN",
#         "LXXXVI: WQG",
#         "XXI: SAB",
#         "XLV: MNO",
#         "XLIV: XTF",
#         "I: OGP",
#         "XCVI: VEV",
#         "LXXXVIII: PWL",
#         "LXXIV: DDJ",
#         "IV: VUJ",
#         "XXV: LKN",
#         "XXXVII: YKU",
#         "XLIII: RBL",
#         "XL: UHH",
#         "LXXXIII: TOL",
#         "XXXVIII: EGM",
#         "XLII: DQH",
#         "XXXV: AQX",
#         "LV: PJT",
#         "LXXI: RWF",
#         "LXXXVII: DMI",
#         "LXIX: AVJ",
#         "VII: GGH",
#         "II: TRU",
#         "XCI: EWC",
#         "XXXIX: ERF",
#         "XX: NQL",
#         "XVIII: BPC",
#         "LXXIII: ISW",
#         "XXXIII: JRO",
#         "XV: CKI",
#         "XXVI: KFS",
#         "XLI: XDF",
#         "LXXXIX: QIL",
#         "XXVII: ZNN",
#         "LXXXII: RCY",
#         "VI: POC",
#         "XCIII: MQD",
#         "XIII: TZE",
#         "V: SPZ",
#         "LXXII: RNN",
#         "LXXVII: PRR",
#         "LIII: EWO",
#         "LXXXV: WCV",
#         "LXXVIII: ZKI",
#         "IX: XYU",
#         "LVII: RKH",
#         "XXIII: LSR",
#     ]


def roman_to_int(s):
    rom_val = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    int_val = 0
    for i in range(len(s)):
        if i > 0 and rom_val[s[i]] > rom_val[s[i - 1]]:
            int_val += rom_val[s[i]] - 2 * rom_val[s[i - 1]]
        else:
            int_val += rom_val[s[i]]
    return int_val


def main():
    instagram = Instagram()
    posts = instagram.get_medias("best_chisinau", count=230)
    keys = []

    for m in posts:
        caption = m.caption
        if caption[-1].isupper():
            parts = caption.split("\n\n")
            if ":" in parts[-1]:
                keys.append(parts[-1])
    mapping = {}

    # covertam roman in arabic si format un dict nr -> litere
    for key in keys:
        roman, val = key.split(":")
        nr = roman_to_int(roman)
        mapping[nr] = val.strip()

    # sortam dict dupa key in ordine crescatoare
    mapping = {k : mapping[k] for k in sorted(mapping)}

    print("Mesajul format este:")
    # concatenam toate valorile din dict
    mesaj = "".join(mapping.values())
    print(mesaj)

if __name__ == "__main__":
    main()