// Room: /binghuo/inhole1.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�ⶴ");
	set("long", @LONG
ɽ�����ǿ����а˾�������м�͸��һ����⣬�����촰һ
�㡣�������衢���롢ʯ�ʡ�ľ�������㣬����һ����Ȥ��ʯ������
������ͷ����һ���ﶴ��
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out"   : __DIR__"shanlu1",
		"enter" : __DIR__"inhole2",
	]));
	setup();
}

void init()
{
	object ob;
	int i = random(2);
	if( i == 0) return;

	ob = this_player();

	message_vision(HIR "\n$Nһ��С�ģ������˵����壡
$Nֻ���ý���һ���ʹ��ԭ���ǲ�����......\n\n" NOR, ob);
	ob->move(__DIR__"xianjing");
}
