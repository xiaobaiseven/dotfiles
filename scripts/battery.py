import psutil

if __name__ == "__main__":
    battery = psutil.sensors_battery()
    if battery is not None:
        percent = battery.percent
        plugged = battery.power_plugged
        if not plugged:
            if percent == 100:
                plug = "󱊣"
            elif percent <= 20:
                plug = "󰁻"
            elif 20 < percent <= 50:
                plug = "󰁽"
            elif 50 < percent <= 80:
                plug = "󰁿"
            else:
                plug = "󰂁"
        else:
            if percent == 100:
                plug = "󰂅"
            elif percent <= 20:
                plug = "󰂆"
            elif 20 < percent <= 50:
                plug = "󰢝"
            elif 50 < percent <= 80:
                plug = "󰂊"
            else:
                plug = "󰂋"

        print(f"{plug} {percent:.1f}%")
