
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("gaibang")+"/hong");
	set("start_room", "/d/gaibang/pomiao");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if ( ob->query("party/party_name")!= HIC"ؤ��"NOR )
	  return "��ؤ���д����ӣ�����ʤ�����ŵ���һְ��";
	return ::zm_apply();
}
