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

public class StereoExpansionGain implements OnPreferenceChangeListener {

    private static final String FILE = "/sys/class/misc/voodoo_sound/stereo_expansion_gain";
    private static final String FILE_CTL = "/sys/class/misc/voodoo_sound/stereo_expansion";

    private static final String PROP_GAIN = "persist.sys.expansion_gain";

    public static boolean isSupported() {
        return Utils.fileExists(FILE);
    }


    public static void restore(Context context) {
	
        if (!isSupported()) {
            return;
        }

        SharedPreferences sharedPrefs = PreferenceManager.getDefaultSharedPreferences(context);

	String myValue = sharedPrefs.getString(WM8994ControlActivity.KEY_EXPANSION_GAIN, "16");

	Utils.writeValue(FILE_CTL, "1");

	if (myValue.equals("0")) {
		Utils.writeValue(FILE_CTL, "0");
       	}

        Utils.writeValue(FILE, myValue);
    }

    @Override
    public boolean onPreferenceChange(Preference preference, Object newValue) {
	String myValue = (String) newValue;

        Utils.writeValue(FILE, myValue);
        SystemProperties.set(PROP_GAIN, myValue);

	Utils.writeValue(FILE_CTL, "1");
	if (myValue.equals("0")) {
		Utils.writeValue(FILE_CTL, "0");
	}

        return true;
    }

}
