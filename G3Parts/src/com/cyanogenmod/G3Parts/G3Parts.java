package com.cyanogenmod.G3Parts;

import android.os.Bundle;
import android.preference.ListPreference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceCategory;
import android.preference.PreferenceScreen;

public class G3Parts extends PreferenceActivity  {

    public static final String KEY_LED_TRIGGERS = "led_triggers";
    public static final String KEY_CATEGORY_RADIO = "category_radio";
    public static final String KEY_HSPA = "hspa";

    private ListPreference mLedTriggers;
    private ListPreference mHspa;
    private PreferenceCategory mHsapCategory;
    private PreferenceScreen mPreferenceScreen;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.main);

        mLedTriggers = (ListPreference) findPreference(KEY_LED_TRIGGERS);
        mLedTriggers.setEnabled(LedTriggers.isSupported());
        mLedTriggers.setOnPreferenceChangeListener(new LedTriggers());

        mHspa = (ListPreference) findPreference(KEY_HSPA);

        if (Hspa.isSupported()) {
            mHspa.setEnabled(true);
            mHspa.setOnPreferenceChangeListener(new Hspa(this));
        } else {
            mHsapCategory = (PreferenceCategory) findPreference(KEY_CATEGORY_RADIO);
            mPreferenceScreen = getPreferenceScreen();

            mHspa.setEnabled(false);
            mHsapCategory.removePreference(mHspa);
            mPreferenceScreen.removePreference(mHsapCategory);
        }
    }
}
