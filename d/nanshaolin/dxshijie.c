// Room: /d/nanshaolin/dxshijie.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "̨��");
	set("long", @LONG
���۱���ǰ��ʯ�ף�����ƽ�е���ʯ��չ��ǰ����������һ��ʯ��
·������Ʈ���������̡�����Ǵ��ڴ���ϢĬ����Ȼ��һ��һ�ݵ���
�۱���ȥ��
LONG );
	set("exits", ([
		"northup" : __DIR__ "pingtai",
		"south"   : __DIR__ "miaofadian",
	]));
	set("objects", ([
		CLASS_D("nanshaolin")+"/first" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

