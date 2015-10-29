package org.apache.sdknative;

import org.json.JSONObject;

import android.app.Activity;
import android.content.Context;
import android.opengl.GLSurfaceView;

import com.hjr.sdkkit.framework.mw.entity.ParamsContainer;
import com.hjr.sdkkit.framework.mw.entity.ParamsKey;
import com.hjr.sdkkit.framework.mw.openapi.HJRSDKKitPlateformCore;

public class SDKKitPlateformBusinessImplWrapper {

	private static HJRSDKKitPlateformCore s_plateformSDK;
	private static Activity s_context;
	public static GLSurfaceView s_glview;

	public static void setContext(Activity activity,
			HJRSDKKitPlateformCore plateformSDK, GLSurfaceView glview) {
		s_context = activity;
		s_plateformSDK = plateformSDK;
		s_glview = glview;
	}

	public static void setPlateform(HJRSDKKitPlateformCore plateformSDK,
			Context context) {
		s_plateformSDK = plateformSDK;
	}

	public static void login() {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				s_plateformSDK.Business.login(s_context);
			}

		});

	}

//	public static void kitCenter() {
//		s_context.runOnUiThread(new Runnable() {
//
//			@Override
//			public void run() {
//				ParamsContainer pc = new ParamsContainer();
//				s_plateformSDK.Business.kitCenter(pc, new Object());
//			}
//
//		});
//	}
//
//	public static void switchAccount() {
//		s_context.runOnUiThread(new Runnable() {
//
//			@Override
//			public void run() {
//				ParamsContainer pc = new ParamsContainer();
//				s_plateformSDK.Business.switchAccount(pc);
//			}
//
//		});
//	}

	public static void pay(
			final int payAmount,
			final String productId,
			final String productName,
			final String payProductNum,
			final String payOrderId,
			final String payProductDesc,
			final String extInfo) {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				ParamsContainer pc = new ParamsContainer();
				// 所购买商品金额, 以元为单位。
				pc.putInt(ParamsKey.KEY_PAY_AMOUNT, payAmount);
				// 购买数量 
				pc.putInt(ParamsKey.KEY_PAY_PRODUCT_NUM, Integer.parseInt(payProductNum));
				// 订单号， 没有传""
				pc.putString(ParamsKey.KEY_PAY_ORDER_ID, payOrderId);
				//商品ID
				pc.putInt(ParamsKey.KEY_PAY_PRODUCT_ID, Integer.parseInt(productId));
				// 所购买商品名称
				pc.putString(ParamsKey.KEY_PAY_PRODUCT_NAME, productName);
				// 区服ID 
				pc.putString(ParamsKey.KEY_PRODUCT_DESC, payProductDesc);
				// 扩展参数
				pc.putString(ParamsKey.KEY_EXTINFO, extInfo);
				
				s_plateformSDK.Business.pay(pc);
			}

		});
	}

	public static void userCenter() {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				s_plateformSDK.Business.userCenter();
			}

		});
	}

	public static void logout() {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				s_plateformSDK.Business.logout();
			}

		});
	}

	public static void getOrderInfo(final String payOrderId) {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				ParamsContainer pc = new ParamsContainer();
				pc.put(ParamsKey.KEY_PAY_ORDER_ID, payOrderId);
				s_plateformSDK.Business.getOrderInfo(pc);
			}

		});
	}

//	public static void floatWindow(final boolean value) {
//		// true： 显示， false：隐藏
//		s_context.runOnUiThread(new Runnable() {
//
//			@Override
//			public void run() {
//				s_plateformSDK.Business.floatWindow(value);
//			}
//
//		});
//	}

	public static void exitGame() {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				s_plateformSDK.Business.exitGame(s_context);
			}

		});
	}
	
	public static String getCurrentLoginedUserInfo() {
		JSONObject userInfo = s_plateformSDK.Business.getCurrentLoginedUserInfo();
		return userInfo.toString();
	}
}
