// /d/beihai/dongmen.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǳ����Ķ��ţ�ľ�Ƶ��ſ�����˴��ɫ����Ȼ�������ڵ����紵��
��ɫȴ�Ծ�ʮ�����ޡ����ĳ�������ר��ά���ġ�����û�������ı�־�����ſ�
վ�ż�����ʿ�����졣
LONG
	);
	set("exits", ([
		"south"     : __DIR__"shulin",
		"northeast" : __DIR__"huafang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -170);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
