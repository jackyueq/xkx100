// Room: /d/nanshaolin/lwc13.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��
�Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬��ʮ����ɮ��������ϰ�似��
�䳡��һ����һ�������õ�÷��׮(zhuang)���������������һ���䳡��
LONG );
	set("exits", ([
		"east" : __DIR__"lwc12",
		"south" : __DIR__"lwc15",
		"west" : __DIR__"lwc14",
		]));
	set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("item_desc", ([
		"zhuang":"����һ�������Ƴɵ�ľ׮����һ�����磬״��÷�����С�\n",
	]));
	set("coor/x", 1860);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
