
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("hengshan")+"/xian");
	set("start_room","/d/hengshan/square");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("gender") != "Ů��" || ob->query("class")!= "bonze")
	{
		return "����ֻ��Ů����ܽ������ŵ���һְ��";
	}
	return ::zm_apply();
}
