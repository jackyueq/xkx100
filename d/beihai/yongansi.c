// /d/beihai/yongansi.c
// Last Modified by winder on May. 22 2002
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������£���ʷ�Ѿ����ƾ��ˡ��������±��ϾͿɵ��������
����������һ��ʯ�ţ�������ʯ�ţ������Ӱ���ɽ���ųǵ�ͨ����
LONG
	);
	set("exits", ([
		"west"      : __DIR__"yuexin",
		"south"     : __DIR__"yonganqiao",
		"northup"   : __DIR__"baita",
		"northeast" : __DIR__"zhizhu",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
