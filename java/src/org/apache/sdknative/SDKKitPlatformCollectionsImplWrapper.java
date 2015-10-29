package org.apache.sdknative;

import android.app.Activity;

import com.hjr.sdkkit.framework.mw.entity.DataTypes;
import com.hjr.sdkkit.framework.mw.entity.ParamsContainer;
import com.hjr.sdkkit.framework.mw.entity.ParamsKey;
import com.hjr.sdkkit.framework.mw.openapi.HJRSDKKitPlateformCore;

public class SDKKitPlatformCollectionsImplWrapper {

	private static HJRSDKKitPlateformCore s_plateformSDK;
	private static Activity s_context;

	public static void setPlateform(HJRSDKKitPlateformCore plateformSDK,
			Activity context) {
		s_plateformSDK = plateformSDK;
		s_context = context;
	}
	
	public static void onEnterGame(
			final String roleId,
			final String roleName,
			final String roleLevel,
			final String serverId,
			final String ServerName) {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				ParamsContainer pc = new ParamsContainer();
				// 角色id
				pc.putString(ParamsKey.KEY_ROLE_ID, roleId);
				// 角色昵称
				pc.putString(ParamsKey.KEY_ROLE_NAME, roleName);
				// 角色等级
				pc.putInt(ParamsKey.KEY_ROLE_LEVEL, Integer.getInteger(roleLevel));
				// 服务器编号
				pc.putString(ParamsKey.KEY_SERVER_ID, serverId);
				// 服务器名称
				pc.putString(ParamsKey.KEY_SERVER_NAME, ServerName);
		
				s_plateformSDK.Collections.onDatas(DataTypes.DATA_ENTER_GAME, pc);

			}
		});
	}


	public static void onLogin(final String userId, final String serverId) {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				ParamsContainer pc = new ParamsContainer();
				// 用户标识
				pc.putString(ParamsKey.KEY_USER_ID, userId);
				// 服务器编号
				pc.putString(ParamsKey.KEY_SERVER_ID, serverId);

				s_plateformSDK.Collections.onDatas(DataTypes.DATA_LOGIN, pc);

			}
		});

	}

	public static void onPay(
			final int amount,
			final String orderNumber,
			final String productDesc) {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				ParamsContainer pc = new ParamsContainer();

				// 充值金额
				pc.putInt(ParamsKey.KEY_AMOUNT, amount);
				// 服务器ID
				// 订单号
				pc.putString(ParamsKey.KEY_ORDERNUMBER, orderNumber);
				// 商品描述
				pc.putString(ParamsKey.KEY_PRODUCT_DESC, productDesc);

				s_plateformSDK.Collections.onDatas(DataTypes.DATA_PAY, pc);
			}
		});
	}

	public static void onUpgrade(final String roleLevel) {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				ParamsContainer pc = new ParamsContainer();
				// 玩家升级后等级
				pc.putString(ParamsKey.KEY_ROLE_LEVEL, roleLevel);

				s_plateformSDK.Collections.onDatas(DataTypes.DATA_ROLE_UPGRADE,
						pc);

			}
		});
	}

	public static void onServerRoleInfo(final String roleId,
			final String roleName, final int roleLevel, final String serverId,
			final String serverName, final String rolePartyName,
			final String roleVipLevel) {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				ParamsContainer pc = new ParamsContainer();
				// 角色id
				pc.putString(ParamsKey.KEY_ROLE_ID, roleId);
				// 角色昵称
				pc.putString(ParamsKey.KEY_ROLE_NAME, roleName);
				// 角色等级
				pc.putInt(ParamsKey.KEY_ROLE_LEVEL, roleLevel);
				// 服务器编号
				pc.putString(ParamsKey.KEY_SERVER_ID, serverId);
				// 服务器名称
				pc.putString(ParamsKey.KEY_SERVER_NAME, serverName);
				// 角色所在帮派或工会名称，没有可以传""
				pc.putString(ParamsKey.KEY_ROLE_PARTY_NAME, rolePartyName);
				// VIP等级，没有可以传""
				pc.putString(ParamsKey.KEY_ROLE_VIP_LEVEL, roleVipLevel);

				s_plateformSDK.Collections.onDatas(
						DataTypes.DATA_SERVER_ROLE_INFO, pc);

			}
		});
	}

	public static void onButtonClick(final String userId,
			final String buttonName) {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				ParamsContainer pc = new ParamsContainer();
				pc.putString(ParamsKey.KEY_USER_ID, userId);
				pc.putString(ParamsKey.KEY_NAME, buttonName);
				s_plateformSDK.Collections.onDatas(DataTypes.DATA_BUTTON_CLICK,
						pc);

			}
		});
	}

	public static void onCreateRole(
			final String roleId,
			final String roleName,
			final String serverId,
			final String serverName) {
		s_context.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				ParamsContainer pc = new ParamsContainer();
				// 角色标识
				pc.putString(ParamsKey.KEY_ROLE_ID, roleId);
				// 角色昵称
				pc.putString(ParamsKey.KEY_ROLE_NAME, roleName);
				// 服务器编号
				pc.putString(ParamsKey.KEY_SERVER_ID, serverId);
				// 服务器名称
				pc.putString(ParamsKey.KEY_SERVER_NAME, serverName);

				s_plateformSDK.Collections.onDatas(DataTypes.DATA_CREATE_ROLE,
						pc);

			}
		});
	}

}
