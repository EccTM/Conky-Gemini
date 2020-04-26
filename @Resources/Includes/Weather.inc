[MeasureWeather]
Measure=Plugin
Plugin=WebParser
Url=https://api.weatherbit.io/v2.0/current?city=#weatherCity#&country=#weatherCountry#&key=#weatherAPIKey#
RegExp="(?siU)"rh":(.*),.*{"icon":"(.*)",.*"description":"(.*)"},.*"temp":(.*),"
UpdateRate=900

[MeasureHumidity]
Measure=Plugin
Plugin=WebParser
URL=[MeasureWeather]
StringIndex=1

[MeasureWeatherCurrentCode]
Measure=Plugin
Plugin=WebParser
URL=[MeasureWeather]
OnChangeAction=[!Log "The measure [*MeasureWeatherCurrentCode*] was just updated to the value [MeasureWeatherCurrentCode]" Debug]
StringIndex=2
Substitute="":"unknown"

[MeasureWeatherCondition]
Measure=Plugin
Plugin=WebParser
URL=[MeasureWeather]
StringIndex=3

[MeasureWeatherCurrentTemp]
Measure=Plugin
Plugin=WebParser
URL=[MeasureWeather]
StringIndex=4