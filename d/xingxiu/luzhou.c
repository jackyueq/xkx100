// Room: /d/xingxiu/luzhou.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "ɳĮ����");
	set("long", @LONG
��ɳĮ�ľ�ͷ������һ�����ޡ���ľ������һ�ۿ���������̨����
һ��ľ��ר���ڿʵ����˺�ˮ��������һ��ϵء�
LONG );
	set("resource/water", 1);
	set("outdoors", "xiyu");
	set("exits", ([
		"northeast" : __DIR__"shanjiao",
		"southwest" : __DIR__"nanjiang3",
		"south"	    : "/d/npc/m_weapon/lianbianshi",
	]));

	set("objects", ([
	    __DIR__"npc/obj/donkey" : 1,
	    __DIR__"npc/obj/hamigua" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -41000);
	set("coor/y", 9000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}
int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water)
	{
	    me->set("water", current_water+30);
	    message("vision", me->name()+"ſ�ڿ������ľ�̨����ľ��Ҩ��һ��ˮ�ȡ�\n", environment(me), ({me}) );
	    write("�����һ�ھ��д���ɽ������������ѩˮ����ֱ���ۻ���\n");
	}
	else write("���Ų�ҪǮ��ˮ����ô�ȣ�������\n");

	return 1;
}

