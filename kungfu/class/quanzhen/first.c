#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("quanzhen")+"/wang");
	set("start_room","/d/quanzhen/datang1");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("class") != "quanzhen")
	{
		return "��������ȫ���ʿ���ţ�";
	}
	return ::zm_apply();
}