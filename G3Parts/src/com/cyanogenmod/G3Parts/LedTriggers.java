package com.cyanogenmod.G3Parts;

import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.os.SystemProperties;
import android.content.SharedPreferences;
import android.preference.Preference;
import android.preference.Preference.OnPreferenceChangeListener;
import android.preference.PreferenceManager;
import android.text.TextUtils;

public class LedTriggers implements OnPreferenceChangeListener {

    private static final String FILE = "/sys/devices/platform/s5p6442_led.1/leds/button_led/trigger";

    private static final String PROP_LED_TRIGGER = "persist.sys.led_trigger";

    public static boolean isSupported() {
        return Utils.fileExists(FILE);
    }


    public static void restore(Context context) {
        if (!isSupported()) {
            return;
        }

        SharedPreferences sharedPrefs = PreferenceManager.getDefaultSharedPreferences(context);
        Utils.writeValue(FILE, sharedPrefs.getString(G3Parts.KEY_LED_TRIGGERS, "none"));
    }

    @Override
    public boolean onPreferenceChange(Preference preference, Object newValue) {
        Utils.writeValue(FILE, (String) newValue);
        SystemProperties.set(PROP_LED_TRIGGER, (String) newValue);
        return true;
    }

}
