
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("emei")+"/miejue");
	set("start_room","/d/emei/hcaguangchang");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("gender") != "Ů��" || ob->query("class") != "bonze")
	{
		return "����������Ů��������ţ�\n";
	}
	return ::zm_apply();
}
