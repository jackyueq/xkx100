#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("nanshaolin")+"/tianhong");
	set("start_room","/d/nanshaolin/dxshijie");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if (ob->query("gender") != "����" || ob->query("class") != "bonze")
	{
		return "�������ŵ��������ɳ��Һ��е��Σ�";
	}
	return ::zm_apply();
}