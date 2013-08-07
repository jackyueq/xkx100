// Room: /binghuo/southboat1.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
��ľ���ǵ��ϲ����ľ���ͣ�������Φ��Φ����Щľ�������ں�
��֮�أ�ľ�����ܣ�Ӳ����ʯ�������ͷ�������������Ƥ����֯����
�ᡣ����ˮ���⣬������ˮ��Ƥ�����Ѿ߱���ֻǷ......
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"haitan",
	]));
	setup();
}

void init()
{
	object ob = this_player();
	mapping fam;
	if ((strsrch(NATURE_D->game_time(), "һ��") >= 0) ||
	   (strsrch(NATURE_D->game_time(), "����") >= 0))
	{
		call_out("south1", 3, ob);
	}
	else
	{
		message_vision(HIR"\n���ڱ���δ������»ز�ȥ�ˣ�\n"NOR, ob);
	}
}

void south1( object ob )
{
	message_vision( BLU
"\n��ʱ��������ľ�ţ�����Ʈ����$N�ۼ���������ģ��������
��С����ȥ�������������ã�������Ҳ�Ʋ����ˡ�\n\n" NOR, ob);
	ob ->move(__DIR__"southboat2") ;
	tell_object(ob, BLU 
"\nһ·�ε��Ǳ��磬����ľ��ֱ�����С�����ãã��֮�ϣ���Ҳ�ϲ�
�����򣬵���ÿ��̫�����������𣬴��������£�ÿ�������ڷ���
��˸����ľ�����ǲ�ͣ���ƶ������֪����ԭ�ս�һ�ա�\n" NOR ) ;
	call_out("south2", 10, ob);
}
void south2( object ob )
{
	tell_object(ob , BLU
"\n���ڵ����ˣ�����ƣ������̤ʵ�������鸡�ĸо���\n\n" NOR) ;
	ob->move ("/d/beijing/haigang");
}

