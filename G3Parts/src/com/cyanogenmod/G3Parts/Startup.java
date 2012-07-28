package com.cyanogenmod.G3Parts;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class Startup extends BroadcastReceiver {

    @Override
    public void onReceive(final Context context, final Intent bootintent) {
        LedTriggers.restore(context);
        WM8994ControlActivity.restore(context);
        if (Hspa.isSupported()) {
            Hspa.restore(context);
        }
    }
}
