// Room: /d/nanshaolin/dmyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"��ĦԺ"NOR);
	set("long", @LONG
����һ�����ӵĵ��á����׵�ǽ�Ϲ����˸����书ͼ�ף����ٰ���
��ü����ɮ����������ͼ�׻���֮ǰ���ƺ��ڿ��˼�����ϱ�ɽǽ�Ǹ�
���ݶ��Ĵ���ܣ��߽�ϸ���������Ǹ��Ÿ��ɵ��书���ţ������а���
���Ű���ڭ�ͼ����ţ���λ��ɮ�����붨�С������и�С��ͨ���
LONG );
	set("exits", ([
		"south" : __DIR__"huilang4",
		"north" : __DIR__"dmyuan2",
	]));
        set("objects",([
		CLASS_D("nanshaolin") + "/tianjing" : 1,
		__DIR__"npc/xiao-bei" : 1,
        ]));
	set("coor/x", 1790);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
        int skill;
	mapping myfam;
	myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "��������") && dir == "north" &&
		objectp(present("tianjing dashi", environment(me))))
		return notify_fail("�쾵��ʦ�ȵ�����ĦԺ�˱����صأ���������ֵ��ӣ��������ڡ�\n");
	skill = me->query_skill("yijinjing", 1);
	if (!wizardp(me) && skill < 80 &&
		objectp(present("tianjing dashi", environment(me))))
	{
		if (dir == "north")
		{
			return notify_fail("�쾵��ʦҡͷ�����㹦�򻹲��������ܽ����ĦԺ��\n");
		}
	}
        return ::valid_leave(me, dir);
}
