#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("wudang")+"/zhang");
	set("start_room","/d/wudang/guangchang");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("class") != "taoist")
	{
		return "��������֮ʿ������ִ���Ż���";
	}	
	return ::zm_apply();
}