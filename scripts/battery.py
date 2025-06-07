import psutil

if __name__ == "__main__":
    battery = psutil.sensors_battery()
    if battery is not None:
        percent = battery.percent
        plugged = battery.power_plugged
        if plugged:
            if percent <= 10:
                plug = "󰢜"
            elif 10 < percent <= 20:
                plug = "󰂆"
            elif 20 < percent <= 30:
                plug = "󰂇"
            elif 30 < percent <= 40:
                plug = "󰂈"
            elif 40 < percent <= 50:
                plug = "󰢝"
            elif 50 < percent <= 60:
                plug = "󰂉"
            elif 60 < percent <= 70:
                plug = "󰢞"
            elif 70 < percent <= 80:
                plug = "󰂊"
            elif 80 < percent <= 90:
                plug = "󰂋"
            else:
                plug = "󰂅"
        else:
            if percent <= 10:
                plug = "󰁺"
            elif 10 < percent <= 20:
                plug = "󰁻"
            elif 20 < percent <= 30:
                plug = "󰁼"
            elif 30 < percent <= 40:
                plug = "󰁽"
            elif 40 < percent <= 50:
                plug = "󰁾"
            elif 50 < percent <= 60:
                plug = "󰁿"
            elif 60 < percent <= 70:
                plug = "󰂀"
            elif 70 < percent <= 80:
                plug = "󰂁"
            elif 80 < percent <= 90:
                plug = "󰂂"
            else:
                plug = "󰁹"

    else:
        print("没有电池")
        
    print(f"{plug} {percent:.1f}%")
