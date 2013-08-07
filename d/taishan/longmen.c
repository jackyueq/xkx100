// Room: /d/taishan/longmen.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˴�ɽ�ƶ��ͣ���ɽ����һ����С�ĺ����ױ����鵽�¹�֮�С�
��������������κ��ġ�̿�ݡ����š����֡���ַ��Ϊ���������꼾
��ˮ��Ͽ����Ȫ��к��
LONG );
	set("exits", ([
		"northup"   : __DIR__"jinman18",
		"southdown" : __DIR__"man18",
	]));
	set("objects", ([
		__DIR__"npc/chi" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 730);
	set("coor/z", 160);
	setup();
}

void init()
{
	object me = this_player();
	
	if( userp(me) && random((int)me->query_skill("dodge")) <= 10) 
	{
		me->receive_damage("qi", 50);
		me->receive_wound("qi",  50);
		message_vision(HIR"$Nһ��С�Ľ���̤�˸���... ��...��\n"NOR, me);
		me->move(__DIR__"daizong");
		tell_object(me, HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
		message("vision",HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
	}
}
