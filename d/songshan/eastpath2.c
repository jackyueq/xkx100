// Room: /d/songshan/eastpath2.c
// Last Modified by Winder on Jul. 15 2001

inherit RESTROOM_OUT;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǻ��Ƴ��������ȣ������񶰣�ȴҲ������ۼ��һ·��������
��ľ���춯��������ζ�������������ģ��˷���磬ֻ�������������
�䣬��ɽ���������
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"south" : __DIR__"eastting",
		"north" : __DIR__"eastwuchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 910);
	set("coor/z", 90);
	set("door_name","��");
	set("door_dir","east");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","���Ϲ��˸����ӣ���Ϣ�ҡ�\n");
	set("no_one_msg",   "���Ϲ��˸����ӣ���Ϣ�ҡ�\n");
	set("inside_msg",   "���Ϲ��˸����ӣ�����һ�Ρ��������죡\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
