// Last Modified by Winder on May. 21 2001
// Room: /d/fuzhou/puxian.c

inherit ROOM;

void create()
{
	set("short", "����ƽԭ");
	set("long", @LONG
����������ƽԭ�ϡ�����������ģ����̳��ܣ��������Ǹ��ݸ���
�ˡ����Ͼͽ������ϡ�������ȥ����һ�����ꡣ��������಻�ڸߣ���
��������ϡ����ܲ��������У�һ��ɽ·����ǰ�졣
LONG );
	set("exits", ([
		"north" : __DIR__"zhongzhou",
		"south" : "/d/quanzhou/anpingqiao",
		"west"  : "/d/nanshaolin/shanlu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1840);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
