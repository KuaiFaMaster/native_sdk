package org.apache.sdknative;

import android.app.Activity;
import android.content.Context;

public class SDKKitPlatformJniHelper {
	private static Activity s_cacheContext;

	public static Activity getCache() {
		return s_cacheContext;
	}

	public static void nativeSetContext(Activity pContext) {
		s_cacheContext = pContext;
		nativeSetContextJni(pContext);
	}

	private static native void nativeSetContextJni(Context pContext);
}
