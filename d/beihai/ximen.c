// /d/beihai/ximen.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǳ��������ţ�ľ�Ƶ��ſ�����˴��ɫ����Ȼ�������ڵ�
���紵����ɫȴ�Ծ�ʮ�����ޡ����ĳ�������ר��ά���ġ�����û��
�����ı�־�����ſ�վ�ż�����ʿ�����졣����ԶԶ���Կ����ų���Ʈ
������ġ�
LONG
	);
	set("exits", ([
		"east"       : __DIR__"yanxiang",
		"north"      : __DIR__"xiaolu1",
		"southwest"  : "/d/beijing/xichang1",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
