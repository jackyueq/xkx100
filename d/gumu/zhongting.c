// Room: /d/gumu/zhongting.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�⴦�ǹ�Ĺ�ɵ��Ӳμ�����֮�����˿̹�Ĺ����С��Ů��������
����������̽����������˲����书�ѳ�һ����ʦ������ʸ־����֮
�������������Ľ���ѡ�����ֻһ�ų���������ʯ�Ρ�
    ���Ϸ���һ���Ҷ�(bian).
LONG	);
	set("exits", ([
		"east"  : __DIR__"mudao06",
		"west"  : __DIR__"mudao05",
		"south" : __DIR__"mudao08",
		"north" : __DIR__"mudao17",
	])); 
	set("item_desc", ([
		"bian" :  HIR"
             ����������������������������������������
             ����������                      ��������
             ��������    ���鲻�� ��ĵ���   ��������
             ��������                        ��������
             ����������������������������������������\n"NOR,
	]));
        set("objects", ([
                CLASS_D("gumu")+"/longnv" : 1,
        ]));
        set("valid_startroom",1);
        set("coor/x", -3200);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
        "/clone/board/gumu_b"->foo();
}

void init()
{ 
	add_action("do_jump","zong");
	add_action("do_jump","tiao");
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg!="bian")
		return notify_fail("Ҫ����������\n");
	if(me->query_skill("yunv-shenfa", 1) < 10)
		return notify_fail("����Ů�������������������Ҷ\n");
	message_vision(HIY"$N�������У�ƽ�հ������ɣ����������Ҷ�֮��\n"NOR,me);
	me->move(__DIR__"bianhou"); 
	return 1; 
}

