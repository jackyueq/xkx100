// Room: /d/chengdu/ruin2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "ؤ��ֶ�");
	set("long", @LONG
������һ���ƾɴ�լ�������������ǽ�ڸ��ݶ��Ѿ�����̮���ˣ�
���쬵����ӱ��ߵ�ȱ��ֱ��������������������ǣ�������ɨ��
�൱���࣬������Ǭ���������������һ����(bed)��
LONG	);
	set("exits", ([
		"east": __DIR__"ruin1"
	]));
	set("item_desc", ([
		"bed"  : "���ͷһ�������ִ��̵��¾�Ȼ�и����ĵĶ�(dong)��\n",
		"dong" : "����һ���ں����Ķ��ڣ���֪�������ж��\n",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/obj/jiaohuaji" : 1,
		FOOD_DIR"jitui" : 1,
		FOOD_DIR"jiudai": 1,
	]));
	set("coor/x", -8080);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me = this_player();
	mapping fam;

	if( !arg || arg=="" ) return 0;
	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "ؤ��")
		{
			message("vision", me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n", environment(me), ({me}) );
			me->move("/d/gaibang/undercd");
                	message("vision", me->name() + "�Ӷ������˽�����\n", environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}
