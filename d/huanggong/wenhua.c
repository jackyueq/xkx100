// Room: /d/huanggong/wenhua.c

inherit ROOM;

void create()
{
	set("short", "�Ļ���");
	set("long", @LONG
�������Ļ���, ���������������ǧ��ٹֵ������챦. ������
�ʵ۾��о��۽�ϰ�ĵط�, ÿ�괺������, �ɾ��۽����ڴ���ʵ۽���
�����徭, ���ɻʵ۸���һ��, �������������.
LONG
	);
	set("exits", ([
		"west"      : __DIR__"guangchang",
		"east"      : __DIR__"donghuamen",
		"south"     : __DIR__"wenyuange",
		"southeast" : __DIR__"guoshiguan",
		"southwest" : __DIR__"neigedatang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}