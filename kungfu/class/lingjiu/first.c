
#include <ansi.h>
inherit F_FIRST;

void create()
{
	set("master_dir",CLASS_D("lingjiu")+"/xuzhu");
	set("start_room","/d/lingjiu/xianchou");
	::create();
}

string zm_apply()
{
	object ob = this_player();
	if ( ob->query("gender")!= "Ů��" )
	  return "���չ�ֻ��Ů�Ӳ��ܽ������ŵ���һְ��";
	return ::zm_apply();
}
