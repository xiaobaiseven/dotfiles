get_ram()
{
    USED_RAM=$(free | awk '/Mem/{printf("%d"), $3/$2*100}')
    echo "💻$USED_RAM%"
}

get_ram
