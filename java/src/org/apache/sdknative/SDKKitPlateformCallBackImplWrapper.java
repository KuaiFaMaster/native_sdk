package org.apache.sdknative;

import android.util.Log;

import com.hjr.sdkkit.framework.mw.openapi.callback.HJRSDKKitPlateformCallBack;

public class SDKKitPlateformCallBackImplWrapper implements
		HJRSDKKitPlateformCallBack {

	private static String TAG = "SDKKitPlateformCallBackImplWrapper";

	@Override
	public void initCallBack(int retStatus, String retMessage) {
		Log.i(TAG, "initCallBack-->retStatus#" + retStatus + ",retMessage#"
				+ retMessage);
		if (retStatus == HJRSDKKitPlateformCallBack.STATUS_SUCCESS) {
			Log.i(TAG, "初始化成功");
		} else {
			Log.i(TAG, "初始化 失败");
		}
		final int fRetStatus = retStatus;
		final String fRetMessage = retMessage;
		SDKKitPlateformBusinessImplWrapper.s_glview.queueEvent(new Runnable() {

			@Override
			public void run() {
				initCallBackJni(fRetStatus, fRetMessage);
			}
		});
	}

	private static native void initCallBackJni(int retStatus, String retMessage);

	@Override
	public void loginCallBack(String loginUserId, String loginUserName,
			String loginAuthToken, String loginOpenId, boolean switchUserFlag,
			int retStatus, String retMessage) {

		Log.i(TAG, "loginCallBack-->retStatus#" + retStatus + ",retMessage#"
				+ retMessage + ",loginUserId#" + loginUserId
				+ ",loginUserName#" + loginUserName + ",loginAuthToken#"
				+ loginAuthToken + ",loginOpenId#" + loginOpenId
				+ ",switchUserFlag#" + switchUserFlag);

		final int fRetStatus = retStatus;
		final String fRetMessage = retMessage;
		final String fLoginUserId = loginUserId;
		final String fLoginUserName = loginUserName;
		final String fLoginAuthToken = loginAuthToken;
		final String fLoginOpenId = loginOpenId;
		final boolean fSwitchUserFlag = switchUserFlag;

		SDKKitPlateformBusinessImplWrapper.s_glview.queueEvent(new Runnable() {

			@Override
			public void run() {
				loginCallBackJni(fRetStatus, fRetMessage, fLoginUserId,
						fLoginUserName, fLoginAuthToken, fLoginOpenId,
						fSwitchUserFlag);
			}
		});
	}

	private static native void loginCallBackJni(int retStatus,
			String retMessage, String loginUserId, String loginUserName,
			String loginAuthToken, String loginOpenId, boolean switchUserFlag);

	@Override
	public void logoutCallBack(int retStatus, String retMessage) {
		Log.i(TAG, "logoutCallBack-->retStatus#" + retStatus + ",retMessage#"
				+ retMessage);
		final int fRetStatus = retStatus;
		final String fRetMessage = retMessage;

		SDKKitPlateformBusinessImplWrapper.s_glview.queueEvent(new Runnable() {
			@Override
			public void run() {

				logoutCallBackJni(fRetStatus, fRetMessage);
			}
		});

	}

	private static native void logoutCallBackJni(int retStatus,
			String retMessage);

	@Override
	public void payCallBack(String payKitOrderId, int retStatus,
			String retMessage) {
		Log.i(TAG, "payCallBack-->retStatus#" + retStatus + ",retMessage#"
				+ retMessage + ",payKitOrderId#" + payKitOrderId);

		final int fRetStatus = retStatus;
		final String fRetMessage = retMessage;
		final String fPayKitOrderId = payKitOrderId;

		SDKKitPlateformBusinessImplWrapper.s_glview.queueEvent(new Runnable() {
			@Override
			public void run() {

				payCallBackJni(fRetStatus, fRetMessage, fPayKitOrderId);
			}
		});

	}

	private static native void payCallBackJni(int retStatus, String retMessage,
			String payKitOrderId);

	@Override
	public void getOrderResultCallBack(String orderStatus, int retStatus,
			String retMessage) {
		Log.i(TAG, "getOrderResultCallBack-->retStatus#" + retStatus
				+ ",retMessage#" + retMessage);
		final int fRetStatus = retStatus;
		final String fRetMessage = retMessage;
		final String fOrderStatus = orderStatus;

		SDKKitPlateformBusinessImplWrapper.s_glview.queueEvent(new Runnable() {
			@Override
			public void run() {

				getOrderResultCallBackJni(fRetStatus, fRetMessage, fOrderStatus);
			}
		});

	}

	private static native void getOrderResultCallBackJni(int retStatus,
			String retMessage, String orderStatus);

	@Override
	public void exitGameCallBack(int retStatus, String retMessage) {
		Log.i(TAG, "exitGameCallBack-->retStatus#" + retStatus + ",retMessage#"
				+ retMessage);
		final int fRetStatus = retStatus;
		final String fRetMessage = retMessage;

		SDKKitPlateformBusinessImplWrapper.s_glview.queueEvent(new Runnable() {
			@Override
			public void run() {

				exitGameCallBackJni(fRetStatus, fRetMessage);
			}
		});
	}

	private static native void exitGameCallBackJni(int retStatus,
			String retMessage);

	@Override
	public void pushReceiveCallBack(int arg0, String arg1) {
		
	}
}