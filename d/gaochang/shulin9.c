// Room: /d/gaochang/shulin9.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�߲��Թ�");
	set("long", @LONG
������������ĳ�������ǰ����������������Թ�֮�ڲ�����
��ָ�����㲻֪��Ҫ������·�ߡ�����ϸ���������ף����׺�ǰ������
·�϶��е������㼣�����ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
	);

	set("outdoors", "gaochang");
        set("no_drop",1);
	set("exits", ([
		"east" : __DIR__"shulin"+(random(8)+6),
		"west" : __DIR__"shulin"+(random(8)+6),
		"south" : __DIR__"shulin"+(random(8)+6),
		"north" : __DIR__"shulin"+(random(8)+6),
	]));
	set("coor/x", -38000);
	set("coor/y", 11000);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob, room;
	mapping fam;

	int i = random(2);
	if( i == 0) return;

	ob = this_player();
	room = this_object();

	if (ob->query("id") == "gui" || !living(ob)) return;

	message_vision(HIR "\n$Nһ��С�ģ��������Թ��Ļ��أ�
$Nֻ����ͷ��һ����죬ԭ����ͷ��һ���ʯ���¡�\n\n" NOR, ob);

	message_vision(HIR "\n$Nʹ�ü���ʧȥ��֪��......\n\n" NOR, ob);

	if((int)ob->query("qi")<250) ob->die(); else ob->unconcious();
}