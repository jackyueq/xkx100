
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("gumu")+"/longnv");
	set("start_room","/d/gumu/qianting");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("gender") != "Ů��")
	{
		return "����ֻ��Ů�Ӳ��ܽ������ŵ���һְ��";
	}
	return ::zm_apply();
}
