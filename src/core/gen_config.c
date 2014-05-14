/*
 * uhub - A tiny ADC p2p connection hub
 * Copyright (C) 2007-2014, Jan Vidar Krey
 *
 * THIS FILE IS AUTOGENERATED - DO NOT MODIFY
 * Created 2014-05-14 11:38, by config.py
 */

void config_defaults(struct hub_config* config)
{
	config->hub_enabled = 1;
	config->server_port = 1511;
	config->server_bind_addr = hub_strdup("any");
	config->server_listen_backlog = 50;
	config->server_alt_ports = hub_strdup("");
	config->show_banner = 1;
	config->show_banner_sys_info = 1;
	config->max_users = 500;
	config->registered_users_only = 0;
	config->obsolete_clients = 0;
	config->hub_name = hub_strdup("uhub");
	config->hub_description = hub_strdup("no description");
	config->redirect_addr = hub_strdup("");
	config->max_recv_buffer = 4096;
	config->max_send_buffer = 131072;
	config->max_send_buffer_soft = 98304;
	config->low_bandwidth_mode = 0;
	config->max_logout_log = 20;
	config->limit_max_hubs_user = 10;
	config->limit_max_hubs_reg = 10;
	config->limit_max_hubs_op = 10;
	config->limit_max_hubs = 25;
	config->limit_min_hubs_user = 0;
	config->limit_min_hubs_reg = 0;
	config->limit_min_hubs_op = 0;
	config->limit_min_share = 0;
	config->limit_max_share = 0;
	config->limit_min_slots = 0;
	config->limit_max_slots = 0;
	config->flood_ctl_interval = 0;
	config->flood_ctl_chat = 0;
	config->flood_ctl_connect = 0;
	config->flood_ctl_search = 0;
	config->flood_ctl_update = 0;
	config->flood_ctl_extras = 0;
	config->tls_enable = 0;
	config->tls_require = 0;
	config->tls_require_redirect_addr = hub_strdup("");
	config->tls_certificate = hub_strdup("");
	config->tls_private_key = hub_strdup("");
	config->nmdc_only_redirect_addr = hub_strdup("");
	config->file_acl = hub_strdup("");
	config->file_plugins = hub_strdup("");
	config->opchat_nick = hub_strdup("Operations");
	config->opchat_desc = hub_strdup("Hub operators");
	config->opchat_keys = 1;
	config->msg_hub_full = hub_strdup("Hub is full");
	config->msg_hub_disabled = hub_strdup("Hub is disabled");
	config->msg_hub_registered_users_only = hub_strdup("Hub is for registered users only");
	config->msg_inf_error_nick_missing = hub_strdup("No nickname given");
	config->msg_inf_error_nick_multiple = hub_strdup("Multiple nicknames given");
	config->msg_inf_error_nick_invalid = hub_strdup("Nickname is invalid");
	config->msg_inf_error_nick_long = hub_strdup("Nickname too long");
	config->msg_inf_error_nick_short = hub_strdup("Nickname too short");
	config->msg_inf_error_nick_spaces = hub_strdup("Nickname cannot start with spaces");
	config->msg_inf_error_nick_bad_chars = hub_strdup("Nickname contains invalid characters");
	config->msg_inf_error_nick_not_utf8 = hub_strdup("Nickname is not valid UTF-8");
	config->msg_inf_error_nick_taken = hub_strdup("Nickname is already in use");
	config->msg_inf_error_nick_restricted = hub_strdup("Nickname cannot be used on this hub");
	config->msg_inf_error_cid_invalid = hub_strdup("CID is not valid");
	config->msg_inf_error_cid_missing = hub_strdup("CID is not specified");
	config->msg_inf_error_cid_taken = hub_strdup("CID is taken");
	config->msg_inf_error_pid_missing = hub_strdup("PID is not specified");
	config->msg_inf_error_pid_invalid = hub_strdup("PID is invalid");
	config->msg_ban_permanently = hub_strdup("Banned permanently");
	config->msg_ban_temporarily = hub_strdup("Banned temporarily");
	config->msg_auth_invalid_password = hub_strdup("Password is wrong");
	config->msg_auth_user_not_found = hub_strdup("User not found in password database");
	config->msg_error_no_memory = hub_strdup("No memory");
	config->msg_user_share_size_low = hub_strdup("User is not sharing enough");
	config->msg_user_share_size_high = hub_strdup("User is sharing too much");
	config->msg_user_slots_low = hub_strdup("User have too few upload slots.");
	config->msg_user_slots_high = hub_strdup("User have too many upload slots.");
	config->msg_user_hub_limit_low = hub_strdup("User is on too few hubs.");
	config->msg_user_hub_limit_high = hub_strdup("User is on too many hubs.");
	config->msg_user_flood_chat = hub_strdup("Chat flood detected, messages are dropped.");
	config->msg_user_flood_connect = hub_strdup("Connect flood detected, connection refused.");
	config->msg_user_flood_search = hub_strdup("Search flood detected, search is stopped.");
	config->msg_user_flood_update = hub_strdup("Update flood detected.");
	config->msg_user_flood_extras = hub_strdup("Flood detected.");
	config->msg_proto_no_common_hash = hub_strdup("No common hash algorithm.");
	config->msg_proto_obsolete_adc0 = hub_strdup("Client is using an obsolete ADC protocol version.");
}

static int apply_config(struct hub_config* config, char* key, char* data, int line_count)
{
	int max = 0;
	int min = 0;

	if (!strcmp(key, "hub_enabled"))
	{
		if (!apply_boolean(key, data, &config->hub_enabled))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "server_port"))
	{
		min = 1;
		max = 65535;
		if (!apply_integer(key, data, &config->server_port, &min, &max))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "server_bind_addr"))
	{
		if (!apply_string(key, data, &config->server_bind_addr, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "server_listen_backlog"))
	{
		min = 5;
		if (!apply_integer(key, data, &config->server_listen_backlog, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "server_alt_ports"))
	{
		if (!apply_string(key, data, &config->server_alt_ports, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "show_banner"))
	{
		if (!apply_boolean(key, data, &config->show_banner))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "show_banner_sys_info"))
	{
		if (!apply_boolean(key, data, &config->show_banner_sys_info))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "max_users"))
	{
		min = 1;
		max = 1048576;
		if (!apply_integer(key, data, &config->max_users, &min, &max))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "registered_users_only"))
	{
		if (!apply_boolean(key, data, &config->registered_users_only))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "obsolete_clients"))
	{
		if (!apply_boolean(key, data, &config->obsolete_clients))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "hub_name"))
	{
		if (!apply_string(key, data, &config->hub_name, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "hub_description"))
	{
		if (!apply_string(key, data, &config->hub_description, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "redirect_addr"))
	{
		if (!apply_string(key, data, &config->redirect_addr, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "max_recv_buffer"))
	{
		min = 1024;
		max = 1048576;
		if (!apply_integer(key, data, &config->max_recv_buffer, &min, &max))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "max_send_buffer"))
	{
		min = 2048;
		if (!apply_integer(key, data, &config->max_send_buffer, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "max_send_buffer_soft"))
	{
		min = 1024;
		if (!apply_integer(key, data, &config->max_send_buffer_soft, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "low_bandwidth_mode"))
	{
		if (!apply_boolean(key, data, &config->low_bandwidth_mode))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "max_logout_log"))
	{
		min = 0;
		max = 2000;
		if (!apply_integer(key, data, &config->max_logout_log, &min, &max))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_max_hubs_user"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_max_hubs_user, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_max_hubs_reg"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_max_hubs_reg, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_max_hubs_op"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_max_hubs_op, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_max_hubs"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_max_hubs, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_min_hubs_user"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_min_hubs_user, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_min_hubs_reg"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_min_hubs_reg, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_min_hubs_op"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_min_hubs_op, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_min_share"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_min_share, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_max_share"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_max_share, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_min_slots"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_min_slots, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "limit_max_slots"))
	{
		min = 0;
		if (!apply_integer(key, data, &config->limit_max_slots, &min, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "flood_ctl_interval"))
	{
		min = 1;
		max = 60;
		if (!apply_integer(key, data, &config->flood_ctl_interval, &min, &max))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "flood_ctl_chat"))
	{
		if (!apply_integer(key, data, &config->flood_ctl_chat, 0, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "flood_ctl_connect"))
	{
		if (!apply_integer(key, data, &config->flood_ctl_connect, 0, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "flood_ctl_search"))
	{
		if (!apply_integer(key, data, &config->flood_ctl_search, 0, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "flood_ctl_update"))
	{
		if (!apply_integer(key, data, &config->flood_ctl_update, 0, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "flood_ctl_extras"))
	{
		if (!apply_integer(key, data, &config->flood_ctl_extras, 0, 0))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "tls_enable"))
	{
		if (!apply_boolean(key, data, &config->tls_enable))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "tls_require"))
	{
		if (!apply_boolean(key, data, &config->tls_require))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "tls_require_redirect_addr"))
	{
		if (!apply_string(key, data, &config->tls_require_redirect_addr, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "tls_certificate"))
	{
		if (!apply_string(key, data, &config->tls_certificate, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "tls_private_key"))
	{
		if (!apply_string(key, data, &config->tls_private_key, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "nmdc_only_redirect_addr"))
	{
		if (!apply_string(key, data, &config->nmdc_only_redirect_addr, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "file_acl"))
	{
		if (!apply_string(key, data, &config->file_acl, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "file_plugins"))
	{
		if (!apply_string(key, data, &config->file_plugins, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "opchat_nick"))
	{
		if (!apply_string(key, data, &config->opchat_nick, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "opchat_desc"))
	{
		if (!apply_string(key, data, &config->opchat_desc, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "opchat_keys"))
	{
		if (!apply_boolean(key, data, &config->opchat_keys))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_hub_full"))
	{
		if (!apply_string(key, data, &config->msg_hub_full, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_hub_disabled"))
	{
		if (!apply_string(key, data, &config->msg_hub_disabled, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_hub_registered_users_only"))
	{
		if (!apply_string(key, data, &config->msg_hub_registered_users_only, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_missing"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_missing, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_multiple"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_multiple, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_invalid"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_invalid, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_long"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_long, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_short"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_short, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_spaces"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_spaces, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_bad_chars"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_bad_chars, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_not_utf8"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_not_utf8, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_taken"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_taken, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_nick_restricted"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_nick_restricted, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_cid_invalid"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_cid_invalid, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_cid_missing"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_cid_missing, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_cid_taken"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_cid_taken, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_pid_missing"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_pid_missing, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_inf_error_pid_invalid"))
	{
		if (!apply_string(key, data, &config->msg_inf_error_pid_invalid, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_ban_permanently"))
	{
		if (!apply_string(key, data, &config->msg_ban_permanently, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_ban_temporarily"))
	{
		if (!apply_string(key, data, &config->msg_ban_temporarily, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_auth_invalid_password"))
	{
		if (!apply_string(key, data, &config->msg_auth_invalid_password, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_auth_user_not_found"))
	{
		if (!apply_string(key, data, &config->msg_auth_user_not_found, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_error_no_memory"))
	{
		if (!apply_string(key, data, &config->msg_error_no_memory, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_share_size_low"))
	{
		if (!apply_string(key, data, &config->msg_user_share_size_low, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_share_size_high"))
	{
		if (!apply_string(key, data, &config->msg_user_share_size_high, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_slots_low"))
	{
		if (!apply_string(key, data, &config->msg_user_slots_low, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_slots_high"))
	{
		if (!apply_string(key, data, &config->msg_user_slots_high, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_hub_limit_low"))
	{
		if (!apply_string(key, data, &config->msg_user_hub_limit_low, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_hub_limit_high"))
	{
		if (!apply_string(key, data, &config->msg_user_hub_limit_high, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_flood_chat"))
	{
		if (!apply_string(key, data, &config->msg_user_flood_chat, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_flood_connect"))
	{
		if (!apply_string(key, data, &config->msg_user_flood_connect, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_flood_search"))
	{
		if (!apply_string(key, data, &config->msg_user_flood_search, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_flood_update"))
	{
		if (!apply_string(key, data, &config->msg_user_flood_update, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_user_flood_extras"))
	{
		if (!apply_string(key, data, &config->msg_user_flood_extras, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_proto_no_common_hash"))
	{
		if (!apply_string(key, data, &config->msg_proto_no_common_hash, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	if (!strcmp(key, "msg_proto_obsolete_adc0"))
	{
		if (!apply_string(key, data, &config->msg_proto_obsolete_adc0, (char*) ""))
		{
			LOG_ERROR("Configuration parse error on line %d", line_count);
			return -1;
		}
		return 0;
	}

	/* Still here -- unknown directive */
	LOG_ERROR("Unknown configuration directive: '%s'", key);
	return -1;
}

void free_config(struct hub_config* config)
{
	hub_free(config->server_bind_addr);

	hub_free(config->server_alt_ports);

	hub_free(config->hub_name);

	hub_free(config->hub_description);

	hub_free(config->redirect_addr);

	hub_free(config->tls_require_redirect_addr);

	hub_free(config->tls_certificate);

	hub_free(config->tls_private_key);

	hub_free(config->nmdc_only_redirect_addr);

	hub_free(config->file_acl);

	hub_free(config->file_plugins);

	hub_free(config->opchat_nick);

	hub_free(config->opchat_desc);

	hub_free(config->msg_hub_full);

	hub_free(config->msg_hub_disabled);

	hub_free(config->msg_hub_registered_users_only);

	hub_free(config->msg_inf_error_nick_missing);

	hub_free(config->msg_inf_error_nick_multiple);

	hub_free(config->msg_inf_error_nick_invalid);

	hub_free(config->msg_inf_error_nick_long);

	hub_free(config->msg_inf_error_nick_short);

	hub_free(config->msg_inf_error_nick_spaces);

	hub_free(config->msg_inf_error_nick_bad_chars);

	hub_free(config->msg_inf_error_nick_not_utf8);

	hub_free(config->msg_inf_error_nick_taken);

	hub_free(config->msg_inf_error_nick_restricted);

	hub_free(config->msg_inf_error_cid_invalid);

	hub_free(config->msg_inf_error_cid_missing);

	hub_free(config->msg_inf_error_cid_taken);

	hub_free(config->msg_inf_error_pid_missing);

	hub_free(config->msg_inf_error_pid_invalid);

	hub_free(config->msg_ban_permanently);

	hub_free(config->msg_ban_temporarily);

	hub_free(config->msg_auth_invalid_password);

	hub_free(config->msg_auth_user_not_found);

	hub_free(config->msg_error_no_memory);

	hub_free(config->msg_user_share_size_low);

	hub_free(config->msg_user_share_size_high);

	hub_free(config->msg_user_slots_low);

	hub_free(config->msg_user_slots_high);

	hub_free(config->msg_user_hub_limit_low);

	hub_free(config->msg_user_hub_limit_high);

	hub_free(config->msg_user_flood_chat);

	hub_free(config->msg_user_flood_connect);

	hub_free(config->msg_user_flood_search);

	hub_free(config->msg_user_flood_update);

	hub_free(config->msg_user_flood_extras);

	hub_free(config->msg_proto_no_common_hash);

	hub_free(config->msg_proto_obsolete_adc0);

}

void dump_config(struct hub_config* config, int ignore_defaults)
{
	if (!ignore_defaults || config->hub_enabled != 1)
		fprintf(stdout, "hub_enabled = %s\n", config->hub_enabled ? "yes" : "no");

	if (!ignore_defaults || config->server_port != 1511)
		fprintf(stdout, "server_port = %d\n", config->server_port);

	if (!ignore_defaults || strcmp(config->server_bind_addr, "any") != 0)
		fprintf(stdout, "server_bind_addr = \"%s\"\n", config->server_bind_addr);

	if (!ignore_defaults || config->server_listen_backlog != 50)
		fprintf(stdout, "server_listen_backlog = %d\n", config->server_listen_backlog);

	if (!ignore_defaults || strcmp(config->server_alt_ports, "") != 0)
		fprintf(stdout, "server_alt_ports = \"%s\"\n", config->server_alt_ports);

	if (!ignore_defaults || config->show_banner != 1)
		fprintf(stdout, "show_banner = %s\n", config->show_banner ? "yes" : "no");

	if (!ignore_defaults || config->show_banner_sys_info != 1)
		fprintf(stdout, "show_banner_sys_info = %s\n", config->show_banner_sys_info ? "yes" : "no");

	if (!ignore_defaults || config->max_users != 500)
		fprintf(stdout, "max_users = %d\n", config->max_users);

	if (!ignore_defaults || config->registered_users_only != 0)
		fprintf(stdout, "registered_users_only = %s\n", config->registered_users_only ? "yes" : "no");

	if (!ignore_defaults || config->obsolete_clients != 0)
		fprintf(stdout, "obsolete_clients = %s\n", config->obsolete_clients ? "yes" : "no");

	if (!ignore_defaults || strcmp(config->hub_name, "uhub") != 0)
		fprintf(stdout, "hub_name = \"%s\"\n", config->hub_name);

	if (!ignore_defaults || strcmp(config->hub_description, "no description") != 0)
		fprintf(stdout, "hub_description = \"%s\"\n", config->hub_description);

	if (!ignore_defaults || strcmp(config->redirect_addr, "") != 0)
		fprintf(stdout, "redirect_addr = \"%s\"\n", config->redirect_addr);

	if (!ignore_defaults || config->max_recv_buffer != 4096)
		fprintf(stdout, "max_recv_buffer = %d\n", config->max_recv_buffer);

	if (!ignore_defaults || config->max_send_buffer != 131072)
		fprintf(stdout, "max_send_buffer = %d\n", config->max_send_buffer);

	if (!ignore_defaults || config->max_send_buffer_soft != 98304)
		fprintf(stdout, "max_send_buffer_soft = %d\n", config->max_send_buffer_soft);

	if (!ignore_defaults || config->low_bandwidth_mode != 0)
		fprintf(stdout, "low_bandwidth_mode = %s\n", config->low_bandwidth_mode ? "yes" : "no");

	if (!ignore_defaults || config->max_logout_log != 20)
		fprintf(stdout, "max_logout_log = %d\n", config->max_logout_log);

	if (!ignore_defaults || config->limit_max_hubs_user != 10)
		fprintf(stdout, "limit_max_hubs_user = %d\n", config->limit_max_hubs_user);

	if (!ignore_defaults || config->limit_max_hubs_reg != 10)
		fprintf(stdout, "limit_max_hubs_reg = %d\n", config->limit_max_hubs_reg);

	if (!ignore_defaults || config->limit_max_hubs_op != 10)
		fprintf(stdout, "limit_max_hubs_op = %d\n", config->limit_max_hubs_op);

	if (!ignore_defaults || config->limit_max_hubs != 25)
		fprintf(stdout, "limit_max_hubs = %d\n", config->limit_max_hubs);

	if (!ignore_defaults || config->limit_min_hubs_user != 0)
		fprintf(stdout, "limit_min_hubs_user = %d\n", config->limit_min_hubs_user);

	if (!ignore_defaults || config->limit_min_hubs_reg != 0)
		fprintf(stdout, "limit_min_hubs_reg = %d\n", config->limit_min_hubs_reg);

	if (!ignore_defaults || config->limit_min_hubs_op != 0)
		fprintf(stdout, "limit_min_hubs_op = %d\n", config->limit_min_hubs_op);

	if (!ignore_defaults || config->limit_min_share != 0)
		fprintf(stdout, "limit_min_share = %d\n", config->limit_min_share);

	if (!ignore_defaults || config->limit_max_share != 0)
		fprintf(stdout, "limit_max_share = %d\n", config->limit_max_share);

	if (!ignore_defaults || config->limit_min_slots != 0)
		fprintf(stdout, "limit_min_slots = %d\n", config->limit_min_slots);

	if (!ignore_defaults || config->limit_max_slots != 0)
		fprintf(stdout, "limit_max_slots = %d\n", config->limit_max_slots);

	if (!ignore_defaults || config->flood_ctl_interval != 0)
		fprintf(stdout, "flood_ctl_interval = %d\n", config->flood_ctl_interval);

	if (!ignore_defaults || config->flood_ctl_chat != 0)
		fprintf(stdout, "flood_ctl_chat = %d\n", config->flood_ctl_chat);

	if (!ignore_defaults || config->flood_ctl_connect != 0)
		fprintf(stdout, "flood_ctl_connect = %d\n", config->flood_ctl_connect);

	if (!ignore_defaults || config->flood_ctl_search != 0)
		fprintf(stdout, "flood_ctl_search = %d\n", config->flood_ctl_search);

	if (!ignore_defaults || config->flood_ctl_update != 0)
		fprintf(stdout, "flood_ctl_update = %d\n", config->flood_ctl_update);

	if (!ignore_defaults || config->flood_ctl_extras != 0)
		fprintf(stdout, "flood_ctl_extras = %d\n", config->flood_ctl_extras);

	if (!ignore_defaults || config->tls_enable != 0)
		fprintf(stdout, "tls_enable = %s\n", config->tls_enable ? "yes" : "no");

	if (!ignore_defaults || config->tls_require != 0)
		fprintf(stdout, "tls_require = %s\n", config->tls_require ? "yes" : "no");

	if (!ignore_defaults || strcmp(config->tls_require_redirect_addr, "") != 0)
		fprintf(stdout, "tls_require_redirect_addr = \"%s\"\n", config->tls_require_redirect_addr);

	if (!ignore_defaults || strcmp(config->tls_certificate, "") != 0)
		fprintf(stdout, "tls_certificate = \"%s\"\n", config->tls_certificate);

	if (!ignore_defaults || strcmp(config->tls_private_key, "") != 0)
		fprintf(stdout, "tls_private_key = \"%s\"\n", config->tls_private_key);

	if (!ignore_defaults || strcmp(config->nmdc_only_redirect_addr, "") != 0)
		fprintf(stdout, "nmdc_only_redirect_addr = \"%s\"\n", config->nmdc_only_redirect_addr);

	if (!ignore_defaults || strcmp(config->file_acl, "") != 0)
		fprintf(stdout, "file_acl = \"%s\"\n", config->file_acl);

	if (!ignore_defaults || strcmp(config->file_plugins, "") != 0)
		fprintf(stdout, "file_plugins = \"%s\"\n", config->file_plugins);

	if (!ignore_defaults || strcmp(config->opchat_nick, "Operations") != 0)
		fprintf(stdout, "opchat_nick = \"%s\"\n", config->opchat_nick);

	if (!ignore_defaults || strcmp(config->opchat_desc, "Hub operators") != 0)
		fprintf(stdout, "opchat_desc = \"%s\"\n", config->opchat_desc);

	if (!ignore_defaults || config->opchat_keys != 1)
		fprintf(stdout, "opchat_keys = %s\n", config->opchat_keys ? "yes" : "no");

	if (!ignore_defaults || strcmp(config->msg_hub_full, "Hub is full") != 0)
		fprintf(stdout, "msg_hub_full = \"%s\"\n", config->msg_hub_full);

	if (!ignore_defaults || strcmp(config->msg_hub_disabled, "Hub is disabled") != 0)
		fprintf(stdout, "msg_hub_disabled = \"%s\"\n", config->msg_hub_disabled);

	if (!ignore_defaults || strcmp(config->msg_hub_registered_users_only, "Hub is for registered users only") != 0)
		fprintf(stdout, "msg_hub_registered_users_only = \"%s\"\n", config->msg_hub_registered_users_only);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_missing, "No nickname given") != 0)
		fprintf(stdout, "msg_inf_error_nick_missing = \"%s\"\n", config->msg_inf_error_nick_missing);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_multiple, "Multiple nicknames given") != 0)
		fprintf(stdout, "msg_inf_error_nick_multiple = \"%s\"\n", config->msg_inf_error_nick_multiple);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_invalid, "Nickname is invalid") != 0)
		fprintf(stdout, "msg_inf_error_nick_invalid = \"%s\"\n", config->msg_inf_error_nick_invalid);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_long, "Nickname too long") != 0)
		fprintf(stdout, "msg_inf_error_nick_long = \"%s\"\n", config->msg_inf_error_nick_long);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_short, "Nickname too short") != 0)
		fprintf(stdout, "msg_inf_error_nick_short = \"%s\"\n", config->msg_inf_error_nick_short);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_spaces, "Nickname cannot start with spaces") != 0)
		fprintf(stdout, "msg_inf_error_nick_spaces = \"%s\"\n", config->msg_inf_error_nick_spaces);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_bad_chars, "Nickname contains invalid characters") != 0)
		fprintf(stdout, "msg_inf_error_nick_bad_chars = \"%s\"\n", config->msg_inf_error_nick_bad_chars);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_not_utf8, "Nickname is not valid UTF-8") != 0)
		fprintf(stdout, "msg_inf_error_nick_not_utf8 = \"%s\"\n", config->msg_inf_error_nick_not_utf8);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_taken, "Nickname is already in use") != 0)
		fprintf(stdout, "msg_inf_error_nick_taken = \"%s\"\n", config->msg_inf_error_nick_taken);

	if (!ignore_defaults || strcmp(config->msg_inf_error_nick_restricted, "Nickname cannot be used on this hub") != 0)
		fprintf(stdout, "msg_inf_error_nick_restricted = \"%s\"\n", config->msg_inf_error_nick_restricted);

	if (!ignore_defaults || strcmp(config->msg_inf_error_cid_invalid, "CID is not valid") != 0)
		fprintf(stdout, "msg_inf_error_cid_invalid = \"%s\"\n", config->msg_inf_error_cid_invalid);

	if (!ignore_defaults || strcmp(config->msg_inf_error_cid_missing, "CID is not specified") != 0)
		fprintf(stdout, "msg_inf_error_cid_missing = \"%s\"\n", config->msg_inf_error_cid_missing);

	if (!ignore_defaults || strcmp(config->msg_inf_error_cid_taken, "CID is taken") != 0)
		fprintf(stdout, "msg_inf_error_cid_taken = \"%s\"\n", config->msg_inf_error_cid_taken);

	if (!ignore_defaults || strcmp(config->msg_inf_error_pid_missing, "PID is not specified") != 0)
		fprintf(stdout, "msg_inf_error_pid_missing = \"%s\"\n", config->msg_inf_error_pid_missing);

	if (!ignore_defaults || strcmp(config->msg_inf_error_pid_invalid, "PID is invalid") != 0)
		fprintf(stdout, "msg_inf_error_pid_invalid = \"%s\"\n", config->msg_inf_error_pid_invalid);

	if (!ignore_defaults || strcmp(config->msg_ban_permanently, "Banned permanently") != 0)
		fprintf(stdout, "msg_ban_permanently = \"%s\"\n", config->msg_ban_permanently);

	if (!ignore_defaults || strcmp(config->msg_ban_temporarily, "Banned temporarily") != 0)
		fprintf(stdout, "msg_ban_temporarily = \"%s\"\n", config->msg_ban_temporarily);

	if (!ignore_defaults || strcmp(config->msg_auth_invalid_password, "Password is wrong") != 0)
		fprintf(stdout, "msg_auth_invalid_password = \"%s\"\n", config->msg_auth_invalid_password);

	if (!ignore_defaults || strcmp(config->msg_auth_user_not_found, "User not found in password database") != 0)
		fprintf(stdout, "msg_auth_user_not_found = \"%s\"\n", config->msg_auth_user_not_found);

	if (!ignore_defaults || strcmp(config->msg_error_no_memory, "No memory") != 0)
		fprintf(stdout, "msg_error_no_memory = \"%s\"\n", config->msg_error_no_memory);

	if (!ignore_defaults || strcmp(config->msg_user_share_size_low, "User is not sharing enough") != 0)
		fprintf(stdout, "msg_user_share_size_low = \"%s\"\n", config->msg_user_share_size_low);

	if (!ignore_defaults || strcmp(config->msg_user_share_size_high, "User is sharing too much") != 0)
		fprintf(stdout, "msg_user_share_size_high = \"%s\"\n", config->msg_user_share_size_high);

	if (!ignore_defaults || strcmp(config->msg_user_slots_low, "User have too few upload slots.") != 0)
		fprintf(stdout, "msg_user_slots_low = \"%s\"\n", config->msg_user_slots_low);

	if (!ignore_defaults || strcmp(config->msg_user_slots_high, "User have too many upload slots.") != 0)
		fprintf(stdout, "msg_user_slots_high = \"%s\"\n", config->msg_user_slots_high);

	if (!ignore_defaults || strcmp(config->msg_user_hub_limit_low, "User is on too few hubs.") != 0)
		fprintf(stdout, "msg_user_hub_limit_low = \"%s\"\n", config->msg_user_hub_limit_low);

	if (!ignore_defaults || strcmp(config->msg_user_hub_limit_high, "User is on too many hubs.") != 0)
		fprintf(stdout, "msg_user_hub_limit_high = \"%s\"\n", config->msg_user_hub_limit_high);

	if (!ignore_defaults || strcmp(config->msg_user_flood_chat, "Chat flood detected, messages are dropped.") != 0)
		fprintf(stdout, "msg_user_flood_chat = \"%s\"\n", config->msg_user_flood_chat);

	if (!ignore_defaults || strcmp(config->msg_user_flood_connect, "Connect flood detected, connection refused.") != 0)
		fprintf(stdout, "msg_user_flood_connect = \"%s\"\n", config->msg_user_flood_connect);

	if (!ignore_defaults || strcmp(config->msg_user_flood_search, "Search flood detected, search is stopped.") != 0)
		fprintf(stdout, "msg_user_flood_search = \"%s\"\n", config->msg_user_flood_search);

	if (!ignore_defaults || strcmp(config->msg_user_flood_update, "Update flood detected.") != 0)
		fprintf(stdout, "msg_user_flood_update = \"%s\"\n", config->msg_user_flood_update);

	if (!ignore_defaults || strcmp(config->msg_user_flood_extras, "Flood detected.") != 0)
		fprintf(stdout, "msg_user_flood_extras = \"%s\"\n", config->msg_user_flood_extras);

	if (!ignore_defaults || strcmp(config->msg_proto_no_common_hash, "No common hash algorithm.") != 0)
		fprintf(stdout, "msg_proto_no_common_hash = \"%s\"\n", config->msg_proto_no_common_hash);

	if (!ignore_defaults || strcmp(config->msg_proto_obsolete_adc0, "Client is using an obsolete ADC protocol version.") != 0)
		fprintf(stdout, "msg_proto_obsolete_adc0 = \"%s\"\n", config->msg_proto_obsolete_adc0);

}

